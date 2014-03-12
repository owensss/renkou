#include <QDebug>
#include "searchobject.h"
#include "ui_searchobject.h"

SearchObject::SearchObject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchObject),
    maxYear(2010), minYear(1980)
{
    ui->setupUi(this);

    QStringList yearList;
    for (int i = minYear; i<=maxYear; i++){
        yearList.push_back(QString::number(i));
    }
    ui->comboYear->addItems(yearList);
    connect(ui->search, SIGNAL(clicked()), this, SLOT(searchButtonClicked()));
    connect(ui->ok, SIGNAL(clicked()), this, SLOT(okButtonClicked()));
    connect(ui->comboArea, SIGNAL(currentTextChanged(QString)), this, SLOT(areaComboChanged(QString)));
    connect(ui->comboYear, SIGNAL(currentTextChanged(QString)), this, SLOT(yearComboChanged(QString)));

}

SearchObject::~SearchObject()
{
    delete ui;
}

void SearchObject::areaComboChanged(QString s)
{

}

void SearchObject::yearComboChanged(QString s)
{
    s = s.simplified();
    if (s.size() > 0){
        bool flag;
        int year = s.toInt(&flag, 10);
        if (flag && year>=minYear && year<=maxYear){
            ui->search->setEnabled(true);
        }
        else ui->search->setEnabled(false);
    }
    else{
        ui->search->setEnabled(false);
    }
}

void SearchObject::okButtonClicked()
{
    getUiManager()->disactive(UiManager::searchObject);
}

void SearchObject::searchButtonClicked()
{
    QString year = ui->comboYear->currentText();
    QString area = ui->comboArea->currentText();
    qDebug()<<"  search  "<<endl<<"year: "<<year<<" area: "<<area<<endl;
}
