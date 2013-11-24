/********************************************************************************
** Form generated from reading UI file 'progress_bar.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_BAR_H
#define UI_PROGRESS_BAR_H

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

class Ui_Progress_bar
{
public:
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Progress_bar)
    {
        if (Progress_bar->objectName().isEmpty())
            Progress_bar->setObjectName(QStringLiteral("Progress_bar"));
        Progress_bar->resize(548, 163);
        progressBar = new QProgressBar(Progress_bar);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(20, 90, 421, 23));
        progressBar->setValue(24);
        pushButton = new QPushButton(Progress_bar);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 90, 75, 23));
        label = new QLabel(Progress_bar);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 40, 54, 12));
        label_2 = new QLabel(Progress_bar);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(240, 40, 54, 12));

        retranslateUi(Progress_bar);

        QMetaObject::connectSlotsByName(Progress_bar);
    } // setupUi

    void retranslateUi(QDialog *Progress_bar)
    {
        Progress_bar->setWindowTitle(QApplication::translate("Progress_bar", "Dialog", 0));
        pushButton->setText(QApplication::translate("Progress_bar", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("Progress_bar", "\345\267\262\347\224\250", 0));
        label_2->setText(QApplication::translate("Progress_bar", "\345\211\251\344\275\231", 0));
    } // retranslateUi

};

namespace Ui {
    class Progress_bar: public Ui_Progress_bar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_BAR_H
