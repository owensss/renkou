#include "display.h"
#include "ui_display.h"

Display::Display(QWidget *parent, UiManager *uiManager) :
    QDialog(parent),
    ui(new Ui::Display),
    uiManager(uiManager)
{
    ui->setupUi(this);
}

Display::~Display()
{
    delete ui;
}
