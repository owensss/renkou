#ifndef DISPLAY_H
#define DISPLAY_H

#include <QDialog>
#include "uiitem.h"
namespace Ui {
class Display;
}

class Display : public QDialog, public UiItem
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

private:
    Ui::Display *ui;

//private slots:
//    void cancelButtonClicked();
};

#endif // DISPLAY_H
