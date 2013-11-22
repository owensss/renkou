#include "evaluate.h"
#include "ui_evaluate.h"

Evaluate::Evaluate(QWidget *parent, UiManager *uiManager) :
    QDialog(parent),
    ui(new Ui::Evaluate),
    uiManager(uiManager)
{
    ui->setupUi(this);

    connect(ui->exit, SIGNAL(clicked()), this, SLOT(exitButtonClicked()));

}

Evaluate::~Evaluate()
{
    delete ui;
}

void Evaluate::exitButtonClicked()
{
    uiManager->disactive(UiManager::evaluate);
}
