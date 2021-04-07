#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "DigiClock.h"
#include "CameraWin.h"
#include "Picture.h"
#include "IoCon.h"
#include <QMouseEvent>
namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private:
    Ui::Menu *ui;
    DigiClock *clock;
    CameraWin* camerawin;
    Picture* picture;
    IoCon *iocon;
    void page_change();
public slots:
    void on_camera_bt_clicked();
    void Reshow();
    bool eventFilter(QObject *watch, QEvent *evn);
private slots:
    void on_picture_bt_clicked();
    void on_net_bt_clicked();
    void on_contol_bt_clicked();
    void on_file_bt_clicked();
};

#endif // MENU_H
