#ifndef EVALUATE_H
#define EVALUATE_H

#include <QDialog>
#include "uimanager.h"
namespace Ui {
class Evaluate;
}

class Evaluate : public QDialog, public UiItem
{
    Q_OBJECT

public:
    explicit Evaluate(QWidget *parent = nullptr);
    ~Evaluate();

private:
    Ui::Evaluate *ui;

private slots:
    void exitButtonClicked();
};

#endif // EVALUATE_H
