/********************************************************************************
** Form generated from reading UI file 'notexit.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEXIT_H
#define UI_NOTEXIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Notexit
{
public:
    QLabel *label;
    QPushButton *yes;
    QPushButton *no;

    void setupUi(QDialog *Notexit)
    {
        if (Notexit->objectName().isEmpty())
            Notexit->setObjectName(QStringLiteral("Notexit"));
        Notexit->resize(400, 300);
        label = new QLabel(Notexit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 60, 221, 81));
        yes = new QPushButton(Notexit);
        yes->setObjectName(QStringLiteral("yes"));
        yes->setGeometry(QRect(50, 180, 75, 23));
        no = new QPushButton(Notexit);
        no->setObjectName(QStringLiteral("no"));
        no->setGeometry(QRect(210, 180, 75, 23));

        retranslateUi(Notexit);

        QMetaObject::connectSlotsByName(Notexit);
    } // setupUi

    void retranslateUi(QDialog *Notexit)
    {
        Notexit->setWindowTitle(QApplication::translate("Notexit", "\346\217\220\347\244\272", 0));
        label->setText(QApplication::translate("Notexit", "\350\257\245\347\240\224\347\251\266\345\257\271\350\261\241\345\260\232\346\234\252\345\273\272\347\253\213\357\274\214\346\230\257\345\220\246\350\246\201\346\226\260\345\273\272\357\274\237", 0));
        yes->setText(QApplication::translate("Notexit", "\346\230\257", 0));
        no->setText(QApplication::translate("Notexit", "\345\220\246", 0));
    } // retranslateUi

};

namespace Ui {
    class Notexit: public Ui_Notexit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEXIT_H
