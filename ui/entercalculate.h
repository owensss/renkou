#ifndef ENTERCACULATE_H
#define ENTERCACULATE_H

#include <QDialog>
#include "uimanager.h"
namespace Ui {
class EnterCalculate;
}

class EnterCalculate : public QDialog, public UiItem
{
    Q_OBJECT

public:
    explicit EnterCalculate(QWidget *parent = nullptr);
    ~EnterCalculate();

private:
    Ui::EnterCalculate *ui;

private slots:
    void cancelButtonClicked();
};

#endif // ENTERCACULATE_H
