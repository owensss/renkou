#include <QDebug>
#include "openproject.h"
#include "ui_openproject.h"

OpenProject::OpenProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenProject),
    uiManager(new UiManager())
{
    ui->setupUi(this);

    //connect(ui->leProjectPath, SIGNAL(textEdited(QString)), this, SLOT(openPathEdited(QString)));
    connect(ui->selectPath, SIGNAL(clicked()), this, SLOT(selectPathButtonClicked()));
    connect(ui->open, SIGNAL(clicked()), this, SLOT(openButtonClicked()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));


}

OpenProject::~OpenProject()
{
    delete ui;
    delete uiManager;
}

//void OpenProject::openPathEdited(QString _filename)
//{
//    _filename = _filename.simplified();
//    if( _filename.size() >0 ){
//        ui->open->setEnabled(true);
//    }
//    else {
//        ui->open->setEnabled(false);
//    }
//}

void OpenProject::selectPathButtonClicked()
{
    QFileDialog *openFilePath = new QFileDialog();
    if (openFilePath->exec() == QDialog::Accepted){
        QStringList *selectedfiles = new QStringList(openFilePath->selectedFiles());
        QChar tmp;
        QString tmpstr = "";
        for (int i=0; i<selectedfiles->size(); i++){
            if (i<selectedfiles->size()-1){
                tmp = ';';
            }
            else {
                tmp = ' ';
            }
            tmpstr = tmpstr + selectedfiles->at(i) + tmp;
        }
        if (tmpstr.size() > 0){
            ui->open->setEnabled(true);
            ui->leProjectPath->setText(tmpstr);
        }
        else{
            ui->open->setEnabled(false);
        }

        delete selectedfiles;
    }
    else {
        ///cancel
    }
    delete openFilePath;
}

void OpenProject::openButtonClicked()
{
    ///load the project
    qDebug()<<"open "<<ui->leProjectPath->text()<<endl;
    uiManager->disactive(UiManager::openProject);
}

void OpenProject::cancelButtonClicked()
{
    uiManager->disactive(UiManager::openProject);
}
