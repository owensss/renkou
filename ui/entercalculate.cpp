#include "entercalculate.h"
#include "ui_entercalculate.h"

EnterCalculate::EnterCalculate(QWidget *parent, UiManager *uiManager) :
    QDialog(parent),
    ui(new Ui::EnterCalculate),
    uiManager(uiManager)
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
