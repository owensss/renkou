#ifndef ADDOBJECT_H
#define ADDOBJECT_H

#include <Qtwidgets/QLabel>
#include <Qtwidgets/QComboBox>
#include <Qtwidgets/QPushButton>
#include <Qtwidgets/QGridLayout>
#include <QStringList>

class AddObject
{
public:
    AddObject(QWidget *parent);
private:
    const int minYear;
    const int maxYear;
};

#endif // ADDOBJECT_H
