#ifndef DIGICLOCK_H
#define DIGICLOCK_H
#include <QLCDNumber>

class DigiClock:public QLCDNumber
{
    Q_OBJECT
public:
    DigiClock(QWidget* parent=0);
    DigiClock(QPoint point,QWidget* parent=0);
public slots:
    void showtime();
private :
    QPoint dragPosition;
    bool showColon;

};

#endif // DIGICLOCK_H
