#include <QtGui>
#include <QtOpenGL>
#include <GL/glu.h>
#include <QDebug>
#include <cmath>
#include "Constants.h"
#include "graph4dmap.h"

#include "../Scheme/SchemeBuffer.hpp"
#include "../Scheme/Scheme.hpp"
#include "../Scheme/ConfigMan.hpp"
#include "../Scheme/schememetadata.h"
#include "../Scheme/SchemeInstance.hpp"
#include "../Scheme/exceptions/ColumnNotExist.hpp"
#include "../Scheme/exceptions/ValueNotExist.hpp"
#include "../Scheme/AbstractScheme.hpp"

using namespace std;

#define HAVE_DATA 1

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

GLdouble quad[][3] = { //bottom surface
                       { 0.0, 0.0, 0.0},
                       { 1.0, 0.0, 0.0},
                       { 1.0, 0.0,-1.0},
                       { 0.0, 0.0,-1.0},
                       {-1.0, 0.0,-1.0},
                       {-1.0, 0.0, 1.0},
                       { 0.0, 0.0, 1.0},
                       //top surface
                       { 0.0, 1.0, 0.0},
                       { 1.0, 1.0, 0.0},
                       { 1.0, 1.0,-1.0},
                       { 0.0, 1.0,-1.0},
                       {-1.0, 1.0,-1.0},
                       {-1.0, 1.0, 1.0},
                       { 0.0, 1.0, 1.0},
};

GLdouble quadcolor[][3] = { //bottom surface
                       { 1.0, 0.0, 0.0},
                       { 0.0, 1.0, 0.0},
                       { 0.0, 0.0, 1.0},
                       { 1.0, 1.0, 0.0},
                       { 1.0, 0.0, 1.0},
                       { 0.0, 1.0, 1.0},
                       { 1.0, 1.0, 1.0},
                       //top surface
                       { 1.0, 0.0, 0.0},
                       { 0.0, 1.0, 0.0},
                       { 0.0, 0.0, 1.0},
                       { 1.0, 1.0, 0.0},
                       { 1.0, 0.0, 1.0},
                       { 0.0, 1.0, 1.0},
                       { 1.0, 1.0, 1.0},
};

GLdouble ppp[40000][3];

//------------------------------------------------------------	OnDraw()
//
void CALLBACK PolyLine3DBegin(GLenum type)
{
        glBegin(type);
}

void CALLBACK PolyLine3DVertex ( GLdouble * vertex)
{
        const GLdouble *pointer;
        pointer = (GLdouble *) vertex;
//       glColor3d(1.0,0,0);//在此设置颜色
        glVertex3d(vertex[0], vertex[1], vertex[2]);
}

void CALLBACK PolyLine3DEnd()
{
        glEnd();
}

GLUtesselator* tesser()
{
        GLUtesselator * tess;
        tess=gluNewTess();
        gluTessCallback(tess,GLU_TESS_BEGIN,(void (CALLBACK*)())&PolyLine3DBegin);
        gluTessCallback(tess,GLU_TESS_VERTEX,(void (CALLBACK*)())&PolyLine3DVertex);
        gluTessCallback(tess,GLU_TESS_END,(void (CALLBACK*)())&PolyLine3DEnd);
        return tess;
}

/////////////////////////////////////////////////////////////////////////////////

//计算坐标上的最大刻度，支持负数
//在IEEE的双精度浮点数标准下适用
static double toUpper(double n)
{
    if(n < 0)
        return 0;
    union{
        double a;
        long long b;
    }temp;
    temp.a = n;                 //把输入转化为来进行位运算
    int exponent = -1023;       //bias of double presion float
    unsigned long long mask = 0x0010000000000000LL;
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
static double toLower(double n)
{
    if(n < 0)
        return -toUpper(-n);
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////

Graph4DMap::Graph4DMap(QStringList curve, QVector<FileInfo> file, int sy, int ey, QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    //汉字支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));

    this->init_height_ = 0.1*20;
    this->rotate_X_ = 0;
    this->rotate_Y_ = 0;
    this->rotate_Z_ = 0;
    this->translate_X_ = -0.3;  //试出来的
    this->translate_Y_ = 0.3;
    this->translate_Z_ = -2.8;
    this->scaling_ = 1.0;

    this->qtPurple_ = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
    this->curve_names_ = curve;

    setAutoBufferSwap(false);
    setAutoFillBackground(false);
    setMinimumSize(200, 200);
    setWindowTitle(tr("4DMapStep1"));

    this->loadMap();
    this->setStartYear(sy);
    this->setEndYear(ey);
    this->setCurrentYear(sy);
    this->loadDataV2(file);

    this->createGradient();
}

Graph4DMap::~Graph4DMap()
{
//    this->makeCurrent();
//    glDeleteLists(this->glObject, 2);
}

void Graph4DMap::setStartYear(int year)
{
    this->start_year_ = year;
}

void Graph4DMap::setEndYear(int year)
{
    this->end_year_ = year;
}

void Graph4DMap::initializeGL()
{
    glShadeModel(GL_SMOOTH);
}

void Graph4DMap::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
//create a qpainter
//    QPainter painter(this);

//    painter.end();

    //save OpenGL state
    //use OpenGL to build model

    makeCurrent();

    switch(this->type_){
    case bar:
        this->drawBarGraph();
        break;
    case color:
        this->drawColorGraph();
        break;
    default:
        this->drawBarGraph();
        break;
    }

    //restore OpenGL state
    //use qpainter to paint foreground
    //delete the qpainter

    swapBuffers();
}

void Graph4DMap::resizeGL(int w, int h)
{
    qreal pixelRatio = devicePixelRatio();
    setupViewport(w*pixelRatio, h*pixelRatio);
}

void Graph4DMap::setupViewport(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-3, +3, -3.0, +3.0, 0.0, 150.0);
//    gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void Graph4DMap::drawBarGraph()
{
    //save OpenGL state
    //use OpenGL to build model

    qreal pixelRatio = devicePixelRatio();
    setupViewport(width() * pixelRatio, height() * pixelRatio);

    glPushMatrix();
    glLoadIdentity();

    qglClearColor(qtPurple_.dark());
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glDisable(GL_LIGHTING);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    //设置全局的旋转平移缩放
    glTranslated(this->translate_X_, this->translate_Y_, this->translate_Z_);
    glRotated(rotate_X_/16.0, 1.0, 0.0, 0.0);
    glRotated(rotate_Y_/16.0, 0.0, 1.0, 0.0);
    glRotated(rotate_Z_/16.0, 0.0, 0.0, 1.0);
    glScaled(this->scaling_, this->scaling_, this->scaling_);

    QMapIterator<QString, ProvinceContent > i(provinces_);

    while(i.hasNext()){
        i.next();
        glPushMatrix();
        ProvinceContent p = i.value();
        double temp_strech = (p.dataAt(current_year_ - start_year_)-data_lower_bound_) / data_range_;
//        qDebug()<<current_year_<<","<<temp_strech;
        glScaled(1.0, temp_strech, 1.0);
        for(int j=0; j<p.getBlockNumber(); ++j){
            glCallList(p.getDisplayListForBar(j));
        }
        glPopMatrix();
    }

    glShadeModel(GL_FLAT);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();


    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

void Graph4DMap::drawColorGraph()
{
    //save OpenGL state
    //use OpenGL to build model

    setupViewport(width(), height());

    glPushMatrix();
    glLoadIdentity();

    qglClearColor(qtPurple_.dark());
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_MULTISAMPLE);
    static GLfloat lightPosition[4] = { 0.5, 5.0, 7.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glDisable(GL_LIGHTING);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    //设置全局的旋转平移缩放
    glTranslated(this->translate_X_, this->translate_Y_, this->translate_Z_);
    glRotated(rotate_X_/16.0, 1.0, 0.0, 0.0);
    glRotated(rotate_Y_/16.0, 0.0, 1.0, 0.0);
    glRotated(rotate_Z_/16.0, 0.0, 0.0, 1.0);
    glScaled(this->scaling_, this->scaling_, this->scaling_);

    QMapIterator<QString, ProvinceContent > i(provinces_);

    while(i.hasNext()){
        i.next();
        glPushMatrix();
        ProvinceContent p = i.value();
        double temp_color = (p.dataAt(current_year_ - start_year_)-data_lower_bound_) / data_range_;
        qDebug()<<"draw color graph"<<temp_color;
        glColor3d(temp_color, temp_color, temp_color);
        for(int j=0; j<p.getBlockNumber(); ++j){
            glCallList(p.getDisplayListForColor(j));
        }
        glPopMatrix();
    }

    glShadeModel(GL_FLAT);
    glDisable(GL_CULL_FACE);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();


    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

QSize Graph4DMap::sizeHint() const
{
    qDebug()<<"Graph4DMap::sizeHint()"<<QSize(600,400);
    return QSize(600,40);
}

QRectF Graph4DMap::boundingRect() const
{
    qreal adjust = 2;
    qDebug()<<"Graph4DMap::boundingRect()"<<QRectF(-300-adjust/2,-200-adjust/2,600+adjust,400+adjust);
    return QRectF(-300-adjust/2,-200-adjust/2,600+adjust,400+adjust);
}

void Graph4DMap::loadMap()
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB18030"));
    const QString mapFileName = QObject::tr("K:\\demography\\归一化全国省份边界百度坐标V2.txt");

    //Open the map file
    QFile *mapFile = new QFile(mapFileName);
    if(!mapFile->open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<mapFileName;
        return ;
    }

    int n;  //number of blocks of a province
    int m;  //number of points in a block
    double x, y;    //temp variables
    QString province;   // the name of a province
    QTextStream stream(mapFile);    //use a text stream to read the map file

    this->provinces_.clear();

    this->makeCurrent();
    while(!stream.atEnd()){
        stream>>province>>n;
        provinces_[province] = ProvinceContent();
        provinces_[province].setColor(GREEN, top_face);
        provinces_[province].setColor(YELLOW, side_face);
        provinces_[province].setColor(BLUE, bottom_face);
        for(int i=0; i<n; ++i){
            //------------------read in the points-------------------
            QVector<QPair<double,double> > bounds;
            stream>>m;
            bounds.resize(m);
            for(int j=0; j<m; ++j){
                stream>>x>>y;
                bounds[j] = qMakePair(x,y);
            }

            QPair<double, double> p, q; //temp variables
            GLUtesselator* tess;
            int k;
            GLuint obj;
            GLdouble vertex[3];

            //generate the display list for bar
            obj = glGenLists(1);
            this->provinces_[province].list_for_bar_.push_back(obj);


            glNewList(obj, GL_COMPILE);

            glShadeModel(GL_FLAT);

            //---------------draw the top surface-----------------
            tess = tesser();
            if(!tess)
                return;

            gluTessBeginPolygon(tess, NULL);
            qglColor(this->provinces_[province].getColor(top_face));
            glFrontFace(GL_CCW);         //坐标都是按逆时针方向存的，所以顶面的正面是逆时针

            gluTessBeginContour(tess);
            k = 0;

            QVectorIterator<QPair<double, double> > point(bounds);
            while(point.hasNext()){
                p = point.next();
                ppp[k][0] = p.first;
                ppp[k][1] = this->init_height_;
                ppp[k][2] = -p.second;
                gluTessVertex(tess, ppp[k], ppp[k]);
                ++k;
            }
            gluTessEndContour(tess);

            gluTessEndPolygon(tess);

            //---------------------draw bottom surface------------------------

            gluTessBeginPolygon(tess, NULL);
            qglColor(this->provinces_[province].getColor(bottom_face));
            glFrontFace(GL_CW);         //坐标都是按逆时针方向存的，所以底面的正面是顺时针

            gluTessBeginContour(tess);
            k = 0;
            point.toFront();
            while(point.hasNext()){
                QPair<double,double> p = point.next();
                ppp[k][0] = p.first;
                ppp[k][1] = 0;
                ppp[k][2] = -p.second;
                gluTessVertex(tess, ppp[k], ppp[k]);
                ++k;
            }
            gluTessEndContour(tess);

            gluTessEndPolygon(tess);

            gluDeleteTess(tess);

            //--------------------draw side surface-------------------------
            qglColor(this->provinces_[province].getColor(side_face));
            glFrontFace(GL_CCW);

            glBegin(GL_QUADS);
            point.toFront();
            q = point.next();
            while(point.hasNext()){
                p = q;
                q = point.next();
                vertex[0] = p.first;
                vertex[1] = init_height_;
                vertex[2] = -p.second;
                glVertex3dv(vertex);
                vertex[0] = p.first;
                vertex[1] = 0.0;
                vertex[2] = -p.second;
                glVertex3dv(vertex);
                vertex[0] = q.first;
                vertex[1] = 0.0;
                vertex[2] = -q.second;
                glVertex3dv(vertex);
                vertex[0] = q.first;
                vertex[1] = init_height_;
                vertex[2] = -q.second;
                glVertex3dv(vertex);
            }
            point.toFront();
            p = q;  //p为最后一个点
            q = point.next();   //q为第一个点
            //绘制最后一个点和第一个点连接的面
            vertex[0] = p.first;
            vertex[1] = init_height_;
            vertex[2] = -p.second;
            glVertex3dv(vertex);
            vertex[0] = p.first;
            vertex[1] = 0.0;
            vertex[2] = -p.second;
            glVertex3dv(vertex);
            vertex[0] = q.first;
            vertex[1] = 0.0;
            vertex[2] = -q.second;
            glVertex3dv(vertex);
            vertex[0] = q.first;
            vertex[1] = init_height_;
            vertex[2] = -q.second;
            glVertex3dv(vertex);

            glEnd();

            glEndList();

            //generate the display list for color
            obj = glGenLists(1);
            this->provinces_[province].list_for_color_.push_back(obj);

            glNewList(obj, GL_COMPILE);

            glShadeModel(GL_FLAT);

            //---------------draw the top surface-----------------
            tess = tesser();
            if(!tess)
                return;

            gluTessBeginPolygon(tess, NULL);
//            qglColor(this->provinces_[province].getColor(top_face));
            glFrontFace(GL_CCW);         //坐标都是按逆时针方向存的，所以顶面的正面是逆时针

            gluTessBeginContour(tess);
            k = 0;

            point.toFront();
            while(point.hasNext()){
                p = point.next();
                ppp[k][0] = p.first;
                ppp[k][1] = this->init_height_;
                ppp[k][2] = -p.second;
                gluTessVertex(tess, ppp[k], ppp[k]);
                ++k;
            }
            gluTessEndContour(tess);

            gluTessEndPolygon(tess);

            //---------------------draw bottom surface------------------------

            gluTessBeginPolygon(tess, NULL);
//            qglColor(this->provinces_[province].getColor(bottom_face));
            glFrontFace(GL_CW);         //坐标都是按逆时针方向存的，所以底面的正面是顺时针

            gluTessBeginContour(tess);
            k = 0;
            point.toFront();
            while(point.hasNext()){
                QPair<double,double> p = point.next();
                ppp[k][0] = p.first;
                ppp[k][1] = 0;
                ppp[k][2] = -p.second;
                gluTessVertex(tess, ppp[k], ppp[k]);
                ++k;
            }
            gluTessEndContour(tess);

            gluTessEndPolygon(tess);

            gluDeleteTess(tess);

            //--------------------draw side surface-------------------------
            qglColor(this->provinces_[province].getColor(side_face));
            glFrontFace(GL_CCW);

            glBegin(GL_QUADS);
            point.toFront();
            q = point.next();
            while(point.hasNext()){
                p = q;
                q = point.next();
                vertex[0] = p.first;
                vertex[1] = init_height_;
                vertex[2] = -p.second;
                glVertex3dv(vertex);
                vertex[0] = p.first;
                vertex[1] = 0.0;
                vertex[2] = -p.second;
                glVertex3dv(vertex);
                vertex[0] = q.first;
                vertex[1] = 0.0;
                vertex[2] = -q.second;
                glVertex3dv(vertex);
                vertex[0] = q.first;
                vertex[1] = init_height_;
                vertex[2] = -q.second;
                glVertex3dv(vertex);
            }
            point.toFront();
            p = q;  //p为最后一个点
            q = point.next();   //q为第一个点
            //绘制最后一个点和第一个点连接的面
            vertex[0] = p.first;
            vertex[1] = init_height_;
            vertex[2] = -p.second;
            glVertex3dv(vertex);
            vertex[0] = p.first;
            vertex[1] = 0.0;
            vertex[2] = -p.second;
            glVertex3dv(vertex);
            vertex[0] = q.first;
            vertex[1] = 0.0;
            vertex[2] = -q.second;
            glVertex3dv(vertex);
            vertex[0] = q.first;
            vertex[1] = init_height_;
            vertex[2] = -q.second;
            glVertex3dv(vertex);

            glEnd();

            glEndList();
        }
    }
    this->provinces_.remove("");
    mapFile->close();
    glShadeModel(GL_SMOOTH);
}

void Graph4DMap::loadData(QVector<FileInfo> files)
{
    //qDebug()<<"In function Graph4DMap::loadData";
    if(HAVE_DATA){
        //汉字支持
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
        QProgressDialog *progress = new QProgressDialog;
        QMutableMapIterator<QString, ProvinceContent> it(this->provinces_);
        double min_value = 0;
        double max_value = 0;
        while(it.hasNext()){
            it.next();
            QString ProvinceName = it.key();
            it.value().datas_.resize(end_year_ - start_year_ + 1);
            for(int k=0; k<files.size(); ++k){
                if(files[k].m_FileName.contains(ProvinceName)){
                    //qDebug()<<"Reading Data of Province"+ProvinceName+".";
                    progress->setWindowTitle(QObject::tr("reading data of") + ProvinceName);
                    progress->setRange(0, end_year_-start_year_);
                    progress->setMinimumDuration(0);
                    progress->setMinimumSize(200, 10);
                    progress->setAcceptDrops(false);
                    progress->show();

                    QString FileName = files[k].m_FileName;
                    QFile *file = new QFile(FileName);
                    if(!file->open(QFile::ReadOnly | QFile::Text)){
                        QMessageBox::warning(0, QObject::tr("Warning!"), QObject::tr("未找到指定文件"));
                        return;
                    }
                    QTextStream in(file);
                    int index = files[0].m_index;
                    int year;

                    //年份循环
                    while(!in.atEnd()){
                        QString line = in.readLine();
                        year = line.section(",", 0, 0).toInt();
                        if(year < start_year_)
                            continue;
                        if(year > this->end_year_)
                            break;
                        QString readdata = line.section(",", index, index);
                       //qDebug()<<year<<","<<readdata;
                        double temp_value = readdata.toDouble();
                        if(temp_value > max_value)
                            max_value = temp_value;
                        if(temp_value < min_value)
                            min_value = temp_value;
                        it.value().datas_[year-start_year_] = temp_value;
                        progress->setValue(year - start_year_);
                    }

                    file->close();
                    progress->hide();
                }
            }
        }
        this->data_upper_bound_ = toUpper(max_value);
        this->data_lower_bound_ = toLower(min_value);
        this->data_range_ = data_upper_bound_ - data_lower_bound_;
    }else{  // just for debug, simple datas generated with cos function
        QMutableMapIterator<QString, ProvinceContent> it(this->provinces_);
        int count = 0;
        while(it.hasNext()){
            it.next();
            for(int i=start_year_; i<end_year_; ++i){
                it.value().datas_.push_back(abs(cos(count*0.01*Pi)));
                ++count;
            }
        }
    }
}

void Graph4DMap::loadDataV2(QVector<FileInfo> files)
{
    //qDebug()<<"In function Graph4DMap::loadDataV2";
    if(HAVE_DATA){

        using Config::config;
        if( !config.read()){
            return ;
        }

        if(files.empty()){
            return ;
        }

        //汉字支持
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

        std::shared_ptr<schememetadata> meta;
        if(files.front().m_FileName.contains(QObject::tr("夫妇子女")))
        {
            meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_FUFUZINV")));
        }
        else if(files.front().m_FileName.contains(QObject::tr("人口概要")))
        {
            meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_RENKOUGAIYAO")));
        }
        else if(files.front().m_FileName.contains(QObject::tr("生育孩次")))
        {
            meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_SHENGYUHAICI")));
        }
        else //if(files.front().m_FileName.contains(QObject::tr("政策生育")))
        {
            meta = std::shared_ptr<schememetadata>( new schememetadata(QString("META_ZHENGCESHENGYU")));
        }

        std::shared_ptr<SchemeBuffer> buffer(new SchemeBuffer);


        //汉字支持
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
        QProgressDialog *progress = new QProgressDialog;
        QMutableMapIterator<QString, ProvinceContent> it(this->provinces_);
        double min_value = 0;
        double max_value = 0;
        while(it.hasNext()){
            it.next();
            QString ProvinceName = it.key();
            it.value().datas_.resize(end_year_ - start_year_ + 1);
            for(int k=0; k<files.size(); ++k){
                if(files[k].m_FileName.contains(ProvinceName)){
                    qDebug()<<"Reading Data of Province"+ProvinceName+".";
                    progress->setWindowTitle(QObject::tr("reading data of") + ProvinceName);
                    progress->setRange(0, end_year_-start_year_);
                    progress->setMinimumDuration(0);
                    progress->setMinimumSize(200, 10);
                    progress->setAcceptDrops(false);
                    progress->show();

                    // 在绝对路径的文件路径中提取出文件名
                    QString filename = files[k].m_FileName.section('/', -1).section('.', 0 ,0);
                    qDebug()<<"GraphMain_LineType1::initDataV2"<<filename;
                    SchemePtr ptr(new Scheme(meta, buffer, filename));

                    //年份循环
                    for(int year=start_year_; year<=end_year_; ++year){
                        double temp_value;
                        try{
                            // Occurs Error HEAP: Free Heap block 13843128 modified at 138431A0 after it was freed
                            temp_value = ptr->getInstance(year)[files[k].m_index];
                        }
                        catch(const RecordNotExist& e){
                            temp_value = 0.0;
                            qDebug() << e.name() << endl;
                        }
                        if(temp_value > max_value)
                            max_value = temp_value;
                        if(temp_value < min_value)
                            min_value = temp_value;
                        it.value().datas_[year-start_year_] = temp_value;
                        progress->setValue(year - start_year_);
                    }

                    progress->hide();
                }
            }
        }
        this->data_upper_bound_ = toUpper(max_value);
        this->data_lower_bound_ = toLower(min_value);
        this->data_range_ = data_upper_bound_ - data_lower_bound_;
    }else{
        QMutableMapIterator<QString, ProvinceContent> it(this->provinces_);
        int count = 0;
        while(it.hasNext()){
            it.next();
            for(int i=start_year_; i<end_year_; ++i){
                it.value().datas_.push_back(abs(cos(count*0.01*Pi)));
                ++count;
            }
        }
    }
}

void Graph4DMap::createGradient()
{
    gradient_ = QLinearGradient(QPoint(0,0), QPoint(width(),height()));
    gradient_.setColorAt(0, Qt::transparent);
    gradient_.setColorAt(.5, Qt::cyan);
    gradient_.setColorAt(1, Qt::transparent);
}

void Graph4DMap::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_U:
        this->scaling_ += 0.2;
        update();
        break;
    case Qt::Key_I:
        this->scaling_ -= 0.2;
        update();
        break;
    case Qt::Key_A:
        this->translate_X_ -= .10;
        update();
        break;
    case Qt::Key_D:
        this->translate_X_ += .10;
        update();
        break;
    case Qt::Key_W:
        this->translate_Y_ += .10;
        update();
        break;
    case Qt::Key_S:
        this->translate_Y_ -= .10;
        update();
        break;
    case Qt::Key_Z:
        this->translate_Z_ += .10;
        update();
        break;
    case Qt::Key_X:
        this->translate_Z_ -= .10;
        update();
        break;
    case Qt::Key_R:
        this->rotate_Y_ += 1.1;
        update();
        break;
    case Qt::Key_P:
        qDebug()<<"transX"<<"transY"<<"transZ";
        qDebug()<<translate_X_<<translate_Y_<<translate_Z_;
        qDebug()<<"rotateX"<<"rotateY"<<"rotateZ";
        qDebug()<<rotate_X_<<rotate_Y_<<rotate_Z_;
        break;
    case Qt::Key_Q:
        this->cc += 50;
        update();
    }
}

static void qNormalizeAngle(int &angle)
{
    while(angle < 0)
        angle += 360 * 16;
    while(angle > 360 * 16)
        angle -= 360 * 16;
}

void Graph4DMap::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if(angle != this->rotate_X_){
        rotate_X_ = angle;
        update();
    }
}

void Graph4DMap::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if(angle != this->rotate_Y_){
        rotate_Y_ = angle;
        update();
    }
}

void Graph4DMap::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if(angle != this->rotate_Z_){
        rotate_Z_ = angle;
        update();
    }
}

void Graph4DMap::setXTranslation(double movement)
{
    if(translate_X_ != movement){
        translate_X_ = movement;
        update();
    }
}

void Graph4DMap::setYTranslation(double movement)
{
    if(translate_Y_ != movement){
        translate_Y_ = movement;
        update();
    }
}

void Graph4DMap::setZTranslation(double movement)
{
    if(translate_Z_ != movement){
        translate_Z_ = movement;
        update();
    }
}

void Graph4DMap::setScalling(double scaling)
{
    if(this->scaling_ != scaling){
        this->scaling_ = scaling;
        update();
    }
}


void Graph4DMap::setCurrentYear(int year)
{
    this->current_year_ = year;
}

void Graph4DMap::mousePressEvent(QMouseEvent *event)
{
    this->last_position_ = event->pos();
}

void Graph4DMap::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - last_position_.x();
    int dy = event->y() - last_position_.y();

    if(event->buttons() & Qt::LeftButton){
        setXTranslation(translate_X_ + 5.0*dx/width());
        setYTranslation(translate_Y_ - 5.0*dy/height());
    }else if(event->buttons() & Qt::RightButton){
        setXRotation(rotate_X_ + 8*dy);
        setZRotation(rotate_Z_ + 8*dx);
    }
    this->last_position_ = event->pos();
}

void Graph4DMap::wheelEvent(QWheelEvent *event)
{
    setScalling(scaling_ + 0.1*event->delta()/120);
}

void Graph4DMap::setMapViewType(map_view_type t)
{
    if(this->type_ != t){
        this->type_ = t;
        update();
    }
}
