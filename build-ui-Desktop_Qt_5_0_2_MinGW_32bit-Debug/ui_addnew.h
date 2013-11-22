/********************************************************************************
** Form generated from reading UI file 'addnew.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEW_H
#define UI_ADDNEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_addnew
{
public:

    void setupUi(QDialog *addnew)
    {
        if (addnew->objectName().isEmpty())
            addnew->setObjectName(QStringLiteral("addnew"));
        addnew->resize(480, 640);

        retranslateUi(addnew);

        QMetaObject::connectSlotsByName(addnew);
    } // setupUi

    void retranslateUi(QDialog *addnew)
    {
        addnew->setWindowTitle(QApplication::translate("addnew", "\346\217\220\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class addnew: public Ui_addnew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEW_H
