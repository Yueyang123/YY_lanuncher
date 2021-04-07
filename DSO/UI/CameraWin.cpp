#include "CameraWin.h"
#include "ui_CameraWin.h"
#include "stdio.h"
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QApplication>
#include <QDesktopWidget>
#include <iostream>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#define WIDTH   640
#define HEIGHT  480



CameraWin::CameraWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraWin)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    image=new unsigned char[WIDTH*HEIGHT*2];
    rgbbuf=new unsigned char [WIDTH*HEIGHT*3];
    timer =new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(display()));
    trave_dir("/dev");
    for(int i=0;i<dev_name_list.size();i++)
    ui->comboBox->addItem(QString(dev_name_list.at(i)));
}




CameraWin::~CameraWin()
{
    delete ui;
}

void CameraWin::on_quit_Bt_clicked()
{
    emit camera_quit();
}

void CameraWin::display()
{
    if(camera->GetBuffer(image)&&status==ON){
          camera->convert_yuv_to_rgb_buffer(image,rgbbuf,WIDTH,HEIGHT);
          QImage img(rgbbuf,WIDTH,HEIGHT,QImage::Format_RGB888);
          QPixmap pixmap = QPixmap::fromImage(img);
          pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio);
          ui->label->setScaledContents(true);
          ui->label->setPixmap(pixmap);
      }
}
void CameraWin::GrabWidgetScreen()

{
    QRect rect = ui->label->geometry();
    QPixmap pix ,bmp;
    pix =bmp.grabWindow(QApplication::desktop()->winId(),0,0,frameGeometry().width(),frameGeometry().height());
    QString filePathName = "widget";
    filePathName += QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss-zzz");
    filePathName += ".bmp";
    if(!pix.save(filePathName,"BMP"))
    {
    }
}
void CameraWin::on_save_Bt_clicked()
{
     GrabWidgetScreen();
}

void CameraWin::on_start_Bt_clicked()
{
    if(status==OFF){
    std::string s="/dev/"+ui->comboBox->currentText().toStdString();
    camera=new Camera((char*)s.data(),WIDTH,HEIGHT);
    if(!camera->OpenDevice())printf("Cam Open error\n");
    status=ON;
    timer->start(100);
    }
}


int CameraWin::trave_dir(char* path)
{
    DIR *d; //声明一个句柄
    struct dirent *file; //readdir函数的返回值就存放在这个结构体中
    if(!(d = opendir(path)))
    {
        printf("error opendir %s!!!\n",path);
        return -1;
    }
    while((file = readdir(d)) != NULL)
    {
        if(strncmp(file->d_name, ".", 1) == 0)
            continue;
        if(file->d_name[0]=='v'&&file->d_name[1]=='i'){
            dev_name_list.append(QString(file->d_name));
        }
    }
    closedir(d);
    return 0;
}



void CameraWin::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(status==ON){
    status=OFF;
    camera->CloseDevice();
    delete camera;
    char* data= (char*)arg1.toStdString().data();
    camera=new Camera(data,WIDTH,HEIGHT);
    if(!camera->OpenDevice())printf("Cam Open error\n");
    status=ON;
    }
}
