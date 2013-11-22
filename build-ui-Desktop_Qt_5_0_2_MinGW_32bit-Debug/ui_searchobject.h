/********************************************************************************
** Form generated from reading UI file 'searchobject.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHOBJECT_H
#define UI_SEARCHOBJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_searchObject
{
public:
    QPushButton *searchButton;
    QComboBox *comboYear;
    QLabel *label_3;
    QLabel *label_2;
    QComboBox *comboArea;
    QPushButton *pushButton;

    void setupUi(QDialog *searchObject)
    {
        if (searchObject->objectName().isEmpty())
            searchObject->setObjectName(QStringLiteral("searchObject"));
        searchObject->resize(400, 145);
        searchButton = new QPushButton(searchObject);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(210, 100, 75, 23));
        comboYear = new QComboBox(searchObject);
        comboYear->setObjectName(QStringLiteral("comboYear"));
        comboYear->setGeometry(QRect(90, 50, 69, 22));
        comboYear->setEditable(true);
        label_3 = new QLabel(searchObject);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 50, 54, 12));
        label_2 = new QLabel(searchObject);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 50, 54, 12));
        comboArea = new QComboBox(searchObject);
        comboArea->setObjectName(QStringLiteral("comboArea"));
        comboArea->setGeometry(QRect(230, 50, 69, 22));
        comboArea->setEditable(true);
        pushButton = new QPushButton(searchObject);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 100, 75, 23));

        retranslateUi(searchObject);

        QMetaObject::connectSlotsByName(searchObject);
    } // setupUi

    void retranslateUi(QDialog *searchObject)
    {
        searchObject->setWindowTitle(QApplication::translate("searchObject", "\346\237\245\346\211\276\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        searchButton->setText(QApplication::translate("searchObject", "\346\237\245\350\257\242", 0));
        comboYear->clear();
        comboYear->insertItems(0, QStringList()
         << QApplication::translate("searchObject", "1980", 0)
         << QApplication::translate("searchObject", "1981", 0)
         << QApplication::translate("searchObject", "1982", 0)
         << QApplication::translate("searchObject", "1983", 0)
         << QApplication::translate("searchObject", "1984", 0)
         << QApplication::translate("searchObject", "1985", 0)
         << QApplication::translate("searchObject", "1986", 0)
         << QApplication::translate("searchObject", "1987", 0)
         << QApplication::translate("searchObject", "1988", 0)
         << QApplication::translate("searchObject", "1989", 0)
         << QApplication::translate("searchObject", "1990", 0)
         << QApplication::translate("searchObject", "1991", 0)
         << QApplication::translate("searchObject", "1992", 0)
         << QApplication::translate("searchObject", "1993", 0)
         << QApplication::translate("searchObject", "1994", 0)
         << QApplication::translate("searchObject", "1995", 0)
         << QApplication::translate("searchObject", "1996", 0)
         << QApplication::translate("searchObject", "1997", 0)
         << QApplication::translate("searchObject", "1998", 0)
         << QApplication::translate("searchObject", "1999", 0)
         << QApplication::translate("searchObject", "2000", 0)
         << QApplication::translate("searchObject", "2001", 0)
         << QApplication::translate("searchObject", "2002", 0)
         << QApplication::translate("searchObject", "2003", 0)
         << QApplication::translate("searchObject", "2004", 0)
         << QApplication::translate("searchObject", "2005", 0)
         << QApplication::translate("searchObject", "2006", 0)
         << QApplication::translate("searchObject", "2007", 0)
         << QApplication::translate("searchObject", "2008", 0)
         << QApplication::translate("searchObject", "2009", 0)
         << QApplication::translate("searchObject", "2010", 0)
        );
        label_3->setText(QApplication::translate("searchObject", "\345\234\260\345\214\272\357\274\232", 0));
        label_2->setText(QApplication::translate("searchObject", "\345\237\272\345\271\264\357\274\232", 0));
        comboArea->clear();
        comboArea->insertItems(0, QStringList()
         << QApplication::translate("searchObject", "\345\205\250\345\233\275", 0)
         << QApplication::translate("searchObject", "\345\214\227\344\272\254", 0)
         << QApplication::translate("searchObject", "\345\244\251\346\264\245", 0)
         << QApplication::translate("searchObject", "\346\262\263\345\214\227", 0)
         << QApplication::translate("searchObject", "\345\261\261\350\245\277", 0)
         << QApplication::translate("searchObject", "\345\206\205\350\222\231\345\217\244", 0)
         << QApplication::translate("searchObject", "\350\276\275\345\256\201", 0)
         << QApplication::translate("searchObject", "\345\220\211\346\236\227", 0)
         << QApplication::translate("searchObject", "\351\273\221\351\276\231\346\261\237", 0)
         << QApplication::translate("searchObject", "\344\270\212\346\265\267", 0)
         << QApplication::translate("searchObject", "\346\261\237\350\213\217", 0)
         << QApplication::translate("searchObject", "\346\265\231\346\261\237", 0)
         << QApplication::translate("searchObject", "\345\256\211\345\276\275", 0)
         << QApplication::translate("searchObject", "\347\246\217\345\273\272", 0)
         << QApplication::translate("searchObject", "\346\261\237\350\245\277", 0)
         << QApplication::translate("searchObject", "\345\261\261\344\270\234", 0)
         << QApplication::translate("searchObject", "\346\262\263\345\215\227", 0)
         << QApplication::translate("searchObject", "\346\271\226\345\214\227", 0)
         << QApplication::translate("searchObject", "\346\271\226\345\215\227", 0)
         << QApplication::translate("searchObject", "\345\271\277\344\270\234", 0)
         << QApplication::translate("searchObject", "\345\271\277\350\245\277", 0)
         << QApplication::translate("searchObject", "\346\265\267\345\215\227", 0)
         << QApplication::translate("searchObject", "\351\207\215\345\272\206", 0)
         << QApplication::translate("searchObject", "\345\233\233\345\267\235", 0)
         << QApplication::translate("searchObject", "\350\264\265\345\267\236", 0)
         << QApplication::translate("searchObject", "\344\272\221\345\215\227", 0)
         << QApplication::translate("searchObject", "\350\245\277\350\227\217", 0)
         << QApplication::translate("searchObject", "\351\231\225\350\245\277", 0)
         << QApplication::translate("searchObject", "\347\224\230\350\202\203", 0)
         << QApplication::translate("searchObject", "\351\235\222\346\265\267", 0)
         << QApplication::translate("searchObject", "\345\256\201\345\244\217", 0)
         << QApplication::translate("searchObject", "\346\226\260\347\226\206", 0)
        );
        pushButton->setText(QApplication::translate("searchObject", "\345\256\214\346\210\220", 0));
    } // retranslateUi

};

namespace Ui {
    class searchObject: public Ui_searchObject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHOBJECT_H
