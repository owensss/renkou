#include "entercalculate.h"
#include "ui_entercalculate.h"

EnterCalculate::EnterCalculate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterCalculate),
    uiManager(new UiManager())
{
    ui->setupUi(this);

    connect(ui->cancel, SIGNAL(clicked()), this, SLOT(cancelButtonClicked()));
}

EnterCalculate::~EnterCalculate()
{
    delete ui;
    delete uiManager;
}

void EnterCalculate::cancelButtonClicked()
{
    uiManager->disactive(UiManager::enterCalculate);
}
