#ifndef SEARCHOBJECT_H
#define SEARCHOBJECT_H

#include <QDialog>
#include <QString>
#include <QComboBox>
#include <QStringList>

#include "uimanager.h"
namespace Ui {
class SearchObject;
}

class SearchObject : public QDialog
{
    Q_OBJECT

public:
    explicit SearchObject(QWidget *parent = 0);
    ~SearchObject();

private:
    Ui::SearchObject *ui;
    UiManager *uiManager;
    const int maxYear;
    const int minYear;

private slots:
    void areaComboChanged(QString s);
    void yearComboChanged(QString s);
    void okButtonClicked();
    void searchButtonClicked();
};

#endif // SEARCHOBJECT_H
