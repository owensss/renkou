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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SearchObject
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelYear;
    QComboBox *comboYear;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelArea;
    QComboBox *comboArea;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *search;
    QPushButton *ok;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *SearchObject)
    {
        if (SearchObject->objectName().isEmpty())
            SearchObject->setObjectName(QStringLiteral("SearchObject"));
        SearchObject->resize(400, 145);
        gridLayout = new QGridLayout(SearchObject);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        labelYear = new QLabel(SearchObject);
        labelYear->setObjectName(QStringLiteral("labelYear"));

        horizontalLayout->addWidget(labelYear);

        comboYear = new QComboBox(SearchObject);
        comboYear->setObjectName(QStringLiteral("comboYear"));
        comboYear->setEditable(true);

        horizontalLayout->addWidget(comboYear);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        labelArea = new QLabel(SearchObject);
        labelArea->setObjectName(QStringLiteral("labelArea"));

        horizontalLayout->addWidget(labelArea);

        comboArea = new QComboBox(SearchObject);
        comboArea->setObjectName(QStringLiteral("comboArea"));
        comboArea->setEditable(true);

        horizontalLayout->addWidget(comboArea);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        search = new QPushButton(SearchObject);
        search->setObjectName(QStringLiteral("search"));
        search->setAutoDefault(false);

        horizontalLayout_2->addWidget(search);

        ok = new QPushButton(SearchObject);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setAutoDefault(false);

        horizontalLayout_2->addWidget(ok);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(SearchObject);

        QMetaObject::connectSlotsByName(SearchObject);
    } // setupUi

    void retranslateUi(QDialog *SearchObject)
    {
        SearchObject->setWindowTitle(QApplication::translate("SearchObject", "\346\237\245\346\211\276\347\240\224\347\251\266\345\257\271\350\261\241", 0));
        labelYear->setText(QApplication::translate("SearchObject", "\345\237\272\345\271\264\357\274\232", 0));
        labelArea->setText(QApplication::translate("SearchObject", "\345\234\260\345\214\272\357\274\232", 0));
        comboArea->clear();
        comboArea->insertItems(0, QStringList()
         << QApplication::translate("SearchObject", "\345\205\250\345\233\275", 0)
         << QApplication::translate("SearchObject", "\345\214\227\344\272\254", 0)
         << QApplication::translate("SearchObject", "\345\244\251\346\264\245", 0)
         << QApplication::translate("SearchObject", "\346\262\263\345\214\227", 0)
         << QApplication::translate("SearchObject", "\345\261\261\350\245\277", 0)
         << QApplication::translate("SearchObject", "\345\206\205\350\222\231\345\217\244", 0)
         << QApplication::translate("SearchObject", "\350\276\275\345\256\201", 0)
         << QApplication::translate("SearchObject", "\345\220\211\346\236\227", 0)
         << QApplication::translate("SearchObject", "\351\273\221\351\276\231\346\261\237", 0)
         << QApplication::translate("SearchObject", "\344\270\212\346\265\267", 0)
         << QApplication::translate("SearchObject", "\346\261\237\350\213\217", 0)
         << QApplication::translate("SearchObject", "\346\265\231\346\261\237", 0)
         << QApplication::translate("SearchObject", "\345\256\211\345\276\275", 0)
         << QApplication::translate("SearchObject", "\347\246\217\345\273\272", 0)
         << QApplication::translate("SearchObject", "\346\261\237\350\245\277", 0)
         << QApplication::translate("SearchObject", "\345\261\261\344\270\234", 0)
         << QApplication::translate("SearchObject", "\346\262\263\345\215\227", 0)
         << QApplication::translate("SearchObject", "\346\271\226\345\214\227", 0)
         << QApplication::translate("SearchObject", "\346\271\226\345\215\227", 0)
         << QApplication::translate("SearchObject", "\345\271\277\344\270\234", 0)
         << QApplication::translate("SearchObject", "\345\271\277\350\245\277", 0)
         << QApplication::translate("SearchObject", "\346\265\267\345\215\227", 0)
         << QApplication::translate("SearchObject", "\351\207\215\345\272\206", 0)
         << QApplication::translate("SearchObject", "\345\233\233\345\267\235", 0)
         << QApplication::translate("SearchObject", "\350\264\265\345\267\236", 0)
         << QApplication::translate("SearchObject", "\344\272\221\345\215\227", 0)
         << QApplication::translate("SearchObject", "\350\245\277\350\227\217", 0)
         << QApplication::translate("SearchObject", "\351\231\225\350\245\277", 0)
         << QApplication::translate("SearchObject", "\347\224\230\350\202\203", 0)
         << QApplication::translate("SearchObject", "\351\235\222\346\265\267", 0)
         << QApplication::translate("SearchObject", "\345\256\201\345\244\217", 0)
         << QApplication::translate("SearchObject", "\346\226\260\347\226\206", 0)
        );
        search->setText(QApplication::translate("SearchObject", "\346\237\245\350\257\242", 0));
        ok->setText(QApplication::translate("SearchObject", "\345\256\214\346\210\220", 0));
    } // retranslateUi

};

namespace Ui {
    class SearchObject: public Ui_SearchObject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHOBJECT_H
