#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QtWidgets/QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QFileDialog>
#include <QDir>
#include <QLabel>
#include <QMessageBox>
#include <QTextCodec>
#include "uimanager.h"

namespace Ui {
class NewProject;
}

class NewProject : public QDialog
{
    Q_OBJECT

public:
    explicit NewProject(QWidget *parent = 0);
    ~NewProject();

private:
    Ui::NewProject *ui;
    UiManager *uiManager;

private slots:
    void projectNameEdited(QString _filename);
    void savePathEdited(QString _filename);
    void selectPathButtonClicked();
    void okButtonClicked();
    void cancelButtonClicked();

};

#endif // NEWPROJECT_H
