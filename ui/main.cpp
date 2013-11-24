#include <QApplication>
#include <QTextCodec>
#include "mainwindow.h"
#include "uimanager.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));
    MainWindow mainWindow;
    UiManager uiManager;
    mainWindow.setUiManager(&uiManager);
    mainWindow.show();
    return app.exec();
}
