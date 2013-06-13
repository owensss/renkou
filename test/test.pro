<<<<<<< HEAD
#-------------------------------------------------
#
# Project created by QtCreator 2013-06-09T10:06:56
#
#-------------------------------------------------

QT       += widgets sql testlib

TARGET = tst_testtest
CONFIG   += console
CONFIG   -= app_bundle
QMAKE_CXXFLAGS += "-std=c++0x"

TEMPLATE = app


SOURCES += tst_testtest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
INCLUDEPATH += E:\renkou\sourcecode\renkou\Scheme
LIBS += -LE:\renkou\sourcecode\renkou\lib -lScheme
DEPENDPATH += ..\Scheme
PRE_TARGETDEPS += ..\lib\libscheme.a
=======
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
>>>>>>> 965dbe3e8a0ef395f8f0932f5263cde96d85fd30
