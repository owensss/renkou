#include "dia_accu_linetype2.h"
#include "ui_dia_accu_linetype2.h"
#include "linetype2.h"

Dia_Accu_LineType2::Dia_Accu_LineType2(LineType2 *parent) :
    ui(new Ui::Dia_Accu_LineType2)
{
    ui->setupUi(this);
    widget = parent;
    connect(ui->X_Data,SIGNAL(textChanged(QString)), widget, SLOT(Xvalue(QString)));
    connect(ui->Y_Data,SIGNAL(textChanged(QString)), widget, SLOT(Yvalue(QString)));
}

Dia_Accu_LineType2::~Dia_Accu_LineType2()
{
    delete ui;
}

void Dia_Accu_LineType2::on_CancelButton_clicked()
{
    widget->CancelLines();
    close();
}

