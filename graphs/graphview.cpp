#include "graphview.h"

GraphView::GraphView(QWidget *parent)
    :QGraphicsView(parent)
{
    setCacheMode(CacheBackground);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
}

void GraphView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    fitInView(scene()->sceneRect());
}
