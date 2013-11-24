/********************************************************************************
** Form generated from reading UI file 'openProject.ui'
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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_OpenProject
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *leProjectPath;
    QPushButton *selectPath;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *open;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *OpenProject)
    {
        if (OpenProject->objectName().isEmpty())
            OpenProject->setObjectName(QStringLiteral("OpenProject"));
        OpenProject->resize(400, 99);
        gridLayout_2 = new QGridLayout(OpenProject);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        leProjectPath = new QLineEdit(OpenProject);
        leProjectPath->setObjectName(QStringLiteral("leProjectPath"));
        leProjectPath->setEnabled(true);
        leProjectPath->setReadOnly(true);

        gridLayout->addWidget(leProjectPath, 0, 0, 1, 1);

        selectPath = new QPushButton(OpenProject);
        selectPath->setObjectName(QStringLiteral("selectPath"));
        selectPath->setEnabled(true);

        gridLayout->addWidget(selectPath, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        open = new QPushButton(OpenProject);
        open->setObjectName(QStringLiteral("open"));
        open->setEnabled(false);

        horizontalLayout->addWidget(open);

        cancel = new QPushButton(OpenProject);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(OpenProject);

        QMetaObject::connectSlotsByName(OpenProject);
    } // setupUi

    void retranslateUi(QDialog *OpenProject)
    {
        OpenProject->setWindowTitle(QApplication::translate("OpenProject", "\346\211\223\345\274\200\351\241\271\347\233\256", 0));
        leProjectPath->setText(QApplication::translate("OpenProject", "D:/Demographic/\351\241\271\347\233\256/", 0));
        selectPath->setText(QApplication::translate("OpenProject", "\351\200\211\346\213\251...", 0));
        open->setText(QApplication::translate("OpenProject", "\346\211\223\345\274\200", 0));
        cancel->setText(QApplication::translate("OpenProject", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenProject: public Ui_OpenProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENPROJECT_H
