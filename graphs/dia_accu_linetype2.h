#ifndef DIA_ACCU_LINETYPE2_H
#define DIA_ACCU_LINETYPE2_H

#include <QDialog>

class LineType2;
namespace Ui {
    class Dia_Accu_LineType2;
}

class Dia_Accu_LineType2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dia_Accu_LineType2(LineType2 *parent = 0);
    ~Dia_Accu_LineType2();

private:
    Ui::Dia_Accu_LineType2 *ui;
    LineType2 *widget;

private slots:
    void on_CancelButton_clicked();
};

#endif // DIA_ACCU_LINETYPE2_H
