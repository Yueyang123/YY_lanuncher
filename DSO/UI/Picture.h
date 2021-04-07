#ifndef PICTURE_H
#define PICTURE_H

#include <QWidget>

namespace Ui {
class Picture;
}

class Picture : public QWidget
{
    Q_OBJECT

public:
    explicit Picture(QWidget *parent = 0);
    ~Picture();
    void showPicture(QString s);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

signals:
void pic_quit();


private:
    Ui::Picture *ui;
};

#endif // PICTURE_H
