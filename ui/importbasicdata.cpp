#include "importbasicdata.h"
#include "ui_importbasicdata.h"

ImportBasicData::ImportBasicData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportBasicData),
    uiManager(new UiManager())
{
    ui->setupUi(this);
}

ImportBasicData::~ImportBasicData()
{
    delete ui;
    delete uiManager;
}

void ImportBasicData::cancelButtonClicked()
{
    uiManager->disactive(UiManager::importBasicData);
}
