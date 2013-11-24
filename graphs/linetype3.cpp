#include <QtGui>
#include "graph4dmap.h"
#include "linetype3.h"
#include "ui_linetype3.h"

LineType3::LineType3(QVector<QString> curve, QVector<FileInfo> file, int sYear, int eYear, QWidget *parent):
        QWidget(parent),
        ui(new Ui::LineType3)
{
    ui->setupUi(this);
    this->curves_ = curve;
    this->files_ = file;
    createStates();
    createTransitions();
    createConnections();
    createGraphicsView(sYear, eYear);
    initSideWidgets();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateYear()));

    stateMachine.setInitialState(initialState);
    stateMachine.start();

//    ui->layoutWidget->hide();   //虽然不知道为什么
}

LineType3::~LineType3()
{
    delete ui;
}

void LineType3::createStates()
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));

    //初始停止键不可用
    initialState = new QState(&stateMachine);
    initialState->assignProperty(ui->stopButton, "enabled", false);

    normalState = new QState(&stateMachine);
    //开始播放，开始键文字改为“暂停”，停止键可用
    runningState = new QState(normalState);
    runningState->assignProperty(ui->playButton, "text", tr("暂停"));
    runningState->assignProperty(ui->stopButton, "enabled", true);

    pausedState = new QState(normalState);
    pausedState->assignProperty(ui->playButton ,"text", tr("继续"));

    stoppedState = new QState(normalState);
    stoppedState->assignProperty(ui->playButton, "text", tr("开始"));
    stoppedState->assignProperty(ui->stopButton, "enabled", false);

    finalState = new QFinalState(&stateMachine);
}

void LineType3::createConnections()
{
    connect(runningState, SIGNAL(entered()), this, SLOT(start()));
    connect(pausedState, SIGNAL(entered()), this, SLOT(pause()));
    connect(stoppedState, SIGNAL(entered()), this, SLOT(stop()));
}

void LineType3::pause()
{
    timer->stop();
//    graph->setMoving(false);
//    ui->VLineButton->setEnabled(true);
//    ui->HLineButton->setEnabled(true);
//    ui->DualLineButton->setEnabled(true);
//    ui->ViewDataButton->setEnabled(true);
}

void LineType3::start()
{
    if(amap->getCurrentYear() == amap->getEndYear())
        amap->setCurrentYear(amap->getStartYear());
    timer->start(100);
//    ui->VLineButton->setEnabled(false);
//    ui->HLineButton->setEnabled(false);
//    ui->DualLineButton->setEnabled(false);
//    ui->ViewDataButton->setEnabled(false);
}

void LineType3::stop()
{
    timer->stop();
    amap->setCurrentYear(amap->getStartYear());
//    graph->setMoving(false);
//    ui->VLineButton->setEnabled(true);
//    ui->HLineButton->setEnabled(true);
//    ui->DualLineButton->setEnabled(true);
//    ui->ViewDataButton->setEnabled(true);
}

void LineType3::createTransitions()
{
    initialState->addTransition(initialState, SIGNAL(propertiesAssigned()), stoppedState);
    runningState->addTransition(ui->playButton, SIGNAL(clicked()), pausedState);
    runningState->addTransition(ui->stopButton, SIGNAL(clicked()), stoppedState);
    runningState->addTransition(ui->advance10YearButton, SIGNAL(clicked()), pausedState);
    runningState->addTransition(ui->back10YearButton, SIGNAL(clicked()), pausedState);
//    runningState->addTransition(ui->ViewDataButton, SIGNAL(clicked()), pausedState);
    pausedState->addTransition(ui->playButton, SIGNAL(clicked()), runningState);
    pausedState->addTransition(ui->stopButton, SIGNAL(clicked()), stoppedState);
    stoppedState->addTransition(ui->playButton, SIGNAL(clicked()), runningState);
    pausedState->addTransition(this, SIGNAL(upperbound()), stoppedState);
    runningState->addTransition(this, SIGNAL(upperbound()), stoppedState);
}

void LineType3::createGraphicsView(int sYear, int eYear)
{
    QStringList cur;
    for(int i=0; i<this->curves_.size(); ++i)
        cur<<this->curves_[i];

    amap = new Graph4DMap(cur, this->files_, sYear, eYear, this);

    xSlider = createSlider();
    ySlider = createSlider();
    zSlider = createSlider();

    connect(xSlider, SIGNAL(valueChanged(int)), amap, SLOT(setXRotation(int)));
    connect(ySlider, SIGNAL(valueChanged(int)), amap, SLOT(setYRotation(int)));
    connect(zSlider, SIGNAL(valueChanged(int)), amap, SLOT(setZRotation(int)));

    ui->horizontalLayout_2->addWidget(amap);
    ui->horizontalLayout_2->addWidget(xSlider);
    ui->horizontalLayout_2->addWidget(ySlider);
    ui->horizontalLayout_2->addWidget(zSlider);
    ui->horizontalLayout_2->setSpacing(10);
    ui->horizontalLayout_2->setMargin(10);
//    ui->widget->setLayout(ui->layout_graph);

    setLayout(ui->verticalLayout_main);

    xSlider->setValue(30 * 16);
    ySlider->setValue(0 * 16);
    zSlider->setValue(0 * 16);
    setWindowTitle(tr("Hello GL"));
}

void LineType3::initSideWidgets()
{
    int StartYear = amap->getStartYear();
    int EndYear = amap->getEndYear();
    ui->comboBox->addItem(tr("更改年份"));
    for(int k=StartYear; k<=EndYear; k++)
        ui->comboBox->addItem(QString::number(k));

    //默认使用柱状模式
    ui->barRadio->setChecked(true);
}

QSlider* LineType3::createSlider()
{
    QSlider *slider = new QSlider(Qt::Vertical);
    slider->setRange(0, 360*16);
    slider->setSingleStep(8);
    slider->setPageStep(15*16);
    slider->setTickInterval(15*16);
    slider->setTickPosition(QSlider::TicksRight);
    return slider;
}

void LineType3::updateYear()
{
    int cy = amap->getCurrentYear() + 1;
    if(cy > amap->getEndYear()){
        emit upperbound();
    }else if(cy < amap->getStartYear()){
        amap->setCurrentYear(amap->getStartYear());
        amap->update();
    }else{
        amap->setCurrentYear(cy);
        amap->update();
    }
}

void LineType3::on_advance10YearButton_clicked()
{
    int year = amap->getCurrentYear() + 10;
    if(year >= amap->getEndYear()){
        year = amap->getEndYear();
        emit upperbound();
    }
    amap->setCurrentYear(year);
    amap->update();
}


void LineType3::on_back10YearButton_clicked()
{
    int year = amap->getCurrentYear() - 10;
    year = qMax(year, amap->getStartYear());
    amap->setCurrentYear(year);
    amap->update();
}

void LineType3::on_comboBox_currentIndexChanged(int index)
{
    if(index != 0){
        amap->setCurrentYear(ui->comboBox->itemText(index).toInt());
        amap->update();
    }
}

void LineType3::on_barRadio_toggled(bool checked)
{
    if(checked){
        amap->setMapViewType(bar);
        this->xSlider->setValue(2*15*16);
    }
}

void LineType3::on_colorRadio_toggled(bool checked)
{
    if(checked){
        amap->setMapViewType(color);
        this->xSlider->setValue(6*15*16);
    }
}
