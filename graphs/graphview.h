#ifndef GRAPHVIEW_H
#define GRAPHVIEW_H

#include <QGraphicsView>

class GraphView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphView(QWidget *parent = 0);
protected:
    void resizeEvent(QResizeEvent *event);
};

#endif // GRAPHVIEW_H
