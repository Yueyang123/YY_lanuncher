#-------------------------------------------------
#
# Project created by QtCreator 2021-04-04T22:16:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DSO
TEMPLATE = app


SOURCES += main.cpp\
        UI/Menu.cpp \
    UI/DigiClock.cpp \
    UI/CameraWin.cpp \
    Service/Camera.cpp \
    UI/Picture.cpp \
    UI/IoCon.cpp

HEADERS  += UI/Menu.h \
    UI/DigiClock.h \
    UI/CameraWin.h \
    Service/Camera.h \
    UI/Picture.h \
    UI/IoCon.h

FORMS    += \
    UI/Menu.ui \
    UI/CameraWin.ui \
    UI/Picture.ui \
    UI/IoCon.ui

RESOURCES += \
    UI/Res/Res.qrc
