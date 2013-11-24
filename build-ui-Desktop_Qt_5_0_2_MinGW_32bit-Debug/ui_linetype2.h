/********************************************************************************
** Form generated from reading UI file 'linetype2.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINETYPE2_H
#define UI_LINETYPE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphview.h"

QT_BEGIN_NAMESPACE

class Ui_LineType2
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_Main;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    GraphView *graphicsView;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QRadioButton *radioCurve;
    QRadioButton *radioBar;
    QCheckBox *checkBox;
    QGroupBox *groupBox_4;
    QPushButton *ViewDataButton;
    QRadioButton *VLineButton;
    QRadioButton *HLineButton;
    QRadioButton *DualLineButton;
    QRadioButton *NoLineButton;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *PlayButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *StopButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Advance10Button;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Back10Button;
    QSpacerItem *horizontalSpacer_6;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_5;

    void setupUi(QWidget *LineType2)
    {
        if (LineType2->objectName().isEmpty())
            LineType2->setObjectName(QStringLiteral("LineType2"));
        LineType2->resize(745, 635);
        verticalLayoutWidget = new QWidget(LineType2);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 743, 635));
        verticalLayout_Main = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_Main->setObjectName(QStringLiteral("verticalLayout_Main"));
        verticalLayout_Main->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5->setContentsMargins(0, 0, 10, 0);
        graphicsView = new GraphView(verticalLayoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(0, 0));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);

        verticalLayout_5->addWidget(graphicsView);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        groupBox_3 = new QGroupBox(verticalLayoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(120, 80));
        radioCurve = new QRadioButton(groupBox_3);
        radioCurve->setObjectName(QStringLiteral("radioCurve"));
        radioCurve->setGeometry(QRect(20, 20, 81, 16));
        radioBar = new QRadioButton(groupBox_3);
        radioBar->setObjectName(QStringLiteral("radioBar"));
        radioBar->setGeometry(QRect(20, 50, 71, 16));

        verticalLayout_6->addWidget(groupBox_3);

        checkBox = new QCheckBox(verticalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_6->addWidget(checkBox);

        groupBox_4 = new QGroupBox(verticalLayoutWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        groupBox_4->setMinimumSize(QSize(100, 140));
        ViewDataButton = new QPushButton(groupBox_4);
        ViewDataButton->setObjectName(QStringLiteral("ViewDataButton"));
        ViewDataButton->setGeometry(QRect(10, 102, 71, 31));
        VLineButton = new QRadioButton(groupBox_4);
        VLineButton->setObjectName(QStringLiteral("VLineButton"));
        VLineButton->setGeometry(QRect(10, 40, 89, 16));
        HLineButton = new QRadioButton(groupBox_4);
        HLineButton->setObjectName(QStringLiteral("HLineButton"));
        HLineButton->setGeometry(QRect(10, 60, 89, 16));
        DualLineButton = new QRadioButton(groupBox_4);
        DualLineButton->setObjectName(QStringLiteral("DualLineButton"));
        DualLineButton->setGeometry(QRect(10, 80, 89, 16));
        NoLineButton = new QRadioButton(groupBox_4);
        NoLineButton->setObjectName(QStringLiteral("NoLineButton"));
        NoLineButton->setGeometry(QRect(10, 20, 89, 16));

        verticalLayout_6->addWidget(groupBox_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(groupBox);


        verticalLayout_6->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalLayout_2->setStretch(0, 3);

        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PlayButton = new QPushButton(verticalLayoutWidget);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));

        horizontalLayout->addWidget(PlayButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        StopButton = new QPushButton(verticalLayoutWidget);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        horizontalLayout->addWidget(StopButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Advance10Button = new QPushButton(verticalLayoutWidget);
        Advance10Button->setObjectName(QStringLiteral("Advance10Button"));

        horizontalLayout->addWidget(Advance10Button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        Back10Button = new QPushButton(verticalLayoutWidget);
        Back10Button->setObjectName(QStringLiteral("Back10Button"));

        horizontalLayout->addWidget(Back10Button);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_Main->addLayout(verticalLayout_4);


        retranslateUi(LineType2);

        QMetaObject::connectSlotsByName(LineType2);
    } // setupUi

    void retranslateUi(QWidget *LineType2)
    {
        LineType2->setWindowTitle(QApplication::translate("LineType2", "Form", 0));
        groupBox_3->setTitle(QApplication::translate("LineType2", "\346\233\262\347\272\277\347\261\273\345\236\213", 0));
        radioCurve->setText(QApplication::translate("LineType2", "\346\233\262\347\272\277\345\233\276", 0));
        radioBar->setText(QApplication::translate("LineType2", "\346\237\261\347\212\266\345\233\276", 0));
        checkBox->setText(QApplication::translate("LineType2", "\346\230\276\347\244\272\346\225\260\345\200\274\347\202\271", 0));
        groupBox_4->setTitle(QApplication::translate("LineType2", "\346\240\207\345\260\272", 0));
        ViewDataButton->setText(QApplication::translate("LineType2", "\347\262\276\347\241\256", 0));
        VLineButton->setText(QApplication::translate("LineType2", "\347\272\265\346\240\207\345\260\272", 0));
        HLineButton->setText(QApplication::translate("LineType2", "\346\250\252\346\240\207\345\260\272", 0));
        DualLineButton->setText(QApplication::translate("LineType2", "\345\215\201\345\255\227\346\240\207\345\260\272", 0));
        NoLineButton->setText(QApplication::translate("LineType2", "\346\227\240\346\240\207\345\260\272", 0));
        groupBox->setTitle(QApplication::translate("LineType2", "\346\233\262\347\272\277\345\237\272\346\234\254\346\214\207\346\240\207", 0));
        PlayButton->setText(QApplication::translate("LineType2", "\346\222\255\346\224\276", 0));
        StopButton->setText(QApplication::translate("LineType2", "\345\201\234\346\255\242", 0));
        Advance10Button->setText(QApplication::translate("LineType2", "\345\211\215\350\277\233\345\215\201\345\271\264", 0));
        Back10Button->setText(QApplication::translate("LineType2", "\345\200\222\351\200\200\345\215\201\345\271\264", 0));
    } // retranslateUi

};

namespace Ui {
    class LineType2: public Ui_LineType2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINETYPE2_H
