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
    connect(ui->ImportData, SIGNAL(triggered()), this, SLOT(importDataActionTriggered()));
    //parameter menu
    connect(ui->ImportPara, SIGNAL(triggered()), this, SLOT(importParaActionTriggered()));
    //simulation menu
    connect(ui->CalculateSim, SIGNAL(triggered()), this, SLOT(calculateSimActionTriggered()));
    connect(ui->ShowSim, SIGNAL(triggered()), this, SLOT(showSimActionTriggered()));
    connect(ui->EvaluateSim, SIGNAL(toggled(bool)), this, SLOT(evaluateSimActionTriggered()));
    //connect(ui->ReportSim, SIGNAL(triggered()), this, SLOT());

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
    uiManager->active(UiManager::projectName);
}

void MainWindow::importDataActionTriggered()
{
    uiManager->active(UiManager::importBasicData);
}

void MainWindow::importParaActionTriggered()
{
    uiManager->active(UiManager::importBasicPara);
}

void MainWindow::calculateSimActionTriggered()
{
    //do some calculate in the background
    uiManager->active(UiManager::doingCalcProgress);
}

void MainWindow::showSimActionTriggered()
{
    uiManager->active(UiManager::display);
}

void MainWindow::evaluateSimActionTriggered()
{
    uiManager->active(UiManager::evaluate);
}

void MainWindow::aboutActionTriggered()
{

}






