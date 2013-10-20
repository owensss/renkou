#---------------------------------------
# 
#  PROJECT CREATED BY OWENSSS 2013/03/03
#
#---------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = evaluate
TMEPLATE = app
QMAKE_CXXFLAGS += "-std=c++0x"
# config += exceptions
INCLUDEPATH += K:\renkou\Scheme
INCLUDEPATH += F:\boost_1_54_0\
DEPENDPATH += ..\Scheme
PRE_TARGETDEPS += ..\lib\libscheme.a

LIBS += -LK:\renkou\lib -LF:\boost_1_54_0\stage\lib
LIBS += -lScheme -lboost_filesystem-mgw48-mt-1_54 -lboost_system-mgw48-mt-1_54

SOURCES += evaluate.cpp \
		method_add.cpp \
    add_multi.cpp
HEADERS += method_add.h \
                evaluate.h \
		method_add_impl.h \
    add_multi.h
