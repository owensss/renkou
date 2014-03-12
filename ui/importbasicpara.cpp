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
}

void ImportBasicPara::cancelButtonClicked()
{
    getUiManager()->disactive(UiManager::importBasicPara);
}
