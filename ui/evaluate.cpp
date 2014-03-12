#include "evaluate.h"
#include "ui_evaluate.h"

Evaluate::Evaluate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Evaluate)
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
    getUiManager()->disactive(UiManager::evaluate);
}
