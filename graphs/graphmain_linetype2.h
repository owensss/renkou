#ifndef GRAPHMAIN_LINETYPE2_H
#define GRAPHMAIN_LINETYPE2_H

#include <QGraphicsItem>
#include <QMouseEvent>
#include "FileInfo.h"
class LineType2;
class GraphMain_LineType2 : public QGraphicsItem
{
public:
    GraphMain_LineType2(LineType2 *parent, QStringList curve, QVector<FileInfo> file, int sYear, int eYear);
    ~GraphMain_LineType2();
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
    int getStartYear(){ return m_StartYear; }
    void setChosen(int chosen);

private:
    void initData(QVector<FileInfo>);
    void initDataV2(QVector<FileInfo>);     // load datas using scheme class
    void DrawBarGraph(QPainter *painter);
    void DrawCurveGraph(QPainter *painter);
    long toUpper(long n);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void ShowCoordinate(QPainter *painter, QPointF pos, int age, long value);
    void MarkPoint(QPointF pos);
    void calKeyValue();
private:
    qreal m_arrowSize;
    QPointF m_point[111];
    qreal m_data[111], m_min, m_max; //曲线图的数据
    long m_Data_F[10][201][111], m_Data_M[10][201][111], m_Max, max; //人口金字塔的数据
    bool m_Data_F_undermouse[10][201][111], m_Data_M_undermouse[10][201][111]; //数据点是否高亮
    QPointF m_Age_M[111],m_Age_F[111];
    bool m_chosen[10];
    QColor m_Color[10];
    int m_order[10];
    int m_CurrentYear, m_StartYear, m_EndYear;        //显示至当前年份
    QLineF m_HLine, m_VLine;
    int m_lines;
    bool m_moving;            //true:动态， false:静止在某一年
    bool m_showData;          //true:显示数据点， false:不显示
    bool m_HLineEnable, m_VLineEnable;
    QStringList m_CurveName;
    LineType2 *w;
};


#endif // GRAPHMAIN_LINETYPE2_H
