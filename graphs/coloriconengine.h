#ifndef COLORICONENGINE_H
#define COLORICONENGINE_H

#include <QIconEngine>

//绘制单色的图标
class ColorIconEngine : public QIconEngine
{
public:
    ColorIconEngine(QColor color);
    void paint(QPainter *painter, const QRect &rect, QIcon::Mode mode, QIcon::State state);
    void setColor(QColor color);
    virtual QIconEngine* clone() const;

private:
    QColor m_Color;
};

#endif // COLORICONENGINE_H
