#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <getopt.h>             /* getopt_long() */
#include <fcntl.h>              /* low-level i/o */
#include <unistd.h>
#include <errno.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <asm/types.h>          /* for videodev2.h */
#include <linux/videodev2.h>
#include "Camera.h"


int Camera::convert_yuv_to_rgb_pixel(int y, int u, int v)
{
 unsigned int pixel32 = 0;
 unsigned char *pixel = (unsigned char *)&pixel32;
 int r, g, b;
 r = y + (1.370705 * (v-128));
 g = y - (0.698001 * (v-128)) - (0.337633 * (u-128));
 b = y + (1.732446 * (u-128));
 if(r > 255) r = 255;
 if(g > 255) g = 255;
 if(b > 255) b = 255;
 if(r < 0) r = 0;
 if(g < 0) g = 0;
 if(b < 0) b = 0;
 pixel[0] = r * 220 / 256;
 pixel[1] = g * 220 / 256;
 pixel[2] = b * 220 / 256;
 return pixel32;
}

int Camera::convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height)
{
 unsigned int in, out = 0;
 unsigned int pixel_16;
 unsigned char pixel_24[3];
 unsigned int pixel32;
 int y0, u, y1, v;
 for(in = 0; in < width * height * 2; in += 4) {
  pixel_16 =
   yuv[in + 3] << 24 |
   yuv[in + 2] << 16 |
   yuv[in + 1] <<  8 |
   yuv[in + 0];
  y0 = (pixel_16 & 0x000000ff);
  u  = (pixel_16 & 0x0000ff00) >>  8;
  y1 = (pixel_16 & 0x00ff0000) >> 16;
  v  = (pixel_16 & 0xff000000) >> 24;
  pixel32 = convert_yuv_to_rgb_pixel(y0, u, v);
  pixel_24[0] = (pixel32 & 0x000000ff);
  pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
  pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
  rgb[out++] = pixel_24[0];
  rgb[out++] = pixel_24[1];
  rgb[out++] = pixel_24[2];
  pixel32 = convert_yuv_to_rgb_pixel(y1, u, v);
  pixel_24[0] = (pixel32 & 0x000000ff);
  pixel_24[1] = (pixel32 & 0x0000ff00) >> 8;
  pixel_24[2] = (pixel32 & 0x00ff0000) >> 16;
  rgb[out++] = pixel_24[0];
  rgb[out++] = pixel_24[1];
  rgb[out++] = pixel_24[2];
 }
 return 0;
}


Camera::Camera(char *DEV_NAME, int w, int h)//????????????
{
    dev_name=DEV_NAME;
    io = IO_METHOD_MMAP;//IO_METHOD_READ;//IO_METHOD_MMAP;
    cap_image_size=0;
    width=w;
    height=h;
}

Camera::~Camera(){

}

unsigned int Camera::getImageSize(){
    return cap_image_size;
}

void Camera::CloseDevice() {
    stop_capturing();
    uninit_device();
    close_device();
}

void Camera::errno_exit(const char * s) {
    fprintf(stderr, "%s error %d, %s\n", s, errno, strerror(errno));
    exit(EXIT_FAILURE);
}
int Camera::xioctl(int fd, int request, void * arg) {
    int r;
    do
        r = ioctl(fd, request, arg);
    while (-1 == r && EINTR == errno);
    return r;
}

int Camera::read_frame(unsigned char *image) {
    struct v4l2_buffer buf;
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
    if (-1 == xioctl(fd, VIDIOC_DQBUF, &buf)) //?????????????????????????????????
    {
        switch (errno) {
        case EAGAIN:
            return 0;
        case EIO:
        default:
            errno_exit("VIDIOC_DQBUF");
        }
    }
    assert(buf.index < CAPTURE_BUFFER_NUMBER);
    memcpy((void*)image,(void*)buffers[0].start,buffers[0].length);
    if (-1 == xioctl(fd, VIDIOC_QBUF, &buf))//?????????????????????????????????????????????
        errno_exit("VIDIOC_QBUF");

    return 1;
}
void Camera::stop_capturing(void) {
    enum v4l2_buf_type type;
    switch (io) {
    case IO_METHOD_READ:
        /* Nothing to do. */
        break;
    case IO_METHOD_MMAP:
    case IO_METHOD_USERPTR:
        type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        /*????????????????????????*/
        if (-1 == xioctl(fd, VIDIOC_STREAMOFF, &type))
            errno_exit("VIDIOC_STREAMOFF");
        break;
    }
}
bool Camera::start_capturing(void) {
    unsigned int i;
    enum v4l2_buf_type type;

    for (i = 0; i < CAPTURE_BUFFER_NUMBER; ++i) {
        struct v4l2_buffer buf;
        CLEAR (buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = i;
        if (-1 == xioctl(fd, VIDIOC_QBUF, &buf))//?????????????????????????????????????????????
            return false;
    }
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (-1 == xioctl(fd, VIDIOC_STREAMON, &type))
        return false;

    return true;
}
void Camera::uninit_device(void) {
    unsigned int i;
    switch (io) {
    case IO_METHOD_READ:
        free(buffers[0].start);
        break;
    case IO_METHOD_MMAP:
        for (i = 0; i < CAPTURE_BUFFER_NUMBER; ++i)//???????????????????????????
            if (-1 == munmap(buffers[i].start, buffers[i].length))
                errno_exit("munmap");
        break;
    case IO_METHOD_USERPTR:
        for (i = 0; i < CAPTURE_BUFFER_NUMBER; ++i)
            free(buffers[i].start);
        break;
    }
}
/*********************??????????????????*******************************/
bool Camera::init_mmap(void) {

    bool CouldSetFrameRate = false;
    struct v4l2_streamparm StreamParam;
    memset(&StreamParam, 0, sizeof StreamParam);
    StreamParam.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    if (ioctl(fd, VIDIOC_G_PARM, &StreamParam) < 0)  {
        fprintf(stderr, "could not set frame rate\n");
    } else {
        CouldSetFrameRate = StreamParam.parm.capture.capability & V4L2_CAP_TIMEPERFRAME;
    }

    // map the capture buffer...
    struct v4l2_requestbuffers req;
    CLEAR (req);
    req.count = CAPTURE_BUFFER_NUMBER; // ??????????????????????????????
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;// ?????????????????????
    req.memory = V4L2_MEMORY_MMAP;//????????????(memorymapping)??????
    if(ioctl(fd, VIDIOC_REQBUFS, &req) < 0) //???????????????count??????????????????
    {

        fprintf(stderr, "request capture buffer failed\n");
        return false;
    }

    if (int(req.count) != CAPTURE_BUFFER_NUMBER) {

        fprintf(stderr, "capture buffer number is wrong\n");
        return false;
    }


    for (unsigned int i = 0; i < req.count; i++) {
        struct v4l2_buffer buf; //??????????????????
        CLEAR (buf);
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;//buffer??????
        buf.memory = V4L2_MEMORY_MMAP;//IO?????????????????????
        buf.index = i;//??????
        //????????????????????????VIDIOC_REQBUFS?????????????????????????????????????????????
        if (ioctl(fd, VIDIOC_QUERYBUF, &buf) < 0)
            errno_exit("VIDIOC_QUERYBUF");
        buffers[i].length = buf.length;
        //??????mmap??????????????????
        buffers[i].start = mmap(NULL /* start anywhere */, buf.length,
                                        PROT_READ | PROT_WRITE /* required */,
                                        MAP_SHARED /* recommended */, fd, buf.m.offset);
        if (MAP_FAILED == buffers[i].start)
            return false;
    }
    return true;
}

bool Camera::init_device(void) {

    v4l2_input input;
    memset(&input, 0, sizeof(struct v4l2_input));
    input.index = 0;
    if (ioctl(fd, VIDIOC_ENUMINPUT, &input) != 0) {

        fprintf(stderr, "No matching index found\n");
        return false;
    }
    if (!input.name) {

        fprintf(stderr, "No matching index found\n");
        return false;
    }
    if (ioctl(fd, VIDIOC_S_INPUT, &input) < 0) {

        fprintf(stderr, "VIDIOC_S_INPUT failed\n");
        return false;
    }


    struct v4l2_fmtdesc fmt1; //v4l2_fmtdesc : ??????????????????
    int ret;
    memset(&fmt1, 0, sizeof(fmt1));//???fmt1??????????????????0
    fmt1.index = 0;            //????????????0???????????????????????????
    fmt1.type = V4L2_BUF_TYPE_VIDEO_CAPTURE; // ?????????????????????????????????V4L2_BUF_TYPE_VIDEO_CAPTURE
    while ((ret = ioctl(fd, VIDIOC_ENUM_FMT, &fmt1)) == 0) //???????????????????????????
    {
        fmt1.index++;
        printf("{ pixelformat = '%c%c%c%c', description = '%s' }\n",fmt1.pixelformat & 0xFF,
        (fmt1.pixelformat >> 8) & 0xFF,(fmt1.pixelformat >> 16) & 0xFF,
        (fmt1.pixelformat >> 24) & 0xFF,fmt1.description); //  pixelformat;??????32???   description[32];// ????????????8???
    }

     /**************************?????????????????????************************/
    struct v4l2_format fmt; //???????????????????????????(v4l2_format??????v4l2_fmtdesc  fmt????????????)
    CLEAR (fmt);
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;//???????????????
    fmt.fmt.pix.width = width;
    fmt.fmt.pix.height = height;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;//V4L2_PIX_FMT_NV12;//????????????????????????
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
    if (-1 == xioctl(fd, VIDIOC_S_FMT, &fmt))//??????????????????
        return false;
     /**************************?????????????????????*************************/
    if (-1 == xioctl(fd, VIDIOC_G_FMT, &fmt))
    {
        return false;
    }
    else
    printf("\nCurrent data format information:\n twidth:%d \n theight:%d \n",
                                     fmt.fmt.pix.width,fmt.fmt.pix.height);
     printf(" pixelformat = '%c%c%c%c'\n",fmt.fmt.pix.pixelformat & 0xFF,
    (fmt.fmt.pix.pixelformat >> 8) & 0xFF,(fmt.fmt.pix.pixelformat >> 16) & 0xFF,
    (fmt.fmt.pix.pixelformat >> 24) & 0xFF); //  pixelformat;??????32???

    //????????????????????????????????????
    cap_image_size = fmt.fmt.pix.sizeimage;
    init_mmap();

    return true;
}

void Camera::close_device(void) {
    if (-1 == close(fd))
        errno_exit("close");
    fd = -1;
}
bool Camera::open_device(void) {
    struct stat st;
    if (-1 == stat(dev_name, &st)) //???????????????filename?????????????????????????????????buf??????????????????st???
    {
        fprintf(stderr, "Cannot identify '%s': %d, %s\n", dev_name, errno,
                strerror(errno));
        return false;
    }
    if (!S_ISCHR(st.st_mode)) {
        fprintf(stderr, "%s is no device\n", dev_name);
        return false;
    }
    fd = ::open(dev_name, O_RDWR | O_NONBLOCK);
    if (-1 == fd) {
        fprintf(stderr, "Cannot open '%s': %d, %s\n", dev_name, errno,
                strerror(errno));
        return false;
    }
    return true;
}

bool Camera::OpenDevice(){
    if (open_device()) {
        printf("Open video success\n");
        if (init_device())
        {
            if (start_capturing())
                return true;
        }
    } else
        printf("open video failed\n");
    return false;
}

bool Camera::GetBuffer(unsigned char *image){

    read_frame(image);

    return true;
}

