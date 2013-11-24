#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
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

#include "uiitem.h"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow, public UiItem {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
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
};

#endif // MAINWINDOW_H
