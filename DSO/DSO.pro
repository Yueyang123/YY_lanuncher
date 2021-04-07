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
    Service/Camera.cpp

HEADERS  += UI/Menu.h \
    UI/DigiClock.h \
    UI/CameraWin.h \
    Service/Camera.h

FORMS    += \
    UI/Menu.ui \
    UI/CameraWin.ui

RESOURCES += \
    UI/Res/Res.qrc
