/********************************************************************************
** Form generated from reading UI file 'importBasicData.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTBASICDATA_H
#define UI_IMPORTBASICDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImportBasicData
{
public:
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLineEdit *info;
    QLabel *label_cc;
    QLabel *labelbb;
    QComboBox *PiCiname;
    QComboBox *objectname;
    QLabel *label_aa;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QComboBox *sourcefilename_7;
    QComboBox *sourcefilename_9;
    QLabel *label_9;
    QComboBox *sourcefilename_8;
    QLabel *label_8;
    QLabel *label_5;
    QPushButton *browse_8;
    QPushButton *browse_4;
    QComboBox *sourcefilename_2;
    QComboBox *sourcefilename_5;
    QComboBox *sourcefilename_4;
    QComboBox *sourcefilename_6;
    QPushButton *browse_9;
    QLabel *label_6;
    QPushButton *browse_2;
    QPushButton *browse_3;
    QPushButton *browse_1;
    QComboBox *sourcefilename_1;
    QPushButton *browse_6;
    QPushButton *browse_5;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *sourcefilename_3;
    QLabel *label_1;
    QLabel *label_2;
    QPushButton *browse_7;
    QLabel *label_7;
    QLabel *label_10;
    QComboBox *sourcefilename_10;
    QPushButton *browse_10;
    QLabel *zhu;
    QHBoxLayout *horizontalLayout;
    QPushButton *importData;
    QPushButton *cancel;

    void setupUi(QDialog *ImportBasicData)
    {
        if (ImportBasicData->objectName().isEmpty())
            ImportBasicData->setObjectName(QStringLiteral("ImportBasicData"));
        ImportBasicData->resize(481, 548);
        gridLayout_3 = new QGridLayout(ImportBasicData);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        info = new QLineEdit(ImportBasicData);
        info->setObjectName(QStringLiteral("info"));

        gridLayout_2->addWidget(info, 2, 1, 1, 1);

        label_cc = new QLabel(ImportBasicData);
        label_cc->setObjectName(QStringLiteral("label_cc"));

        gridLayout_2->addWidget(label_cc, 2, 0, 1, 1);

        labelbb = new QLabel(ImportBasicData);
        labelbb->setObjectName(QStringLiteral("labelbb"));

        gridLayout_2->addWidget(labelbb, 1, 0, 1, 1);

        PiCiname = new QComboBox(ImportBasicData);
        PiCiname->setObjectName(QStringLiteral("PiCiname"));
        PiCiname->setEditable(true);

        gridLayout_2->addWidget(PiCiname, 1, 1, 1, 1);

        objectname = new QComboBox(ImportBasicData);
        objectname->setObjectName(QStringLiteral("objectname"));
        objectname->setEditable(false);

        gridLayout_2->addWidget(objectname, 0, 1, 1, 1);

        label_aa = new QLabel(ImportBasicData);
        label_aa->setObjectName(QStringLiteral("label_aa"));

        gridLayout_2->addWidget(label_aa, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sourcefilename_7 = new QComboBox(ImportBasicData);
        sourcefilename_7->setObjectName(QStringLiteral("sourcefilename_7"));
        sourcefilename_7->setEditable(true);

        gridLayout->addWidget(sourcefilename_7, 6, 1, 1, 1);

        sourcefilename_9 = new QComboBox(ImportBasicData);
        sourcefilename_9->setObjectName(QStringLiteral("sourcefilename_9"));
        sourcefilename_9->setEditable(true);

        gridLayout->addWidget(sourcefilename_9, 8, 1, 1, 1);

        label_9 = new QLabel(ImportBasicData);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        sourcefilename_8 = new QComboBox(ImportBasicData);
        sourcefilename_8->setObjectName(QStringLiteral("sourcefilename_8"));
        sourcefilename_8->setEditable(true);

        gridLayout->addWidget(sourcefilename_8, 7, 1, 1, 1);

        label_8 = new QLabel(ImportBasicData);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label_5 = new QLabel(ImportBasicData);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        browse_8 = new QPushButton(ImportBasicData);
        browse_8->setObjectName(QStringLiteral("browse_8"));

        gridLayout->addWidget(browse_8, 7, 2, 1, 1);

        browse_4 = new QPushButton(ImportBasicData);
        browse_4->setObjectName(QStringLiteral("browse_4"));

        gridLayout->addWidget(browse_4, 3, 2, 1, 1);

        sourcefilename_2 = new QComboBox(ImportBasicData);
        sourcefilename_2->setObjectName(QStringLiteral("sourcefilename_2"));
        sourcefilename_2->setEditable(true);

        gridLayout->addWidget(sourcefilename_2, 1, 1, 1, 1);

        sourcefilename_5 = new QComboBox(ImportBasicData);
        sourcefilename_5->setObjectName(QStringLiteral("sourcefilename_5"));
        sourcefilename_5->setEditable(true);

        gridLayout->addWidget(sourcefilename_5, 4, 1, 1, 1);

        sourcefilename_4 = new QComboBox(ImportBasicData);
        sourcefilename_4->setObjectName(QStringLiteral("sourcefilename_4"));
        sourcefilename_4->setEditable(true);

        gridLayout->addWidget(sourcefilename_4, 3, 1, 1, 1);

        sourcefilename_6 = new QComboBox(ImportBasicData);
        sourcefilename_6->setObjectName(QStringLiteral("sourcefilename_6"));
        sourcefilename_6->setEditable(true);

        gridLayout->addWidget(sourcefilename_6, 5, 1, 1, 1);

        browse_9 = new QPushButton(ImportBasicData);
        browse_9->setObjectName(QStringLiteral("browse_9"));

        gridLayout->addWidget(browse_9, 8, 2, 1, 1);

        label_6 = new QLabel(ImportBasicData);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        browse_2 = new QPushButton(ImportBasicData);
        browse_2->setObjectName(QStringLiteral("browse_2"));

        gridLayout->addWidget(browse_2, 1, 2, 1, 1);

        browse_3 = new QPushButton(ImportBasicData);
        browse_3->setObjectName(QStringLiteral("browse_3"));

        gridLayout->addWidget(browse_3, 2, 2, 1, 1);

        browse_1 = new QPushButton(ImportBasicData);
        browse_1->setObjectName(QStringLiteral("browse_1"));

        gridLayout->addWidget(browse_1, 0, 2, 1, 1);

        sourcefilename_1 = new QComboBox(ImportBasicData);
        sourcefilename_1->setObjectName(QStringLiteral("sourcefilename_1"));
        sourcefilename_1->setEditable(true);

        gridLayout->addWidget(sourcefilename_1, 0, 1, 1, 1);

        browse_6 = new QPushButton(ImportBasicData);
        browse_6->setObjectName(QStringLiteral("browse_6"));

        gridLayout->addWidget(browse_6, 5, 2, 1, 1);

        browse_5 = new QPushButton(ImportBasicData);
        browse_5->setObjectName(QStringLiteral("browse_5"));

        gridLayout->addWidget(browse_5, 4, 2, 1, 1);

        label_3 = new QLabel(ImportBasicData);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(ImportBasicData);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        sourcefilename_3 = new QComboBox(ImportBasicData);
        sourcefilename_3->setObjectName(QStringLiteral("sourcefilename_3"));
        sourcefilename_3->setEditable(true);

        gridLayout->addWidget(sourcefilename_3, 2, 1, 1, 1);

        label_1 = new QLabel(ImportBasicData);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_1, 0, 0, 1, 1);

        label_2 = new QLabel(ImportBasicData);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        browse_7 = new QPushButton(ImportBasicData);
        browse_7->setObjectName(QStringLiteral("browse_7"));

        gridLayout->addWidget(browse_7, 6, 2, 1, 1);

        label_7 = new QLabel(ImportBasicData);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_10 = new QLabel(ImportBasicData);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        sourcefilename_10 = new QComboBox(ImportBasicData);
        sourcefilename_10->setObjectName(QStringLiteral("sourcefilename_10"));
        sourcefilename_10->setEditable(true);

        gridLayout->addWidget(sourcefilename_10, 9, 1, 1, 1);

        browse_10 = new QPushButton(ImportBasicData);
        browse_10->setObjectName(QStringLiteral("browse_10"));

        gridLayout->addWidget(browse_10, 9, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 2);

        zhu = new QLabel(ImportBasicData);
        zhu->setObjectName(QStringLiteral("zhu"));

        gridLayout_3->addWidget(zhu, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        importData = new QPushButton(ImportBasicData);
        importData->setObjectName(QStringLiteral("importData"));
        importData->setAutoDefault(false);

        horizontalLayout->addWidget(importData);

        cancel = new QPushButton(ImportBasicData);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setAutoDefault(false);

        horizontalLayout->addWidget(cancel);


        gridLayout_3->addLayout(horizontalLayout, 3, 1, 1, 1);


        retranslateUi(ImportBasicData);

        QMetaObject::connectSlotsByName(ImportBasicData);
    } // setupUi

    void retranslateUi(QDialog *ImportBasicData)
    {
        ImportBasicData->setWindowTitle(QApplication::translate("ImportBasicData", "\345\257\274\345\205\245\345\237\272\347\241\200\346\225\260\346\215\256", 0));
        info->setText(QApplication::translate("ImportBasicData", "\346\227\240", 0));
        label_cc->setText(QApplication::translate("ImportBasicData", "\345\244\207\346\263\250\357\274\232", 0));
        labelbb->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256\351\233\206\345\220\215\347\247\260\357\274\232", 0));
        label_aa->setText(QApplication::translate("ImportBasicData", "\351\234\200\350\246\201\345\257\274\345\205\245\346\225\260\346\215\256\347\232\204\347\240\224\347\251\266\345\257\271\350\261\241\357\274\232", 0));
        label_9->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\205\250\345\233\275\344\272\272\345\217\243\345\271\264\351\276\204\347\273\223\346\236\204\345\222\214\346\212\232\345\205\273\346\257\224", 0));
        label_8->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\205\250\345\233\275\344\272\272\345\217\243\345\207\272\347\224\237\347\216\207\346\255\273\344\272\241\347\216\207\345\222\214\350\207\252\347\204\266\345\242\236\351\225\277\347\216\207", 0));
        label_5->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\220\204\345\234\260\345\214\272\344\272\272\345\217\243\345\237\216\344\271\241\346\236\204\346\210\220", 0));
        browse_8->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        browse_4->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        browse_9->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        label_6->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\220\204\345\234\260\345\214\272\344\272\272\345\217\243\345\233\233\347\216\207", 0));
        browse_2->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        browse_3->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        browse_1->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        browse_6->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        browse_5->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        label_3->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\210\206\345\271\264\351\276\204\344\272\272\345\217\243", 0));
        label_4->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\210\206\345\271\264\351\276\204\346\200\247\345\210\253\344\272\272\345\217\243", 0));
        label_1->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\255\220\345\245\263", 0));
        label_2->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\344\272\272\345\217\243\346\246\202\350\246\201", 0));
        browse_7->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        label_7->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\205\250\345\233\275\344\272\272\345\217\243\345\237\216\344\271\241\346\236\204\346\210\220", 0));
        label_10->setText(QApplication::translate("ImportBasicData", "\345\237\272\347\241\200\346\225\260\346\215\256_\345\220\204\345\234\260\345\214\272\346\210\267\346\225\260\344\272\272\345\217\243\346\225\260\346\200\247\345\210\253\346\257\224\345\222\214\346\210\267\350\247\204\346\250\241", 0));
        browse_10->setText(QApplication::translate("ImportBasicData", "\346\265\217\350\247\210", 0));
        zhu->setText(QApplication::translate("ImportBasicData", "\346\263\250\357\274\232\344\270\213\346\213\211\345\217\257\351\200\211\346\213\251\345\267\262\345\257\274\345\205\245\346\225\260\346\215\256\351\233\206\347\232\204\350\241\250\346\240\274", 0));
        importData->setText(QApplication::translate("ImportBasicData", "\345\257\274\345\205\245", 0));
        cancel->setText(QApplication::translate("ImportBasicData", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ImportBasicData: public Ui_ImportBasicData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTBASICDATA_H
