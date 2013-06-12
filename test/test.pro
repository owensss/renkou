#-------------------------------------------------
#
# Project created by QtCreator 2013-06-12T14:08:42
#
#-------------------------------------------------

QT       += testlib

TARGET = tst_testtest
CONFIG   += console
CONFIG   -= app_bundle
QMAKE_CXXFLAGS += -std=c++0x
TEMPLATE = app


SOURCES += tst_testtest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
LIBS += ..\lib\libScheme.a
DEPENDPATH += ..\Scheme
# PRE_TARGETDEPS += ..\Scheme\Scheme.pro
INCLUDEPATH += ../Scheme/
