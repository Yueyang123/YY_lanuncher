/********************************************************************************
** Form generated from reading UI file 'KeyBoardWidget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDWIDGET_H
#define UI_KEYBOARDWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyBoardWidget
{
public:

    void setupUi(QWidget *KeyBoardWidget)
    {
        if (KeyBoardWidget->objectName().isEmpty())
            KeyBoardWidget->setObjectName(QString::fromUtf8("KeyBoardWidget"));
        KeyBoardWidget->resize(400, 300);

        retranslateUi(KeyBoardWidget);

        QMetaObject::connectSlotsByName(KeyBoardWidget);
    } // setupUi

    void retranslateUi(QWidget *KeyBoardWidget)
    {
        KeyBoardWidget->setWindowTitle(QApplication::translate("KeyBoardWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KeyBoardWidget: public Ui_KeyBoardWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDWIDGET_H
