#ifndef OPENPROJECT_H
#define OPENPROJECT_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QDir>
#include <QLabel>
#include <QMessageBox>
#include <QStringList>
#include <QChar>
#include "uimanager.h"

namespace Ui {
class OpenProject;
}

class OpenProject : public QDialog
{
    Q_OBJECT

public:
    explicit OpenProject(QWidget *parent = 0);
    ~OpenProject();

private:
    Ui::OpenProject *ui;
    UiManager *uiManager;

private slots:
    //void openPathEdited(QString _filename);
    void selectPathButtonClicked();
    void openButtonClicked();
    void cancelButtonClicked();

};

#endif // OPENPROJECT_H
