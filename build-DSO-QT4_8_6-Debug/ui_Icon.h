/********************************************************************************
** Form generated from reading UI file 'Icon.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICON_H
#define UI_ICON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Icon
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;

    void setupUi(QWidget *Icon)
    {
        if (Icon->objectName().isEmpty())
            Icon->setObjectName(QString::fromUtf8("Icon"));
        Icon->resize(80, 100);
        graphicsView = new QGraphicsView(Icon);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 80, 80, 20));
        pushButton = new QPushButton(Icon);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 80, 80));

        retranslateUi(Icon);

        QMetaObject::connectSlotsByName(Icon);
    } // setupUi

    void retranslateUi(QWidget *Icon)
    {
        Icon->setWindowTitle(QApplication::translate("Icon", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Icon", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Icon: public Ui_Icon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICON_H
