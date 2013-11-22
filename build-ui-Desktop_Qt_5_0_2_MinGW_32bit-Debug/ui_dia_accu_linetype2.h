/********************************************************************************
** Form generated from reading UI file 'dia_accu_linetype2.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIA_ACCU_LINETYPE2_H
#define UI_DIA_ACCU_LINETYPE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dia_Accu_LineType2
{
public:
    QLineEdit *Y_Data;
    QPushButton *CancelButton;
    QLabel *label;
    QPushButton *OkButton;
    QLabel *label_2;
    QLineEdit *X_Data;

    void setupUi(QDialog *Dia_Accu_LineType2)
    {
        if (Dia_Accu_LineType2->objectName().isEmpty())
            Dia_Accu_LineType2->setObjectName(QStringLiteral("Dia_Accu_LineType2"));
        Dia_Accu_LineType2->resize(240, 287);
        Y_Data = new QLineEdit(Dia_Accu_LineType2);
        Y_Data->setObjectName(QStringLiteral("Y_Data"));
        Y_Data->setGeometry(QRect(60, 160, 113, 20));
        CancelButton = new QPushButton(Dia_Accu_LineType2);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setGeometry(QRect(150, 220, 75, 23));
        label = new QLabel(Dia_Accu_LineType2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 201, 16));
        OkButton = new QPushButton(Dia_Accu_LineType2);
        OkButton->setObjectName(QStringLiteral("OkButton"));
        OkButton->setGeometry(QRect(10, 220, 75, 23));
        label_2 = new QLabel(Dia_Accu_LineType2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 130, 54, 12));
        X_Data = new QLineEdit(Dia_Accu_LineType2);
        X_Data->setObjectName(QStringLiteral("X_Data"));
        X_Data->setGeometry(QRect(60, 70, 113, 20));

        retranslateUi(Dia_Accu_LineType2);
        QObject::connect(OkButton, SIGNAL(clicked()), Dia_Accu_LineType2, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dia_Accu_LineType2);
    } // setupUi

    void retranslateUi(QDialog *Dia_Accu_LineType2)
    {
        Dia_Accu_LineType2->setWindowTitle(QApplication::translate("Dia_Accu_LineType2", "Dialog", 0));
        CancelButton->setText(QApplication::translate("Dia_Accu_LineType2", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("Dia_Accu_LineType2", "X\350\275\264\346\225\260\346\215\256(\345\234\250Y\350\275\264\345\267\246\344\276\247\344\270\272\350\264\237\357\274\214\345\217\263\344\276\247\344\270\272\346\255\243)", 0));
        OkButton->setText(QApplication::translate("Dia_Accu_LineType2", "\347\241\256\345\256\232", 0));
        label_2->setText(QApplication::translate("Dia_Accu_LineType2", "Y\350\275\264\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class Dia_Accu_LineType2: public Ui_Dia_Accu_LineType2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIA_ACCU_LINETYPE2_H
