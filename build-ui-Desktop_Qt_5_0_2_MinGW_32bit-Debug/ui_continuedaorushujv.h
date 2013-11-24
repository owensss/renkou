/********************************************************************************
** Form generated from reading UI file 'continuedaorushujv.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTINUEDAORUSHUJV_H
#define UI_CONTINUEDAORUSHUJV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ContinueDaoruShujv
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ContinueDaoruShujv)
    {
        if (ContinueDaoruShujv->objectName().isEmpty())
            ContinueDaoruShujv->setObjectName(QStringLiteral("ContinueDaoruShujv"));
        ContinueDaoruShujv->resize(228, 115);
        label = new QLabel(ContinueDaoruShujv);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 171, 51));
        pushButton = new QPushButton(ContinueDaoruShujv);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 80, 71, 23));
        pushButton_2 = new QPushButton(ContinueDaoruShujv);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 80, 61, 23));

        retranslateUi(ContinueDaoruShujv);

        QMetaObject::connectSlotsByName(ContinueDaoruShujv);
    } // setupUi

    void retranslateUi(QDialog *ContinueDaoruShujv)
    {
        ContinueDaoruShujv->setWindowTitle(QApplication::translate("ContinueDaoruShujv", "\345\257\274\345\205\245", 0));
        label->setText(QApplication::translate("ContinueDaoruShujv", "\346\225\260\346\215\256\345\257\274\345\205\245\346\210\220\345\212\237!\n"
"\n"
"\346\230\257\345\220\246\347\273\247\347\273\255\344\270\213\344\270\200\346\254\241\345\257\274\345\205\245\346\225\260\346\215\256\346\223\215\344\275\234\357\274\237", 0));
        pushButton->setText(QApplication::translate("ContinueDaoruShujv", "\346\230\257", 0));
        pushButton_2->setText(QApplication::translate("ContinueDaoruShujv", "\345\220\246", 0));
    } // retranslateUi

};

namespace Ui {
    class ContinueDaoruShujv: public Ui_ContinueDaoruShujv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTINUEDAORUSHUJV_H
