/********************************************************************************
** Form generated from reading UI file 'docalculate.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCALCULATE_H
#define UI_DOCALCULATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_docalculate
{
public:
    QProgressBar *progressBar;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *docalculate)
    {
        if (docalculate->objectName().isEmpty())
            docalculate->setObjectName(QStringLiteral("docalculate"));
        docalculate->resize(400, 105);
        progressBar = new QProgressBar(docalculate);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(30, 20, 351, 23));
        progressBar->setValue(24);
        label = new QLabel(docalculate);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 151, 16));
        pushButton = new QPushButton(docalculate);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 70, 75, 23));

        retranslateUi(docalculate);

        QMetaObject::connectSlotsByName(docalculate);
    } // setupUi

    void retranslateUi(QDialog *docalculate)
    {
        docalculate->setWindowTitle(QApplication::translate("docalculate", "\346\255\243\345\234\250\350\256\241\347\256\227", 0));
        label->setText(QApplication::translate("docalculate", "\346\255\243\345\234\250\350\256\241\347\256\227...", 0));
        pushButton->setText(QApplication::translate("docalculate", "\344\270\255\346\226\255", 0));
    } // retranslateUi

};

namespace Ui {
    class docalculate: public Ui_docalculate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCALCULATE_H
