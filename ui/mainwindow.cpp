#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
    ui(new Ui::MainWindow),
    uiManager(new UiManager())
{
	ui->setupUi(this);

    //project menu
    connect(ui->NewProject, SIGNAL(triggered()), this, SLOT(addProjectActionTriggered()));
    connect(ui->OpenProject, SIGNAL(triggered()), this, SLOT(openProjectActionTriggered()));

    //data manage menu
    connect(ui->ImportData, SIGNAL(triggered()), this, SLOT
    //parameter menu

    //simulation menu

    //help menu
    connect(ui->About, SIGNAL(triggered()), this, SLOT(aboutActionTriggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete uiManager;
}

void MainWindow::addProjectActionTriggered()
{
    uiManager->active(UiManager::newProject);
}

void MainWindow::openProjectActionTriggered()
{

}

void MainWindow::aboutActionTriggered()
{

}





