#include "Menu.h"
#include "ui_Menu.h"
#include <QString>
#include <QDebug>
#include <unistd.h>
#include <sys/types.h>
Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    this->setWindowFlags(Qt::FramelessWindowHint);
    clock=new DigiClock(QPoint(this->width()-80,0), this);
    clock->show();
    this->installEventFilter(this);
}



Menu::~Menu()
{
    delete ui;
    delete clock;
}

void Menu::Reshow()
{
    this->show();
}

void Menu::on_camera_bt_clicked()
{
    camerawin = new CameraWin();//新建子界面
    connect(camerawin,SIGNAL(camera_quit()),this,SLOT(Reshow()));//当点击子界面时，调用主界面的reshow()函数
    camerawin->show();//子界面出现
    this->hide();//主界面关闭
}

bool Menu::eventFilter(QObject *watch, QEvent *evn)
{
    static int press_x;  //鼠标按下时的位置
    static int press_y;
    static int relea_x;  //鼠标释放时的位置
    static int relea_y;
    QMouseEvent *event = static_cast<QMouseEvent *>(evn); //将之转换为鼠标事件
    if(event->type()==QEvent::MouseButtonPress)  //如果鼠标按下
    {
        press_x = event->globalX();
        press_y = event->globalY();
    }
    if(event->type()==QEvent::MouseButtonRelease)  //如果鼠标释放
    {
         relea_x = event->globalX();
         relea_y = event->globalY();
    }
    //判断滑动方向（右滑）
    if((relea_x - press_x)>20 && event->type()==QEvent::MouseButtonRelease && qAbs(relea_y-press_y)<50)
    {
        page_change();
    }
    //判断滑动方向（左滑）
    if((press_x - relea_x)>20 && event->type()==QEvent::MouseButtonRelease && qAbs(relea_y-press_y)<50)
    {
        page_change();
    }
    return QWidget::eventFilter(watch,evn);
}
void Menu::page_change()
{
    int nCount = ui->stackedWidget->count();
    int nIndex = ui->stackedWidget->currentIndex();

    // 获取下一个需要显示的页面索引
    ++nIndex;
    // 当需要显示的页面索引大于等于总页面时，切换至首页
    if (nIndex >= nCount)
        nIndex = 0;
    ui->stackedWidget->setCurrentIndex(nIndex);
}


void Menu::on_picture_bt_clicked()
{

}

void Menu::on_net_bt_clicked()
{
    pid_t pid;
    pid=fork();
    if(pid==0)
    {
        execl("./Camera","Camera");
    }

}
