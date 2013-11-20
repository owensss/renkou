#include "importbasicpara.h"
#include "ui_importbasicpara.h"

ImportBasicPara::ImportBasicPara(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportBasicPara)
{
    ui->setupUi(this);

    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));

}

ImportBasicPara::~ImportBasicPara()
{
    delete ui;
    delete uiManager;
}

void ImportBasicPara::cancelButtonClicked()
{
    uiManager->disactive(UiManager::importBasicPara);
}
