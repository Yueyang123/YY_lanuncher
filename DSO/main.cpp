#include "UI/Menu.h"
#include <QApplication>
Camera *camera;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();
    return a.exec();
}
