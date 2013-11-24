/********************************************************************************
** Form generated from reading UI file 'entercalculate.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERCALCULATE_H
#define UI_ENTERCALCULATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_EnterCalculate
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *calculate;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *EnterCalculate)
    {
        if (EnterCalculate->objectName().isEmpty())
            EnterCalculate->setObjectName(QStringLiteral("EnterCalculate"));
        EnterCalculate->resize(280, 282);
        gridLayout = new QGridLayout(EnterCalculate);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(EnterCalculate);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        textBrowser = new QTextBrowser(EnterCalculate);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout->addWidget(textBrowser, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        calculate = new QPushButton(EnterCalculate);
        calculate->setObjectName(QStringLiteral("calculate"));

        horizontalLayout->addWidget(calculate);

        cancel = new QPushButton(EnterCalculate);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(EnterCalculate);

        QMetaObject::connectSlotsByName(EnterCalculate);
    } // setupUi

    void retranslateUi(QDialog *EnterCalculate)
    {
        EnterCalculate->setWindowTitle(QApplication::translate("EnterCalculate", "\350\277\233\345\205\245\350\256\241\347\256\227", 0));
        label->setText(QApplication::translate("EnterCalculate", "\345\275\223\345\211\215\351\200\211\346\213\251\347\232\204\347\273\204\345\220\210\357\274\232", 0));
        textBrowser->setHtml(QApplication::translate("EnterCalculate", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.Lucida Grande UI'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\345\234\260\345\214\272</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">:</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\345\205\250\345\233\275\357\274\233\345\214\227\344\272\254\357\274\233\344\270\212\346\265\267</span><span style=\" font-family:'Times New Roman'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-rig"
                        "ht:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\346\226\271\346\241\210\357\274\232\344\270\200\346\255\245\350\265\260</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">/2011;</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\346\224\277\347\255\226\345\256\236\347\216\260\347\250\213\345\272\246\344\274\260\350\256\241\346\263\225</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">: </span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\346\224\277\347\255\226\347\224\237\350\202\262</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">; </span><span style"
                        "=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\346\204\217\346\204\277\347\224\237\350\202\262</span><span style=\" font-family:'Times New Roman'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\347\273\223\345\251\232\347\216\207\346\234\211\345\201\266\347\216\207\344\274\260\350\256\241\346\263\225</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">: </span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\345\205\250\345\221\230\345\251\232\351\205\215\346\234\211\345\201\266</span><span style=\" font-family:'Times New Roman'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span sty"
                        "le=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\350\277\201\347\247\273\345\274\272\345\272\246</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">: </span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\346\227\240\350\277\201\347\247\273</span><span style=\" font-family:'Times New Roman'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\350\260\203\346\225\264\345\257\271\350\261\241\346\210\267\347\261\215\357\274\232\345\206\234\344\270\232</span><span style=\" font-family:'Times New Roman'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344"
                        "\275\223'; font-size:10pt; color:#000000;\">\345\251\232\351\205\215\346\246\202\347\216\207\344\274\260\350\256\241\346\263\225\357\274\232\345\220\214\351\276\204\346\246\202\347\216\207</span><span style=\" font-family:'Times New Roman'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\345\240\206\347\247\257\351\207\212\346\224\276\346\250\241\345\274\217\357\274\232\346\204\217\346\204\277\346\250\241\345\274\217\357\274\233\347\274\223\351\207\212\346\250\241\345\274\217</span><span style=\" font-family:'Times New Roman'; font-size:10pt; color:#000000;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\345\237\272\346\234\254"
                        "\345\217\202\346\225\260\357\274\232\346\255\273\344\272\241\346\246\202\347\216\207</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">/</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\346\250\241\345\236\213</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">1/</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\346\250\241\345\236\213</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">2</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:10pt; color:#000000;\">\357\274\233</span><span style=\" font-family:'Calibri'; font-size:10pt; color:#000000;\">\342\200\246</span><span style=\" font-family:'Arial'; font-size:9pt; color:#000000;\"> </span></p></body></html>", 0));
        calculate->setText(QApplication::translate("EnterCalculate", "\350\256\241\347\256\227", 0));
        cancel->setText(QApplication::translate("EnterCalculate", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class EnterCalculate: public Ui_EnterCalculate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERCALCULATE_H
