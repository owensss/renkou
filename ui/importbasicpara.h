#ifndef IMPORTBASICPARA_H
#define IMPORTBASICPARA_H

#include <QDialog>
#include "uimanager.h"

namespace Ui {
class ImportBasicPara;
}

class ImportBasicPara : public QDialog
{
    Q_OBJECT

public:
    explicit ImportBasicPara(QWidget *parent = 0);
    ~ImportBasicPara();

private:
    Ui::ImportBasicPara *ui;
    UiManager* uiManager;

private slots:
    void cancelButtonClicked();
};

#endif // IMPORTBASICPARA_H
