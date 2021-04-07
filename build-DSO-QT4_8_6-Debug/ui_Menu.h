/********************************************************************************
** Form generated from reading UI file 'Menu.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *file_bt;
    QPushButton *contol_bt;
    QPushButton *camera_bt;
    QPushButton *adc_bt;
    QPushButton *picture_bt;
    QPushButton *net_bt;
    QWidget *page_2;
    QPushButton *view_bt;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(480, 272);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Menu->sizePolicy().hasHeightForWidth());
        Menu->setSizePolicy(sizePolicy);
        stackedWidget = new QStackedWidget(Menu);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 40, 461, 211));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayoutWidget = new QWidget(page);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 421, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setHorizontalSpacing(40);
        gridLayout->setVerticalSpacing(20);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        file_bt = new QPushButton(gridLayoutWidget);
        file_bt->setObjectName(QString::fromUtf8("file_bt"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(80);
        sizePolicy1.setVerticalStretch(100);
        sizePolicy1.setHeightForWidth(file_bt->sizePolicy().hasHeightForWidth());
        file_bt->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(file_bt, 1, 0, 1, 1);

        contol_bt = new QPushButton(gridLayoutWidget);
        contol_bt->setObjectName(QString::fromUtf8("contol_bt"));
        sizePolicy1.setHeightForWidth(contol_bt->sizePolicy().hasHeightForWidth());
        contol_bt->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(contol_bt, 0, 2, 1, 1);

        camera_bt = new QPushButton(gridLayoutWidget);
        camera_bt->setObjectName(QString::fromUtf8("camera_bt"));
        sizePolicy1.setHeightForWidth(camera_bt->sizePolicy().hasHeightForWidth());
        camera_bt->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(camera_bt, 0, 0, 1, 1);

        adc_bt = new QPushButton(gridLayoutWidget);
        adc_bt->setObjectName(QString::fromUtf8("adc_bt"));
        sizePolicy1.setHeightForWidth(adc_bt->sizePolicy().hasHeightForWidth());
        adc_bt->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(adc_bt, 0, 1, 1, 1);

        picture_bt = new QPushButton(gridLayoutWidget);
        picture_bt->setObjectName(QString::fromUtf8("picture_bt"));
        sizePolicy1.setHeightForWidth(picture_bt->sizePolicy().hasHeightForWidth());
        picture_bt->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(picture_bt, 1, 1, 1, 1);

        net_bt = new QPushButton(gridLayoutWidget);
        net_bt->setObjectName(QString::fromUtf8("net_bt"));
        sizePolicy1.setHeightForWidth(net_bt->sizePolicy().hasHeightForWidth());
        net_bt->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(net_bt, 1, 2, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        view_bt = new QPushButton(page_2);
        view_bt->setObjectName(QString::fromUtf8("view_bt"));
        view_bt->setGeometry(QRect(30, 30, 113, 75));
        sizePolicy1.setHeightForWidth(view_bt->sizePolicy().hasHeightForWidth());
        view_bt->setSizePolicy(sizePolicy1);
        stackedWidget->addWidget(page_2);

        retranslateUi(Menu);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Form", 0, QApplication::UnicodeUTF8));
        file_bt->setText(QApplication::translate("Menu", "FILE", 0, QApplication::UnicodeUTF8));
        contol_bt->setText(QApplication::translate("Menu", "GPIO", 0, QApplication::UnicodeUTF8));
        camera_bt->setText(QApplication::translate("Menu", "Camera", 0, QApplication::UnicodeUTF8));
        adc_bt->setText(QApplication::translate("Menu", "ADC", 0, QApplication::UnicodeUTF8));
        picture_bt->setText(QApplication::translate("Menu", "PICTURE", 0, QApplication::UnicodeUTF8));
        net_bt->setText(QApplication::translate("Menu", "NET", 0, QApplication::UnicodeUTF8));
        view_bt->setText(QApplication::translate("Menu", "View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
