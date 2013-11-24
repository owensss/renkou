#include <QPainter>
#include "coloriconengine.h"

ColorIconEngine::ColorIconEngine(QColor color)
{
    m_Color = color;
}

void ColorIconEngine::paint(QPainter *painter, const QRect &rect, QIcon::Mode mode, QIcon::State state)
{
    Q_UNUSED(mode)
    Q_UNUSED(state)
    painter->setBrush(QBrush(m_Color));
    painter->drawRect(rect);
}

void ColorIconEngine::setColor(QColor color)
{
    m_Color = color;
}

QIconEngine* ColorIconEngine::clone() const
{
    return new ColorIconEngine(m_Color);
}
