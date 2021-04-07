#include "IoCon.h"
#include "ui_IoCon.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include <sys/ioctl.h>
#include <stropts.h>


IoCon::IoCon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IoCon)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    trave_dir("/dev");
    for(int i=0;i<dev_name_list.size();i++)
    ui->comboBox->addItem(QString(dev_name_list.at(i)));
}
int IoCon::trave_dir(char* path)
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
        if(file->d_name[0]=='g'&&file->d_name[1]=='p'){
            dev_name_list.append(QString(file->d_name));
        }
    }
    closedir(d);
    return 0;
}

IoCon::~IoCon()
{
    delete ui;
}

void IoCon::on_pushButton_clicked()
{

    current_fd = open((QString("/dev/").toStdString()+ui->comboBox->currentText().toStdString()).data(), O_RDWR);
    if (current_fd < 0) {
        return;
    }
}

void IoCon::on_pushButton_2_clicked()
{
    long data;
    ioctl(current_fd, GET_GPIO_VALUE, (long)(&data));
    if(data){
        ioctl(current_fd, SET_GPIO_LOW);
        ui->label->setText("STATUS:LOW");
    }
    else {
        ioctl(current_fd, SET_GPIO_HIGHT);
        ui->label->setText("STATUS:HIGH");
    }
}

void IoCon::on_pushButton_3_clicked()
{
    emit io_quit();
}

void IoCon::on_pushButton_4_clicked()
{
    led_fd = open("/dev/imx28x_led", O_RDWR);
    if (led_fd < 0) {
        perror("open /dev/imx28x_led");
    }
}

void IoCon::on_pushButton_5_clicked()
{
    char buf[1] = {0};

    if(led_status==FALSE){
    buf[0] = 0;
    write(led_fd, buf, 1);
    led_status=TRUE;
    ui->label_2->setText("STATUS:ON");
    }else
    {
        buf[0] = 1;
        write(led_fd, buf, 1);
        led_status=FALSE;
        ui->label_2->setText("STATUS:OFF");
    }
}
