/********************************************************************************
** Form generated from reading UI file 'daorujichu.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAORUJICHU_H
#define UI_DAORUJICHU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_daorujichu
{
public:

    void setupUi(QDialog *daorujichu)
    {
        if (daorujichu->objectName().isEmpty())
            daorujichu->setObjectName(QStringLiteral("daorujichu"));
        daorujichu->resize(400, 300);

        retranslateUi(daorujichu);

        QMetaObject::connectSlotsByName(daorujichu);
    } // setupUi

    void retranslateUi(QDialog *daorujichu)
    {
        daorujichu->setWindowTitle(QApplication::translate("daorujichu", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class daorujichu: public Ui_daorujichu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAORUJICHU_H
