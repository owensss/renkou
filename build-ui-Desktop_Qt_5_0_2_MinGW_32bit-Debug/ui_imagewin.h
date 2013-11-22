/********************************************************************************
** Form generated from reading UI file 'imagewin.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEWIN_H
#define UI_IMAGEWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ImageWin
{
public:

    void setupUi(QDialog *ImageWin)
    {
        if (ImageWin->objectName().isEmpty())
            ImageWin->setObjectName(QStringLiteral("ImageWin"));
        ImageWin->resize(400, 300);

        retranslateUi(ImageWin);

        QMetaObject::connectSlotsByName(ImageWin);
    } // setupUi

    void retranslateUi(QDialog *ImageWin)
    {
        ImageWin->setWindowTitle(QApplication::translate("ImageWin", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageWin: public Ui_ImageWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEWIN_H
