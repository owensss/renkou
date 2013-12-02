#include "addobject.h"

AddObject::AddObject(QWidget* parent):
    maxYear(2010), minYear(1980)
{
    QGridLayout *gridLayout = new QGridLayout(parent);
    QLabel *yearLabel = new QLabel("基年");
    gridLayout->addWidget(yearLabel, 0, 0);

    QComboBox *yearCombo = new QComboBox();
    QStringList yearList;
    for (int i = minYear; i<=maxYear; ++i){
        yearList.push_back(QString::number(i));
    }
    yearCombo->addItems(yearList);
    gridLayout->addWidget(yearCombo, 0, 1);

}

