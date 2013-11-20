//#include <QApplication>
#include <QTextCodec>
#include "mainwindow.h"
#include "newproject.h"
#include "openproject.h"
#include "searchobject.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    //MainWindow w;
    //NewProject w;
    //OpenProject w;
    SearchObject w;
    w.show();
    return a.exec();
}
