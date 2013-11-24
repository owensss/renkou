#ifndef LINETYPE2_H
#define LINETYPE2_H

#include <QState>
#include <QFinalState>
#include <QWidget>
#include <QStateMachine>
#include <QGraphicsScene>
#include <QTimer>
#include <QVector>
#include <QToolBox>
#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "Objectcounter.h"
#include "FileInfo.h"
#define MaxLine 10
class GraphMain_LineType2;
class QValueBoard;

namespace Ui {
    class LineType2;
}

class LineType2 : public QWidget, private Counted<LineType2>
{
    Q_OBJECT
public:
    using Counted<LineType2>::objectCount;
    using Counted<LineType2>::TooManyObjects;

    static LineType2* makeLineType2(QVector<QString> curve, QVector<FileInfo> file, int sYear, int eYear, QWidget *parent=0)
    { return new LineType2(curve, file, sYear, eYear, parent);}
    ~LineType2();
    void setText(int n, QString s);
    int graphType();
    void CancelLines();
    void setEditText(int line, int culumn, QString s);
    void addGrpahicsLabel(QPointF point, QString content, QColor color);
    void deleteqvalueboard();
public slots:
    void setShowFlag(int f){m_ShowFlag = f;}

private:
    LineType2(QVector<QString> curve, QVector<FileInfo> file, int sYear, int eYear, QWidget *parent = 0);
    void createStates();
    void createTransitions();
    void createConnections();
    void createGraphicsView(int sYear, int eYear);
    void initSideWidgets();

signals:
    void upperbound();
private slots:
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
    Ui::LineType2 *ui;
    QGraphicsScene *scene;
    GraphMain_LineType2 *graph;
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
    QVector<QValueBoard*> board;

    int t_StartYear;
    int t_EndYear;

    QToolBox *m_ValueBox;
    QBoxLayout *m_BLayout[MaxLine];
    QBoxLayout *m_OuterLayout;
    QLabel *m_MaxLabel[MaxLine];
    QLineEdit *m_MaxEdit[MaxLine];
    QLabel *m_MinLabel[MaxLine];
    QLineEdit *m_MinEdit[MaxLine];
    QLabel *m_AveLabel[MaxLine];
    QLineEdit *m_AveEdit[MaxLine];
    QLabel *m_MidLabel[MaxLine];
    QLineEdit *m_MidEdit[MaxLine];
    QWidget *m_bkgdWidget[MaxLine];
    QLabel  *m_NameLabel[MaxLine];
    QLineEdit *m_NameEdit[MaxLine];
    QColor m_Color[MaxLine];    //鏁版嵁鏍忔瘡椤圭殑鍥炬爣棰滆壊
};

#endif // LINETYPE2_H
