#include "Picture.h"
#include "ui_Picture.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
Picture::Picture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Picture)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Picture::~Picture()
{
    delete ui;
}

void Picture::on_pushButton_2_clicked()
{
    emit pic_quit();
}

void Picture::showPicture(QString ss)
{
    QImage* img=new QImage;

    if(! ( img->load(ss) ) ) //加载图像
    {
        QMessageBox::information(this,
                                tr("打开图像失败"),
                                tr("打开图像失败!"));
       delete img;
       return;
     }
     ui->label->setPixmap(QPixmap::fromImage(*img));
}

void Picture::on_pushButton_clicked()
{
    QFileDialog* fd = new QFileDialog(this);//创建对话框
    fd->setDirectory("/usr/picture");
    fd->resize(480,250);    //设置显示的大小
    fd->setFilter("PIC(*png *jpg *bmp *gif)"); //设置文件过滤器
    if ( fd->exec() == QDialog::Accepted )   //如果成功的执行
    {
    QStringList fileName0 = fd->selectedFiles();      //返回文件列表的名称
    QString fileName = fileName0[0];            //取第一个文件名
    qDebug()<<fileName;
    showPicture(fileName);
    }
    else
    fd->close();
}
