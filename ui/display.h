#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>

#include "uimanager.h"
namespace Ui {
class Display;
}

class Display : public QDialog
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr, UiManager *uiManager);
    ~Display();

private:
    Ui::Display *ui;
    UiManager *uiManager;
};

#endif // DISPLAY_H
