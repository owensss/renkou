#ifndef LINETYPE3_H
#define LINETYPE3_H

#include <QWidget>
#include <QStateMachine>
#include "FileInfo.h"
#include "Constants.h"

class Graph4DMap;
class QSlider;
class QTimer;
class QStateMachine;
class QState;
class QFinalState;

namespace Ui {
    class LineType3;
}

class LineType3 : public QWidget
{
    Q_OBJECT

public:
    static LineType3* makeLineType3(QVector<QString> curve, QVector<FileInfo> file, int sYear, int eYear, QWidget *parent=0)
    { return new LineType3(curve, file, sYear, eYear, parent);}

    ~LineType3();

public slots:
    void updateYear();
    void setShowFlag(int f){m_ShowFlag = f;}

signals:
    void upperbound();

private slots:
    void on_colorRadio_toggled(bool checked);
    void on_barRadio_toggled(bool checked);
    void on_comboBox_currentIndexChanged(int index);
    void on_back10YearButton_clicked();
    void on_advance10YearButton_clicked();
    void start();
    void pause();
    void stop();

private:
//    explicit LineType3(QWidget *parent=0);
    LineType3(QVector<QString> curve, QVector<FileInfo> file, int sYear, int eYear, QWidget *parent=0);
    QSlider *createSlider();
    void createStates();
    void createTransitions();
    void createConnections();
    void createGraphicsView(int sYear, int eYear);
    void initSideWidgets();

    int m_ShowFlag;

    Ui::LineType3 *ui;
    Graph4DMap *amap;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;

    QVector<QString> curves_;
    QVector<FileInfo> files_;
    QTimer *timer;

    QStateMachine stateMachine;
    QState *initialState;
    QState *normalState;
    QState *stoppedState;
    QState *runningState;
    QState *pausedState;
    QFinalState *finalState;
};

#endif // LINETYPE3_H
