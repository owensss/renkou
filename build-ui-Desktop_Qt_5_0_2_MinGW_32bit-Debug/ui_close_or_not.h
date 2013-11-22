/********************************************************************************
** Form generated from reading UI file 'close_or_not.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOSE_OR_NOT_H
#define UI_CLOSE_OR_NOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_close_or_not
{
public:
    QPushButton *yes;
    QPushButton *no;
    QLabel *label;

    void setupUi(QDialog *close_or_not)
    {
        if (close_or_not->objectName().isEmpty())
            close_or_not->setObjectName(QStringLiteral("close_or_not"));
        close_or_not->resize(353, 171);
        yes = new QPushButton(close_or_not);
        yes->setObjectName(QStringLiteral("yes"));
        yes->setGeometry(QRect(60, 120, 75, 23));
        no = new QPushButton(close_or_not);
        no->setObjectName(QStringLiteral("no"));
        no->setGeometry(QRect(230, 120, 75, 23));
        label = new QLabel(close_or_not);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 281, 81));

        retranslateUi(close_or_not);

        QMetaObject::connectSlotsByName(close_or_not);
    } // setupUi

    void retranslateUi(QDialog *close_or_not)
    {
        close_or_not->setWindowTitle(QApplication::translate("close_or_not", "\346\217\220\347\244\272", 0));
        yes->setText(QApplication::translate("close_or_not", "\346\230\257", 0));
        no->setText(QApplication::translate("close_or_not", "\345\220\246", 0));
        label->setText(QApplication::translate("close_or_not", "\346\226\260\345\273\272\351\241\271\347\233\256\351\234\200\350\246\201\345\205\263\351\227\255\345\267\262\346\211\223\345\274\200\347\232\204\351\241\271\347\233\256\357\274\214\346\230\257\345\220\246\345\205\263\351\227\255\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class close_or_not: public Ui_close_or_not {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOSE_OR_NOT_H
