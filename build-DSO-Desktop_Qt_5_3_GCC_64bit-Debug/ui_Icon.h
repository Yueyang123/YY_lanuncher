/********************************************************************************
** Form generated from reading UI file 'Icon.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ICON_H
#define UI_ICON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Icon
{
public:
    QGraphicsView *graphicsView;
    QPushButton *pushButton;

    void setupUi(QWidget *Icon)
    {
        if (Icon->objectName().isEmpty())
            Icon->setObjectName(QStringLiteral("Icon"));
        Icon->resize(80, 100);
        graphicsView = new QGraphicsView(Icon);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 80, 80, 20));
        pushButton = new QPushButton(Icon);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 0, 80, 80));

        retranslateUi(Icon);

        QMetaObject::connectSlotsByName(Icon);
    } // setupUi

    void retranslateUi(QWidget *Icon)
    {
        Icon->setWindowTitle(QApplication::translate("Icon", "Form", 0));
        pushButton->setText(QApplication::translate("Icon", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Icon: public Ui_Icon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ICON_H
