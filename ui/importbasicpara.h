#ifndef IMPORTBASICPARA_H
#define IMPORTBASICPARA_H

#include <QDialog>
#include "uiitem.h"

namespace Ui {
class ImportBasicPara;
}

class ImportBasicPara : public QDialog, public UiItem
{
    Q_OBJECT

public:
    explicit ImportBasicPara(QWidget *parent = nullptr);
    ~ImportBasicPara();

private:
    Ui::ImportBasicPara *ui;

private slots:
    void cancelButtonClicked();
};

#endif // IMPORTBASICPARA_H
