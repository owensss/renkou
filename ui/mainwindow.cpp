#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    ui(new Ui::MainWindow),
    uiManager(new UiManager())
{
	ui->setupUi(this);

    connect(ui->NewProject, SIGNAL(triggered()), this, SLOT(addProjectActionTriggered());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addProjectActionTriggered()
{
    uiManager->active(UiManager::NEW_PROJECT);
}



