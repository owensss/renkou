#include "entercalculate.h"
#include "ui_entercalculate.h"

EnterCalculate::EnterCalculate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterCalculate)
{
    ui->setupUi(this);

    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
}

EnterCalculate::~EnterCalculate()
{
    delete ui;
}

void EnterCalculate::cancelButtonClicked()
{
    getUiManager()->disactive(UiManager::enterCalculate);
}
