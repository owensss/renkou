#include "dia_accu_linetype1.h"
#include "ui_dia_accu_linetype1.h"
#include "linetype1.h"

Dia_Accu_LineType1::Dia_Accu_LineType1(LineType1 *parent) :
    widget(parent),
    ui(new Ui::Dia_Accu_LineType1)
{
    ui->setupUi(this);
    connect(ui->X_Data,SIGNAL(textChanged(QString)), widget, SLOT(Xvalue(QString)));
    connect(ui->Y_Data,SIGNAL(textChanged(QString)), widget, SLOT(Yvalue(QString)));
}

Dia_Accu_LineType1::~Dia_Accu_LineType1()
{
    delete ui;
}

void Dia_Accu_LineType1::on_CancelButton_clicked()
{
    widget->CancelLines();
    close();
}
