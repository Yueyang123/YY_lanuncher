#ifndef IOCON_H
#define IOCON_H

#include <QWidget>
#include <QList>
#include <QString>
namespace Ui {
class IoCon;
}

class IoCon : public QWidget
{
    Q_OBJECT

public:
    explicit IoCon(QWidget *parent = 0);
    ~IoCon();
    int trave_dir(char* path);

signals:
    void io_quit();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    QList<QString> dev_name_list;
    int current_fd;
    int led_fd;
    bool led_status;
    Ui::IoCon *ui;
    enum {
        SET_GPIO_HIGHT = 9,
        SET_GPIO_LOW,
        GET_GPIO_VALUE,
    };

};

#endif // IOCON_H
