/********************************************************************************
** Form generated from reading UI file 'daorujichuornot.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAORUJICHUORNOT_H
#define UI_DAORUJICHUORNOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_daorujichuornot
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *daorujichuornot)
    {
        if (daorujichuornot->objectName().isEmpty())
            daorujichuornot->setObjectName(QStringLiteral("daorujichuornot"));
        daorujichuornot->resize(400, 137);
        pushButton = new QPushButton(daorujichuornot);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 90, 75, 23));
        pushButton_2 = new QPushButton(daorujichuornot);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 90, 75, 23));
        label = new QLabel(daorujichuornot);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 40, 111, 31));

        retranslateUi(daorujichuornot);

        QMetaObject::connectSlotsByName(daorujichuornot);
    } // setupUi

    void retranslateUi(QDialog *daorujichuornot)
    {
        daorujichuornot->setWindowTitle(QApplication::translate("daorujichuornot", "Dialog", 0));
        pushButton->setText(QApplication::translate("daorujichuornot", "\346\230\257", 0));
        pushButton_2->setText(QApplication::translate("daorujichuornot", "\345\220\246", 0));
        label->setText(QApplication::translate("daorujichuornot", "\346\230\257\345\220\246\345\257\274\345\205\245\345\237\272\347\241\200\346\225\260\346\215\256\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class daorujichuornot: public Ui_daorujichuornot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAORUJICHUORNOT_H
