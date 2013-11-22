/********************************************************************************
** Form generated from reading UI file 'openproject.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENPROJECT_H
#define UI_OPENPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_openproject
{
public:
    QPushButton *browse;
    QPushButton *complete;
    QLineEdit *sourcefilename;
    QPushButton *pushButton;

    void setupUi(QDialog *openproject)
    {
        if (openproject->objectName().isEmpty())
            openproject->setObjectName(QStringLiteral("openproject"));
        openproject->resize(339, 116);
        browse = new QPushButton(openproject);
        browse->setObjectName(QStringLiteral("browse"));
        browse->setGeometry(QRect(240, 30, 75, 23));
        complete = new QPushButton(openproject);
        complete->setObjectName(QStringLiteral("complete"));
        complete->setEnabled(false);
        complete->setGeometry(QRect(150, 70, 75, 23));
        sourcefilename = new QLineEdit(openproject);
        sourcefilename->setObjectName(QStringLiteral("sourcefilename"));
        sourcefilename->setGeometry(QRect(10, 30, 221, 20));
        pushButton = new QPushButton(openproject);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 70, 75, 23));

        retranslateUi(openproject);

        QMetaObject::connectSlotsByName(openproject);
    } // setupUi

    void retranslateUi(QDialog *openproject)
    {
        openproject->setWindowTitle(QApplication::translate("openproject", "\346\211\223\345\274\200\351\241\271\347\233\256", 0));
        browse->setText(QApplication::translate("openproject", "\346\265\217\350\247\210", 0));
        complete->setText(QApplication::translate("openproject", "\345\256\214\346\210\220", 0));
        pushButton->setText(QApplication::translate("openproject", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class openproject: public Ui_openproject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENPROJECT_H
