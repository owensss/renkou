#ifndef IMPORTBASICDATA_H
#define IMPORTBASICDATA_H

#include <QDialog>
#include "uimanager.h"
namespace Ui {
class ImportBasicData;
}

class ImportBasicData : public QDialog, public UiItem
{
    Q_OBJECT

public:
    explicit ImportBasicData(QWidget *parent = nullptr);
    ~ImportBasicData();

private:
    Ui::ImportBasicData *ui;

private slots:
    void cancelButtonClicked();
};

#endif // IMPORTBASICDATA_H
