#include "newproject.h"
#include "ui_newproject.h"

NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject),
    uiManager(new UiManager())
{
    ui->setupUi(this);

    connect(ui->leProjectName, SIGNAL(textEdited(QString)), this, SLOT(projectNameEdited(QString)));
    connect(ui->leSavePath, SIGNAL(textEdited(QString)), this, SLOT(savePahtEdited(QString)));
    connect(ui->selectPath, SIGNAL(clicked()), this, SLOT(selectPathButtonClicked()));

    connect(ui->ok, SIGNAL(clicked()), this, SLOT(okButtonClicked()));
    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));

}

NewProject::~NewProject()
{
    delete ui;
    delete uiManager;
}

void NewProject::projectNameEdited(QString _filename)
{
    ///Returns a string that has all whitespace removed
    ///and that has each sequence of internal whitespace
    ///replaced with a single space.
    _filename = _filename.simplified();
    if ( _filename.size()>0 ){
        ui->ok->setEnabled(true);
        ui->leSavePath->setEnabled(true);
        ui->selectPath->setEnabled(true);
    }
    else{
        ui->ok->setEnabled(false);
        ui->leSavePath->setEnabled(false);
        ui->selectPath->setEnabled(false);
    }
}

void NewProject::savePathEdited(QString _filename)
{
    _filename = _filename.simplified();
    if (_filename.size()>0){
        ui->ok->setEnabled(true);
    }
    else{
        ui->ok->setEnabled(false);
    }

}
void NewProject::selectPathButtonClicked()
{
    QFileDialog *openFilePath = new QFileDialog();

    openFilePath->setFileMode(QFileDialog::DirectoryOnly);
    openFilePath->setOptions(QFileDialog::ShowDirsOnly);

    if (openFilePath->exec() == QDialog::Accepted){
        QDir *openDir = new QDir(openFilePath->directory());
        ui->leSavePath->setText(openDir->absolutePath());

        delete openDir;
    }
    delete openFilePath;
}

void NewProject::okButtonClicked()
{
    QDir *openDir = new QDir(ui->leSavePath->text());
    if (openDir->exists()){
        ///create the new project in the background

        uiManager->disactive(UiManager::newProject);
    }
    else {
        QMessageBox* message = new QMessageBox(QMessageBox::Critical,"错误","当前输入的路径不存在!请重新输入");
        message->addButton("确定", QMessageBox::AcceptRole);
        if (message->exec() == QMessageBox::AcceptRole){
            ///if we can new a directory
        }
        delete message;
    }
}

void NewProject::cancelButtonClicked()
{
    uiManager->disactive(UiManager::newProject);
}
