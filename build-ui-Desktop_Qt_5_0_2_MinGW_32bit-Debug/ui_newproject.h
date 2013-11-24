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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_NewProject
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *leProjectName;
    QLabel *lbSavePath;
    QLabel *lbProjectName;
    QLineEdit *leSavePath;
    QPushButton *selectPath;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *NewProject)
    {
        if (NewProject->objectName().isEmpty())
            NewProject->setObjectName(QStringLiteral("NewProject"));
        NewProject->resize(419, 170);
        gridLayout = new QGridLayout(NewProject);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        leProjectName = new QLineEdit(NewProject);
        leProjectName->setObjectName(QStringLiteral("leProjectName"));

        gridLayout_2->addWidget(leProjectName, 0, 1, 1, 1);

        lbSavePath = new QLabel(NewProject);
        lbSavePath->setObjectName(QStringLiteral("lbSavePath"));
        lbSavePath->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lbSavePath, 1, 0, 1, 1);

        lbProjectName = new QLabel(NewProject);
        lbProjectName->setObjectName(QStringLiteral("lbProjectName"));

        gridLayout_2->addWidget(lbProjectName, 0, 0, 1, 1);

        leSavePath = new QLineEdit(NewProject);
        leSavePath->setObjectName(QStringLiteral("leSavePath"));
        leSavePath->setEnabled(true);
        leSavePath->setReadOnly(true);

        gridLayout_2->addWidget(leSavePath, 1, 1, 1, 1);

        selectPath = new QPushButton(NewProject);
        selectPath->setObjectName(QStringLiteral("selectPath"));
        selectPath->setEnabled(true);
        selectPath->setAutoDefault(false);
        selectPath->setDefault(false);

        gridLayout_2->addWidget(selectPath, 1, 2, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ok = new QPushButton(NewProject);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setEnabled(false);
        ok->setAutoDefault(false);
        ok->setDefault(false);

        horizontalLayout->addWidget(ok);

        cancel = new QPushButton(NewProject);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setAutoDefault(false);
        cancel->setDefault(false);
        cancel->setFlat(false);

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        QWidget::setTabOrder(leProjectName, leSavePath);
        QWidget::setTabOrder(leSavePath, selectPath);
        QWidget::setTabOrder(selectPath, ok);
        QWidget::setTabOrder(ok, cancel);

        retranslateUi(NewProject);

        QMetaObject::connectSlotsByName(NewProject);
    } // setupUi

    void retranslateUi(QDialog *NewProject)
    {
        NewProject->setWindowTitle(QApplication::translate("NewProject", "\346\226\260\345\273\272\351\241\271\347\233\256", 0));
        lbSavePath->setText(QApplication::translate("NewProject", "\344\277\235\345\255\230\350\267\257\345\276\204\357\274\232", 0));
        lbProjectName->setText(QApplication::translate("NewProject", "\346\226\260\345\273\272\351\241\271\347\233\256\357\274\232", 0));
        leSavePath->setText(QApplication::translate("NewProject", "D:/Demographic/\351\241\271\347\233\256/", 0));
        selectPath->setText(QApplication::translate("NewProject", "\351\200\211\346\213\251...", 0));
        ok->setText(QApplication::translate("NewProject", "\347\241\256\345\256\232", 0));
        cancel->setText(QApplication::translate("NewProject", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class NewProject: public Ui_NewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECT_H
