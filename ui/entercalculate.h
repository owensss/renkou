#ifndef ENTERCACULATE_H
#define ENTERCACULATE_H

#include <QDialog>
#include "uimanager.h"
namespace Ui {
class EnterCalculate;
}

class EnterCalculate : public QDialog
{
    Q_OBJECT

public:
    explicit EnterCalculate(QWidget *parent = 0);
    ~EnterCalculate();

private:
    Ui::EnterCalculate *ui;
    UiManager *uiManager;

private slots:
    void cancelButtonClicked();
};

#endif // ENTERCACULATE_H
