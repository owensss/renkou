#include <QObject>
#include <QLine>
#include <QFont>
#include <QTextStream>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QLinearGradient>
#include <QGraphicsOpacityEffect>
#include <QTextCodec>
#include <QMessageBox>
#include <QPainter>
#include <QFile>
#include <QRadialGradient>
#include <QPainterPath>
#include <QProgressDialog>
#include <math.h>
#include "linetype2.h"
#include "graphmain_linetype2.h"
#include "Constants.h"
#include "../Scheme/SchemeBuffer.hpp"
#include "../Scheme/Scheme.hpp"
#include "../Scheme/ConfigMan.hpp"
#include "../Scheme/schememetadata.h"
#include "../Scheme/SchemeInstance.hpp"
#include "../Scheme/exceptions/ColumnNotExist.hpp"
#include "../Scheme/exceptions/ValueNotExist.hpp"
#include "../Scheme/AbstractScheme.hpp"

#define DEBUG
#ifdef DEBUG
#define DEBUG_INIT
#endif


GraphMain_LineType2::GraphMain_LineType2(LineType2 *parent, QStringList curve, QVector<FileInfo> file, int sYear, int eYear)
{
    w = parent;
    m_StartYear = sYear;
    m_EndYear = eYear;
    m_CurrentYear = sYear;
    m_arrowSize = 7.0;
    m_CurveName = curve;
    m_moving  = false;
    m_showData = false;
    m_HLineEnable = false;
    m_VLineEnable = false;
    memset(m_chosen, 0, sizeof m_chosen);
    setFlag(ItemSendsGeometryChanges);
    m_lines = curve.size();
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
    setZValue(0);
    initData(file);
}

GraphMain_LineType2::~GraphMain_LineType2()
{

}

QRectF GraphMain_LineType2::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-300-adjust/2,-200-adjust/2,600+adjust,400+adjust);
}

void GraphMain_LineType2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    //Draw Background
    QLinearGradient gradient(-300,-200,600,400);
    gradient.setColorAt(0, Qt::transparent);
    gradient.setColorAt(.5, Qt::cyan);
    gradient.setColorAt(1, Qt::transparent);
    painter->fillRect(-300,-200,600,400,gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(-300, -200, 600, 400);

    max = toUpper(m_Max);
    int flag = w->graphType();
    if(flag == 0)
        DrawCurveGraph(painter);
    else
        DrawBarGraph(painter);

    //Draw Axis
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidthF(1.5);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter->setPen(pen);
    QPointF Zero(-275, 175);
    QPointF Xend(275, 175);
    QPointF Mid(0,175);
    QPointF Yend(0, -175);
    QLineF AxisX(Zero, Xend);
    QLineF AxisY(Mid, Yend);
    painter->drawLine(AxisX);
    painter->drawLine(AxisY);
    pen.setWidth(1);
    painter->setPen(pen);
    QPointF ArrowX1 = Xend - QPointF(sin(Pi/3)*m_arrowSize, cos(Pi/3)*m_arrowSize);
    QPointF ArrowX2 = Xend - QPointF(sin(Pi/3)*m_arrowSize, -cos(Pi/3)*m_arrowSize);
    painter->drawLine(ArrowX1, Xend);
    painter->drawLine(ArrowX2, Xend);
    ArrowX1 = Zero + QPointF(sin(Pi/3)*m_arrowSize, cos(Pi/3)*m_arrowSize);
    ArrowX2 = Zero + QPointF(sin(Pi/3)*m_arrowSize, -cos(Pi/3)*m_arrowSize);
    painter->drawLine(ArrowX1, Zero);
    painter->drawLine(ArrowX2, Zero);
    QPointF ArrowY1 = Yend + QPointF(-cos(Pi/3)*m_arrowSize, sin(Pi/3)*m_arrowSize);
    QPointF ArrowY2 = Yend + QPointF(cos(Pi/3)*m_arrowSize, sin(Pi/3)*m_arrowSize);
    painter->drawLine(ArrowY1, Yend);
    painter->drawLine(ArrowY2, Yend);

    //Draw Coordinate
    QString t;
    QFont font("Arial",8,1);
    QPointF mark;
    QPointF offsetX(0,-5);
    double dy;
    int i;
    pen.setWidthF(1);
    painter->setPen(pen);
    painter->setFont(font);

    //Draw X-Axis
    dy = max / 5;
    for(i=0; i<=10; i++){
            t = QString::number(abs(i*dy - max), 10);    //It's used for draw a population pyramid
            mark = offsetX + QPointF(-250+50*i, 175);
            painter->drawLine(mark, QPointF(-250+50*i, 175));
            painter->drawText(QRectF(-274+i*50,175,48,15),Qt::AlignBottom|Qt::AlignHCenter, t);
    }
    painter->drawText(QRectF(-295,155, 40, 15),Qt::AlignLeft, QObject::tr("万人(男)"));
    painter->drawText(QRectF(255,155, 40, 15),Qt::AlignRight, QObject::tr("万人(女)"));
    painter->drawText(QRectF(-230,-195+m_lines*10, 60, 20),Qt::AlignBottom|Qt::AlignHCenter, QString::number(m_CurrentYear));
    //Draw Y-Axis
    dy = 330 * 1./ 11;
    QPointF offsetY(5, 0);
    for(i=1; i<=11; i++){
            t = QString::number(i*10, 10);//Divide by decade
            mark = offsetY + QPointF(0, 175 - dy*i);
            painter->drawLine(mark, QPointF(0, 175 - dy*i));
            //Draw Text in a rectangle the x,y,w,h are rechieved by trials.
            painter->drawText(QRectF(-18, 168-dy*i, 16,15),Qt::AlignRight, t);
    }
    painter->drawText(QRectF(1,-170, 40, 16),Qt::AlignLeft, QObject::tr("年龄(岁)"));
}

void GraphMain_LineType2::DrawCurveGraph(QPainter *painter)
{
    QPen pen;
    pen.setWidth(1);
    painter->setPen(pen);
    int i;
    double dy;
    dy = 330 * 1./ 11;

    //Count DataPoint
    QPointF Age_M[111], Age_F[111];
    //Sorting with priority, the chosen line has higher priority than others.
    int* order = new int[m_lines];
    for(int k=0; k<m_lines; ++k){
        if(m_chosen[m_order[k]] == true){
            for(int j=k+1; j<m_lines; ++j)
                order[j-1] = m_order[j];
            order[m_lines-1] = m_order[k];
            break;
        }
        else
            order[k] = m_order[k];
    }

    for(int k=0; k<m_lines; k++){
        int city = order[k];
        //Set Turnning Point
        for(i=0; i<111; i++){
            Age_M[i].setY(175-dy*i/10);
            Age_M[i].setX(-m_Data_M[city][m_CurrentYear-m_StartYear][i]*1./max*250);
            Age_F[i].setY(175-dy*i/10);
            Age_F[i].setX(m_Data_F[city][m_CurrentYear-m_StartYear][i]*1./max*250);
        }

        //Draw DataCurve
        if(m_chosen[city] == true){
            pen.setColor(CHOSEN);
            pen.setWidthF(1.5f);
        }
        else{
            pen.setColor(m_Color[city]);
            pen.setWidth(1);
        }
        painter->setPen(pen);
        for(i=0; i<110; i++){
            painter->drawLine(Age_M[i], Age_M[i+1]);
            painter->drawLine(Age_F[i], Age_F[i+1]);
        }

        //Draw FileName
        if(m_chosen[city] == true){
            painter->setFont(QFont("Arail", 6, QFont::Bold));
        }
        else
            painter->setFont(QFont("Arail", 6, QFont::Normal));
        QString s = QObject::tr("曲线") + QString::number(city+1) + ":" + m_CurveName.at(city);
        painter->drawText(QRectF(-230,-195+city*10, 10*s.length(), 10), Qt::AlignLeft|Qt::AlignVCenter, s);

        //Draw DataPoints
        if(m_showData){
            for(i=0; i<110; i++){
                QPainterPath path;
                if(m_Data_M_undermouse[city][m_CurrentYear-m_StartYear][i]){
                    painter->drawEllipse(Age_M[i], 2, 2);
                    path.addEllipse(Age_M[i], 2, 2);
                    ShowCoordinate(painter, Age_M[i], i, m_Data_M[city][m_CurrentYear-m_StartYear][i]);
                }
                else
                    path.addEllipse(Age_M[i], 1, 1);

                if(m_Data_F_undermouse[city][m_CurrentYear-m_StartYear][i]){
                    painter->drawEllipse(Age_F[i], 2, 2);
                    path.addEllipse(Age_F[i], 2, 2);
                    ShowCoordinate(painter, Age_F[i], i, m_Data_F[city][m_CurrentYear-m_StartYear][i]);
                }
                else
                    path.addEllipse(Age_F[i], 1, 1);
                painter->fillPath(path, QBrush(Qt::black));
            }
        }
    }

    if(m_moving)
        return;
    pen.setColor(Qt::darkGray);
    painter->setPen(pen);
    //DrawAddingLine
    if(m_HLineEnable)
        painter->drawLine(m_HLine);

    if(m_VLineEnable)
        painter->drawLine(m_VLine);

    if(m_HLineEnable && m_VLineEnable)
        ShowCoordinate(painter, QPointF(m_VLine.x1(), m_HLine.y1()), (175-m_HLine.y1())*111/330, fabs(m_VLine.x1()*max/250));
}

void GraphMain_LineType2::DrawBarGraph(QPainter *painter)
{
    QPen pen;
    pen.setWidth(1);
    painter->setPen(pen);
    int i;
    double dy;
    dy = 330 * 1./ 11;

    //Count DataPoint
    QPointF Age_M[111], Age_F[111];
    //Sorting with priority, the chosen line has higher priority than others.
    int* order = new int[m_lines];
    for(int k=0; k<m_lines; ++k){
        if(m_chosen[m_order[k]] == true){
            for(int j=k+1; j<m_lines; ++j)
                order[j-1] = m_order[j];
            order[m_lines-1] = m_order[k];
            break;
        }
        else
            order[k] = m_order[k];
    }

    for(int k=0; k<m_lines; k++){

        QPainterPath *path = new QPainterPath(QPoint(0,175));
        int city = order[k];

        //The Male side
        for(i=0; i<111; i++){
            Age_M[i].setY(175-dy*i/10);
            Age_M[i].setX(-m_Data_M[city][m_CurrentYear-m_StartYear][i]*1./max*250);
            path->lineTo(Age_M[i]);
            Age_M[i].setY(Age_M[i].y()-dy/10);
            path->lineTo(Age_M[i]);
        }

        //The Female side
        for(i=110; i>-1; i--){
            Age_F[i].setY(175-dy*(i+1)/10);
            Age_F[i].setX(m_Data_F[city][m_CurrentYear-m_StartYear][i]*1./max*250);
            path->lineTo(Age_F[i]);
            Age_F[i].setY(Age_F[i].y()+dy/10);
            path->lineTo(Age_F[i]);
        }
        path->lineTo(0,175);//Close the path

        //Draw DataCurve
        if(m_chosen[city] == true)
            painter->setOpacity(1);
        else
            painter->setOpacity(0.75);
        painter->fillPath(*path, QBrush(m_Color[city]));
        if(m_chosen[city] == true){
            painter->setOpacity(1);
            pen.setColor(CHOSEN);
            pen.setWidthF(1.5);
            painter->setPen(pen);
            painter->drawPath(*path);
            painter->setFont(QFont("Arail", 6, QFont::Bold));
        }
        else{
            pen.setColor(DARKGRAY);
            pen.setWidth(1);
            painter->setPen(pen);
            painter->drawPath(*path);
            pen.setColor(m_Color[city]);
            painter->setPen(pen);
            painter->setOpacity(1);
            painter->setFont(QFont("Arail", 6, 1));
        }
        QString s = QObject::tr("曲线") + QString::number(city+1) + ":" + m_CurveName.at(city);
        painter->drawText(QRectF(-230,-195+city*10, 10*s.length(), 10), Qt::AlignLeft|Qt::AlignVCenter, s);
        delete path;
    }

    if(m_moving)
        return;
    pen.setColor(Qt::darkGray);
    painter->setPen(pen);
    //DrawAddingLine
    if(m_HLineEnable)
        painter->drawLine(m_HLine);

    if(m_VLineEnable)
        painter->drawLine(m_VLine);

    if(m_HLineEnable && m_VLineEnable)
        ShowCoordinate(painter, QPointF(m_VLine.x1(), m_HLine.y1()), (175-m_HLine.y1())*111/330, fabs(m_VLine.x1()*max/250));
}

void GraphMain_LineType2::initData(QVector<FileInfo> fileinfo)
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    m_Max = 0;
    qreal sum[10];
    for(int k=0; k<10; ++k)
        sum[k] = 0;

    //进度条
    QProgressDialog *progress = new QProgressDialog(w);
    progress->setWindowTitle(QObject::tr("读取数据..."));
//    progress->setWindowModality(Qt::WindowModal);
    progress->setCancelButton(0);
    int total = m_lines*111;
    progress->setRange(0, total);
    progress->setMinimumDuration(5);
    progress->setMinimumSize(200, 10);
    progress->show();

    //曲线循环，有几条曲线就循环几遍
    for(int k=0; k<m_lines; ++k){
/*        QString FileName;
        QFile *Popu;
        FileName = fileinfo[k].m_FileName;*/
        QString FileName = fileinfo[k].m_FileName;
        QFile *Popu = new QFile(FileName);
#ifdef DEBUG_INIT
        qDebug()<<Popu->fileName();
#endif
        if(!Popu->open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(w, QObject::tr("错误!"), QObject::tr("未找到指定文件"), QMessageBox::Ok);
            return;
        }
        QTextStream in(Popu);
        while(!in.atEnd()){
            QString line = in.readLine();
            int age =  line.section(",", 0, 0).toInt();
            int maxYear = line.count(',')/2 + m_StartYear - 1;
#ifdef DEBUG_INIT
            qDebug()<<maxYear;
#endif
            m_EndYear = m_EndYear > maxYear? maxYear : m_EndYear;
            for(int i=0; i<=m_EndYear-m_StartYear; ++i){
                m_Data_M[k][i][age] = line.section(",", 2*i+1, 2*i+1).toLong();
                m_Data_M[k][i][age] /= 10000;   //把单位转化为万人
                sum[k] += m_Data_M[k][i][age];
                if(m_Max < m_Data_M[k][i][age])
                    m_Max = m_Data_M[k][i][age];
                m_Data_F[k][i][age] = line.section(",", 2*i+2, 2*i+2).toLong();
                m_Data_F[k][i][age] /= 10000;
                sum[k] += m_Data_F[k][i][age];   //把单位转化为万人
                if(m_Max < m_Data_F[k][i][age])
                    m_Max = m_Data_F[k][i][age];
            }
            progress->setValue((k+1)*111+age);
        }

        Popu->close();
        delete Popu;
        //用人口总和来比较大小更加合理
        int i;
        for(i=k-1; i>=0 && sum[i]<sum[k]; --i){
            m_order[i+1] = m_order[i];
        }
        m_order[i+1] = k;
    }
    progress->setValue(total);
//    progress->hide();
    for(int i=0; i<m_lines; ++i){
        for(int j=0; j<92; ++j){
            for(int k=0; k<111; ++k){
                m_Data_M_undermouse[i][j][k] = false;
                m_Data_F_undermouse[i][j][k] = false;
            }
        }
    }
    progress->hide();
    delete progress;
}

void GraphMain_LineType2::initDataV2(QVector<FileInfo> fileinfo)
{/*
    using Config::config;
    if( !config.read()){
        return ;
    }

    if(fileinfo.empty()){
        return ;
    }

    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

    std::shared_ptr<schememetadata> meta;
    if(fileinfo.front().m_FileName.contains(QObject::tr("夫妇子女")))
    {
        meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_FUFUZINV")));
    }
    else if(fileinfo.front().m_FileName.contains(QObject::tr("人口概要")))
    {
        meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_RENKOUGAIYAO")));
    }
    else if(fileinfo.front().m_FileName.contains(QObject::tr("生育孩次")))
    {
        meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_SHENGYUHAICI")));
    }
    else //if(fileinfo.front().m_FileName.contains(QObject::tr("政策生育")))
    {
        meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_ZHENGCESHENGYU")));
    }

    std::shared_ptr<SchemeBuffer> buffer(new SchemeBuffer);

    //初始化一些统计数据
    m_Max = 0;
    qreal sum[10];
    for(int k=0; k<10; ++k)
        sum[k] = 0;

    //进度条
    QProgressDialog *progress = new QProgressDialog(w);
    progress->setWindowTitle(QObject::tr("读取数据..."));
//    progress->setWindowModality(Qt::WindowModal);
    progress->setCancelButton(0);
    int total = m_lines*111;
    progress->setRange(0, total);
    progress->setMinimumDuration(5);
    progress->setMinimumSize(200, 10);
    progress->show();

    //曲线循环，有几条曲线就循环几遍
    for(int k=0; k<m_lines; ++k){
        // 在绝对路径的文件路径中提取出文件名
        QString filename = fileinfo[k].m_FileName.section('/', -1).section('.', 0 ,0);
        qDebug()<<"GraphMain_LineType1::initDataV2"<<filename;

        SchemePtr ptr(new Scheme(meta, buffer, filename));
        for(int age =)
        for(int year=m_StartYear; year<=m_EndYear; ++year){
            try{
                m_Data_M[k][i][age]
                                m_Data_M[k][i][age] = line.section(",", 2*i+1, 2*i+1).toLong();
                                m_Data_M[k][i][age] /= 10000;   //把单位转化为万人
                                sum[k] += m_Data_M[k][i][age];
                                if(m_Max < m_Data_M[k][i][age])
                                    m_Max = m_Data_M[k][i][age];
                                m_Data_F[k][i][age] = line.section(",", 2*i+2, 2*i+2).toLong();
                                m_Data_F[k][i][age] /= 10000;
                                sum[k] += m_Data_F[k][i][age];   //把单位转化为万人
                                if(m_Max < m_Data_F[k][i][age])
                                    m_Max = m_Data_F[k][i][age];
                            }
            }
            catch(const RecordNotExist& e){
                qDebug()<<"GraphMain_LineType2::initDataV2"<<"Can't achieve record"<<e.name();
                m_data[k][year-m_StartYear] = 0.0;
            }
            if(m_max < m_data[k][year-m_StartYear])
                m_max = m_data[k][year-m_StartYear];
            if(m_min > m_data[k][year-m_StartYear])
                m_min = m_data[k][year-m_StartYear];
            progress->setValue((k+1)*111+age);
        }

//        while(!in.atEnd()){
//            QString line = in.readLine();
//            int age =  line.section(",", 0, 0).toInt();
//            int maxYear = line.count(',')/2 + m_StartYear - 1;
//#ifdef DEBUG_INIT
//            qDebug()<<maxYear;
//#endif
//            m_EndYear = m_EndYear > maxYear? maxYear : m_EndYear;
//            for(int i=0; i<=m_EndYear-m_StartYear; ++i){
//                m_Data_M[k][i][age] = line.section(",", 2*i+1, 2*i+1).toLong();
//                m_Data_M[k][i][age] /= 10000;   //把单位转化为万人
//                sum[k] += m_Data_M[k][i][age];
//                if(m_Max < m_Data_M[k][i][age])
//                    m_Max = m_Data_M[k][i][age];
//                m_Data_F[k][i][age] = line.section(",", 2*i+2, 2*i+2).toLong();
//                m_Data_F[k][i][age] /= 10000;
//                sum[k] += m_Data_F[k][i][age];   //把单位转化为万人
//                if(m_Max < m_Data_F[k][i][age])
//                    m_Max = m_Data_F[k][i][age];
//            }
//            progress->setValue((k+1)*111+age);
//        }

//        Popu->close();
//        delete Popu;
//        //用人口总和来比较大小更加合理
//        int i;
//        for(i=k-1; i>=0 && sum[i]<sum[k]; --i){
//            m_order[i+1] = m_order[i];
//        }
//        m_order[i+1] = k;
//    }

    progress->setValue(total);
//    progress->hide();
    for(int i=0; i<m_lines; ++i){
        for(int j=0; j<92; ++j){
            for(int k=0; k<111; ++k){
                m_Data_M_undermouse[i][j][k] = false;
                m_Data_F_undermouse[i][j][k] = false;
            }
        }
    }

    progress->hide();
    delete progress;*/
}

void GraphMain_LineType2::setYear(int year){
    m_CurrentYear = year;
    if(year < m_StartYear)
        m_CurrentYear = m_StartYear;
    if(year > m_EndYear)
        m_CurrentYear = m_EndYear;
    update();//曲线的移动就是在这里实现的
    calKeyValue();
}

void GraphMain_LineType2::calKeyValue()
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    for(int i=0; i<m_lines; i++){
        qreal ave, mid;
        qint32 min, max;
        qreal sum = 0, popu = 0;
        int line = m_order[i];
        min = max = 0;
        for(int j=0; j<111; j++){
            if((m_Data_M[line][m_CurrentYear-m_StartYear][j] + m_Data_F[line][m_CurrentYear-m_StartYear][j]) <
               (m_Data_M[line][m_CurrentYear-m_StartYear][min] + m_Data_F[line][m_CurrentYear-m_StartYear][min]))
                min = j;
            if((m_Data_M[line][m_CurrentYear-m_StartYear][j] + m_Data_F[line][m_CurrentYear-m_StartYear][j]) >
               (m_Data_M[line][m_CurrentYear-m_StartYear][max] + m_Data_F[line][m_CurrentYear-m_StartYear][max]))
                max = j;
            popu += m_Data_M[line][m_CurrentYear-m_StartYear][j] + m_Data_F[line][m_CurrentYear-m_StartYear][j];
            sum += (m_Data_M[line][m_CurrentYear-m_StartYear][j] + m_Data_F[line][m_CurrentYear-m_StartYear][j]) * j;
        }
        ave = sum / popu;
        int j = -1;
        popu /= 2;
        while(popu > 0){
            ++j;
            popu -= m_Data_M[line][m_CurrentYear-m_StartYear][j] + m_Data_F[line][m_CurrentYear-m_StartYear][j];
        }
        popu += m_Data_M[line][m_CurrentYear-m_StartYear][j] + m_Data_F[line][m_CurrentYear-m_StartYear][j];
        mid = j + popu/(m_Data_M[line][m_CurrentYear-m_StartYear][j] + m_Data_F[line][m_CurrentYear-m_StartYear][j]);
        QString s1 = QString::number(m_Data_M[line][m_CurrentYear-m_StartYear][max]
                                     + m_Data_F[line][m_CurrentYear-m_StartYear][max])
                     + QObject::tr("万人，") + QString::number(max) + QObject::tr("岁");
        QString s2 = QString::number(m_Data_M[line][m_CurrentYear-m_StartYear][min]
                                     + m_Data_F[line][m_CurrentYear-m_StartYear][min])
                     + QObject::tr("万人，") + QString::number(min) + QObject::tr("岁");
        w->setEditText(line, 1, s1);
        w->setEditText(line, 2, s2);
        w->setEditText(line, 3, QString::number(ave));
        w->setEditText(line, 4, QString::number(mid));
    }
}

long GraphMain_LineType2::toUpper(long n)
{
    long max = 1;
    while(n > 100){
        max *= 10;
        n /= 10;
    }
    //如果第二高位小于5，进为5，如果大于等于5就进位
    if(n % 10 >= 5)
        max *= (n/10 + 1)*10;
    else
        max *= (n/10)*10+5;
    return max;
}

void GraphMain_LineType2::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    w->deleteqvalueboard();
    if(m_showData)
        MarkPoint(event->pos());
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    if(isMoving()){
        update();
        return;
    }
    QPointF click, start, end, p;
    QString t;
    QVector<QString> v1;
    QVector<QPointF> v2;
    QVector<QColor> v3;
    long tmp;
    click = mapFromScene(event->pos());
    if(click.y()<-175 || click.y()>175 || click.x()>250 || click.x()<-250)
        return;
    //Draw Vertical Line
    if(m_VLineEnable){
        start.setY(175);
        start.setX(click.x());
        end.setY(-180);
        end.setX(click.x());
        if(!m_HLineEnable){
            for(int i=0; i<m_lines; i++){
                if(click.x() <= 0){
                    tmp = -click.x()/250*max;
                    for(int j=0; j<110; j++){
                        if((m_Data_M[i][m_CurrentYear-m_StartYear][j]-tmp)*(m_Data_M[i][m_CurrentYear-m_StartYear][j+1]-tmp) <= 0){
                            qDebug()<<j<<tmp<<m_Data_M[i][m_CurrentYear-m_StartYear][j]<<m_Data_M[i][m_CurrentYear-m_StartYear][j+1];
                            t = QString::number(j) + QObject::tr("岁,") + QString::number(tmp) + QObject::tr("万人");
                            p.setX(click.x());
                            p.setY(175-j*1.*330/110);
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                    }
                }
                else if(click.x() >= 0){
                    tmp = click.x()/250*max;
                    for(int j=0; j<110; j++){
                        if((m_Data_F[i][m_CurrentYear-m_StartYear][j]-tmp)*(m_Data_F[i][m_CurrentYear-m_StartYear][j+1]-tmp) <= 0){
                            t = QString::number(j) + QObject::tr("岁,") + QString::number(tmp) + QObject::tr("万人");
                            p.setX(click.x());
                            p.setY(175-j*1.*330/110);
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                    }
                }
            }
        }
    }
    m_VLine = QLineF(start, end);
    //Draw Horizontial Line
    if(m_HLineEnable){
        start.setX(-260);
        start.setY(click.y());
        end.setX(260);
        end.setY(click.y());
        if(!m_VLineEnable){
            tmp = (int)((175-click.y())*330/110);
            p.setY(click.y());
            for(int i=0; i<m_lines; i++){
                p.setX(-m_Data_M[i][m_CurrentYear][tmp]*250./max);
                t = QString::number(tmp) + QObject::tr("岁,") + QString::number(m_Data_M[i][m_CurrentYear][tmp]) + QObject::tr("万人");
                v2.push_front(p);
                v1.push_front(t);
                v3.push_front(m_Color[i]);
            }
            for(int i=0; i<m_lines; i++){
                p.setX(m_Data_F[i][m_CurrentYear][tmp]*250./max);
                t = QString::number(tmp) + QObject::tr("岁,") + QString::number(m_Data_F[i][m_CurrentYear][tmp]) + QObject::tr("万人");
                v2.push_front(p);
                v1.push_front(t);
                v3.push_front(m_Color[i]);
            }
        }
    }
    m_HLine = QLineF(start, end);
    update();
    while(!v1.empty()){
        p = v2.at(0);
        v2.pop_front();
        t = v1.at(0);
        v1.pop_front();
        w->addGrpahicsLabel(this->mapToScene(p),t,v3.front());
        v3.pop_front();
    }
}

void GraphMain_LineType2::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    w->deleteqvalueboard();
    if(m_showData)
        MarkPoint(event->pos());
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    if(isMoving()){
        update();
        return;
    }
    QPointF click, start, end, p;
    QString t;
    QVector<QString> v1;
    QVector<QPointF> v2;
    QVector<QColor> v3;
    long tmp;
    click = mapFromScene(event->pos());
    if(click.y()<-175 || click.y()>175 || click.x()>250 || click.x()<-250)
        return;
    //Draw Vertical Line
    if(m_VLineEnable){
        start.setY(175);
        start.setX(click.x());
        end.setY(-180);
        end.setX(click.x());
        if(!m_HLineEnable){
            for(int i=0; i<m_lines; i++){
                if(click.x() <= 0){
                    tmp = -click.x()/250*max;
                    for(int j=0; j<110; j++){
                        if((m_Data_M[i][m_CurrentYear-m_StartYear][j]-tmp)*(m_Data_M[i][m_CurrentYear-m_StartYear][j+1]-tmp) <= 0){
                            qDebug()<<j<<tmp<<m_Data_M[i][m_CurrentYear-m_StartYear][j]<<m_Data_M[i][m_CurrentYear-m_StartYear][j+1];
                            t = QString::number(j) + QObject::tr("岁,") + QString::number(tmp) + QObject::tr("万人");
                            p.setX(click.x());
                            p.setY(175-j*1.*330/110);
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                    }
                }
                else if(click.x() >= 0){
                    tmp = click.x()/250*max;
                    for(int j=0; j<110; j++){
                        if((m_Data_F[i][m_CurrentYear-m_StartYear][j]-tmp)*(m_Data_F[i][m_CurrentYear-m_StartYear][j+1]-tmp) <= 0){
                            t = QString::number(j) + QObject::tr("岁,") + QString::number(tmp) + QObject::tr("万人");
                            p.setX(click.x());
                            p.setY(175-j*1.*330/110);
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                    }
                }
            }
        }
    }
    m_VLine = QLineF(start, end);
    //Draw Horizontial Line
    if(m_HLineEnable){
        start.setX(-260);
        start.setY(click.y());
        end.setX(260);
        end.setY(click.y());
        if(!m_VLineEnable){
            tmp = (int)((175-click.y())*330/110);
            p.setY(click.y());
            for(int i=0; i<m_lines; i++){
                p.setX(-m_Data_M[i][m_CurrentYear][tmp]*250./max);
                t = QString::number(tmp) + QObject::tr("岁,") + QString::number(m_Data_M[i][m_CurrentYear][tmp]) + QObject::tr("万人");
                v2.push_front(p);
                v1.push_front(t);
                v3.push_front(m_Color[i]);
            }
            for(int i=0; i<m_lines; i++){
                p.setX(m_Data_F[i][m_CurrentYear][tmp]*250./max);
                t = QString::number(tmp) + QObject::tr("岁,") + QString::number(m_Data_F[i][m_CurrentYear][tmp]) + QObject::tr("万人");
                v2.push_front(p);
                v1.push_front(t);
                v3.push_front(m_Color[i]);
            }
        }
    }
    m_HLine = QLineF(start, end);
    update();
    while(!v1.empty()){
        p = v2.at(0);
        v2.pop_front();
        t = v1.at(0);
        v1.pop_front();
        w->addGrpahicsLabel(this->mapToScene(p),t,v3.front());
        v3.pop_front();
    }
}

void GraphMain_LineType2::setVLine(long population)
{
    QPointF start,end;
    start.setX(population*1./max*250);
    start.setY(-180);
    end.setX(population*1./max*250);
    end.setY(175);
    m_VLineEnable = true;
    m_VLine = QLineF(start, end);
    update();
}

void GraphMain_LineType2::setHLine(int age)
{
    QPointF start, end;
    start.setX(-260);
    start.setY(175 - age*3);
    end.setX(260);
    end.setY(175 - age*3);
    m_HLineEnable = true;
    m_HLine = QLineF(start, end);
    update();
}

void GraphMain_LineType2::ShowCoordinate(QPainter *painter, QPointF pos, int age, long value)
{
    QPen pen;
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->setFont(QFont("Arial", 5 ,1));
    QPointF next;
    QPainterPath *path = new QPainterPath(pos);
    next = pos + QPointF(0, -25);
    path->lineTo(next);
    next = next + QPointF(40,0);
    path->lineTo(next);
    next = next + QPointF(0, 18);
    path->lineTo(next);
    next = next + QPointF(-35, 0);
    path->lineTo(next);
    path->lineTo(pos);
    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawPath(*path);
    painter->setOpacity(0.75);
    painter->fillPath(*path, QBrush(Qt::green));
    pen.setColor(Qt::black);
    painter->setPen(pen);
    QString t;
    t = QString::number(age) + QObject::tr("岁,") + QString::number(value) + QObject::tr("万人");
    painter->drawText(QRectF(pos.x(), pos.y()-25, 40, 18), Qt::AlignCenter, t);
    painter->drawText(QRectF(pos.x(),pos.y()-25,40, 18), Qt::AlignCenter, t);
}

void GraphMain_LineType2::MarkPoint(QPointF pos)
{
    for(int i=0; i<m_lines; ++i){
        for(int j=0; j<92; ++j){
            for(int k=0; k<111; ++k){
                m_Data_M_undermouse[i][j][k] = false;
                m_Data_F_undermouse[i][j][k] = false;
            }
        }
    }

    for(int i=0; i<m_lines; ++i){
       int city = m_order[i];
       int age = (int)((175 - pos.y())/3);
       if(pos.x() >= 0)
           if(fabs(m_Data_F[city][m_CurrentYear-m_StartYear][age]*250/max - pos.x()) < 1)
               m_Data_F_undermouse[city][m_CurrentYear-m_StartYear][age] = true;
       if(pos.x() <= 0)
           if(fabs(m_Data_M[city][m_CurrentYear-m_StartYear][age]*250/max + pos.x()) < 1)
               m_Data_M_undermouse[city][m_CurrentYear-m_StartYear][age] = true;
    }
}

void GraphMain_LineType2::setChosen(int chosen)
{
    memset(m_chosen, 0, sizeof m_chosen);
    if(chosen == -1)
        return;
    m_chosen[chosen] = true;
}
