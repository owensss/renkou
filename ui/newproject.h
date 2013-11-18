#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QLineEdit>
#include <QLabel>

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
};

#endif // NEWPROJECT_H
