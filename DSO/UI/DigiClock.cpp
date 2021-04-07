#include "DigiClock.h"
#include <QTime>
#include <QTimer>

DigiClock::DigiClock(QWidget* parent):QLCDNumber(parent)
{
    this->setSegmentStyle(QLCDNumber::Flat);
    this->setStyleSheet("border:2pxsolidgreen;color:blue;background:white;");

    setWindowFlags(Qt::FramelessWindowHint);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start(1000);
    showtime();
    resize(80,30);
    this->dragPosition=QPoint(0,0);
    showColon=true;
}

DigiClock::DigiClock(QPoint point,QWidget* parent):QLCDNumber(parent)
{
    new(this) DigiClock(parent);
    this->dragPosition=QPoint(point);
    this->move(dragPosition);
}
void DigiClock::showtime(){
    QTime time=QTime::currentTime();
    QString text=time.toString("hh:mm");
    if(showColon){
        text[2]=':';
        showColon=false;\
    }else{
        text[2]=' ';
        showColon=true;
    }
    display(text);
}
