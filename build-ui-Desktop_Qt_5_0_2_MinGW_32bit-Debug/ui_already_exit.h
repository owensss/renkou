/********************************************************************************
** Form generated from reading UI file 'already_exit.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALREADY_EXIT_H
#define UI_ALREADY_EXIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_already_exit
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *already_exit)
    {
        if (already_exit->objectName().isEmpty())
            already_exit->setObjectName(QStringLiteral("already_exit"));
        already_exit->resize(400, 217);
        label = new QLabel(already_exit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 40, 231, 91));
        pushButton = new QPushButton(already_exit);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 140, 75, 23));
        pushButton_2 = new QPushButton(already_exit);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 140, 75, 23));

        retranslateUi(already_exit);

        QMetaObject::connectSlotsByName(already_exit);
    } // setupUi

    void retranslateUi(QDialog *already_exit)
    {
        already_exit->setWindowTitle(QApplication::translate("already_exit", "\346\217\220\347\244\272", 0));
        label->setText(QApplication::translate("already_exit", "\350\257\245\347\240\224\347\251\266\345\257\271\350\261\241\345\267\262\345\255\230\345\234\250\357\274\214\346\230\257\345\220\246\346\233\264\346\226\260\357\274\237", 0));
        pushButton->setText(QApplication::translate("already_exit", "\346\230\257", 0));
        pushButton_2->setText(QApplication::translate("already_exit", "\345\220\246", 0));
    } // retranslateUi

};

namespace Ui {
    class already_exit: public Ui_already_exit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALREADY_EXIT_H
