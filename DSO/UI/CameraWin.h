#ifndef CAMERAWIN_H
#define CAMERAWIN_H

#include <QWidget>
#include "Service/Camera.h"
#include <QThread>
#include <QSemaphore>
#include <QImage>
#include <QQueue>
#include <QImage>
#include <QLabel>
#include <QTimer>
#include <QList>
namespace Ui {
class CameraWin;
}

class CameraWin : public QWidget
{
    Q_OBJECT

public:
    explicit CameraWin(QWidget *parent = 0);
    ~CameraWin();
    Camera* camera;

private:
    Ui::CameraWin *ui;
    typedef enum {OFF,ON}Camerastatus;
    Camerastatus status;
    unsigned char* rgbbuf;
    unsigned char* image;
    QList<QString> dev_name_list;
    QTimer *timer;
    void GrabWidgetScreen();
    int trave_dir(char* path);

signals:
    void camera_quit();
    void start();
private slots:
    void on_start_Bt_clicked();
    void on_quit_Bt_clicked();
    void on_save_Bt_clicked();
    void display();

    void on_comboBox_currentIndexChanged(const QString &arg1);
};

#endif // CAMERAWIN_H
