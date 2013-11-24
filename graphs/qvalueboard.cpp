#include <QPainter>
#include <math.h>
#include "qvalueboard.h"
#define Pi 3.141592654

QValueBoard::QValueBoard(QString s, double dx, double dy, QColor color)
    :m_coor(s), m_zvalue(1)
{
    setCacheMode(DeviceCoordinateCache);
    m_dx = dx;
    m_dy = dy;
    m_color = color;
    setZValue(m_zvalue);
}

void QValueBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPath(this->realshape());
    painter->setOpacity(0.65);
    painter->fillPath(this->realshape(), QBrush(m_color));
    painter->setOpacity(1);
    painter->setFont(QFont("Arial", 6 ,1));
    painter->drawText(shape().boundingRect(), Qt::AlignCenter, m_coor);
}

QPainterPath QValueBoard::shape() const
{
    QPainterPath path;
    if(m_dy > 0)
        path.addRect(m_dx, m_dy, 5*m_coor.length(), 8);
    else
        path.addRect(m_dx, -8+m_dy, 5*m_coor.length(), 8);
    return path;
}

QPainterPath QValueBoard::realshape() const
{
    QPainterPath path;
//    path.setFillRule(Qt::WindingFill);
    path.moveTo(0, 0);

    //In Region I
    if(m_dx>=0 && m_dy<=0){
        //数据牌向上偏移
        path.lineTo(m_dx, m_dy);
        path.lineTo(m_dx, -8+m_dy);
        path.lineTo(m_coor.length()*5+m_dx, -8+m_dy);
        path.lineTo(m_coor.length()*5+m_dx, m_dy);
        path.lineTo(5+m_dx, 0+m_dy);
        path.lineTo(0, 0);
    }
    //In Region II
    else if(m_dx<=0 && m_dy<0){
        //数据牌向上偏移
        path.lineTo(m_dx, m_dy);
        path.lineTo(m_dx, -8+m_dy);
        path.lineTo(m_coor.length()*5+m_dx, -8+m_dy);
        path.lineTo(m_coor.length()*5+m_dx, m_dy);
        path.lineTo(5+m_dx, 0+m_dy);
        path.lineTo(0, 0);
    }
    //In Region III
    else if(m_dx<0 && m_dy>=0){
        //数据牌向下偏移
        path.lineTo(m_dx, m_dy);
        path.lineTo(m_dx, 8+m_dy);
        path.lineTo(m_coor.length()*5+m_dx, 8+m_dy);
        path.lineTo(m_coor.length()*5+m_dx, m_dy);
        path.lineTo(5+m_dx,  m_dy);
        path.lineTo(0, 0);
    }
    //In Region IV
    else{
        //数据牌向下偏移
        path.lineTo(m_dx, m_dy);
        path.lineTo(m_dx, 8+m_dy);
        path.lineTo(m_coor.length()*5+m_dx, 8+m_dy);
        path.lineTo(m_coor.length()*5+m_dx, m_dy);
        path.lineTo(5+m_dx,  m_dy);
        path.lineTo(0, 0);
    }
    return path;
}

QRectF QValueBoard::boundingRect() const
{
    return realshape().boundingRect();
}
