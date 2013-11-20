#ifndef IMPORTBASICDATA_H
#define IMPORTBASICDATA_H

#include <QDialog>
#include "uimanager.h"
namespace Ui {
class ImportBasicData;
}

class ImportBasicData : public QDialog
{
    Q_OBJECT

public:
    explicit ImportBasicData(QWidget *parent = 0);
    ~ImportBasicData();

private:
    Ui::ImportBasicData *ui;
    UiManager* uiManager;

private slots:
    void cancelButtonClicked();
};

#endif // IMPORTBASICDATA_H
