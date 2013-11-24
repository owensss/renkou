#ifndef GRAPH4DMAP_H
#define GRAPH4DMAP_H

#include <QGLWidget>
#include <QColor>
#include "Constants.h"
#include "FileInfo.h"

QT_BEGIN_NAMESPACE
class QPaintEvent;
class QWidget;
class QKeyEvent;
QT_END_NAMESPACE

struct ProvinceContent
{
    QVector<GLuint> list_for_bar_;    //OpenGL的显示列表
    QVector<GLuint> list_for_color_;
    QVector<double> datas_;     //每一年的待显示数据值
    QColor top_face_color_;
    QColor bottom_face_color_;
    QColor side_face_color_;

    //获得块的数量
    int getBlockNumber() const
    {
        return list_for_bar_.size();
    }

    //获得指定块
    GLuint getDisplayListForBar(int n) const
    {
        return list_for_bar_[n];
    }

    GLuint getDisplayListForColor(int n)
    {
        return list_for_color_[n];
    }

    //获得指定年份的数据
    double dataAt(int n) const
    {
        double ret;
        if(n < 0)
            ret = datas_.front();
        else if(n >= datas_.size())
            ret = datas_.back();
        else
            ret = datas_[n];
        return ret;
    }

    //获得面的颜色
    QColor getColor(face f) const
    {
        QColor ret;
        switch(f){
        case top_face:
            ret = top_face_color_;
            break;
        case side_face:
            ret = side_face_color_;
            break;
        default: //case bottom_face:
            ret = bottom_face_color_;
            break;
        }
        return ret;
    }

    //设置面的颜色
    void setColor(QColor c, face f)
    {
        switch(f){
        case top_face:
            top_face_color_ = c;
            break;
        case side_face:
            side_face_color_ = c;
            break;
        case bottom_face:
            bottom_face_color_ = c;
            break;
        }
    }
};

class Graph4DMap : public QGLWidget
{
    Q_OBJECT
public:
    Graph4DMap(int sy = 2013, int ey = 2100, QWidget *parent = 0);
    Graph4DMap(QStringList curve, QVector<FileInfo> file, int sy, int ey, QWidget *parent = 0);
    ~Graph4DMap();

    QRectF boundingRect() const;
    QSize sizeHint() const;
    int getCurrentYear(){ return current_year_; }    //当前显示的年份
    int getStartYear(){ return start_year_; }
    int getEndYear(){   return end_year_;   }
    map_view_type getMapViewType(){ return this->type_;   }
    void setMapViewType(map_view_type t);

public slots:
    void setXRotation(int angle);   //设置地图绕x轴旋转角度
    void setYRotation(int angle);   //设置地图绕y轴旋转角度
    void setZRotation(int angle);   //设置地图绕z轴旋转角度
    void setXTranslation(double movement);  //设置地图沿x轴平移距离
    void setYTranslation(double movement);  //设置地图沿y轴平移距离
    void setZTranslation(double movement);  //设置地图沿z轴平移距离
    void setScalling(double scalling);      //设置地图的全局缩放
    void setCurrentYear(int year);     //设置当前年份
    void setStartYear(int year);
    void setEndYear(int year);

protected:
    void initializeGL();
    void paintEvent(QPaintEvent *event);
    void resizeGL(int w, int h);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    void setupViewport(int width, int height);
    void createGradient();  //生成用于画背景的画笔
    void loadMap();         //载入地图，生成显示列表
    void loadData(QVector<FileInfo> files);        //载入数据
    void loadDataV2(QVector<FileInfo> files);        //load data using scheme class
    void normalizeCoordinates();    //归一化地图坐标
    void drawBarGraph();            //画柱状图
    void drawColorGraph();          //画颜色变化图

    QColor qtPurple_;            //某一种颜色
    QLinearGradient gradient_;       //用于画背景
    QMap<QString, ProvinceContent> provinces_;
    double init_height_;    //初始的柱子高度
    double scaling_;   //全局缩放
    double rotate_X_;  //全局x旋转
    double rotate_Y_;  //全局y旋转
    double rotate_Z_;  //全局z旋转
    double translate_X_;    //全局x偏移
    double translate_Y_;    //全局y偏移
    double translate_Z_;    //全局z偏移
    QPoint last_position_;   //鼠标之前的位置

    int cc;//?

    int start_year_;    //开始年份
    int end_year_;  //结束年份
    int current_year_;  //当前显示的年份

    double data_upper_bound_;   //数据范围上限
    double data_lower_bound_;   //数据范围下限
    double data_range_;         //数据区间

    QStringList curve_names_;       //所显示的曲线名
    map_view_type type_;           //显示类型
};

#endif // GRAPH4DMAP_H
