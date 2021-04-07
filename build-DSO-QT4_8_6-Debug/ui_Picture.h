/********************************************************************************
** Form generated from reading UI file 'Picture.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURE_H
#define UI_PICTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Picture
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Picture)
    {
        if (Picture->objectName().isEmpty())
            Picture->setObjectName(QString::fromUtf8("Picture"));
        Picture->resize(480, 272);
        label = new QLabel(Picture);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 441, 221));
        pushButton = new QPushButton(Picture);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 99, 27));
        pushButton_2 = new QPushButton(Picture);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 10, 99, 27));

        retranslateUi(Picture);

        QMetaObject::connectSlotsByName(Picture);
    } // setupUi

    void retranslateUi(QWidget *Picture)
    {
        Picture->setWindowTitle(QApplication::translate("Picture", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QApplication::translate("Picture", "CHOOSE", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Picture", "QUIT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Picture: public Ui_Picture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURE_H
