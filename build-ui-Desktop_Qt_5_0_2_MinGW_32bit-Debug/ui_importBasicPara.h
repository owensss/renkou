/********************************************************************************
** Form generated from reading UI file 'importBasicPara.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTBASICPARA_H
#define UI_IMPORTBASICPARA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ImportBasicPara
{
public:
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_2;
    QLineEdit *info;
    QComboBox *objectname;
    QLabel *label_6;
    QLabel *labelss;
    QLabel *warn;
    QComboBox *PiCiname;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QLabel *label71;
    QComboBox *sourcefilename_71;
    QPushButton *browse_71;
    QLabel *label72;
    QComboBox *sourcefilename_72;
    QPushButton *browse_72;
    QLabel *label73;
    QComboBox *sourcefilename_73;
    QPushButton *browse_73;
    QGroupBox *yuqishoumin;
    QGridLayout *gridLayout_7;
    QLabel *label11;
    QComboBox *sourcefilename_11;
    QPushButton *browse_11;
    QGroupBox *siwanggailv;
    QGridLayout *gridLayout_4;
    QLabel *label21;
    QComboBox *sourcefilename_21;
    QPushButton *browse_21;
    QLabel *label22;
    QComboBox *sourcefilename_22;
    QPushButton *browse_22;
    QGroupBox *qianyimoshi;
    QGridLayout *gridLayout_3;
    QLabel *label31;
    QComboBox *sourcefilename_31;
    QPushButton *browse_31;
    QLabel *label32;
    QComboBox *sourcefilename_32;
    QPushButton *browse_32;
    QLabel *label33;
    QComboBox *sourcefilename_33;
    QPushButton *browse_33;
    QLabel *label34;
    QComboBox *sourcefilename_34;
    QPushButton *browse_34;
    QLabel *label35;
    QComboBox *sourcefilename_35;
    QPushButton *browse_35;
    QGroupBox *shenyumoshi;
    QGridLayout *gridLayout;
    QLabel *label41;
    QComboBox *sourcefilename_41;
    QPushButton *browse_41;
    QLabel *label42;
    QComboBox *sourcefilename_42;
    QPushButton *browse_42;
    QLabel *label43;
    QComboBox *sourcefilename_43;
    QPushButton *browse_43;
    QLabel *label44;
    QComboBox *sourcefilename_44;
    QPushButton *browse_44;
    QLabel *label45;
    QComboBox *sourcefilename_45;
    QPushButton *browse_45;
    QLabel *label46;
    QComboBox *sourcefilename_46;
    QPushButton *browse_46;
    QGroupBox *zhongshengyiyuan;
    QGridLayout *gridLayout_5;
    QLabel *label51;
    QComboBox *sourcefilename_51;
    QPushButton *browse_51;
    QGroupBox *shengyushuipin;
    QGridLayout *gridLayout_6;
    QLabel *label61;
    QComboBox *sourcefilename_61;
    QPushButton *browse_61;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *daoru;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *ImportBasicPara)
    {
        if (ImportBasicPara->objectName().isEmpty())
            ImportBasicPara->setObjectName(QStringLiteral("ImportBasicPara"));
        ImportBasicPara->resize(951, 617);
        gridLayout_9 = new QGridLayout(ImportBasicPara);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        info = new QLineEdit(ImportBasicPara);
        info->setObjectName(QStringLiteral("info"));

        gridLayout_2->addWidget(info, 2, 2, 1, 1);

        objectname = new QComboBox(ImportBasicPara);
        objectname->setObjectName(QStringLiteral("objectname"));
        objectname->setEditable(false);

        gridLayout_2->addWidget(objectname, 0, 2, 1, 1);

        label_6 = new QLabel(ImportBasicPara);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 1, 1, 1);

        labelss = new QLabel(ImportBasicPara);
        labelss->setObjectName(QStringLiteral("labelss"));

        gridLayout_2->addWidget(labelss, 1, 1, 1, 1);

        warn = new QLabel(ImportBasicPara);
        warn->setObjectName(QStringLiteral("warn"));

        gridLayout_2->addWidget(warn, 3, 1, 1, 2);

        PiCiname = new QComboBox(ImportBasicPara);
        PiCiname->setObjectName(QStringLiteral("PiCiname"));
        PiCiname->setEditable(true);

        gridLayout_2->addWidget(PiCiname, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(115, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        label_5 = new QLabel(ImportBasicPara);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 2, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 3, 1, 1);


        gridLayout_9->addLayout(gridLayout_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(ImportBasicPara);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        label71 = new QLabel(groupBox);
        label71->setObjectName(QStringLiteral("label71"));
        label71->setLayoutDirection(Qt::RightToLeft);

        gridLayout_8->addWidget(label71, 0, 0, 1, 1);

        sourcefilename_71 = new QComboBox(groupBox);
        sourcefilename_71->setObjectName(QStringLiteral("sourcefilename_71"));
        sourcefilename_71->setEditable(true);

        gridLayout_8->addWidget(sourcefilename_71, 0, 1, 1, 1);

        browse_71 = new QPushButton(groupBox);
        browse_71->setObjectName(QStringLiteral("browse_71"));

        gridLayout_8->addWidget(browse_71, 0, 2, 1, 1);

        label72 = new QLabel(groupBox);
        label72->setObjectName(QStringLiteral("label72"));
        label72->setLayoutDirection(Qt::RightToLeft);

        gridLayout_8->addWidget(label72, 1, 0, 1, 1);

        sourcefilename_72 = new QComboBox(groupBox);
        sourcefilename_72->setObjectName(QStringLiteral("sourcefilename_72"));
        sourcefilename_72->setEditable(true);

        gridLayout_8->addWidget(sourcefilename_72, 1, 1, 1, 1);

        browse_72 = new QPushButton(groupBox);
        browse_72->setObjectName(QStringLiteral("browse_72"));

        gridLayout_8->addWidget(browse_72, 1, 2, 1, 1);

        label73 = new QLabel(groupBox);
        label73->setObjectName(QStringLiteral("label73"));
        label73->setLayoutDirection(Qt::RightToLeft);

        gridLayout_8->addWidget(label73, 2, 0, 1, 1);

        sourcefilename_73 = new QComboBox(groupBox);
        sourcefilename_73->setObjectName(QStringLiteral("sourcefilename_73"));
        sourcefilename_73->setEditable(true);

        gridLayout_8->addWidget(sourcefilename_73, 2, 1, 1, 1);

        browse_73 = new QPushButton(groupBox);
        browse_73->setObjectName(QStringLiteral("browse_73"));

        gridLayout_8->addWidget(browse_73, 2, 2, 1, 1);


        gridLayout_9->addWidget(groupBox, 0, 1, 1, 1);

        yuqishoumin = new QGroupBox(ImportBasicPara);
        yuqishoumin->setObjectName(QStringLiteral("yuqishoumin"));
        gridLayout_7 = new QGridLayout(yuqishoumin);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label11 = new QLabel(yuqishoumin);
        label11->setObjectName(QStringLiteral("label11"));
        label11->setLayoutDirection(Qt::RightToLeft);

        gridLayout_7->addWidget(label11, 0, 0, 1, 1);

        sourcefilename_11 = new QComboBox(yuqishoumin);
        sourcefilename_11->setObjectName(QStringLiteral("sourcefilename_11"));
        sourcefilename_11->setEditable(true);

        gridLayout_7->addWidget(sourcefilename_11, 0, 1, 1, 1);

        browse_11 = new QPushButton(yuqishoumin);
        browse_11->setObjectName(QStringLiteral("browse_11"));

        gridLayout_7->addWidget(browse_11, 0, 2, 1, 1);


        gridLayout_9->addWidget(yuqishoumin, 1, 0, 1, 1);

        siwanggailv = new QGroupBox(ImportBasicPara);
        siwanggailv->setObjectName(QStringLiteral("siwanggailv"));
        gridLayout_4 = new QGridLayout(siwanggailv);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label21 = new QLabel(siwanggailv);
        label21->setObjectName(QStringLiteral("label21"));
        label21->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(label21, 0, 0, 1, 1);

        sourcefilename_21 = new QComboBox(siwanggailv);
        sourcefilename_21->setObjectName(QStringLiteral("sourcefilename_21"));
        sourcefilename_21->setEditable(true);

        gridLayout_4->addWidget(sourcefilename_21, 0, 1, 1, 1);

        browse_21 = new QPushButton(siwanggailv);
        browse_21->setObjectName(QStringLiteral("browse_21"));

        gridLayout_4->addWidget(browse_21, 0, 2, 1, 1);

        label22 = new QLabel(siwanggailv);
        label22->setObjectName(QStringLiteral("label22"));
        label22->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(label22, 1, 0, 1, 1);

        sourcefilename_22 = new QComboBox(siwanggailv);
        sourcefilename_22->setObjectName(QStringLiteral("sourcefilename_22"));
        sourcefilename_22->setEditable(true);

        gridLayout_4->addWidget(sourcefilename_22, 1, 1, 1, 1);

        browse_22 = new QPushButton(siwanggailv);
        browse_22->setObjectName(QStringLiteral("browse_22"));

        gridLayout_4->addWidget(browse_22, 1, 2, 1, 1);


        gridLayout_9->addWidget(siwanggailv, 1, 1, 1, 1);

        qianyimoshi = new QGroupBox(ImportBasicPara);
        qianyimoshi->setObjectName(QStringLiteral("qianyimoshi"));
        gridLayout_3 = new QGridLayout(qianyimoshi);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label31 = new QLabel(qianyimoshi);
        label31->setObjectName(QStringLiteral("label31"));
        label31->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(label31, 0, 0, 1, 1);

        sourcefilename_31 = new QComboBox(qianyimoshi);
        sourcefilename_31->setObjectName(QStringLiteral("sourcefilename_31"));
        sourcefilename_31->setEditable(true);

        gridLayout_3->addWidget(sourcefilename_31, 0, 1, 1, 1);

        browse_31 = new QPushButton(qianyimoshi);
        browse_31->setObjectName(QStringLiteral("browse_31"));

        gridLayout_3->addWidget(browse_31, 0, 2, 1, 1);

        label32 = new QLabel(qianyimoshi);
        label32->setObjectName(QStringLiteral("label32"));
        label32->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(label32, 1, 0, 1, 1);

        sourcefilename_32 = new QComboBox(qianyimoshi);
        sourcefilename_32->setObjectName(QStringLiteral("sourcefilename_32"));
        sourcefilename_32->setEditable(true);

        gridLayout_3->addWidget(sourcefilename_32, 1, 1, 1, 1);

        browse_32 = new QPushButton(qianyimoshi);
        browse_32->setObjectName(QStringLiteral("browse_32"));

        gridLayout_3->addWidget(browse_32, 1, 2, 1, 1);

        label33 = new QLabel(qianyimoshi);
        label33->setObjectName(QStringLiteral("label33"));
        label33->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(label33, 2, 0, 1, 1);

        sourcefilename_33 = new QComboBox(qianyimoshi);
        sourcefilename_33->setObjectName(QStringLiteral("sourcefilename_33"));
        sourcefilename_33->setEditable(true);

        gridLayout_3->addWidget(sourcefilename_33, 2, 1, 1, 1);

        browse_33 = new QPushButton(qianyimoshi);
        browse_33->setObjectName(QStringLiteral("browse_33"));

        gridLayout_3->addWidget(browse_33, 2, 2, 1, 1);

        label34 = new QLabel(qianyimoshi);
        label34->setObjectName(QStringLiteral("label34"));
        label34->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(label34, 3, 0, 1, 1);

        sourcefilename_34 = new QComboBox(qianyimoshi);
        sourcefilename_34->setObjectName(QStringLiteral("sourcefilename_34"));
        sourcefilename_34->setEditable(true);

        gridLayout_3->addWidget(sourcefilename_34, 3, 1, 1, 1);

        browse_34 = new QPushButton(qianyimoshi);
        browse_34->setObjectName(QStringLiteral("browse_34"));

        gridLayout_3->addWidget(browse_34, 3, 2, 1, 1);

        label35 = new QLabel(qianyimoshi);
        label35->setObjectName(QStringLiteral("label35"));
        label35->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(label35, 4, 0, 1, 1);

        sourcefilename_35 = new QComboBox(qianyimoshi);
        sourcefilename_35->setObjectName(QStringLiteral("sourcefilename_35"));
        sourcefilename_35->setEditable(true);

        gridLayout_3->addWidget(sourcefilename_35, 4, 1, 1, 1);

        browse_35 = new QPushButton(qianyimoshi);
        browse_35->setObjectName(QStringLiteral("browse_35"));

        gridLayout_3->addWidget(browse_35, 4, 2, 1, 1);


        gridLayout_9->addWidget(qianyimoshi, 2, 0, 1, 1);

        shenyumoshi = new QGroupBox(ImportBasicPara);
        shenyumoshi->setObjectName(QStringLiteral("shenyumoshi"));
        gridLayout = new QGridLayout(shenyumoshi);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label41 = new QLabel(shenyumoshi);
        label41->setObjectName(QStringLiteral("label41"));
        label41->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label41, 0, 0, 1, 1);

        sourcefilename_41 = new QComboBox(shenyumoshi);
        sourcefilename_41->setObjectName(QStringLiteral("sourcefilename_41"));
        sourcefilename_41->setEditable(true);

        gridLayout->addWidget(sourcefilename_41, 0, 1, 1, 1);

        browse_41 = new QPushButton(shenyumoshi);
        browse_41->setObjectName(QStringLiteral("browse_41"));

        gridLayout->addWidget(browse_41, 0, 2, 1, 1);

        label42 = new QLabel(shenyumoshi);
        label42->setObjectName(QStringLiteral("label42"));
        label42->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label42, 1, 0, 1, 1);

        sourcefilename_42 = new QComboBox(shenyumoshi);
        sourcefilename_42->setObjectName(QStringLiteral("sourcefilename_42"));
        sourcefilename_42->setEditable(true);

        gridLayout->addWidget(sourcefilename_42, 1, 1, 1, 1);

        browse_42 = new QPushButton(shenyumoshi);
        browse_42->setObjectName(QStringLiteral("browse_42"));

        gridLayout->addWidget(browse_42, 1, 2, 1, 1);

        label43 = new QLabel(shenyumoshi);
        label43->setObjectName(QStringLiteral("label43"));
        label43->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label43, 2, 0, 1, 1);

        sourcefilename_43 = new QComboBox(shenyumoshi);
        sourcefilename_43->setObjectName(QStringLiteral("sourcefilename_43"));
        sourcefilename_43->setEditable(true);

        gridLayout->addWidget(sourcefilename_43, 2, 1, 1, 1);

        browse_43 = new QPushButton(shenyumoshi);
        browse_43->setObjectName(QStringLiteral("browse_43"));

        gridLayout->addWidget(browse_43, 2, 2, 1, 1);

        label44 = new QLabel(shenyumoshi);
        label44->setObjectName(QStringLiteral("label44"));
        label44->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label44, 3, 0, 1, 1);

        sourcefilename_44 = new QComboBox(shenyumoshi);
        sourcefilename_44->setObjectName(QStringLiteral("sourcefilename_44"));
        sourcefilename_44->setEditable(true);

        gridLayout->addWidget(sourcefilename_44, 3, 1, 1, 1);

        browse_44 = new QPushButton(shenyumoshi);
        browse_44->setObjectName(QStringLiteral("browse_44"));

        gridLayout->addWidget(browse_44, 3, 2, 1, 1);

        label45 = new QLabel(shenyumoshi);
        label45->setObjectName(QStringLiteral("label45"));
        label45->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label45, 4, 0, 1, 1);

        sourcefilename_45 = new QComboBox(shenyumoshi);
        sourcefilename_45->setObjectName(QStringLiteral("sourcefilename_45"));
        sourcefilename_45->setEditable(true);

        gridLayout->addWidget(sourcefilename_45, 4, 1, 1, 1);

        browse_45 = new QPushButton(shenyumoshi);
        browse_45->setObjectName(QStringLiteral("browse_45"));

        gridLayout->addWidget(browse_45, 4, 2, 1, 1);

        label46 = new QLabel(shenyumoshi);
        label46->setObjectName(QStringLiteral("label46"));
        label46->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label46, 5, 0, 1, 1);

        sourcefilename_46 = new QComboBox(shenyumoshi);
        sourcefilename_46->setObjectName(QStringLiteral("sourcefilename_46"));
        sourcefilename_46->setEditable(true);

        gridLayout->addWidget(sourcefilename_46, 5, 1, 1, 1);

        browse_46 = new QPushButton(shenyumoshi);
        browse_46->setObjectName(QStringLiteral("browse_46"));

        gridLayout->addWidget(browse_46, 5, 2, 1, 1);


        gridLayout_9->addWidget(shenyumoshi, 2, 1, 1, 1);

        zhongshengyiyuan = new QGroupBox(ImportBasicPara);
        zhongshengyiyuan->setObjectName(QStringLiteral("zhongshengyiyuan"));
        gridLayout_5 = new QGridLayout(zhongshengyiyuan);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label51 = new QLabel(zhongshengyiyuan);
        label51->setObjectName(QStringLiteral("label51"));
        label51->setLayoutDirection(Qt::RightToLeft);

        gridLayout_5->addWidget(label51, 0, 0, 1, 1);

        sourcefilename_51 = new QComboBox(zhongshengyiyuan);
        sourcefilename_51->setObjectName(QStringLiteral("sourcefilename_51"));
        sourcefilename_51->setEditable(true);

        gridLayout_5->addWidget(sourcefilename_51, 0, 1, 1, 1);

        browse_51 = new QPushButton(zhongshengyiyuan);
        browse_51->setObjectName(QStringLiteral("browse_51"));

        gridLayout_5->addWidget(browse_51, 0, 2, 1, 1);


        gridLayout_9->addWidget(zhongshengyiyuan, 3, 0, 1, 1);

        shengyushuipin = new QGroupBox(ImportBasicPara);
        shengyushuipin->setObjectName(QStringLiteral("shengyushuipin"));
        gridLayout_6 = new QGridLayout(shengyushuipin);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label61 = new QLabel(shengyushuipin);
        label61->setObjectName(QStringLiteral("label61"));
        label61->setLayoutDirection(Qt::RightToLeft);

        gridLayout_6->addWidget(label61, 0, 0, 1, 1);

        sourcefilename_61 = new QComboBox(shengyushuipin);
        sourcefilename_61->setObjectName(QStringLiteral("sourcefilename_61"));
        sourcefilename_61->setEditable(true);

        gridLayout_6->addWidget(sourcefilename_61, 0, 1, 1, 1);

        browse_61 = new QPushButton(shengyushuipin);
        browse_61->setObjectName(QStringLiteral("browse_61"));

        gridLayout_6->addWidget(browse_61, 0, 2, 1, 1);


        gridLayout_9->addWidget(shengyushuipin, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        daoru = new QPushButton(ImportBasicPara);
        daoru->setObjectName(QStringLiteral("daoru"));
        daoru->setAutoDefault(false);

        horizontalLayout->addWidget(daoru);

        cancel = new QPushButton(ImportBasicPara);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setAutoDefault(false);

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout_9->addLayout(horizontalLayout, 4, 1, 1, 1);


        retranslateUi(ImportBasicPara);

        QMetaObject::connectSlotsByName(ImportBasicPara);
    } // setupUi

    void retranslateUi(QDialog *ImportBasicPara)
    {
        ImportBasicPara->setWindowTitle(QApplication::translate("ImportBasicPara", "\345\257\274\345\205\245\345\237\272\346\234\254\345\217\202\346\225\260", 0));
        info->setText(QApplication::translate("ImportBasicPara", "\346\227\240", 0));
        label_6->setText(QApplication::translate("ImportBasicPara", "\351\234\200\350\246\201\345\257\274\345\205\245\346\225\260\346\215\256\347\232\204\347\240\224\347\251\266\345\257\271\350\261\241\357\274\232", 0));
        labelss->setText(QApplication::translate("ImportBasicPara", "\345\237\272\347\241\200\346\225\260\346\215\256\351\233\206\345\220\215\347\247\260\357\274\232", 0));
        warn->setText(QApplication::translate("ImportBasicPara", "\346\263\250\357\274\232\344\270\213\346\213\211\345\217\257\351\200\211\346\213\251\345\267\262\345\257\274\345\205\245\346\225\260\346\215\256\351\233\206\347\232\204\350\241\250\346\240\274", 0));
        label_5->setText(QApplication::translate("ImportBasicPara", "\345\244\207\346\263\250\357\274\232", 0));
        groupBox->setTitle(QApplication::translate("ImportBasicPara", "\345\251\232\345\247\273\346\250\241\345\274\217", 0));
        label71->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\210\206\345\234\260\345\214\272\345\271\263\345\235\207\345\210\235\345\251\232\345\271\264\351\276\204", 0));
        browse_71->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label72->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\205\250\345\233\275\346\214\211\345\246\273\345\255\220\345\271\264\351\276\204\345\210\206\347\232\204\344\270\210\345\244\253\345\271\264\351\276\204\345\210\206\345\270\203\346\250\241\345\274\217", 0));
        browse_72->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label73->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\205\250\345\233\275\346\214\211\344\270\210\345\244\253\345\271\264\351\276\204\345\210\206\347\232\204\345\246\273\345\255\220\345\271\264\351\276\204\345\210\206\345\270\203\346\250\241\345\274\217", 0));
        browse_73->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        yuqishoumin->setTitle(QApplication::translate("ImportBasicPara", "\351\242\204\346\234\237\345\257\277\345\221\275\345\217\202\346\225\260", 0));
        label11->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\237\216\344\271\241\351\242\204\346\234\237\345\257\277\345\221\275\351\242\204\346\265\213", 0));
        browse_11->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        siwanggailv->setTitle(QApplication::translate("ImportBasicPara", "\346\255\273\344\272\241\346\246\202\347\216\207\345\217\202\346\225\260", 0));
        label21->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\346\255\273\344\272\241\346\246\202\347\216\207\351\242\204\346\265\213", 0));
        browse_21->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label22->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\346\255\273\344\272\241\346\246\202\347\216\207\344\277\256\346\255\243\347\263\273\346\225\260", 0));
        browse_22->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        qianyimoshi->setTitle(QApplication::translate("ImportBasicPara", "\350\277\201\347\247\273\346\250\241\345\274\217\345\217\202\346\225\260", 0));
        label31->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\220\204\345\234\260\345\214\272\345\237\216\344\271\241\344\272\272\345\217\243\350\277\201\347\247\273", 0));
        browse_31->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label32->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\350\277\201\347\247\273\344\277\256\346\255\243\347\263\273\346\225\260", 0));
        browse_32->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label33->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\210\206\347\234\201\346\200\273\345\222\214\350\277\201\347\247\273\347\216\207\351\242\204\346\265\213", 0));
        browse_33->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label34->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\210\206\347\234\201\345\207\200\350\277\201\347\247\273\347\216\207", 0));
        browse_34->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label35->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\350\277\201\347\247\273\346\250\241\345\274\217\345\222\214\346\246\202\347\216\207", 0));
        browse_35->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        shenyumoshi->setTitle(QApplication::translate("ImportBasicPara", "\347\224\237\350\202\262\345\217\212\351\207\212\346\224\276\346\250\241\345\274\217\345\217\202\346\225\260", 0));
        label41->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\220\204\345\234\260\345\214\27250\345\262\201\345\217\212\344\273\245\344\270\212\345\246\207\345\245\263\346\227\240\346\264\273\344\272\247\345\255\220\345\245\263\346\257\224\344\276\213", 0));
        browse_41->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label42->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\220\204\345\234\260\345\214\272\344\273\243\347\240\201\345\222\214\345\207\272\347\224\237\346\200\247\345\210\253\346\257\224", 0));
        browse_42->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label43->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\347\224\237\350\202\262\345\217\212\351\207\212\346\224\276\346\250\241\345\274\217_\345\255\230\346\264\273\344\270\200\345\255\251\346\263\225", 0));
        browse_43->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label44->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\347\224\237\350\202\262\345\217\212\351\207\212\346\224\276\346\250\241\345\274\217_\345\271\263\345\235\207\345\255\230\346\264\273\346\263\225", 0));
        browse_44->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label45->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\347\224\237\350\202\262\345\217\212\351\207\212\346\224\276\346\250\241\345\274\217_\347\224\237\350\202\262\346\250\241\345\274\217\346\263\225", 0));
        browse_45->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        label46->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\347\224\237\350\202\262\346\204\217\346\204\277", 0));
        browse_46->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        zhongshengyiyuan->setTitle(QApplication::translate("ImportBasicPara", "\347\273\210\350\272\253\346\204\217\346\204\277\347\224\237\350\202\262\347\216\207\345\217\202\346\225\260", 0));
        label51->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\345\220\204\345\234\260\345\214\272\347\273\210\350\272\253\346\224\277\347\255\226\347\224\237\350\202\262\347\216\207", 0));
        browse_51->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        shengyushuipin->setTitle(QApplication::translate("ImportBasicPara", "\347\224\237\350\202\262\346\260\264\345\271\263\347\216\260\347\212\266\350\257\204\344\274\260\344\270\216\346\224\277\347\255\226\345\201\217\347\246\273\345\272\246\351\207\217\345\214\226\350\257\204\344\274\260", 0));
        label61->setText(QApplication::translate("ImportBasicPara", "\345\237\272\346\234\254\345\217\202\346\225\260_\347\216\260\345\256\236\347\224\237\350\202\262\347\216\207\344\270\216\346\224\277\347\255\226\347\224\237\350\202\262\347\216\207\346\257\224\350\276\20306_09", 0));
        browse_61->setText(QApplication::translate("ImportBasicPara", "\346\265\217\350\247\210", 0));
        daoru->setText(QApplication::translate("ImportBasicPara", "\345\257\274\345\205\245", 0));
        cancel->setText(QApplication::translate("ImportBasicPara", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class ImportBasicPara: public Ui_ImportBasicPara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTBASICPARA_H
