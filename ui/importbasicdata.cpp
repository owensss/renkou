#include "importbasicdata.h"
#include "ui_importbasicdata.h"

ImportBasicData::ImportBasicData(QWidget *parent, UiManager *uiManager) :
    QDialog(parent),
    ui(new Ui::ImportBasicData),
    uiManager(uiManager)
{
    ui->setupUi(this);
}

ImportBasicData::~ImportBasicData()
{
    delete ui;
}

void ImportBasicData::cancelButtonClicked()
{
    uiManager->disactive(UiManager::importBasicData);
}
