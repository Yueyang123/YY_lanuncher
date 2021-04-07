/********************************************************************************
** Form generated from reading UI file 'KeyBoardWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDWIDGET_H
#define UI_KEYBOARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyBoardWidget
{
public:

    void setupUi(QWidget *KeyBoardWidget)
    {
        if (KeyBoardWidget->objectName().isEmpty())
            KeyBoardWidget->setObjectName(QStringLiteral("KeyBoardWidget"));
        KeyBoardWidget->resize(400, 300);

        retranslateUi(KeyBoardWidget);

        QMetaObject::connectSlotsByName(KeyBoardWidget);
    } // setupUi

    void retranslateUi(QWidget *KeyBoardWidget)
    {
        KeyBoardWidget->setWindowTitle(QApplication::translate("KeyBoardWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class KeyBoardWidget: public Ui_KeyBoardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDWIDGET_H
