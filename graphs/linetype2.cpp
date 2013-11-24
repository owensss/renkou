#include <QTextCodec>
#include <QAbstractState>
#include <QGraphicsWidget>
#include <QDebug>
#include "math.h"
#include "qvalueboard.h"
#include "linetype2.h"
#include "ui_linetype2.h"
#include "graphmain_linetype2.h"
#include "dia_accu_linetype2.h"
#include "coloriconengine.h"
#include "Constants.h"

//#define DEBUG
#ifdef DEBUG
#define DEBUG_FILENAME
#endif

template <class LineType2>
const int Counted<LineType2>::maxObjects = 15;

LineType2::LineType2(QVector<QString> curve, QVector<FileInfo> file, int sYear, int eYear, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LineType2),
    m_CurveName(curve), m_File(file)
{
    ui->setupUi(this);
    createStates();
    createTransitions();
    createConnections();
    createGraphicsView(sYear, eYear);
    initSideWidgets();
    stateMachine.setInitialState(initialState);
    stateMachine.start();
    ui->radioCurve->setChecked(true);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateyear()));
}

LineType2::~LineType2()
{
    delete graph;
    delete scene;
    delete ui;
    delete initialState;
    delete runningState;
    delete pausedState;
    delete stoppedState;
    delete normalState;
    delete finalState;
    delete timer;
}

void LineType2::createStates()
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));

    //初始停止键不可用
    initialState = new QState(&stateMachine);
    initialState->assignProperty(ui->StopButton, "enabled", false);

    normalState = new QState(&stateMachine);
    //开始播放，开始键文字改为“暂停”，停止键可用
    runningState = new QState(normalState);
    runningState->assignProperty(ui->PlayButton, "text", tr("暂停"));
    runningState->assignProperty(ui->StopButton, "enabled", true);

    pausedState = new QState(normalState);
    pausedState->assignProperty(ui->PlayButton ,"text", tr("继续"));

    stoppedState = new QState(normalState);
    stoppedState->assignProperty(ui->PlayButton, "text", tr("开始"));
    stoppedState->assignProperty(ui->StopButton, "enabled", false);

    finalState = new QFinalState(&stateMachine);
}

void LineType2::createTransitions()
{
    initialState->addTransition(initialState, SIGNAL(propertiesAssigned()), stoppedState);
    runningState->addTransition(ui->PlayButton, SIGNAL(clicked()), pausedState);
    runningState->addTransition(ui->StopButton, SIGNAL(clicked()), stoppedState);
    runningState->addTransition(ui->Advance10Button, SIGNAL(clicked()), pausedState);
    runningState->addTransition(ui->Back10Button, SIGNAL(clicked()), pausedState);
    runningState->addTransition(ui->ViewDataButton, SIGNAL(clicked()), pausedState);
    pausedState->addTransition(ui->PlayButton, SIGNAL(clicked()), runningState);
    pausedState->addTransition(ui->StopButton, SIGNAL(clicked()), stoppedState);
    stoppedState->addTransition(ui->PlayButton, SIGNAL(clicked()), runningState);
    pausedState->addTransition(this, SIGNAL(upperbound()), stoppedState);
    runningState->addTransition(this, SIGNAL(upperbound()), stoppedState);
}

void LineType2::createConnections()
{
    connect(runningState, SIGNAL(entered()), this, SLOT(start()));
    connect(pausedState, SIGNAL(entered()), this, SLOT(pause()));
    connect(stoppedState, SIGNAL(entered()), this, SLOT(stop()));
}

void LineType2::pause()
{
    timer->stop();
    graph->setMoving(false);
    ui->VLineButton->setEnabled(true);
    ui->HLineButton->setEnabled(true);
    ui->DualLineButton->setEnabled(true);
}

void LineType2::start()
{
    if(graph->CurrentYear() == graph->getEndYear())
        graph->setYear(graph->getStartYear());
    timer->start(100);
    graph->setMoving(true);
    ui->VLineButton->setEnabled(false);
    ui->HLineButton->setEnabled(false);
    ui->DualLineButton->setEnabled(false);
}

void LineType2::stop()
{
    timer->stop();
    graph->setYear(graph->getStartYear());
    graph->setMoving(false);
    ui->VLineButton->setEnabled(true);
    ui->HLineButton->setEnabled(true);
    ui->DualLineButton->setEnabled(true);
}

void LineType2::createGraphicsView(int sYear, int eYear)
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));

    scene = new QGraphicsScene(ui->graphicsView);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    QStringList cur;
    for(int i=0; i<m_CurveName.size(); ++i)
        cur<<m_CurveName[i];
#ifdef DEBUG_FILENAME
    for(int i=0; i<m_File.size(); ++i)
        qDebug()<<m_File[i].m_FileName<<m_File[i].m_index;
#endif
    graph = new GraphMain_LineType2(this, cur, m_File, sYear, eYear);
    scene->addItem(graph);
    ui->graphicsView->setScene(scene);
    setLayout(ui->verticalLayout_Main);

    ui->comboBox->addItem(tr("更改年份"));
    int StartYear = graph->getStartYear();
    int FinalYear = graph->getEndYear();
    for(int k=StartYear; k<=FinalYear; k++)
        ui->comboBox->addItem(QString::number(k));

    m_Color[0] = RED;
    m_Color[1] = GREEN;
    m_Color[2] = BLUE;
    m_Color[3] = MAGENTA;
    m_Color[4] = DARKYELLOW;
    m_Color[5] = DARKRED;
    m_Color[6] = DARKGREEN;
    m_Color[7] = DARKBLUE;
    m_Color[8] = DARKMAGENTA;
    m_Color[9] = YELLOW;

    m_ValueBox = new QToolBox(this);
    for(int i=0; i<m_CurveName.size(); ++i){
        m_BLayout[i] = new QBoxLayout(QBoxLayout::TopToBottom, this);
        m_BLayout[i]->setSpacing(5);
        m_NameLabel[i] = new QLabel(tr("曲线名称"), this);
        m_BLayout[i]->addWidget(m_NameLabel[i]);
        m_NameEdit[i] = new QLineEdit(this);
        m_NameEdit[i]->setText(m_CurveName[i]);
        m_NameEdit[i]->setReadOnly(true);
        m_BLayout[i]->addWidget(m_NameEdit[i]);
        m_MaxLabel[i] = new QLabel(tr("最多人口"), this);
        m_BLayout[i]->addWidget(m_MaxLabel[i]);
        m_MaxEdit[i] = new QLineEdit(this);
        m_MaxEdit[i]->setReadOnly(true);
        m_BLayout[i]->addWidget(m_MaxEdit[i]);
        m_MinLabel[i] = new QLabel(tr("最少人口"), this);
        m_BLayout[i]->addWidget(m_MinLabel[i]);
        m_MinEdit[i] = new QLineEdit(this);
        m_MinEdit[i]->setReadOnly(true);
        m_BLayout[i]->addWidget(m_MinEdit[i]);
        m_AveLabel[i] = new QLabel(tr("平均年龄"), this);
        m_BLayout[i]->addWidget(m_AveLabel[i]);
        m_AveEdit[i] = new QLineEdit(this);
        m_AveEdit[i]->setReadOnly(true);
        m_BLayout[i]->addWidget(m_AveEdit[i]);
        m_MidLabel[i] = new QLabel(tr("中位年龄"), this);
        m_BLayout[i]->addWidget(m_MidLabel[i]);
        m_MidEdit[i] = new QLineEdit(this);
        m_MidEdit[i]->setReadOnly(true);
        m_BLayout[i]->addWidget(m_MidEdit[i]);
        m_bkgdWidget[i] = new QWidget(this);
        m_bkgdWidget[i]->setLayout(m_BLayout[i]);
        m_ValueBox->addItem(m_bkgdWidget[i], tr("年龄金字塔")+QString::number(i+1));
        m_ValueBox->setItemIcon(i, QIcon(new ColorIconEngine(m_Color[i])));
    }
    m_OuterLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    m_OuterLayout->setMargin(5);
//    m_OuterLayout->setSpacing(5);
    m_OuterLayout->addWidget(m_ValueBox);
    ui->groupBox->setLayout(m_OuterLayout);
    connect(m_ValueBox, SIGNAL(currentChanged(int)), this, SLOT(setChosen(int)));
}

void LineType2::on_Advance10Button_clicked()
{
    int Year;
    Year = graph->CurrentYear()+10;
    if(Year > graph->getEndYear()){
        Year = graph->getEndYear();
        emit upperbound();
    }
    graph->setYear(Year);
}

void LineType2::on_Back10Button_clicked()
{
    int Year;
    Year = graph->CurrentYear()-10;
    if(Year < graph->getStartYear())
        Year = graph->getStartYear();
    graph->setYear(Year);
}

void LineType2::updateyear()
{
    int Year;
    Year = graph->CurrentYear()+1;
    if(Year > graph->getEndYear()){
        Year = graph->getEndYear();
        emit upperbound();
    }
    graph->setYear(Year);
}

void LineType2::setText(int n, QString s)
{/*
    switch(n){
    case 1:ui->Value_1->setText(s);break;
    case 2:ui->Value_2->setText(s);break;
    case 3:ui->Value_3->setText(s);break;
    case 4:ui->Value_4->setText(s);break;
    case 5:ui->Value_5->setText(s);break;
    }*/
}

int LineType2::graphType()
{
    if(ui->radioBar->isChecked())
        return 1;
    return 0;
}

void LineType2::on_radioCurve_clicked()
{
    //变相更新曲线类型
    graph->setYear(graph->CurrentYear());
}


void LineType2::on_radioBar_clicked()
{
    //变相更新曲线类型
    graph->setYear(graph->CurrentYear());
}

void LineType2::on_checkBox_toggled(bool checked)
{
    graph->setShowData(checked);
    graph->setYear(graph->CurrentYear());
}

void LineType2::on_ViewDataButton_clicked()
{
    CancelLines();
    Dia_Accu_LineType2 *dialog = new Dia_Accu_LineType2(this);
    dialog->exec();
}

void LineType2::on_radioCurve_toggled(bool checked)
{
    if(checked)
        ui->checkBox->setEnabled(true);
    else
        ui->checkBox->setEnabled(false);
}

void LineType2::on_VLineButton_toggled(bool checked)
{
    graph->HLineEnabled(!checked);
    graph->VLineEnabled(checked);
}


void LineType2::on_HLineButton_toggled(bool checked)
{
    graph->HLineEnabled(checked);
    graph->VLineEnabled(!checked);
}

void LineType2::on_DualLineButton_toggled(bool checked)
{
    graph->HLineEnabled(checked);
    graph->VLineEnabled(checked);
}

void LineType2::Xvalue(QString x)
{
    long population = x.toLong();
    if(ui->HLineButton->isChecked() || ui->DualLineButton->isChecked())
        ui->DualLineButton->setChecked(true);
    else
        ui->VLineButton->setChecked(true);
    graph->setVLine(population);
}

void LineType2::Yvalue(QString y)
{
    int age = y.toInt();
    if(ui->VLineButton->isChecked() || ui->DualLineButton->isChecked())
        ui->DualLineButton->setChecked(true);
    else
        ui->HLineButton->setChecked(true);
    graph->setHLine(age);
}

void LineType2::CancelLines()
{
    graph->HLineEnabled(false);
    graph->VLineEnabled(false);/*
    ui->HLineButton->setAutoExclusive(false);
    ui->VLineButton->setAutoExclusive(false);
    ui->DualLineButton->setAutoExclusive(false);
    ui->HLineButton->setChecked(false);
    ui->VLineButton->setChecked(false);
    ui->DualLineButton->setChecked(false);
    ui->HLineButton->setAutoExclusive(true);
    ui->VLineButton->setAutoExclusive(true);
    ui->DualLineButton->setAutoExclusive(true);
    */
    ui->NoLineButton->setChecked(true);
}

void LineType2::on_comboBox_currentIndexChanged(QString t)
{
    if(ui->comboBox->currentIndex()!=0)
        graph->setYear(t.toInt());
}

void LineType2::on_NoLineButton_toggled(bool checked)
{
    graph->HLineEnabled(!checked);
    graph->VLineEnabled(!checked);
}

void LineType2::initSideWidgets()
{
    ui->radioCurve->setChecked(true);
    ui->radioBar->setChecked(false);

    ui->NoLineButton->setChecked(true);
    ui->VLineButton->setChecked(false);
    ui->HLineButton->setChecked(false);
    ui->DualLineButton->setChecked(false);
}

void LineType2::setEditText(int line, int culumn, QString s)
{
    switch(culumn){
    case 1:m_MaxEdit[line]->setText(s);break;
    case 2:m_MinEdit[line]->setText(s);break;
    case 3:m_AveEdit[line]->setText(s);break;
    case 4:m_MidEdit[line]->setText(s);break;
    }
}

void LineType2::addGrpahicsLabel(QPointF point, QString content, QColor color)
{
    double length = 5;
    double angle = Pi * 0.5;
    QValueBoard *datalabel = new QValueBoard(content, length*cos(angle), length*sin(angle), color);
    scene->addItem(datalabel);
    datalabel->setPos(point);
    for(size_t i=0; i<board.size(); i++){
        while(datalabel->collidesWithItem(board[i])){
            for(;datalabel->collidesWithItem(board[i])&&angle<2.5*Pi; angle+=Pi/6){
               datalabel->SetDx(length*cos(angle));
               datalabel->SetDy(length*sin(angle));
            }
            angle = Pi*0.5;
            length += 10;
        }
    }
    board.push_back(datalabel);
}

void LineType2::deleteqvalueboard()
{
    QValueBoard *t;
    while(!board.empty()){
        t = board.back();
        board.pop_back();
        scene->removeItem(t);
    }
}

void LineType2::setChosen(int chosen)
{
    graph->setChosen(chosen);
    //Update
    graph->setYear(graph->CurrentYear());
}
