#ifndef LINETYPE1_H
#define LINETYPE1_H

#include <QState>
#include <QFinalState>
#include <QWidget>
#include <QStateMachine>
#include <QGraphicsScene>
#include <QTimer>
#include <QLineEdit>
#include <QLabel>
#include <QBoxLayout>
#include <QToolBox>
#include "vector"
#include "Objectcounter.h"
#include "FileInfo.h"

#define MaxLine 10
using namespace std;

class GraphMain_LineType1;
class QValueBoard;

namespace Ui {
    class LineType1;
}

class LineType1 : public QWidget, private Counted<LineType1>
{
    Q_OBJECT
public:
    using Counted<LineType1>::objectCount;
    using Counted<LineType1>::TooManyObjects;

    static LineType1* makeLineType1(QVector<QString> curve, QVector<FileInfo> file, int sYear, int eYear, QWidget *parent=0)
    { return new LineType1(curve, file, sYear, eYear, parent);}
    ~LineType1();
    void setText(int n, QString s);
    int graphType();
    void CancelLines();
    void setEditText(int line, int culumn, QString s);
    void addGrpahicsLabel(QPointF point, QString content, QColor color);
    void deleteqvalueboard();
public slots:
    void setShowFlag(int f);

private:
    LineType1(QVector<QString> curve, QVector<FileInfo> file, int sYear, int eYear, QWidget* parent=0);
    void createStates();
    void createTransitions();
    void createConnections();
    void createGraphicsView(int sYear, int eYear);
    void initSideWidgets();

signals:
    void upperbound();
private slots:
    void on_radio3DBar_clicked();
    void on_NoLineButton_toggled(bool checked);
    void on_comboBox_currentIndexChanged(QString );
    void on_DualLineButton_toggled(bool checked);
    void on_HLineButton_toggled(bool checked);
    void on_VLineButton_toggled(bool checked);
    void on_radioCurve_toggled(bool checked);
    void on_ViewDataButton_clicked();
    void on_checkBox_toggled(bool checked);
    void on_radioBar_clicked();
    void on_radioCurve_clicked();
    void on_Back10Button_clicked();
    void on_Advance10Button_clicked();
    void start();
    void pause();
    void stop();
    void updateyear();
    void Xvalue(QString x);
    void Yvalue(QString y);
    void setChosen(int chosen);

private:
    Ui::LineType1 *ui;
    QGraphicsScene *scene;
    GraphMain_LineType1 *graph;
    QTimer *timer;
    int m_ShowFlag;
    QVector<QString> m_CurveName;
    QVector<FileInfo> m_File;

    QStateMachine stateMachine;
    QState *initialState;
    QState *normalState;
    QState *stoppedState;
    QState *runningState;
    QState *pausedState;
    QFinalState *finalState;
    vector<QValueBoard *> board;

    QToolBox *m_ValueBox;
    QBoxLayout *m_BLayout[MaxLine];
    QLabel *m_MaxLabel[MaxLine];
    QLineEdit *m_MaxEdit[MaxLine];
    QLabel *m_MinLabel[MaxLine];
    QLineEdit *m_MinEdit[MaxLine];
    QLabel *m_AveLabel[MaxLine];
    QLineEdit *m_AveEdit[MaxLine];
    QLabel  *m_NameLabel[MaxLine];
    QLineEdit *m_NameEdit[MaxLine];
    QWidget *m_bkgdWidget[MaxLine];
    QColor m_Color[MaxLine];    //鏁版嵁鏍忔瘡椤圭殑鍥炬爣棰滆壊
};



#endif // LINETYPE1_H
