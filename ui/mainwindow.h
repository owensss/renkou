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

#include "uimanager.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget* parent = nullptr, UiManager *uiManager);
    ~MainWindow();
private slots:
    //project menu
    void addProjectActionTriggered();
    void openProjectActionTriggered();

    //data manage menu
    void importDataActionTriggered();

    //parameter menu
    void importParaActionTriggered();

    //simulation menu
    void calculateSimActionTriggered();
    void showSimActionTriggered();
    void evaluateSimActionTriggered();

    //help menu
    void aboutActionTriggered();

private:
    Ui::MainWindow* ui;
    UiManager *uiManager;

};

#endif // MAINWINDOW_H
