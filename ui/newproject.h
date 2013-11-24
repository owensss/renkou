#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QLabel>
#include <QMessageBox>
#include "uiitem.h"
namespace Ui {
class NewProject;
}

class NewProject : public QDialog, public UiItem
{
    Q_OBJECT

public:
    explicit NewProject(QWidget *parent = nullptr);
    ~NewProject();

private:
    Ui::NewProject *ui;

private slots:
    void projectNameEdited(QString _filename);
    //void savePathEdited(QString _filename);
    void selectPathButtonClicked();
    void okButtonClicked();
    void cancelButtonClicked();

};

#endif // NEWPROJECT_H
