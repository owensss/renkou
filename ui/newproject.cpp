#include "newproject.h"
#include "ui_newproject.h"

NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject),
    uiManager(new UiManager())
{
    ui->setupUi(this);

}

NewProject::~NewProject()
{
    delete ui;
    delete uiManager;
}
