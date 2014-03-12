#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <Qtwidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <Qtwidgets/QTableView>
#include <Qtwidgets/QHeaderView>

<<<<<<< HEAD
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget* parent = NULL);
    ~MainWindow();
private:
    Ui::MainWindow* ui;
};

QT_END_NAMESPACE

=======
#include <QColor>
#include <QStandardItemModel>
#include <QPalette>

#include "uiitem.h"
namespace Ui {
    class MainWindow;
}

//class MainWindow : public QMainWindow, public UiItem
//{

class MainWindow : public QMainWindow, public UiItem {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();


private slots:
    //project menu
    void addProjectActionTriggered();
    void openProjectActionTriggered();
    void searchObjectActionTriggered();
    void addObjectAcionTriggered();
    void quitActionTriggered();
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

    //enable some actions after a project opened

private:
    Ui::MainWindow* ui;
    void enableActions();
};

>>>>>>> f7bbdfeec132428a546966e8f5919d9479f7f366
#endif // MAINWINDOW_H
