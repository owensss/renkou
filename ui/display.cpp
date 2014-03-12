#include "display.h"
#include "ui_display.h"

Display::Display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);

}

Display::~Display()
{
    delete ui;
}
