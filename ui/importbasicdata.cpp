#include "importbasicdata.h"
#include "ui_importbasicdata.h"

ImportBasicData::ImportBasicData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportBasicData)
{
    ui->setupUi(this);
}

ImportBasicData::~ImportBasicData()
{
    delete ui;
}

void ImportBasicData::cancelButtonClicked()
{
    getUiManager()->disactive(UiManager::importBasicData);
}
