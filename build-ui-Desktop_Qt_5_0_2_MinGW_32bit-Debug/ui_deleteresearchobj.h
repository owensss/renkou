/********************************************************************************
** Form generated from reading UI file 'deleteresearchobj.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETERESEARCHOBJ_H
#define UI_DELETERESEARCHOBJ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DeleteResearchObj
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QDialog *DeleteResearchObj)
    {
        if (DeleteResearchObj->objectName().isEmpty())
            DeleteResearchObj->setObjectName(QStringLiteral("DeleteResearchObj"));
        DeleteResearchObj->resize(358, 135);
        pushButton = new QPushButton(DeleteResearchObj);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 80, 151, 31));
        pushButton_2 = new QPushButton(DeleteResearchObj);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 80, 141, 31));
        label = new QLabel(DeleteResearchObj);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 30, 141, 16));

        retranslateUi(DeleteResearchObj);

        QMetaObject::connectSlotsByName(DeleteResearchObj);
    } // setupUi

    void retranslateUi(QDialog *DeleteResearchObj)
    {
        DeleteResearchObj->setWindowTitle(QApplication::translate("DeleteResearchObj", "\345\210\240\351\231\244\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        pushButton->setText(QApplication::translate("DeleteResearchObj", "\345\217\252\345\210\240\351\231\244\346\234\254\351\241\271\347\233\256\347\232\204\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        pushButton_2->setText(QApplication::translate("DeleteResearchObj", "\345\275\273\345\272\225\345\210\240\351\231\244\350\257\245\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        label->setText(QApplication::translate("DeleteResearchObj", "\346\230\257\345\220\246\345\275\273\345\272\225\345\210\240\351\231\244\347\240\224\347\251\266\345\257\271\350\261\241\357\274\237", 0));
    } // retranslateUi

};

namespace Ui {
    class DeleteResearchObj: public Ui_DeleteResearchObj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETERESEARCHOBJ_H
