/*
 * @Author: your name
 * @Date: 2021-04-06 22:02:32
 * @LastEditTime: 2021-04-06 23:23:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /UVC/Camera.h
 */
#ifndef CAMERA_H
#define CAMERA_H

#include <sys/types.h>

#define CLEAR(x) memset (&(x), 0, sizeof (x))
#define CAPTURE_BUFFER_NUMBER	1
typedef enum {
    IO_METHOD_READ, IO_METHOD_MMAP, IO_METHOD_USERPTR,
} io_method;

class Camera
{
public:
    Camera(char *DEV_NAME,int w,int h);//构造函数
    ~Camera();
    bool OpenDevice();//打开设备
    void CloseDevice();//关闭设备
    bool GetBuffer(unsigned char *image);//得到一幅图像
    int GetWidth(){return width;}
    int GetHeight(){return height;}
    unsigned int getImageSize();   //图像大小
    int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);
private:
    char *dev_name;
    io_method io;
    int fd;
    bool  sign3;
    FILE * yuv_fd;                      //将捕捉的图像保存为文件
    int width;
    int height;
    struct { void * start; int length; } buffers[CAPTURE_BUFFER_NUMBER];
    struct buffer
    {
            void *                  start;
            size_t                  length;
    };

    unsigned int cap_image_size ;

    bool init_device(void);
    bool init_mmap(void);
    void uninit_device(void);
    bool start_capturing(void);//开始捕捉
    void stop_capturing(void);//停止捕捉
    void mainloop(unsigned char *image);
    int read_frame(unsigned char *image);//读取一帧
    void close_device(void);
    bool open_device(void);
    bool process_image(unsigned char *image,const void * p);
    int convert_yuv_to_rgb_pixel( int y, int u, int v);

    void errno_exit(const char * s);
    int xioctl(int fd, int request, void * arg);
};

#endif // CAMERA_H
