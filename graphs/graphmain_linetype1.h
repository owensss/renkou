#ifndef GraphMain_LineType1_LINETYPE1_H
#define GraphMain_LineType1_LINETYPE1_H

#include <QGraphicsItem>
#include <QMouseEvent>
#include <vector>
#include "FileInfo.h"

//using namespace std;
//普通曲线
class LineType1;
class GraphMain_LineType1 : public QGraphicsItem
{
public:
    GraphMain_LineType1(LineType1 *parent, QStringList curve, QVector<FileInfo> file, int sYear, int eYear);
    ~GraphMain_LineType1();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void changePoint();
    int CurrentYear(){return m_CurrentYear;}
    void setYear(int year);
    void setMoving(bool moving){m_moving = moving;}
    bool isMoving(){return m_moving;}
    void HLineEnabled(bool enable){m_HLineEnable = enable;}
    bool isHLineEnable(){return m_HLineEnable;}
    void VLineEnabled(bool enable){m_VLineEnable = enable;}
    bool isVLineEnable(){return m_VLineEnable;}
    void setShowData(bool show){m_showData = show;}
    void setHLine(int age);
    void setVLine(long population);
    int getEndYear(){  return m_EndYear;   }
    int getStartYear(){    return m_StartYear; }
    void setChosen(int chosen);
private:
    void initData(QVector<FileInfo>);
    void initDataV2(QVector<FileInfo>);     // load datas using scheme class
    void DrawBarGraph(QPainter *painter);
    void DrawCurveGraph(QPainter *painter);
    void DrawCoordinates(QPainter *painter);
    void Draw3DBarGraph(QPainter *painter);
    double toUpper(double n);
    double toLower(double n);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void ShowCoordinate(QPainter *painter, QPointF pos, double xvalue, double yvalue);
    void MarkPoint(QPointF pos);
    void calKeyValue();
private:
    qreal m_arrowSize;
    QPointF m_point[10][201];
    QColor m_Color[10];
    bool m_chosen[10];
    qreal m_data[10][201];        //曲线图的数据
    qreal m_max, m_min;      //最大最小数据
    qreal min, max;          //坐标轴的最大最小值
    int m_order[10];
    int m_CurrentYear, m_StartYear, m_EndYear;        //显示至当前年份
    QLineF m_HLine, m_VLine;
    int m_lines;
    bool m_PointUndermouse[10][201];            //
    bool m_moving;            //true:动态， false:静止在某一年
    bool m_showData;          //true:显示数据点， false:不显示
    bool m_HLineEnable, m_VLineEnable;
    QStringList m_curvename;
    LineType1 *w;
    double m_Xlength;
    double m_dx;
    double m_Ylength;
    double m_dy;
    double m_ylowest;           //在曲线图主体部分y的最小值，因为坐标是倒的，所以是正数
    double m_yhighest;          //在曲线图主体部分y的最大值，负数
    double m_xlowest;           //在曲线图主体部分x的最小值，正数
    double m_xhighest;          //在曲线图主体部分x的最大值，负数
    double m_yzero;             //0对应的y坐标值
};
#endif // GraphMain_LineType1_LineType1_LINETYPE1_H
