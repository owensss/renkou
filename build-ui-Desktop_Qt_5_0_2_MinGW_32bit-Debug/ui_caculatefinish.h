/********************************************************************************
** Form generated from reading UI file 'caculatefinish.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CACULATEFINISH_H
#define UI_CACULATEFINISH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_caculatefinish
{
public:
    QLabel *label;

    void setupUi(QDialog *caculatefinish)
    {
        if (caculatefinish->objectName().isEmpty())
            caculatefinish->setObjectName(QStringLiteral("caculatefinish"));
        caculatefinish->resize(279, 79);
        label = new QLabel(caculatefinish);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 30, 151, 16));

        retranslateUi(caculatefinish);

        QMetaObject::connectSlotsByName(caculatefinish);
    } // setupUi

    void retranslateUi(QDialog *caculatefinish)
    {
        caculatefinish->setWindowTitle(QApplication::translate("caculatefinish", "Dialog", 0));
        label->setText(QApplication::translate("caculatefinish", "\350\256\241\347\256\227\345\256\214\346\210\220\357\274\201\345\267\262\345\255\230\344\272\216\351\241\271\347\233\256\345\206\205\343\200\202", 0));
    } // retranslateUi

};

namespace Ui {
    class caculatefinish: public Ui_caculatefinish {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CACULATEFINISH_H
