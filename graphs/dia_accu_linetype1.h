#ifndef DIA_ACCU_LINETYPE1_H
#define DIA_ACCU_LINETYPE1_H

#include <QDialog>
class LineType1;
namespace Ui {
    class Dia_Accu_LineType1;
}

class Dia_Accu_LineType1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dia_Accu_LineType1(LineType1 *parent = 0);
    ~Dia_Accu_LineType1();

private:
    Ui::Dia_Accu_LineType1 *ui;
    LineType1 *widget;

private slots:
    void on_CancelButton_clicked();
};


#endif // DIA_ACCU_LINETYPE1_H
