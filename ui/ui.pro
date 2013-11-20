#-------------------------------------------------
#
# Project created by QtCreator 2013-10-19T16:17:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    uimanager.cpp \
    newproject.cpp \
    openproject.cpp \
    searchobject.cpp \
    importbasicdata.cpp \
    importbasicpara.cpp \
    entercalculate.cpp \
    evaluate.cpp \
    display.cpp

HEADERS  += \
    mainwindow.h \
    uimanager.h \
    newproject.h \
    openproject.h \
    searchobject.h \
    importbasicdata.h \
    importbasicpara.h \
    entercalculate.h \
    evaluate.h \
    display.h

FORMS += \
    progress_bar.ui \
    newproject.ui \
    mainwindow.ui \
    linetype2.ui \
    linetype1.ui \
    evaluate.ui \
    display.ui \
    dia_accu_linetype2.ui \
    custommadearea.ui \
    dia_accu_linetype1.ui \
    importbasicpara.ui \
    doingcalcprogress.ui \
    importbasicdata.ui \
    openproject.ui \
    searchobject.ui \
    entercalculate.ui
