#ifndef QVALUEBOARD_H
#define QVALUEBOARD_H

#include <QGraphicsItem>

class QValueBoard : public QGraphicsItem
{
public:
    QValueBoard(QString s, double dx, double dy, QColor color);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;             //用于检测碰撞的形状
    void SetDx(qreal dx){   m_dx = dx;   }  //设置x方向偏移量
    void SetDy(qreal dy){   m_dy = dy;   }  //设置y方向偏移量
    qreal GetDx(){   return m_dx;   }       //获得x方向偏移量
    qreal GetDy(){   return m_dy;   }       //获得y方向偏移量

private:
    QPainterPath realshape() const;          //实际的形状，用于绘图

private:
    QString m_coor;         //待显示字符串
    qreal m_zvalue;
    double m_dx;
    double m_dy;       //x和y方向上的偏移量
    QColor m_color;     //颜色
};

#endif // QVALUEBOARD_H
