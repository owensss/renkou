#include "evaluate.h"
#include "ui_evaluate.h"

Evaluate::Evaluate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Evaluate),
    uiManager(new UiManager())
{
    ui->setupUi(this);

    connect(ui->exit, SIGNAL(clicked()), this, SLOT(exitButtonClicked()));

}

Evaluate::~Evaluate()
{
    delete ui;
    delete uiManager;
}

void Evaluate::exitButtonClicked()
{
    uiManager->disactive(UiManager::evaluate);
}
