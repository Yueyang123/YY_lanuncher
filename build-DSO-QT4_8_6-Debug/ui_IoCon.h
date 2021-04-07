/********************************************************************************
** Form generated from reading UI file 'IoCon.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IOCON_H
#define UI_IOCON_H

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

class Ui_IoCon
{
public:
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QPushButton *pushButton_5;

    void setupUi(QWidget *IoCon)
    {
        if (IoCon->objectName().isEmpty())
            IoCon->setObjectName(QString::fromUtf8("IoCon"));
        IoCon->resize(480, 272);
        pushButton = new QPushButton(IoCon);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 10, 99, 27));
        comboBox = new QComboBox(IoCon);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 10, 131, 31));
        label = new QLabel(IoCon);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 91, 16));
        pushButton_2 = new QPushButton(IoCon);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 40, 99, 27));
        pushButton_3 = new QPushButton(IoCon);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 200, 99, 27));
        pushButton_4 = new QPushButton(IoCon);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(340, 70, 99, 27));
        label_2 = new QLabel(IoCon);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 90, 67, 17));
        pushButton_5 = new QPushButton(IoCon);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(340, 100, 99, 27));

        retranslateUi(IoCon);

        QMetaObject::connectSlotsByName(IoCon);
    } // setupUi

    void retranslateUi(QWidget *IoCon)
    {
        IoCon->setWindowTitle(QApplication::translate("IoCon", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("IoCon", "I/O", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("IoCon", "STATUS:", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("IoCon", "TOGGLE", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("IoCon", "QUIT", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("IoCon", "OPEN LED", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("IoCon", "STATUS:", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("IoCon", "TOGGLE LED", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class IoCon: public Ui_IoCon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IOCON_H
