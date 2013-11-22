/********************************************************************************
** Form generated from reading UI file 'newproject.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECT_H
#define UI_NEWPROJECT_H

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

class Ui_newProject
{
public:
    QLabel *label;
    QLineEdit *projectroute;
    QLabel *label_2;
    QPushButton *ok;
    QLineEdit *projectname;
    QPushButton *cancel;

    void setupUi(QDialog *newProject)
    {
        if (newProject->objectName().isEmpty())
            newProject->setObjectName(QStringLiteral("newProject"));
        newProject->resize(419, 170);
        label = new QLabel(newProject);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 61, 16));
        projectroute = new QLineEdit(newProject);
        projectroute->setObjectName(QStringLiteral("projectroute"));
        projectroute->setEnabled(false);
        projectroute->setGeometry(QRect(100, 80, 201, 20));
        label_2 = new QLabel(newProject);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 71, 16));
        ok = new QPushButton(newProject);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setEnabled(false);
        ok->setGeometry(QRect(240, 130, 75, 23));
        projectname = new QLineEdit(newProject);
        projectname->setObjectName(QStringLiteral("projectname"));
        projectname->setGeometry(QRect(100, 40, 201, 20));
        cancel = new QPushButton(newProject);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(330, 130, 75, 23));

        retranslateUi(newProject);

        QMetaObject::connectSlotsByName(newProject);
    } // setupUi

    void retranslateUi(QDialog *newProject)
    {
        newProject->setWindowTitle(QApplication::translate("newProject", "\346\226\260\345\273\272\351\241\271\347\233\256", 0));
        label->setText(QApplication::translate("newProject", "\351\241\271\347\233\256\345\220\215\357\274\232", 0));
        projectroute->setText(QApplication::translate("newProject", "D:/Demographic/\351\241\271\347\233\256/", 0));
        label_2->setText(QApplication::translate("newProject", "\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", 0));
        ok->setText(QApplication::translate("newProject", "\347\241\256\345\256\232", 0));
        cancel->setText(QApplication::translate("newProject", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class newProject: public Ui_newProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECT_H
