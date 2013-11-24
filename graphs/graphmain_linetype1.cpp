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
#include <QVector>
#include <QGraphicsProxyWidget>
#include <QProgressDialog>
#include <math.h>
#include "linetype1.h"
#include "graphmain_linetype1.h"
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
//#define DEBUG_INITDATA
//#define DEBUG_DRAWCOOR
//#define DEBUG_DRAW3D
#define DEBUG_MOUSEEVENT
#endif


GraphMain_LineType1::GraphMain_LineType1(LineType1 *parent, QStringList curve, QVector<FileInfo> file, int sYear, int eYear)
{
    w = parent;
    m_arrowSize = 7.0;
    m_StartYear = sYear;
    m_EndYear = eYear;
    m_Xlength = 450.0;
    m_dx = 0.0;
    m_Ylength = 330.0;
    m_dy = 0.0;
    m_ylowest = 175.0;
    m_yhighest = -175.0;
    m_xlowest = -250.0;
    m_xhighest = 250.0;
    m_yzero = m_ylowest;
    m_curvename = curve;
    m_moving = false;
    m_showData = false;
    m_HLineEnable = false;
    m_VLineEnable = false;
    setFlag(ItemSendsGeometryChanges);
    setZValue(0);
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
    memset(m_chosen, 0, sizeof m_chosen);
    m_CurrentYear = m_StartYear;
    initDataV2(file);
}

GraphMain_LineType1::~GraphMain_LineType1()
{

}

QRectF GraphMain_LineType1::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-300-adjust/2,-200-adjust/2,600+adjust,400+adjust);
}

void GraphMain_LineType1::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
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

    max = toUpper(m_max);
    int flag = w->graphType();
    if(flag == 0){
        DrawCurveGraph(painter);
        DrawCoordinates(painter);
    }
    else if(flag == 1){
        DrawBarGraph(painter);
        DrawCoordinates(painter);
    }
    else{
        Draw3DBarGraph(painter);
    }
}

void GraphMain_LineType1::DrawCurveGraph(QPainter *painter)
{
    QPen pen;
    pen.setWidth(1);
    painter->setPen(pen);
    int i;
    QPointF LeftdownPoint(m_xlowest,m_ylowest);                      //最低点位置
    m_dx = m_Xlength * 1./ (m_EndYear-m_StartYear);     //x轴的分度值
    m_dy = m_Ylength * 1./ (max - min);             //y轴的分度值

    //Count DataPoint
    QPointF point[m_EndYear-m_StartYear+1];
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
        for(i=0; i<=m_CurrentYear-m_StartYear; i++){
            point[i].setY(LeftdownPoint.y()-(m_data[city][i]-min)*m_dy);
            point[i].setX(LeftdownPoint.x()+i*m_dx);
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
        for(i=0; i<m_CurrentYear-m_StartYear; i++)
            painter->drawLine(point[i], point[i+1]);

        //Draw DataPoints
        if(m_showData){
            for(i=0; i<=m_CurrentYear-m_StartYear; i++){
                QPainterPath path;
                if(m_PointUndermouse[city][i]){
                    painter->drawEllipse(point[i], 2, 2);
                    path.addEllipse(point[i], 2, 2);
                    ShowCoordinate(painter, point[i], i+m_StartYear, m_data[city][i]);
                }
                else
                    path.addEllipse(point[i], 1, 1);
                painter->fillPath(path, QBrush(Qt::black));
            }
        }

        //Draw FileName
        if(m_chosen[city] == true){
            painter->setFont(QFont("Arail", 6, QFont::Bold));
        }
        else
            painter->setFont(QFont("Arail", 6, QFont::Normal));
        QString s = QObject::tr("曲线") + QString::number(city+1) + ":" + m_curvename.at(city);
        painter->drawText(QRectF(-230,-195+city*10, 10*s.length(), 10), Qt::AlignLeft|Qt::AlignVCenter, s);
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
        ShowCoordinate(painter,
                       QPointF(m_VLine.x1(), m_HLine.y1()),
                       m_StartYear+(m_VLine.x2()-LeftdownPoint.x())/m_dx,
                       (LeftdownPoint.y()-m_HLine.y1())/m_Ylength*max);
}

void GraphMain_LineType1::DrawBarGraph(QPainter *painter)
{
    QPen pen;
    pen.setWidth(1);
    painter->setPen(pen);
    int i;
    QPointF LeftdownPoint(m_xlowest,m_ylowest);
    m_dx = m_Xlength * 1./ (m_EndYear-m_StartYear);
    m_dy = m_Ylength * 1./ (max - min);

    QPointF ZeroPoint(m_xlowest, 0);
    if(fabs(min) < 0.000000001){        //最小值是否等于0，用(==)是错误的
        ZeroPoint = LeftdownPoint;
    }
    else{
        ZeroPoint.setY(m_ylowest-(-min)*m_dy);     //y轴向上值减小，min是负数
    }

    painter->setOpacity(0.65);
    //Count DataPoint
    QPointF point[m_EndYear-m_StartYear+1];

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

        QPainterPath *path = new QPainterPath(ZeroPoint);
        int city = order[k];

        for(i=0; i<=m_CurrentYear-m_StartYear; i++){
            point[i].setY(ZeroPoint.y()-m_data[city][i]*m_dy);
            point[i].setX(ZeroPoint.x()+i*m_dx);
            path->lineTo(point[i]);
            point[i].setX(ZeroPoint.x()+i*m_dx+m_dx);
            path->lineTo(point[i]);
        }
        point[i-1].setY(ZeroPoint.y());
        path->lineTo(point[i-1]);
        path->lineTo(ZeroPoint);//Close the path

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
        QString s = QObject::tr("曲线") + QString::number(city+1) + ":" + m_curvename.at(city);
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
        ShowCoordinate(painter, QPointF(m_VLine.x1(), m_HLine.y1()),
                       m_StartYear+(m_VLine.x2()-ZeroPoint.x())/m_Xlength*(m_EndYear-m_StartYear+1),
                       (ZeroPoint.y()-m_HLine.y1())/330*max);
}

void GraphMain_LineType1::DrawCoordinates(QPainter *painter)
{
    //Draw Axis
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidthF(1);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter->setPen(pen);
    QPointF Leftdown(m_xlowest, m_ylowest);
    QPointF Yend(m_xlowest, m_yhighest);
    QPointF Xend(m_xhighest, m_ylowest);
    QPointF Zero(m_xlowest, 0);
    if(fabs(min) < 0.000000001){        //最小值是否等于0，用(==)是错误的
        Zero = Leftdown;
        Xend.setY(Zero.y());
    }
    else{
        Zero.setY(m_ylowest-(-min)*m_dy);     //y轴向上值减小，min是负数
        m_yzero = m_ylowest-(-min)*m_dy;
        Xend.setY(Zero.y());
    }
    QLineF AxisX(Zero, Xend);
    QLineF AxisY(Leftdown+QPointF(0,5), Yend);
    painter->drawLine(AxisX);
    painter->drawLine(AxisY);
    //Draw the arrows
    QPointF ArrowX1 = Xend - QPointF(sin(Pi/3)*m_arrowSize, cos(Pi/3)*m_arrowSize);
    QPointF ArrowX2 = Xend - QPointF(sin(Pi/3)*m_arrowSize, -cos(Pi/3)*m_arrowSize);
    QPointF ArrowY1 = Yend + QPointF(-cos(Pi/3)*m_arrowSize, sin(Pi/3)*m_arrowSize);
    QPointF ArrowY2 = Yend + QPointF(cos(Pi/3)*m_arrowSize, sin(Pi/3)*m_arrowSize);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->drawLine(ArrowX1, Xend);
    painter->drawLine(ArrowX2, Xend);
    painter->drawLine(ArrowY1, Yend);
    painter->drawLine(ArrowY2, Yend);
    //Draw Coordinate
    int i;
    int Grad = 10;          //分度值为10年
    QString t;
    QFont font("Arial",8,1);
    QPointF mark;
    QPointF offsetX(0,-5);
    pen.setWidthF(1);
    painter->setPen(pen);
    painter->setFont(font);

    //Draw X-Axis

    int labelMin = (m_StartYear+Grad-1)/Grad*Grad;   //最小的年份坐标
#ifdef DEBUG_DRAWCOOR
            qDebug()<<labelMin;
#endif
    int labelMax = (m_EndYear+Grad-1)/Grad*Grad;     //最大的年份坐标
    m_dx = m_Xlength*1. / (m_EndYear-m_StartYear);       //每年的间距

    //起始年份刻度
    if(labelMin != m_StartYear){
        t = QString::number(m_StartYear, 10);
        mark = offsetX + QPointF(Zero.x(), Zero.y());     //计算出每个刻度的位置
        painter->drawText(Zero.x()-8, Zero.y()+12, t);
    }
    for(i=labelMin; i<=labelMax; i+=Grad){
            t = QString::number(i, 10);//把一个数转换成字符，用十进制表示
            mark = offsetX + QPointF(Zero.x()+m_dx*(i-m_StartYear), Zero.y());     //计算出每个刻度的位置
#ifdef DEBUG_DRAWCOOR
//            qDebug()<<mark;
#endif
            painter->drawLine(mark, QPointF(Zero.x()+m_dx*(i-m_StartYear), Zero.y()));
            painter->drawText(Zero.x()-8+m_dx*(i-m_StartYear), Zero.y()+12, t);
    }

    //Draw Y-Axis
    double dy = m_Ylength * 1./ 10;
    QPointF offsetY(5, 0);
    for(i=0; i<=10; i++){
            double scale = (max-min)*0.1*i+min;     //乘以0.1因为画11个刻度，每个之间的间隔是1/10
            if(fabs(scale) < 1e-9)
                scale = 0;
            t = QString::number(scale);//Divide by decade
            mark = offsetY + QPointF(Leftdown.x(), Leftdown.y() - dy*i);
            painter->drawLine(mark, QPointF(Leftdown.x(), Leftdown.y() - dy*i));
            //Draw Text in a rectangle the x,y,w,h are rechieved by trials.
            painter->drawText(QRectF(-295, Leftdown.y()-7-dy*i, 43, 15),Qt::AlignRight, t);
    }
    painter->drawText(QRectF(Xend.x()+1,Xend.y(), 40, 16),Qt::AlignLeft, QObject::tr("年份"));
}

void GraphMain_LineType1::Draw3DBarGraph(QPainter *painter)
{
    double xlength = 400;           //x方向的长度
    double ylength = 250;           //y方向的长度
    double depth = 100;              //z方向的长度
    double margin = 10;              //多出来的长度

    //x,y,z三个方向上的基向量
    QPointF xbase(cos(Pi/72), sin(Pi/72));
    QPointF ybase(cos(Pi/2), -sin(Pi/2));
    QPointF zbase(cos(Pi/12), -sin(Pi/12));
    QPointF LeftdownPoint(-250, 150);
    QPointF ZeroPoint(-250, 0);
    if(fabs(min) < 0.000000001){        //最小值是否等于0，用(==)是错误的
        ZeroPoint = LeftdownPoint;
    }
    else{
        ZeroPoint.setY(175-(-min)*m_dy);     //y轴向上值减小，min是负数
    }

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidthF(1);
    pen.setJoinStyle(Qt::MiterJoin);
    pen.setCapStyle(Qt::RoundCap);
    painter->setPen(pen);
    painter->setFont(QFont("Arial", 6, 1));

    //Draw x-aixs line
    QPointF Xend, Yend, Zend;
    Xend = ZeroPoint + (xlength+margin) * xbase;
    Yend = LeftdownPoint + (ylength+margin) * ybase;
    Zend = ZeroPoint + depth * zbase;
    painter->drawLine(ZeroPoint, Xend);
    painter->drawLine(LeftdownPoint, Yend);
    painter->drawLine(ZeroPoint, Zend);

#ifdef DEBUG_DRAW3D
    qDebug()<<"m_EndYear"<<m_EndYear;
#endif

    //x,y,z方向上每一格的长度
    double xdiv, ydiv, zdiv;
    int xblock, yblock, zblock;         //每个方向分的段数
    int Grad = 10;
    int labelMin = (m_StartYear+Grad-1)/Grad*Grad;   //最小的年份坐标
    int labelMax = (m_EndYear+Grad-1)/Grad*Grad;     //最大的年份坐标
    xblock = (labelMax - labelMin)/Grad+1;
    yblock = 10;
    zblock = m_lines;
    xdiv = (xlength-margin) / (m_EndYear-m_StartYear);
    ydiv = ylength / yblock;
    zdiv = depth / zblock;
//画刻度
    QPointF offset, temp;
    offset = QPointF(-5,0);
    for(int i=0; i<=yblock; i++){
        //y刻度
        temp = LeftdownPoint + i*ydiv*ybase;
        painter->drawLine(temp, temp+offset);
        double scale = (max-min)*1./yblock*i + min;
        if(fabs(scale) < 1e-9)
            scale = 0;
        painter->drawText(QRectF(temp.x()-40, temp.y()-5, 34, 10), Qt::AlignRight, QString::number(scale));
        painter->drawLine(temp, temp+depth*zbase);
        temp += depth * zbase;
        painter->drawLine(temp, temp + (xlength+margin)*xbase);
    }
    //x刻度
    offset = QPointF(0,5);
    if(labelMin > m_StartYear)
        painter->drawText(QRectF(ZeroPoint.x()-10, ZeroPoint.y()+6, 20, 10), Qt::AlignCenter, QString::number(m_StartYear));
    for(int i=labelMin; i<=labelMax; i+=Grad){
        temp = ZeroPoint + (i-m_StartYear)*xdiv*xbase;           //Edit on 2011.9.24 by TP
        painter->drawLine(temp, temp + offset);
        painter->drawText(QRectF(temp.x()-10, temp.y()+6, 20, 10), Qt::AlignCenter, QString::number(i));//Edit on 2011.9.24 by TP
    }
    painter->drawText(QRectF(ZeroPoint.x()+xlength+margin+2, ZeroPoint.y()+2, 20, 10), Qt::AlignCenter, QObject::tr("年份"));

    //Sorting with priority, the chosen line has higher priority than others.
    int* order = new int[m_lines];
    for(int k=m_lines-1; k>=0; --k){
        if(m_chosen[m_order[k]]){
            for(int j=k; j>0; --j)
                order[j] = m_order[j-1];
            order[0] = m_order[k];
            break;
        }
        else
            order[k] = m_order[k];
    }

//画柱子,因为覆盖效果，所以要从后往前画
    for(int i=m_lines-1; i>=0; i--){
        int city;
        city = order[i];
        QPointF BasePoint;
        QPointF p1,p2,p3;
        if(m_chosen[city] == true)
            pen.setColor(CHOSEN);
        else
            pen.setColor(DARKGRAY);
        painter->setPen(pen);

        //画正面
        BasePoint = ZeroPoint + ((i+0.5)*zdiv) * zbase;
        QPainterPath *path = new QPainterPath(BasePoint);
        temp = BasePoint;
        int j;
        for(j=0; j<m_CurrentYear-m_StartYear; j++){
            temp = BasePoint + (m_data[city][j]/(max-min)*ylength)*ybase + (xlength*j*1./(m_EndYear-m_StartYear+1))*xbase;
            path->lineTo(temp);
            temp = temp + (xlength * 1./(m_EndYear-m_StartYear+1))*xbase;
            path->lineTo(temp);
        }
        temp = BasePoint + xlength * j / (m_EndYear-m_StartYear+1) * xbase;
        path->lineTo(temp);
        path->lineTo(BasePoint);

        if(m_chosen[city] == true)
            painter->setOpacity(1);
        else
            painter->setOpacity(0.65);
        painter->fillPath(*path, QBrush(m_Color[city]));
        painter->drawPath(*path);

        //画上面
        QPointF TPoint[250];
        *path = QPainterPath();
        painter->setOpacity(0.65);
        p2 = BasePoint +(m_data[city][0]/(max-min)*ylength)*ybase;
        path->moveTo(p2);
        temp = BasePoint;
        TPoint[0] = p2 + 0.5*zdiv*zbase;
        for(j=0; j<m_CurrentYear-m_StartYear; j++){
            temp = BasePoint + (m_data[city][j]/(max-min)*ylength)*ybase + (xlength*j*1./(m_EndYear-m_StartYear+1))*xbase;
            TPoint[2*j+1] = temp + 0.5*zdiv*zbase;
            path->lineTo(temp);
            temp = temp + (xlength * 1./(m_EndYear-m_StartYear+1))*xbase;
            path->lineTo(temp);
            TPoint[2*j+2] = temp + 0.5*zdiv*zbase;
        }
        for(int k=2*j; k>=0; k--)
                path->lineTo(TPoint[k]);

        //画侧面
        path->moveTo(TPoint[2*j]);
        temp = TPoint[2*j] - 0.5*zdiv*zbase;
        path->lineTo(temp);
        temp = BasePoint + (xlength*(m_CurrentYear-m_StartYear)/(m_EndYear-m_StartYear+1))*xbase;
        path->lineTo(temp);
        temp = temp + 0.5*zdiv*zbase;
        path->lineTo(temp);
        path->lineTo(TPoint[2*j]);

        if(m_chosen[city] == true)
            painter->setOpacity(1);
        else
            painter->setOpacity(0.65);
        painter->fillPath(*path, QBrush(m_Color[city]));
        painter->drawPath(*path);

        //画背后的线
        pen.setColor(Qt::darkGray);
        painter->setPen(pen);
        if(m_CurrentYear - m_StartYear){
            p2 = BasePoint + 0.5*zdiv*zbase;
            painter->drawLine(BasePoint, p2);
            painter->drawLine(p2, TPoint[0]);
            p3 = p2 + (xlength*(m_CurrentYear-m_StartYear)/(m_EndYear-m_StartYear+1))*xbase;
            painter->drawLine(p2, p3);
        }

        //顶上的线
        for(j=0; j<m_CurrentYear-m_StartYear; ++j){
            temp = BasePoint + (m_data[city][j]/(max-min)*ylength)*ybase + (xlength*j*1./(m_EndYear-m_StartYear+1))*xbase;
            p1 = temp + 0.5*zdiv*zbase;
            painter->drawLine(temp, p1);
        }
        painter->setOpacity(1);
        //Draw FileName
        if(m_chosen[city] == true){
            pen.setColor(CHOSEN);
            painter->setFont(QFont("Arail", 6, QFont::Bold));;
        }
        else{
            pen.setColor(m_Color[city]);
            painter->setFont(QFont("Arail", 6, QFont::Normal));
        }
        painter->setPen(pen);
        QString s = QObject::tr("曲线") + QString::number(city+1) + ":" + m_curvename.at(city);
        painter->drawText(QRectF(-230,-195+city*10, 10*s.length(), 10), Qt::AlignLeft|Qt::AlignVCenter, s);
    }
}

void GraphMain_LineType1::initData(QVector<FileInfo> fileinfo)
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    m_max = 0;
    m_min = 0;
    qreal sum[10];
    for(int k=0; k<10; ++k)
        sum[k] = 0;

    //进度条
    QProgressDialog *progress = new QProgressDialog(w);
    progress->setWindowTitle(QObject::tr("读取数据..."));
    progress->setCancelButton(0);
    int total = m_lines*(m_EndYear-m_StartYear+1);
    progress->setRange(0, total);
    progress->setMinimumDuration(25);
    progress->setMinimumSize(200, 10);
    progress->setAcceptDrops(false);
    progress->show();

    //曲线循环，有几条曲线就循环几遍
    for(int k=0; k<fileinfo.size(); ++k){
        QString FileName;
        FileName = fileinfo[k].m_FileName;
#ifdef DEBUG_INITDATA
        qDebug()<<"initial data"<<FileName;
#endif
        QFile *Popu;
        Popu = new QFile(FileName);
        if(!Popu->open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(w, QObject::tr("Warning!"), QObject::tr("未找到指定文件"));
            return;
        }
        QTextStream in(Popu);
        int index = fileinfo[0].m_index;
        int year = m_StartYear;

        //年份循环
        while(!in.atEnd()){
            QString line = in.readLine();
            year = line.section(",", 0, 0).toInt();
            if(year < m_StartYear)
                continue;
            if(year > m_EndYear)
                break;
            QString readdata = line.section(",", index, index);
            m_data[k][year-m_StartYear] = readdata.toDouble();
            sum[k] += m_data[k][year-m_StartYear];
            if(m_max < m_data[k][year-m_StartYear])
                m_max = m_data[k][year-m_StartYear];
            if(m_min > m_data[k][year-m_StartYear])
                m_min = m_data[k][year-m_StartYear];
            progress->setValue(total/m_lines*(k+1) + year-m_StartYear+1);
        }

        m_EndYear = m_EndYear > year? year : m_EndYear;
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
#ifdef DEBUG_INITDATA
    for(int i=0; i<m_lines; ++i)
        qDebug()<<sum[i];
#endif
    for(int i=0; i<m_lines; ++i){
        for(int j=0; j<123; ++j){
            m_PointUndermouse[i][j] = false;
            m_PointUndermouse[i][j] = false;
        }
    }

    //如果初始数据为0，则不显示这一年的数据       Edit on 2011.10.4 by TP
    for(int i=0; i<m_lines; ++i){
        if(m_data[i][0] == 0){
            m_StartYear++;
            m_CurrentYear++;
            break;
        }
    }
    max = toUpper(m_max);
    min = toLower(m_min);
#ifdef DEBUG_UNUSED
    qDebug()<<m_StartYear<<m_CurrentYear;
#endif
    progress->hide();
    delete progress;
}

void GraphMain_LineType1::initDataV2(QVector<FileInfo> fileinfo)
{
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
    m_max = 0;
    m_min = 0;
    qreal sum[10];
    for(int k=0; k<10; ++k)
        sum[k] = 0;

    //进度条
    QProgressDialog *progress = new QProgressDialog(w);
    progress->setWindowTitle(QObject::tr("读取数据..."));
    progress->setCancelButton(0);
    int total = m_lines*(m_EndYear-m_StartYear+1);
    progress->setRange(0, total);
    progress->setMinimumDuration(25);
    progress->setMinimumSize(200, 10);
    progress->setAcceptDrops(false);
    progress->show();

    for(int k=0; k<fileinfo.size(); ++k){
        // 在绝对路径的文件路径中提取出文件名
        QString filename = fileinfo[k].m_FileName.section('/', -1).section('.', 0 ,0);
        qDebug()<<"GraphMain_LineType1::initDataV2"<<filename;

        SchemePtr ptr(new Scheme(meta, buffer, filename));
        for(int year=m_StartYear; year<=m_EndYear; ++year){
            try{
                m_data[k][year-m_StartYear] = ptr->getInstance(year)[fileinfo[k].m_index];
            }
            catch(const RecordNotExist& e){
                qDebug()<<"GraphMain_LineType1::initDataV2"<<"Can't achieve record"<<e.name();
                m_data[k][year-m_StartYear] = 0.0;
            }
            if(m_max < m_data[k][year-m_StartYear])
                m_max = m_data[k][year-m_StartYear];
            if(m_min > m_data[k][year-m_StartYear])
                m_min = m_data[k][year-m_StartYear];
            progress->setValue(total/m_lines*(k+1) + year-m_StartYear+1);
        }

        //用人口总和来比较大小确定曲线的初始先后顺序
        int i;
        for(i=k-1; i>=0 && sum[i]<sum[k]; --i){
            m_order[i+1] = m_order[i];
        }
        m_order[i+1] = k;
    }

    progress->setValue(total);

#ifdef DEBUG_INITDATA
    for(int i=0; i<m_lines; ++i)
        qDebug()<<sum[i];
#endif

    for(int i=0; i<m_lines; ++i){
        for(int j=0; j<123; ++j){
            m_PointUndermouse[i][j] = false;
            m_PointUndermouse[i][j] = false;
        }
    }

    //如果初始数据为0，则不显示这一年的数据       Edit on 2011.10.4 by TP
    for(int i=0; i<m_lines; ++i){
        if(m_data[i][0] == 0){
            m_StartYear++;
            m_CurrentYear++;
            break;
        }
    }
    max = toUpper(m_max);
    min = toLower(m_min);
#ifdef DEBUG_UNUSED
    qDebug()<<m_StartYear<<m_CurrentYear;
#endif
    progress->hide();
    delete progress;
}

void GraphMain_LineType1::setYear(int year){
    m_CurrentYear = year;
    if(year < m_StartYear)
        m_CurrentYear = m_StartYear;
    if(year > m_EndYear)    //Edit on 2011.9.24 by TP
        m_CurrentYear = m_EndYear;
    update();//曲线的移动就是在这里实现的
    calKeyValue();
}

//这个函数的算法可以改进
void GraphMain_LineType1::calKeyValue()
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    for(int i=0; i<m_lines; i++){
        qreal ave,sum = 0;
        int min, max;
        int line = m_order[i];      //这个其实一点用都没有
        min = max = 0;
        for(int j=0; j<=m_CurrentYear-m_StartYear; j++){
            if(m_data[line][j] < m_data[line][min])
                min = j;
            if(m_data[line][j] > m_data[line][max])
                max = j;
            sum += m_data[line][j];
        }
        QString s1 = QString::number(m_data[line][max]) + ", "
                     + QString::number(max+m_StartYear) + QObject::tr("年");
        QString s2 = QString::number(m_data[line][min]) + ", "
                     + QString::number(min+m_StartYear) + QObject::tr("年");
        ave = sum / (m_CurrentYear-m_StartYear+1);
        w->setEditText(line, 1, s1);
        w->setEditText(line, 2, s2);
        w->setEditText(line, 3, QString::number(ave));
    }
}

//计算坐标上的最大刻度，支持负数
//在IEEE的双精度浮点数标准下适用
double GraphMain_LineType1::toUpper(double n)
{
    if(n < 0)
        return 0;
    union{
        double a;
        long long b;
    }temp;
    temp.a = n;                 //把输入转化为来进行位运算
    int exponent = -1023;       //bias of double presion float
    unsigned long long mask = 0x0010000000000000;
    int value = 1;
    for(int i=0; i<11; i++){
        if((mask&temp.b) != 0){
            exponent += value;
        }
        value = value<<1;
        mask = mask<<1;
    }
    //计算出来的次方是二进制下的，除以三后大致是十进制的次方的上界
    exponent /= 3;
    double upbound = pow(10.0, exponent);
    while(upbound > n)
        upbound /= 10.;
    upbound /= 10.0;        //取n的前两位
    int msb = (int)floor(n/upbound);
    if(msb%10 >= 5)         //如果第二位大于等于5则用整十的数作为最大刻度
        return (msb/10+1)*upbound*10.;
    else                    //否则用类似x500000的数作为最大刻度
        return (msb/10*10+5)*upbound;
}

//计算坐标上的最大刻度，支持负数
//在IEEE的双精度浮点数标准下适用
double GraphMain_LineType1::toLower(double n)
{
    if(n < 0)
        return -toUpper(-n);
    return 0;
}

void GraphMain_LineType1::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    w->deleteqvalueboard();
    if(m_showData){}
        MarkPoint(event->pos());
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    if(isMoving())
        return;
    QPointF click, start, end, p;
    QString t;
    QVector<QString> v1;
    QVector<QPointF> v2;
    QVector<QColor> v3;
    click = mapFromScene(event->pos());
    if(click.y()<m_yhighest || click.y()>m_ylowest || click.x()>m_xhighest || click.x()<m_xlowest)
        return;
    //Draw Vertical Line
    if(m_VLineEnable){
        start.setY(m_ylowest);
        start.setX(click.x());
        end.setY(m_yhighest-5);
        end.setX(click.x());

        if(!m_HLineEnable){
            for(int i=0; i<m_lines; i++){
                if(click.x() > m_xhighest)
                    continue;
                double tmp = (click.x()-m_xlowest)/m_dx;
                if(tmp <= m_CurrentYear-m_StartYear){
                    int yearbefore = (int)tmp;
                    int yearafter = yearbefore+1;
                    double tmpvalue = m_data[i][yearbefore] + (m_data[i][yearafter]-m_data[i][yearbefore])*(tmp-yearbefore);
                    if(fabs(tmpvalue-m_data[i][yearbefore]) < 1){
                        t = QString::number(yearbefore+m_StartYear) + " , " + QString::number(m_data[i][yearbefore]);
                        p.setX(yearbefore*m_dx+m_xlowest);
                        p.setY(m_ylowest-(m_data[i][yearbefore]-min)*m_dy);
                        v2.push_front(p);
                        v1.push_front(t);
                        v3.push_front(m_Color[i]);
                    }
                    else if(fabs(tmpvalue-m_data[i][yearafter]) < 1){
                        t = QString::number(yearafter+m_StartYear) + " , " + QString::number(m_data[i][yearafter]);
                        p.setX(yearafter*m_dx+m_xlowest);
                        p.setY(m_ylowest-(m_data[i][yearafter]-min)*m_dy);
                        v2.push_front(p);
                        v1.push_front(t);
                        v3.push_front(m_Color[i]);
                    }
                    else{
                        t = QString::number(tmp+m_StartYear) + " , " + QString::number(tmpvalue);
                        p.setX(click.x());
                        p.setY(m_ylowest-(tmpvalue-min)*m_dy);
                        v2.push_front(p);
                        v1.push_front(t);
                        v3.push_front(m_Color[i]);
                    }
                }
            }
        }
    }
    m_VLine = QLineF(start, end);
    //Draw Horizontal Line
    if(m_HLineEnable){
        start.setX(m_xlowest-5);
        start.setY(click.y());
        end.setX(m_xhighest);
        end.setY(click.y());
        if(!m_VLineEnable){
            double temp = (m_yzero-click.y())/m_dy;
#ifdef DEBUG_MOUSEEVENT
            qDebug()<<temp;
#endif
            for(int i=0; i<m_lines; i++){
                for(int j=0; j<m_CurrentYear-m_StartYear; j++){
                    if((m_data[i][j]-temp)*(m_data[i][j+1]-temp)<=0){
                        //如果和数据点很接近就显示数据点数据
                        if(fabs(m_data[i][j]-temp) < 1){
                            t = QString::number(j+m_StartYear) + " , " + QString::number(m_data[i][j]);
                            p.setX((j)*m_dx+m_xlowest);
                            p.setY(m_ylowest-(m_data[i][j]-min)*m_dy);
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                        else if(fabs(m_data[i][j+1]-temp) < 1){
                            t = QString::number(j+1+m_StartYear) + " , " + QString::number(m_data[i][j+1]);
                            p.setX((j+1)*m_dx+m_xlowest);
                            p.setY(m_ylowest-(m_data[i][j+1]-min)*m_dy);
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                        //否则则估算交接点的值作为显示
                        else{
                            double year = j+(temp-m_data[i][j])/(m_data[i][j+1]-m_data[i][j]);
                            t = QString::number(m_StartYear+year)+" , "+QString::number(temp);
                            p.setX(year*m_dx+m_xlowest);
                            p.setY(click.y());
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                    }
                }
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

void GraphMain_LineType1::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    w->deleteqvalueboard();
    if(m_showData){}
        MarkPoint(event->pos());
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    if(isMoving())
        return;
    QPointF click, start, end, p;
    QString t;
    QVector<QString> v1;
    QVector<QPointF> v2;
    QVector<QColor> v3;
    click = mapFromScene(event->pos());
    if(click.y()<m_yhighest || click.y()>m_ylowest || click.x()>m_xhighest || click.x()<m_xlowest)
        return;
    //Draw Vertical Line
    if(m_VLineEnable){
        start.setY(m_ylowest);
        start.setX(click.x());
        end.setY(m_yhighest-5);
        end.setX(click.x());

        if(!m_HLineEnable){
            for(int i=0; i<m_lines; i++){
                if(click.x() > m_xhighest)
                    continue;
                double tmp = (click.x()-m_xlowest)/m_dx;
                if(tmp <= m_CurrentYear-m_StartYear){
                    int yearbefore = (int)tmp;
                    int yearafter = yearbefore+1;
                    double tmpvalue = m_data[i][yearbefore] + (m_data[i][yearafter]-m_data[i][yearbefore])*(tmp-yearbefore);
                    if(fabs(tmpvalue-m_data[i][yearbefore]) < 1){
                        t = QString::number(yearbefore+m_StartYear) + " , " + QString::number(m_data[i][yearbefore]);
                        p.setX(yearbefore*m_dx+m_xlowest);
                        p.setY(m_ylowest-(m_data[i][yearbefore]-min)*m_dy);
                        v2.push_front(p);
                        v1.push_front(t);
                        v3.push_front(m_Color[i]);
                    }
                    else if(fabs(tmpvalue-m_data[i][yearafter]) < 1){
                        t = QString::number(yearafter+m_StartYear) + " , " + QString::number(m_data[i][yearafter]);
                        p.setX(yearafter*m_dx+m_xlowest);
                        p.setY(m_ylowest-(m_data[i][yearafter]-min)*m_dy);
                        v2.push_front(p);
                        v1.push_front(t);
                        v3.push_front(m_Color[i]);
                    }
                    else{
                        t = QString::number(tmp+m_StartYear) + " , " + QString::number(tmpvalue);
                        p.setX(click.x());
                        p.setY(m_ylowest-(tmpvalue-min)*m_dy);
                        v2.push_front(p);
                        v1.push_front(t);
                        v3.push_front(m_Color[i]);
                    }
                }
            }
        }
    }
    m_VLine = QLineF(start, end);
    //Draw Horizontal Line
    if(m_HLineEnable){
        start.setX(m_xlowest-5);
        start.setY(click.y());
        end.setX(m_xhighest);
        end.setY(click.y());
        if(!m_VLineEnable){
            double temp = (m_yzero-click.y())/m_dy;
#ifdef DEBUG_MOUSEEVENT
            qDebug()<<temp;
#endif
            for(int i=0; i<m_lines; i++){
                for(int j=0; j<m_CurrentYear-m_StartYear; j++){
                    if((m_data[i][j]-temp)*(m_data[i][j+1]-temp)<=0){
                        //如果和数据点很接近就显示数据点数据
                        if(fabs(m_data[i][j]-temp) < 1){
                            t = QString::number(j+m_StartYear) + " , " + QString::number(m_data[i][j]);
                            p.setX((j)*m_dx+m_xlowest);
                            p.setY(m_ylowest-(m_data[i][j]-min)*m_dy);
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                        else if(fabs(m_data[i][j+1]-temp) < 1){
                            t = QString::number(j+1+m_StartYear) + " , " + QString::number(m_data[i][j+1]);
                            p.setX((j+1)*m_dx+m_xlowest);
                            p.setY(m_ylowest-(m_data[i][j+1]-min)*m_dy);
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                        //否则则估算交接点的值作为显示
                        else{
                            double year = j+(temp-m_data[i][j])/(m_data[i][j+1]-m_data[i][j]);
#ifdef DEBUG_MOUSEEVENT
                            qDebug()<<"year"<<year;
#endif
                            t = QString::number(year)+" , "+QString::number(temp);
                            p.setX(year*m_dx+m_xlowest);
                            p.setY(click.y());
                            v2.push_front(p);
                            v1.push_front(t);
                            v3.push_front(m_Color[i]);
                        }
                    }
                }
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

void GraphMain_LineType1::setVLine(long population)
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

void GraphMain_LineType1::setHLine(int age)
{
    QPointF start, end;
    start.setX(-255);
    start.setY(175 - age*3);
    end.setX(250);
    end.setY(175 - age*3);
    m_HLineEnable = true;
    m_HLine = QLineF(start, end);
    update();
}

void GraphMain_LineType1::ShowCoordinate(QPainter *painter, QPointF pos, double xvalue, double yvalue)
{
    QPen pen;
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->setFont(QFont("Arial", 6 ,1));
    QString t;
    t = QString::number(xvalue, 'g', 5) + " , " + QString::number(yvalue);
    double length = t.length()*6;
    QPointF next;
    QPainterPath *path = new QPainterPath(pos);
    next = pos + QPointF(0, -15);
    path->lineTo(next);
    next = next + QPointF(length,0);
    path->lineTo(next);
    next = next + QPointF(0, 10);
    path->lineTo(next);
    next = next + QPointF(5-length, 0);
    path->lineTo(next);
    path->lineTo(pos);
    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawPath(*path);
    painter->setOpacity(0.65);
    painter->fillPath(*path, QBrush(Qt::green));
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->setOpacity(1);
    painter->drawText(QRectF(pos.x(), pos.y()-15, length, 10), Qt::AlignCenter, t);
    painter->drawText(QRectF(pos.x(),pos.y()-15,length, 10), Qt::AlignCenter, t);
}

void GraphMain_LineType1::MarkPoint(QPointF pos)
{
    //清除上次的标记记录
    memset(m_PointUndermouse, 0, sizeof m_PointUndermouse);

    for(int i=0; i<m_lines; ++i){
       int city = m_order[i];
       int year = (int)((pos.x()-m_xlowest)/m_dx);
       if(fabs(m_ylowest-(m_data[city][year]-min)*m_dy - pos.y()) < 1)
           m_PointUndermouse[city][year] = true;
    }
}

void GraphMain_LineType1::setChosen(int chosen)
{
    memset(m_chosen, 0, sizeof m_chosen);
    m_chosen[chosen] = true;
}
