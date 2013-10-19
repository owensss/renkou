/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *display;
    QAction *NewProject;
    QAction *OpenProject;
    QAction *CloseProject;
    QAction *prepare;
    QAction *manual;
    QAction *about;
    QAction *input_2;
    QAction *search;
    QAction *evaluate2;
    QAction *report2;
    QAction *add;
    QAction *exit;
    QAction *input;
    QAction *import_2;
    QAction *view;
    QAction *modify;
    QAction *view_2;
    QAction *modify_2;
    QAction *enter;
    QAction *import_4;
    QAction *action_11;
    QAction *action_12;
    QAction *action_13;
    QAction *action_14;
    QAction *action_15;
    QAction *action_16;
    QAction *action_17;
    QAction *action_18;
    QAction *action_19;
    QAction *action_20;
    QAction *action_21;
    QAction *action_22;
    QAction *action_23;
    QAction *action_24;
    QAction *action_25;
    QAction *action_26;
    QAction *action_27;
    QAction *action_28;
    QAction *action_29;
    QAction *action_30;
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QAction *action_4;
    QAction *action_5;
    QAction *action_6;
    QAction *action_7;
    QAction *action_8;
    QAction *action_9;
    QAction *action_10;
    QAction *action_31;
    QAction *action_32;
    QAction *action_33;
    QAction *action_34;
    QAction *action_35;
    QAction *p1;
    QAction *p2;
    QAction *p3;
    QAction *p4;
    QAction *p5;
    QAction *p6;
    QAction *import_5;
    QAction *caculate;
    QAction *evaluate;
    QAction *report;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *display_icon;
    QMenuBar *menuBar;
    QMenu *File;
    QMenu *base_parameter;
    QMenu *caculate_2;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_7;
    QMenu *menu_8;
    QMenu *Analysis;
    QMenu *Help;
    QMenu *base_data;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(917, 555);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        display = new QAction(MainWindow);
        display->setObjectName(QStringLiteral("display"));
        display->setEnabled(true);
        NewProject = new QAction(MainWindow);
        NewProject->setObjectName(QStringLiteral("NewProject"));
        OpenProject = new QAction(MainWindow);
        OpenProject->setObjectName(QStringLiteral("OpenProject"));
        CloseProject = new QAction(MainWindow);
        CloseProject->setObjectName(QStringLiteral("CloseProject"));
        CloseProject->setEnabled(false);
        prepare = new QAction(MainWindow);
        prepare->setObjectName(QStringLiteral("prepare"));
        prepare->setEnabled(false);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        prepare->setFont(font);
        manual = new QAction(MainWindow);
        manual->setObjectName(QStringLiteral("manual"));
        manual->setEnabled(true);
        about = new QAction(MainWindow);
        about->setObjectName(QStringLiteral("about"));
        about->setEnabled(true);
        input_2 = new QAction(MainWindow);
        input_2->setObjectName(QStringLiteral("input_2"));
        input_2->setEnabled(false);
        input_2->setFont(font);
        search = new QAction(MainWindow);
        search->setObjectName(QStringLiteral("search"));
        evaluate2 = new QAction(MainWindow);
        evaluate2->setObjectName(QStringLiteral("evaluate2"));
        evaluate2->setEnabled(true);
        report2 = new QAction(MainWindow);
        report2->setObjectName(QStringLiteral("report2"));
        report2->setEnabled(false);
        add = new QAction(MainWindow);
        add->setObjectName(QStringLiteral("add"));
        add->setEnabled(false);
        exit = new QAction(MainWindow);
        exit->setObjectName(QStringLiteral("exit"));
        input = new QAction(MainWindow);
        input->setObjectName(QStringLiteral("input"));
        input->setEnabled(false);
        import_2 = new QAction(MainWindow);
        import_2->setObjectName(QStringLiteral("import_2"));
        import_2->setEnabled(false);
        view = new QAction(MainWindow);
        view->setObjectName(QStringLiteral("view"));
        view->setEnabled(false);
        modify = new QAction(MainWindow);
        modify->setObjectName(QStringLiteral("modify"));
        modify->setEnabled(false);
        view_2 = new QAction(MainWindow);
        view_2->setObjectName(QStringLiteral("view_2"));
        view_2->setEnabled(false);
        modify_2 = new QAction(MainWindow);
        modify_2->setObjectName(QStringLiteral("modify_2"));
        modify_2->setEnabled(false);
        enter = new QAction(MainWindow);
        enter->setObjectName(QStringLiteral("enter"));
        enter->setEnabled(false);
        import_4 = new QAction(MainWindow);
        import_4->setObjectName(QStringLiteral("import_4"));
        action_11 = new QAction(MainWindow);
        action_11->setObjectName(QStringLiteral("action_11"));
        action_12 = new QAction(MainWindow);
        action_12->setObjectName(QStringLiteral("action_12"));
        action_13 = new QAction(MainWindow);
        action_13->setObjectName(QStringLiteral("action_13"));
        action_14 = new QAction(MainWindow);
        action_14->setObjectName(QStringLiteral("action_14"));
        action_14->setEnabled(false);
        action_15 = new QAction(MainWindow);
        action_15->setObjectName(QStringLiteral("action_15"));
        action_15->setEnabled(false);
        action_16 = new QAction(MainWindow);
        action_16->setObjectName(QStringLiteral("action_16"));
        action_17 = new QAction(MainWindow);
        action_17->setObjectName(QStringLiteral("action_17"));
        action_18 = new QAction(MainWindow);
        action_18->setObjectName(QStringLiteral("action_18"));
        action_19 = new QAction(MainWindow);
        action_19->setObjectName(QStringLiteral("action_19"));
        action_20 = new QAction(MainWindow);
        action_20->setObjectName(QStringLiteral("action_20"));
        action_21 = new QAction(MainWindow);
        action_21->setObjectName(QStringLiteral("action_21"));
        action_22 = new QAction(MainWindow);
        action_22->setObjectName(QStringLiteral("action_22"));
        action_23 = new QAction(MainWindow);
        action_23->setObjectName(QStringLiteral("action_23"));
        action_24 = new QAction(MainWindow);
        action_24->setObjectName(QStringLiteral("action_24"));
        action_25 = new QAction(MainWindow);
        action_25->setObjectName(QStringLiteral("action_25"));
        action_26 = new QAction(MainWindow);
        action_26->setObjectName(QStringLiteral("action_26"));
        action_27 = new QAction(MainWindow);
        action_27->setObjectName(QStringLiteral("action_27"));
        action_28 = new QAction(MainWindow);
        action_28->setObjectName(QStringLiteral("action_28"));
        action_29 = new QAction(MainWindow);
        action_29->setObjectName(QStringLiteral("action_29"));
        action_30 = new QAction(MainWindow);
        action_30->setObjectName(QStringLiteral("action_30"));
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action->setEnabled(false);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_2->setEnabled(false);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QStringLiteral("action_3"));
        action_3->setEnabled(false);
        action_4 = new QAction(MainWindow);
        action_4->setObjectName(QStringLiteral("action_4"));
        action_4->setEnabled(false);
        action_5 = new QAction(MainWindow);
        action_5->setObjectName(QStringLiteral("action_5"));
        action_5->setEnabled(false);
        action_6 = new QAction(MainWindow);
        action_6->setObjectName(QStringLiteral("action_6"));
        action_6->setEnabled(false);
        action_7 = new QAction(MainWindow);
        action_7->setObjectName(QStringLiteral("action_7"));
        action_7->setEnabled(false);
        action_8 = new QAction(MainWindow);
        action_8->setObjectName(QStringLiteral("action_8"));
        action_9 = new QAction(MainWindow);
        action_9->setObjectName(QStringLiteral("action_9"));
        action_10 = new QAction(MainWindow);
        action_10->setObjectName(QStringLiteral("action_10"));
        action_10->setEnabled(false);
        action_31 = new QAction(MainWindow);
        action_31->setObjectName(QStringLiteral("action_31"));
        action_31->setEnabled(false);
        action_32 = new QAction(MainWindow);
        action_32->setObjectName(QStringLiteral("action_32"));
        action_32->setEnabled(false);
        action_33 = new QAction(MainWindow);
        action_33->setObjectName(QStringLiteral("action_33"));
        action_33->setEnabled(false);
        action_34 = new QAction(MainWindow);
        action_34->setObjectName(QStringLiteral("action_34"));
        action_34->setEnabled(false);
        action_35 = new QAction(MainWindow);
        action_35->setObjectName(QStringLiteral("action_35"));
        action_35->setEnabled(false);
        p1 = new QAction(MainWindow);
        p1->setObjectName(QStringLiteral("p1"));
        p2 = new QAction(MainWindow);
        p2->setObjectName(QStringLiteral("p2"));
        p3 = new QAction(MainWindow);
        p3->setObjectName(QStringLiteral("p3"));
        p4 = new QAction(MainWindow);
        p4->setObjectName(QStringLiteral("p4"));
        p5 = new QAction(MainWindow);
        p5->setObjectName(QStringLiteral("p5"));
        p6 = new QAction(MainWindow);
        p6->setObjectName(QStringLiteral("p6"));
        import_5 = new QAction(MainWindow);
        import_5->setObjectName(QStringLiteral("import_5"));
        import_5->setEnabled(false);
        caculate = new QAction(MainWindow);
        caculate->setObjectName(QStringLiteral("caculate"));
        caculate->setEnabled(false);
        evaluate = new QAction(MainWindow);
        evaluate->setObjectName(QStringLiteral("evaluate"));
        report = new QAction(MainWindow);
        report->setObjectName(QStringLiteral("report"));
        report->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 30, 871, 461));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 15, 0, 0);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        display_icon = new QWidget(centralWidget);
        display_icon->setObjectName(QStringLiteral("display_icon"));
        display_icon->setGeometry(QRect(900, 210, 100, 90));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 917, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        menuBar->setFont(font1);
        File = new QMenu(menuBar);
        File->setObjectName(QStringLiteral("File"));
        File->setFont(font);
        base_parameter = new QMenu(menuBar);
        base_parameter->setObjectName(QStringLiteral("base_parameter"));
        base_parameter->setEnabled(true);
        caculate_2 = new QMenu(base_parameter);
        caculate_2->setObjectName(QStringLiteral("caculate_2"));
        caculate_2->setEnabled(false);
        menu_2 = new QMenu(caculate_2);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(caculate_2);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(caculate_2);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(caculate_2);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        menu_7 = new QMenu(caculate_2);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        menu_8 = new QMenu(caculate_2);
        menu_8->setObjectName(QStringLiteral("menu_8"));
        Analysis = new QMenu(menuBar);
        Analysis->setObjectName(QStringLiteral("Analysis"));
        Analysis->setEnabled(true);
        Analysis->setFont(font);
        Help = new QMenu(menuBar);
        Help->setObjectName(QStringLiteral("Help"));
        base_data = new QMenu(menuBar);
        base_data->setObjectName(QStringLiteral("base_data"));
        base_data->setEnabled(true);
        base_data->setAcceptDrops(true);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(File->menuAction());
        menuBar->addAction(base_data->menuAction());
        menuBar->addAction(base_parameter->menuAction());
        menuBar->addAction(Analysis->menuAction());
        menuBar->addAction(Help->menuAction());
        File->addAction(NewProject);
        File->addAction(OpenProject);
        File->addSeparator();
        File->addAction(search);
        File->addAction(add);
        File->addSeparator();
        File->addAction(CloseProject);
        File->addAction(exit);
        base_parameter->addAction(input_2);
        base_parameter->addAction(import_5);
        base_parameter->addSeparator();
        base_parameter->addAction(caculate_2->menuAction());
        base_parameter->addSeparator();
        base_parameter->addAction(view_2);
        base_parameter->addAction(modify_2);
        caculate_2->addAction(menu_2->menuAction());
        caculate_2->addAction(menu_3->menuAction());
        caculate_2->addSeparator();
        caculate_2->addAction(menu_4->menuAction());
        caculate_2->addAction(menu_5->menuAction());
        caculate_2->addSeparator();
        caculate_2->addAction(menu_7->menuAction());
        caculate_2->addAction(menu_8->menuAction());
        menu_2->addAction(import_4);
        menu_2->addAction(action_8);
        menu_2->addSeparator();
        menu_2->addAction(action_9);
        menu_2->addAction(action_10);
        menu_3->addAction(action_13);
        menu_3->addAction(action_14);
        menu_3->addSeparator();
        menu_3->addAction(action_15);
        menu_3->addAction(action);
        menu_3->addSeparator();
        menu_3->addAction(action_2);
        menu_3->addAction(action_3);
        menu_3->addSeparator();
        menu_3->addAction(action_4);
        menu_3->addAction(action_5);
        menu_3->addSeparator();
        menu_3->addAction(action_6);
        menu_3->addAction(action_7);
        menu_3->addSeparator();
        menu_3->addAction(action_31);
        menu_4->addAction(action_16);
        menu_4->addAction(action_32);
        menu_5->addAction(action_19);
        menu_5->addAction(action_33);
        menu_7->addAction(action_25);
        menu_7->addAction(action_34);
        menu_8->addAction(action_28);
        menu_8->addAction(action_35);
        Analysis->addAction(caculate);
        Analysis->addAction(display);
        Analysis->addSeparator();
        Analysis->addAction(evaluate);
        Analysis->addAction(report);
        Help->addAction(manual);
        Help->addSeparator();
        Help->addAction(about);
        base_data->addAction(input);
        base_data->addAction(import_2);
        base_data->addSeparator();
        base_data->addAction(view);
        base_data->addAction(modify);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\347\224\237\350\202\262\346\224\277\347\255\226\344\273\277\347\234\237\345\222\214\345\206\263\347\255\226\346\224\257\346\214\201\345\255\220\347\263\273\347\273\237", 0));
        display->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\346\274\224\347\244\272", 0));
        NewProject->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", 0));
        OpenProject->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\241\271\347\233\256", 0));
        CloseProject->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\351\241\271\347\233\256", 0));
        prepare->setText(QApplication::translate("MainWindow", "\345\207\206\345\244\207\350\256\241\347\256\227", 0));
        manual->setText(QApplication::translate("MainWindow", "\346\211\213\345\206\214", 0));
        about->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
        input_2->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245", 0));
        search->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        evaluate2->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\350\257\204\344\273\267", 0));
        report2->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\346\212\245\345\221\212", 0));
        add->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        exit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        input->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245", 0));
        import_2->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", 0));
        view->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
        modify->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", 0));
        view_2->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
        modify_2->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", 0));
        enter->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\350\256\241\347\256\227", 0));
        import_4->setText(QApplication::translate("MainWindow", "\345\257\271\346\225\260\346\250\241\345\236\213\346\263\225", 0));
        action_11->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2132", 0));
        action_12->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2133", 0));
        action_13->setText(QApplication::translate("MainWindow", "\350\277\255\344\273\243\351\242\204\346\265\213\346\250\241\345\236\213\346\263\225", 0));
        action_14->setText(QApplication::translate("MainWindow", "\344\270\234\346\226\271\346\250\241\345\274\217", 0));
        action_15->setText(QApplication::translate("MainWindow", "\350\245\277\346\226\271\346\250\241\345\274\217", 0));
        action_16->setText(QApplication::translate("MainWindow", "\346\200\273\345\222\214\350\277\201\347\247\273\347\216\207\346\250\241\345\236\213\346\263\225", 0));
        action_17->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2132", 0));
        action_18->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2133", 0));
        action_19->setText(QApplication::translate("MainWindow", "\345\233\236\345\275\222\346\250\241\345\236\213\346\263\225", 0));
        action_20->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2132", 0));
        action_21->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2133", 0));
        action_22->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2131", 0));
        action_23->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2132", 0));
        action_24->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2133", 0));
        action_25->setText(QApplication::translate("MainWindow", "\345\237\272\344\272\216\350\260\203\346\237\245\346\225\260\346\215\256\347\232\204\351\207\217\345\214\226\346\250\241\345\236\213\346\263\225", 0));
        action_26->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2132", 0));
        action_27->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2133", 0));
        action_28->setText(QApplication::translate("MainWindow", "\350\277\255\344\273\243\345\233\236\345\275\222\346\250\241\345\236\213\346\263\225", 0));
        action_29->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2132", 0));
        action_30->setText(QApplication::translate("MainWindow", "\346\250\241\345\236\2133", 0));
        action->setText(QApplication::translate("MainWindow", "\345\214\227\346\226\271\346\250\241\345\274\217", 0));
        action_2->setText(QApplication::translate("MainWindow", "\345\215\227\346\226\271\346\250\241\345\274\217", 0));
        action_3->setText(QApplication::translate("MainWindow", "\350\201\224\345\220\210\345\233\275\344\270\200\350\210\254\346\250\241\345\274\217", 0));
        action_4->setText(QApplication::translate("MainWindow", "\350\201\224\345\220\210\345\233\275\346\213\211\344\270\201\347\276\216\346\264\262\346\250\241\345\274\217", 0));
        action_5->setText(QApplication::translate("MainWindow", "\350\201\224\345\220\210\345\233\275\346\231\272\345\210\251\346\250\241\345\274\217", 0));
        action_6->setText(QApplication::translate("MainWindow", "\350\201\224\345\220\210\345\233\275\345\215\227\344\272\232\346\250\241\345\274\217", 0));
        action_7->setText(QApplication::translate("MainWindow", "\350\201\224\345\220\210\345\233\275\344\270\234\344\272\232\346\250\241\345\274\217", 0));
        action_8->setText(QApplication::translate("MainWindow", "\350\201\224\345\220\210\345\233\275\346\263\225", 0));
        action_9->setText(QApplication::translate("MainWindow", "\351\200\273\350\276\221\346\226\257\350\222\202\346\250\241\345\236\213\346\263\225", 0));
        action_10->setText(QApplication::translate("MainWindow", "\345\205\266\345\256\203\346\250\241\345\236\213\346\263\225", 0));
        action_31->setText(QApplication::translate("MainWindow", "\345\205\266\345\256\203\346\250\241\345\236\213\346\263\225", 0));
        action_32->setText(QApplication::translate("MainWindow", "\345\205\266\345\256\203\346\250\241\345\236\213\346\263\225", 0));
        action_33->setText(QApplication::translate("MainWindow", "\345\205\266\345\256\203\346\250\241\345\236\213\346\263\225", 0));
        action_34->setText(QApplication::translate("MainWindow", "\345\205\266\345\256\203\346\250\241\345\236\213\346\263\225", 0));
        action_35->setText(QApplication::translate("MainWindow", "\345\205\266\345\256\203\346\250\241\345\236\213\346\263\225", 0));
        p1->setText(QApplication::translate("MainWindow", "\351\242\204\346\234\237\345\257\277\345\221\275\345\217\202\346\225\260", 0));
        p2->setText(QApplication::translate("MainWindow", "\346\255\273\344\272\241\346\246\202\347\216\207\345\217\202\346\225\260", 0));
        p3->setText(QApplication::translate("MainWindow", "\350\277\201\347\247\273\346\250\241\345\274\217\345\217\202\346\225\260", 0));
        p4->setText(QApplication::translate("MainWindow", "\347\224\237\350\202\262\346\250\241\345\274\217\345\217\202\346\225\260", 0));
        p5->setText(QApplication::translate("MainWindow", "\347\273\210\350\272\253\346\204\217\346\204\277\347\224\237\350\202\262\347\216\207\345\217\202\346\225\260", 0));
        p6->setText(QApplication::translate("MainWindow", "\347\224\237\350\202\262\346\260\264\345\271\263\347\216\260\347\212\266\350\257\204\344\274\260\344\270\216\346\224\277\347\255\226\345\201\217\347\246\273\345\272\246\351\207\217\345\214\226\350\257\204\344\274\260", 0));
        import_5->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", 0));
        caculate->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\350\256\241\347\256\227", 0));
        evaluate->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\350\257\204\344\273\267", 0));
        report->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\346\212\245\345\221\212", 0));
        File->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        base_parameter->setTitle(QApplication::translate("MainWindow", "\345\237\272\346\234\254\345\217\202\346\225\260", 0));
        caculate_2->setTitle(QApplication::translate("MainWindow", "\350\256\241\347\256\227", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\351\242\204\346\234\237\345\257\277\345\221\275\351\242\204\346\265\213\n"
"", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\346\255\273\344\272\241\346\246\202\347\216\207\351\242\204\346\265\213\n"
"", 0));
        menu_4->setTitle(QApplication::translate("MainWindow", "\350\277\201\347\247\273\346\246\202\347\216\207\351\242\204\346\265\213\n"
"", 0));
        menu_5->setTitle(QApplication::translate("MainWindow", "\347\224\237\350\202\262\345\217\212\351\207\212\346\224\276\346\250\241\345\274\217\351\242\204\346\265\213\n"
"", 0));
        menu_7->setTitle(QApplication::translate("MainWindow", "\347\273\210\350\272\253\346\204\217\346\204\277\347\224\237\350\202\262\347\216\207\351\207\217\345\214\226\n"
"", 0));
        menu_8->setTitle(QApplication::translate("MainWindow", "\347\224\237\350\202\262\346\260\264\345\271\263\347\216\260\347\212\266\350\257\204\344\274\260\344\270\216\346\224\277\347\255\226\345\201\217\347\246\273\345\272\246\351\207\217\345\214\226\344\274\260\350\256\241\347\216\207\351\207\217\345\214\226\n"
"", 0));
        Analysis->setTitle(QApplication::translate("MainWindow", "\346\224\277\347\255\226\344\273\277\347\234\237", 0));
        Help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        base_data->setTitle(QApplication::translate("MainWindow", "\345\237\272\347\241\200\346\225\260\346\215\256", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H
