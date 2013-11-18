//#include <QApplication>
#include <QTextCodec>
#include "mainwindow.h"
#include "newproject.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    //MainWindow w;
    NewProject w;
    w.show();
    return a.exec();
}
