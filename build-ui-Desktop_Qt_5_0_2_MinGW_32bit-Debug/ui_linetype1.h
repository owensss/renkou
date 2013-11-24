/********************************************************************************
** Form generated from reading UI file 'linetype1.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINETYPE1_H
#define UI_LINETYPE1_H

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

class Ui_LineType1
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_Main;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    GraphView *graphicsView;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QRadioButton *radioCurve;
    QRadioButton *radioBar;
    QRadioButton *radio3DBar;
    QCheckBox *checkBox;
    QGroupBox *groupBox_4;
    QPushButton *ViewDataButton;
    QRadioButton *VLineButton;
    QRadioButton *HLineButton;
    QRadioButton *DualLineButton;
    QRadioButton *NoLineButton;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
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

    void setupUi(QWidget *LineType1)
    {
        if (LineType1->objectName().isEmpty())
            LineType1->setObjectName(QStringLiteral("LineType1"));
        LineType1->resize(738, 612);
        verticalLayoutWidget = new QWidget(LineType1);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 743, 611));
        verticalLayout_Main = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_Main->setObjectName(QStringLiteral("verticalLayout_Main"));
        verticalLayout_Main->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setContentsMargins(10, 10, 10, 10);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_5->setContentsMargins(0, 0, 10, 0);
        graphicsView = new GraphView(widget);
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
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(10, 80));
        radioCurve = new QRadioButton(groupBox_3);
        radioCurve->setObjectName(QStringLiteral("radioCurve"));
        radioCurve->setGeometry(QRect(10, 20, 71, 16));
        radioBar = new QRadioButton(groupBox_3);
        radioBar->setObjectName(QStringLiteral("radioBar"));
        radioBar->setGeometry(QRect(10, 40, 71, 16));
        radio3DBar = new QRadioButton(groupBox_3);
        radio3DBar->setObjectName(QStringLiteral("radio3DBar"));
        radio3DBar->setGeometry(QRect(10, 60, 101, 16));

        verticalLayout_6->addWidget(groupBox_3);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_6->addWidget(checkBox);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMinimumSize(QSize(100, 135));
        ViewDataButton = new QPushButton(groupBox_4);
        ViewDataButton->setObjectName(QStringLiteral("ViewDataButton"));
        ViewDataButton->setGeometry(QRect(10, 100, 81, 31));
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

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(0, 220));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 20, 61, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_6->addWidget(groupBox);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalLayout_2->setStretch(0, 3);

        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        PlayButton = new QPushButton(widget);
        PlayButton->setObjectName(QStringLiteral("PlayButton"));

        horizontalLayout->addWidget(PlayButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        StopButton = new QPushButton(widget);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        horizontalLayout->addWidget(StopButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Advance10Button = new QPushButton(widget);
        Advance10Button->setObjectName(QStringLiteral("Advance10Button"));

        horizontalLayout->addWidget(Advance10Button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        Back10Button = new QPushButton(widget);
        Back10Button->setObjectName(QStringLiteral("Back10Button"));

        horizontalLayout->addWidget(Back10Button);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_Main->addWidget(widget);


        retranslateUi(LineType1);

        QMetaObject::connectSlotsByName(LineType1);
    } // setupUi

    void retranslateUi(QWidget *LineType1)
    {
        LineType1->setWindowTitle(QApplication::translate("LineType1", "Form", 0));
        groupBox_3->setTitle(QApplication::translate("LineType1", "\346\233\262\347\272\277\347\261\273\345\236\213", 0));
        radioCurve->setText(QApplication::translate("LineType1", "\346\233\262\347\272\277\345\233\276", 0));
        radioBar->setText(QApplication::translate("LineType1", "\346\237\261\347\212\266\345\233\276", 0));
        radio3DBar->setText(QApplication::translate("LineType1", "\344\270\211\347\273\264\346\237\261\347\212\266\345\233\276", 0));
        checkBox->setText(QApplication::translate("LineType1", "\346\230\276\347\244\272\346\225\260\345\200\274\347\202\271", 0));
        groupBox_4->setTitle(QApplication::translate("LineType1", "\346\240\207\345\260\272", 0));
        ViewDataButton->setText(QApplication::translate("LineType1", "\347\262\276\347\241\256", 0));
        VLineButton->setText(QApplication::translate("LineType1", "\347\272\265\346\240\207\345\260\272", 0));
        HLineButton->setText(QApplication::translate("LineType1", "\346\250\252\346\240\207\345\260\272", 0));
        DualLineButton->setText(QApplication::translate("LineType1", "\345\215\201\345\255\227\346\240\207\345\260\272", 0));
        NoLineButton->setText(QApplication::translate("LineType1", "\346\227\240\346\240\207\345\260\272", 0));
        groupBox->setTitle(QApplication::translate("LineType1", "\346\233\262\347\272\277\345\237\272\346\234\254\346\214\207\346\240\207", 0));
        PlayButton->setText(QApplication::translate("LineType1", "\346\222\255\346\224\276", 0));
        StopButton->setText(QApplication::translate("LineType1", "\345\201\234\346\255\242", 0));
        Advance10Button->setText(QApplication::translate("LineType1", "\345\211\215\350\277\233\345\215\201\345\271\264", 0));
        Back10Button->setText(QApplication::translate("LineType1", "\345\200\222\351\200\200\345\215\201\345\271\264", 0));
    } // retranslateUi

};

namespace Ui {
    class LineType1: public Ui_LineType1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINETYPE1_H
