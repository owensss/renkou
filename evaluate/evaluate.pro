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
INCLUDEPATH += G:\github\renkou\lib
INCLUDEPATH += G:\boost_1_53_0\mingw\include\boost-1_53
LIBS += -LG:\boost_1_53_0\mingw\lib -lboost_filesystem-mgw47-1_53 -lboost_system-mgw47-1_53
LIBS += G:\github\renkou\lib\libScheme.a
DEPENDPATH += ..\Scheme
# PRE_TARGETDEPS += ..\lib\libscheme.a

SOURCES += evaluate.cpp \
		method_add.cpp
HEADERS += method_add.h \
                evaluate.h \
		method_add_impl.h


INCLUDEPATH += ../Scheme/
