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
INCLUDEPATH += E:\renkou\sourcecode\renkou\renkou-build-Qt5-Debug\lib
LIBS += -LD:\Soft\boost_1_51_0\stage\lib -lboost_filesystem-mgw47-1_51 -lboost_system-mgw47-1_51 -L..\lib\ \
-L..\..\lib\ -LE:\renkou\sourcecode\renkou\renkou-build-Qt5-Debug\lib -lScheme
DEPENDPATH += ..\Scheme
# PRE_TARGETDEPS += ..\lib\libscheme.a
INCLUDE += -ID:\Soft\boost_1_51_0

SOURCES += evaluate.cpp \
		method_add.cpp
HEADERS += method_add.h \
                evaluate.h \
		method_add_impl.h


INCLUDEPATH += ../Scheme/
