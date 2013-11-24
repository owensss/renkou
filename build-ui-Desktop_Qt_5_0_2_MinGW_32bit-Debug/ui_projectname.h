/********************************************************************************
** Form generated from reading UI file 'projectname.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTNAME_H
#define UI_PROJECTNAME_H

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

class Ui_projectname
{
public:
    QLabel *label;
    QLineEdit *projectname_2;
    QLabel *label_2;
    QLineEdit *projectroute;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *projectname)
    {
        if (projectname->objectName().isEmpty())
            projectname->setObjectName(QStringLiteral("projectname"));
        projectname->resize(400, 178);
        label = new QLabel(projectname);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 61, 16));
        projectname_2 = new QLineEdit(projectname);
        projectname_2->setObjectName(QStringLiteral("projectname_2"));
        projectname_2->setGeometry(QRect(80, 40, 201, 20));
        label_2 = new QLabel(projectname);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 71, 16));
        projectroute = new QLineEdit(projectname);
        projectroute->setObjectName(QStringLiteral("projectroute"));
        projectroute->setEnabled(false);
        projectroute->setGeometry(QRect(80, 80, 201, 20));
        ok = new QPushButton(projectname);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setEnabled(false);
        ok->setGeometry(QRect(220, 130, 75, 23));
        cancel = new QPushButton(projectname);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(310, 130, 75, 23));

        retranslateUi(projectname);

        QMetaObject::connectSlotsByName(projectname);
    } // setupUi

    void retranslateUi(QDialog *projectname)
    {
        projectname->setWindowTitle(QApplication::translate("projectname", "Dialog", 0));
        label->setText(QApplication::translate("projectname", "\351\241\271\347\233\256\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("projectname", "\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", 0));
        projectroute->setText(QApplication::translate("projectname", "D:/Demographic/\351\241\271\347\233\256/", 0));
        ok->setText(QApplication::translate("projectname", "\347\241\256\345\256\232", 0));
        cancel->setText(QApplication::translate("projectname", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class projectname: public Ui_projectname {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTNAME_H
