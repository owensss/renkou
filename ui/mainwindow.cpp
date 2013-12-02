#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    //test widget
    QPalette *palette = new QPalette();
    ui->showWidget->setAutoFillBackground(true);

    palette->setColor(QPalette::Background, QColor(255, 255, 255));
    ui->showWidget->setPalette(*palette);
    ui->addObjectGroup->setVisible(false);

    QStringList yearList;
    for (int i = 1980; i<=2010; i++){
        yearList.push_back(QString::number(i));
    }
    ui->yearComboBox->addItems(yearList);
    //project menu
    connect(ui->NewProject, SIGNAL(triggered()), this, SLOT(addProjectActionTriggered()));
    connect(ui->OpenProject, SIGNAL(triggered()), this, SLOT(openProjectActionTriggered()));
    connect(ui->SearchObject, SIGNAL(triggered()), this, SLOT(searchObjectActionTriggered()));
    connect(ui->AddObject, SIGNAL(triggered()), this, SLOT(addObjectAcionTriggered()));
    connect(ui->Quit, SIGNAL(triggered()), this, SLOT(quitActionTriggered()));
    //data manage menu
    connect(ui->ImportData, SIGNAL(triggered()), this, SLOT(importDataActionTriggered()));
    //parameter menu
    connect(ui->ImportPara, SIGNAL(triggered()), this, SLOT(importParaActionTriggered()));
    //simulation menu
    connect(ui->CalculateSim, SIGNAL(triggered()), this, SLOT(calculateSimActionTriggered()));
    connect(ui->ShowSim, SIGNAL(triggered()), this, SLOT(showSimActionTriggered()));
    connect(ui->EvaluateSim, SIGNAL(triggered()), this, SLOT(evaluateSimActionTriggered()));
    //connect(ui->ReportSim, SIGNAL(triggered()), this, SLOT());

    //help menu
    connect(ui->About, SIGNAL(triggered()), this, SLOT(aboutActionTriggered()));


    //connect(this, SIGNAL(projectOpened()), this, SLOT(enableActions()));

    //object table

    QStandardItemModel *objectModel = new QStandardItemModel();
    objectModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("研究对象")));
    objectModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("当前数据集")));
    objectModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("数据状态")));
    objectModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("仿真结果状态")));
    ui->objectTable->setModel(objectModel);
    ui->objectTable->horizontalHeader()->setStretchLastSection(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableActions(){
    ui->AddObject->setEnabled(true);
    ui->SearchObject->setEnabled(true);
    ui->CloseProject->setEnabled(true);
    ui->ImportData->setEnabled(true);
    ui->ImportPara->setEnabled(true);
    ui->CalculatePara->setEnabled(true);
    ui->ShowSim->setEnabled(true);
    ui->EvaluateSim->setEnabled(true);

}
void MainWindow::addProjectActionTriggered()
{
    getUiManager()->active(UiManager::newProject);
    this->enableActions();
}

void MainWindow::openProjectActionTriggered()
{
    getUiManager()->active(UiManager::openProject);
    this->enableActions();
}

void MainWindow::searchObjectActionTriggered()
{
    getUiManager()->active(UiManager::searchObject);
}

void MainWindow::addObjectAcionTriggered(){
    ui->addObjectGroup->setVisible(true);
}

void MainWindow::quitActionTriggered(){
    this->close();
}
void MainWindow::importDataActionTriggered()
{
    getUiManager()->active(UiManager::importBasicData);
}

void MainWindow::importParaActionTriggered()
{
    getUiManager()->active(UiManager::importBasicPara);
}

void MainWindow::calculateSimActionTriggered()
{
    //do some calculate in the background
    getUiManager()->active(UiManager::enterCalculate);
}

void MainWindow::showSimActionTriggered()
{
    getUiManager()->active(UiManager::display);
}

void MainWindow::evaluateSimActionTriggered()
{
    getUiManager()->active(UiManager::evaluate);
}

void MainWindow::aboutActionTriggered()
{

}







