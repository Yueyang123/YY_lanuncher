/********************************************************************************
** Form generated from reading UI file 'CameraWin.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERAWIN_H
#define UI_CAMERAWIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraWin
{
public:
    QPushButton *quit_Bt;
    QLabel *label;
    QPushButton *save_Bt;
    QPushButton *start_Bt;
    QComboBox *comboBox;

    void setupUi(QWidget *CameraWin)
    {
        if (CameraWin->objectName().isEmpty())
            CameraWin->setObjectName(QString::fromUtf8("CameraWin"));
        CameraWin->resize(480, 272);
        quit_Bt = new QPushButton(CameraWin);
        quit_Bt->setObjectName(QString::fromUtf8("quit_Bt"));
        quit_Bt->setGeometry(QRect(410, 10, 61, 31));
        label = new QLabel(CameraWin);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 461, 221));
        save_Bt = new QPushButton(CameraWin);
        save_Bt->setObjectName(QString::fromUtf8("save_Bt"));
        save_Bt->setGeometry(QRect(320, 10, 61, 31));
        start_Bt = new QPushButton(CameraWin);
        start_Bt->setObjectName(QString::fromUtf8("start_Bt"));
        start_Bt->setGeometry(QRect(230, 10, 61, 31));
        comboBox = new QComboBox(CameraWin);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 10, 85, 27));

        retranslateUi(CameraWin);

        QMetaObject::connectSlotsByName(CameraWin);
    } // setupUi

    void retranslateUi(QWidget *CameraWin)
    {
        CameraWin->setWindowTitle(QApplication::translate("CameraWin", "Form", 0, QApplication::UnicodeUTF8));
        quit_Bt->setText(QApplication::translate("CameraWin", "Quit", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CameraWin", "CameraWIn", 0, QApplication::UnicodeUTF8));
        save_Bt->setText(QApplication::translate("CameraWin", "SAVE", 0, QApplication::UnicodeUTF8));
        start_Bt->setText(QApplication::translate("CameraWin", "STATRT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CameraWin: public Ui_CameraWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERAWIN_H
