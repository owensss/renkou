#-------------------------------------------------
#
# Project created by QtCreator 2011-04-15T16:29:28
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += "-std=c++0x"

#INCLUDEPATH += E:\software\MySQL\include
#LIBS += E:\software\MySQL\lib\libmysql.a

DEFINES += SRCDIR=\\\"$$PWD/\\\"
INCLUDEPATH += K:\renkou\Scheme
LIBS += -LK:\renkou\lib -lScheme

DEPENDPATH += ..\Scheme
PRE_TARGETDEPS += ..\lib\libscheme.a

TARGET = graphs
TEMPLATE = app

SOURCES += main.cpp\
    graphmain_linetype1.cpp \
    graphview.cpp \
    qvalueboard.cpp \
    linetype1.cpp \
    graphmain_linetype2.cpp \
    linetype2.cpp \
    coloriconengine.cpp \
    linetype3.cpp \
    graph4dmap.cpp \
    dia_accu_linetype2.cpp \
    dia_accu_linetype1.cpp

HEADERS  += mainwindow.h \
    graphmain_linetype1.h \
    graphview.h \
    qvalueboard.h \
    linetype1.h \
    graphmain_linetype2.h \
    linetype2.h \
    Objectcounter.h \
    coloriconengine.h \
    Constants.h \
    FileInfo.h \
    linetype3.h \
    graph4dmap.h \
    dia_accu_linetype2.h \
    dia_accu_linetype1.h

FORMS    += linetype1.ui \
    linetype2.ui \
    linetype3.ui \
    dia_accu_linetype2.ui \
    dia_accu_linetype1.ui

#RESOURCES += \
#    images.qrc \
#    Data.qrc

contains(QT_CONFIG, opengles.) {
    contains(QT_CONFIG, angle): \
        warning("Qt was built with ANGLE, which provides only OpenGL ES 2.0 on top of DirectX 9.0c")
    error("This example requires Qt to be configured with -opengl desktop")
}
