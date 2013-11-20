#ifndef EVALUATE_H
#define EVALUATE_H

#include <QDialog>
#include "uimanager.h"
namespace Ui {
class Evaluate;
}

class Evaluate : public QDialog
{
    Q_OBJECT

public:
    explicit Evaluate(QWidget *parent = 0);
    ~Evaluate();

private:
    Ui::Evaluate *ui;
    UiManager *uiManager;

private slots:
    void exitButtonClicked();
};

#endif // EVALUATE_H
