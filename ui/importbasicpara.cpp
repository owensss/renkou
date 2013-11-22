#include "importbasicpara.h"
#include "ui_importbasicpara.h"

ImportBasicPara::ImportBasicPara(QWidget *parent, UiManager *uiManager) :
    QDialog(parent),
    ui(new Ui::ImportBasicPara),
    uiManager(uiManager)
{
    ui->setupUi(this);

    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));

}

ImportBasicPara::~ImportBasicPara()
{
    delete ui;
}

void ImportBasicPara::cancelButtonClicked()
{
    uiManager->disactive(UiManager::importBasicPara);
}
