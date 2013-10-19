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
INCLUDEPATH += E:\renkou\sourcecode\renkou\Scheme
INCLUDEPATH += D:\Soft\boost_1_53_0
LIBS += -LD:\Soft\boost_1_53_0\stage\lib -lboost_filesystem-mgw47-mt-1_53 -lboost_system-mgw47-mt-1_53
LIBS += -LE:\renkou\sourcecode\renkou\lib -lScheme
DEPENDPATH += ..\Scheme
PRE_TARGETDEPS += ..\lib\libscheme.a

SOURCES += evaluate.cpp \
		method_add.cpp
HEADERS += method_add.h \
                evaluate.h \
		method_add_impl.h


INCLUDEPATH += ../Scheme/
