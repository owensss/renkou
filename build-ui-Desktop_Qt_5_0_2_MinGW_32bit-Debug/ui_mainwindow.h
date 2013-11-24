/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *NewProject;
    QAction *OpenProject;
    QAction *SearchObject;
    QAction *AddObject;
    QAction *CloseProject;
    QAction *Quit;
    QAction *InputData;
    QAction *ImportData;
    QAction *WatchData;
    QAction *ModifyData;
    QAction *InputPara;
    QAction *ImportPara;
    QAction *CalculatePara;
    QAction *WatchPara;
    QAction *ModifyPara;
    QAction *CalculateSim;
    QAction *ShowSim;
    QAction *EvaluateSim;
    QAction *ReportSim;
    QAction *About;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *File;
    QMenu *DataManage;
    QMenu *Parameter;
    QMenu *Simulation;
    QMenu *Help;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(763, 377);
        NewProject = new QAction(MainWindow);
        NewProject->setObjectName(QStringLiteral("NewProject"));
        OpenProject = new QAction(MainWindow);
        OpenProject->setObjectName(QStringLiteral("OpenProject"));
        SearchObject = new QAction(MainWindow);
        SearchObject->setObjectName(QStringLiteral("SearchObject"));
        AddObject = new QAction(MainWindow);
        AddObject->setObjectName(QStringLiteral("AddObject"));
        CloseProject = new QAction(MainWindow);
        CloseProject->setObjectName(QStringLiteral("CloseProject"));
        Quit = new QAction(MainWindow);
        Quit->setObjectName(QStringLiteral("Quit"));
        InputData = new QAction(MainWindow);
        InputData->setObjectName(QStringLiteral("InputData"));
        ImportData = new QAction(MainWindow);
        ImportData->setObjectName(QStringLiteral("ImportData"));
        WatchData = new QAction(MainWindow);
        WatchData->setObjectName(QStringLiteral("WatchData"));
        ModifyData = new QAction(MainWindow);
        ModifyData->setObjectName(QStringLiteral("ModifyData"));
        InputPara = new QAction(MainWindow);
        InputPara->setObjectName(QStringLiteral("InputPara"));
        ImportPara = new QAction(MainWindow);
        ImportPara->setObjectName(QStringLiteral("ImportPara"));
        CalculatePara = new QAction(MainWindow);
        CalculatePara->setObjectName(QStringLiteral("CalculatePara"));
        WatchPara = new QAction(MainWindow);
        WatchPara->setObjectName(QStringLiteral("WatchPara"));
        ModifyPara = new QAction(MainWindow);
        ModifyPara->setObjectName(QStringLiteral("ModifyPara"));
        CalculateSim = new QAction(MainWindow);
        CalculateSim->setObjectName(QStringLiteral("CalculateSim"));
        ShowSim = new QAction(MainWindow);
        ShowSim->setObjectName(QStringLiteral("ShowSim"));
        EvaluateSim = new QAction(MainWindow);
        EvaluateSim->setObjectName(QStringLiteral("EvaluateSim"));
        ReportSim = new QAction(MainWindow);
        ReportSim->setObjectName(QStringLiteral("ReportSim"));
        About = new QAction(MainWindow);
        About->setObjectName(QStringLiteral("About"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 763, 22));
        File = new QMenu(menuBar);
        File->setObjectName(QStringLiteral("File"));
        DataManage = new QMenu(menuBar);
        DataManage->setObjectName(QStringLiteral("DataManage"));
        Parameter = new QMenu(menuBar);
        Parameter->setObjectName(QStringLiteral("Parameter"));
        Simulation = new QMenu(menuBar);
        Simulation->setObjectName(QStringLiteral("Simulation"));
        Help = new QMenu(menuBar);
        Help->setObjectName(QStringLiteral("Help"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(File->menuAction());
        menuBar->addAction(DataManage->menuAction());
        menuBar->addAction(Parameter->menuAction());
        menuBar->addAction(Simulation->menuAction());
        menuBar->addAction(Help->menuAction());
        File->addAction(NewProject);
        File->addAction(OpenProject);
        File->addSeparator();
        File->addAction(SearchObject);
        File->addAction(AddObject);
        File->addSeparator();
        File->addAction(CloseProject);
        File->addAction(Quit);
        DataManage->addAction(InputData);
        DataManage->addAction(ImportData);
        DataManage->addSeparator();
        DataManage->addAction(WatchData);
        DataManage->addAction(ModifyData);
        Parameter->addAction(InputPara);
        Parameter->addAction(ImportPara);
        Parameter->addSeparator();
        Parameter->addAction(CalculatePara);
        Parameter->addSeparator();
        Parameter->addAction(WatchPara);
        Parameter->addAction(ModifyPara);
        Simulation->addAction(CalculateSim);
        Simulation->addAction(ShowSim);
        Simulation->addSeparator();
        Simulation->addAction(EvaluateSim);
        Simulation->addAction(ReportSim);
        Help->addAction(About);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        NewProject->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", 0));
        OpenProject->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\241\271\347\233\256", 0));
        SearchObject->setText(QApplication::translate("MainWindow", "\346\237\245\346\211\276\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        AddObject->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        CloseProject->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\351\241\271\347\233\256", 0));
        Quit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        InputData->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245", 0));
        ImportData->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", 0));
        WatchData->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
        ModifyData->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", 0));
        InputPara->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245", 0));
        ImportPara->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", 0));
        CalculatePara->setText(QApplication::translate("MainWindow", "\350\256\241\347\256\227", 0));
        WatchPara->setText(QApplication::translate("MainWindow", "\346\237\245\347\234\213", 0));
        ModifyPara->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271", 0));
        CalculateSim->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\350\256\241\347\256\227", 0));
        ShowSim->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\346\274\224\347\244\272", 0));
        EvaluateSim->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\350\257\204\344\273\267", 0));
        ReportSim->setText(QApplication::translate("MainWindow", "\344\273\277\347\234\237\346\212\245\345\221\212", 0));
        About->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
        File->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        DataManage->setTitle(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\225\260\346\215\256", 0));
        Parameter->setTitle(QApplication::translate("MainWindow", "\345\237\272\346\234\254\345\217\202\346\225\260", 0));
        Simulation->setTitle(QApplication::translate("MainWindow", "\346\224\277\347\255\226\344\273\277\347\234\237", 0));
        Help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
