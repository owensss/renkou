/********************************************************************************
** Form generated from reading UI file 'evaluate.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVALUATE_H
#define UI_EVALUATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Evaluate
{
public:
    QGridLayout *gridLayout_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QWidget *page_2;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QWidget *page_3;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_4;
    QListWidget *listWidget;
    QPushButton *pushButton_4;
    QLabel *label_10;
    QLabel *label_7;
    QListWidget *listWidget_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QComboBox *comboArea_2;
    QLabel *label_12;
    QComboBox *comboBox_2;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer;
    QRadioButton *value1;
    QTableWidget *tableWidget;
    QRadioButton *area1;
    QTreeWidget *value2;
    QLabel *label_3;
    QLabel *label_8;
    QComboBox *comboBox_method;
    QPushButton *pushButton_9;
    QComboBox *area2;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *exit;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Evaluate)
    {
        if (Evaluate->objectName().isEmpty())
            Evaluate->setObjectName(QStringLiteral("Evaluate"));
        Evaluate->resize(1197, 675);
        gridLayout_4 = new QGridLayout(Evaluate);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        stackedWidget = new QStackedWidget(Evaluate);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        pushButton_2 = new QPushButton(page);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(390, 400, 75, 31));
        comboBox = new QComboBox(page);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 30, 231, 22));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 91, 21));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        pushButton = new QPushButton(page);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 400, 75, 31));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 90, 351, 91));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 20, 81, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 52, 121, 20));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 20, 54, 12));
        groupBox_2 = new QGroupBox(page);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 220, 351, 151));
        checkBox_1 = new QCheckBox(groupBox_2);
        checkBox_1->setObjectName(QStringLiteral("checkBox_1"));
        checkBox_1->setGeometry(QRect(40, 30, 151, 16));
        checkBox_1->setChecked(true);
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(40, 70, 151, 16));
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(40, 110, 211, 16));
        checkBox_3->setChecked(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        textBrowser = new QTextBrowser(page_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 50, 411, 331));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 20, 91, 16));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 410, 141, 41));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout_2 = new QGridLayout(page_3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_4 = new QGroupBox(page_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        listWidget = new QListWidget(groupBox_4);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(15, 58, 256, 192));
        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(279, 260, 146, 32));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(285, 34, 52, 16));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(15, 34, 91, 16));
        listWidget_2 = new QListWidget(groupBox_4);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem1->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem2->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem3->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem4->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem5->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem6->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem7->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem8 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem8->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem9 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem9->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem10 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem10->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem11 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem11->setCheckState(Qt::Unchecked);
        QListWidgetItem *__qlistwidgetitem12 = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem12->setCheckState(Qt::Unchecked);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(285, 58, 256, 191));

        gridLayout_2->addWidget(groupBox_4, 0, 4, 5, 1);

        groupBox_3 = new QGroupBox(page_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        comboArea_2 = new QComboBox(groupBox_3);
        comboArea_2->setObjectName(QStringLiteral("comboArea_2"));
        comboArea_2->setEditable(false);

        gridLayout->addWidget(comboArea_2, 0, 1, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setEnabled(false);

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(103, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 2, 1);

        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(false);

        gridLayout->addWidget(pushButton_6, 3, 1, 1, 1);

        pushButton_7 = new QPushButton(groupBox_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setEnabled(false);

        gridLayout->addWidget(pushButton_7, 4, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_3, 5, 4, 2, 1);

        value1 = new QRadioButton(page_3);
        value1->setObjectName(QStringLiteral("value1"));
        value1->setEnabled(true);

        gridLayout_2->addWidget(value1, 3, 0, 1, 1);

        tableWidget = new QTableWidget(page_3);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 32)
            tableWidget->setRowCount(32);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(21, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(22, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(23, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(24, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(25, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(26, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(27, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(28, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(29, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(30, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(31, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setCheckState(Qt::Unchecked);
        tableWidget->setItem(0, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setCheckState(Qt::Unchecked);
        tableWidget->setItem(0, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setCheckState(Qt::Unchecked);
        tableWidget->setItem(0, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setCheckState(Qt::Unchecked);
        tableWidget->setItem(0, 3, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setCheckState(Qt::Unchecked);
        tableWidget->setItem(1, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setCheckState(Qt::Unchecked);
        tableWidget->setItem(1, 1, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setCheckState(Qt::Unchecked);
        tableWidget->setItem(1, 2, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setCheckState(Qt::Unchecked);
        tableWidget->setItem(1, 3, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        __qtablewidgetitem44->setCheckState(Qt::Unchecked);
        tableWidget->setItem(2, 0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        __qtablewidgetitem45->setCheckState(Qt::Unchecked);
        tableWidget->setItem(2, 1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        __qtablewidgetitem46->setCheckState(Qt::Unchecked);
        tableWidget->setItem(2, 2, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        __qtablewidgetitem47->setCheckState(Qt::Unchecked);
        tableWidget->setItem(2, 3, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        __qtablewidgetitem48->setCheckState(Qt::Unchecked);
        tableWidget->setItem(3, 0, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        __qtablewidgetitem49->setCheckState(Qt::Unchecked);
        tableWidget->setItem(3, 1, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        __qtablewidgetitem50->setCheckState(Qt::Unchecked);
        tableWidget->setItem(3, 2, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        __qtablewidgetitem51->setCheckState(Qt::Unchecked);
        tableWidget->setItem(3, 3, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        __qtablewidgetitem52->setCheckState(Qt::Unchecked);
        tableWidget->setItem(4, 0, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        __qtablewidgetitem53->setCheckState(Qt::Unchecked);
        tableWidget->setItem(4, 1, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        __qtablewidgetitem54->setCheckState(Qt::Unchecked);
        tableWidget->setItem(4, 2, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        __qtablewidgetitem55->setCheckState(Qt::Unchecked);
        tableWidget->setItem(4, 3, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        __qtablewidgetitem56->setCheckState(Qt::Unchecked);
        tableWidget->setItem(5, 0, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        __qtablewidgetitem57->setCheckState(Qt::Unchecked);
        tableWidget->setItem(5, 1, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        __qtablewidgetitem58->setCheckState(Qt::Unchecked);
        tableWidget->setItem(5, 2, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        __qtablewidgetitem59->setCheckState(Qt::Unchecked);
        tableWidget->setItem(5, 3, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        __qtablewidgetitem60->setCheckState(Qt::Unchecked);
        tableWidget->setItem(6, 0, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        __qtablewidgetitem61->setCheckState(Qt::Unchecked);
        tableWidget->setItem(6, 1, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        __qtablewidgetitem62->setCheckState(Qt::Unchecked);
        tableWidget->setItem(6, 2, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        __qtablewidgetitem63->setCheckState(Qt::Unchecked);
        tableWidget->setItem(6, 3, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        __qtablewidgetitem64->setCheckState(Qt::Unchecked);
        tableWidget->setItem(7, 0, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        __qtablewidgetitem65->setCheckState(Qt::Unchecked);
        tableWidget->setItem(7, 1, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        __qtablewidgetitem66->setCheckState(Qt::Unchecked);
        tableWidget->setItem(7, 2, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        __qtablewidgetitem67->setCheckState(Qt::Unchecked);
        tableWidget->setItem(7, 3, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        __qtablewidgetitem68->setCheckState(Qt::Unchecked);
        tableWidget->setItem(8, 0, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        __qtablewidgetitem69->setCheckState(Qt::Unchecked);
        tableWidget->setItem(8, 1, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        __qtablewidgetitem70->setCheckState(Qt::Unchecked);
        tableWidget->setItem(8, 2, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        __qtablewidgetitem71->setCheckState(Qt::Unchecked);
        tableWidget->setItem(8, 3, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        __qtablewidgetitem72->setCheckState(Qt::Unchecked);
        tableWidget->setItem(9, 0, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        __qtablewidgetitem73->setCheckState(Qt::Unchecked);
        tableWidget->setItem(9, 1, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        __qtablewidgetitem74->setCheckState(Qt::Unchecked);
        tableWidget->setItem(9, 2, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        __qtablewidgetitem75->setCheckState(Qt::Unchecked);
        tableWidget->setItem(9, 3, __qtablewidgetitem75);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        __qtablewidgetitem76->setCheckState(Qt::Unchecked);
        tableWidget->setItem(10, 0, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setCheckState(Qt::Unchecked);
        tableWidget->setItem(10, 1, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setCheckState(Qt::Unchecked);
        tableWidget->setItem(10, 2, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        __qtablewidgetitem79->setCheckState(Qt::Unchecked);
        tableWidget->setItem(10, 3, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setCheckState(Qt::Unchecked);
        tableWidget->setItem(11, 0, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        __qtablewidgetitem81->setCheckState(Qt::Unchecked);
        tableWidget->setItem(11, 1, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        __qtablewidgetitem82->setCheckState(Qt::Unchecked);
        tableWidget->setItem(11, 2, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        __qtablewidgetitem83->setCheckState(Qt::Unchecked);
        tableWidget->setItem(11, 3, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        __qtablewidgetitem84->setCheckState(Qt::Unchecked);
        tableWidget->setItem(12, 0, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        __qtablewidgetitem85->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(12, 1, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        __qtablewidgetitem86->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(12, 2, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        __qtablewidgetitem87->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(12, 3, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        __qtablewidgetitem88->setCheckState(Qt::Unchecked);
        tableWidget->setItem(13, 0, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        __qtablewidgetitem89->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(13, 1, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        __qtablewidgetitem90->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(13, 2, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        __qtablewidgetitem91->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(13, 3, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        __qtablewidgetitem92->setCheckState(Qt::Unchecked);
        tableWidget->setItem(14, 0, __qtablewidgetitem92);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        __qtablewidgetitem93->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(14, 1, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        __qtablewidgetitem94->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(14, 2, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        __qtablewidgetitem95->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(14, 3, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        __qtablewidgetitem96->setCheckState(Qt::Unchecked);
        tableWidget->setItem(15, 0, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        __qtablewidgetitem97->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(15, 1, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        __qtablewidgetitem98->setCheckState(Qt::Checked);
        tableWidget->setItem(15, 2, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        __qtablewidgetitem99->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(15, 3, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        __qtablewidgetitem100->setCheckState(Qt::Unchecked);
        tableWidget->setItem(16, 0, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        __qtablewidgetitem101->setCheckState(Qt::Checked);
        tableWidget->setItem(16, 1, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        __qtablewidgetitem102->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(16, 2, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        __qtablewidgetitem103->setCheckState(Qt::Checked);
        tableWidget->setItem(16, 3, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        __qtablewidgetitem104->setCheckState(Qt::Checked);
        tableWidget->setItem(17, 0, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        __qtablewidgetitem105->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(17, 1, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        __qtablewidgetitem106->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(17, 2, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        __qtablewidgetitem107->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(17, 3, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        __qtablewidgetitem108->setCheckState(Qt::Checked);
        tableWidget->setItem(18, 0, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        __qtablewidgetitem109->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(18, 1, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        __qtablewidgetitem110->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(18, 2, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        __qtablewidgetitem111->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(18, 3, __qtablewidgetitem111);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        __qtablewidgetitem112->setCheckState(Qt::Checked);
        tableWidget->setItem(19, 0, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        __qtablewidgetitem113->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(19, 1, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        __qtablewidgetitem114->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(19, 2, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        __qtablewidgetitem115->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(19, 3, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        __qtablewidgetitem116->setCheckState(Qt::Checked);
        tableWidget->setItem(20, 0, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        __qtablewidgetitem117->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(20, 1, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        __qtablewidgetitem118->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(20, 2, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        __qtablewidgetitem119->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(20, 3, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        __qtablewidgetitem120->setCheckState(Qt::Checked);
        tableWidget->setItem(21, 0, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        __qtablewidgetitem121->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(21, 1, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        __qtablewidgetitem122->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(21, 2, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        __qtablewidgetitem123->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(21, 3, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        __qtablewidgetitem124->setCheckState(Qt::Checked);
        tableWidget->setItem(22, 0, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        __qtablewidgetitem125->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(22, 1, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        __qtablewidgetitem126->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(22, 2, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        __qtablewidgetitem127->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(22, 3, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        __qtablewidgetitem128->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(23, 0, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        __qtablewidgetitem129->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(23, 1, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        __qtablewidgetitem130->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(23, 2, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        __qtablewidgetitem131->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(23, 3, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        __qtablewidgetitem132->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(24, 0, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        __qtablewidgetitem133->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(24, 1, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        __qtablewidgetitem134->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(24, 2, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        __qtablewidgetitem135->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(24, 3, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        __qtablewidgetitem136->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(25, 0, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        __qtablewidgetitem137->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(25, 1, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        __qtablewidgetitem138->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(25, 2, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        __qtablewidgetitem139->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(25, 3, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        __qtablewidgetitem140->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(26, 0, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        __qtablewidgetitem141->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(26, 1, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        __qtablewidgetitem142->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(26, 2, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        __qtablewidgetitem143->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(26, 3, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        __qtablewidgetitem144->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(27, 0, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        __qtablewidgetitem145->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(27, 1, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        __qtablewidgetitem146->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(27, 2, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        __qtablewidgetitem147->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(27, 3, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        __qtablewidgetitem148->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(28, 0, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        __qtablewidgetitem149->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(28, 1, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        __qtablewidgetitem150->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(28, 2, __qtablewidgetitem150);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        __qtablewidgetitem151->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(28, 3, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        __qtablewidgetitem152->setCheckState(Qt::Checked);
        tableWidget->setItem(29, 0, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        __qtablewidgetitem153->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(29, 1, __qtablewidgetitem153);
        QTableWidgetItem *__qtablewidgetitem154 = new QTableWidgetItem();
        __qtablewidgetitem154->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(29, 2, __qtablewidgetitem154);
        QTableWidgetItem *__qtablewidgetitem155 = new QTableWidgetItem();
        __qtablewidgetitem155->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(29, 3, __qtablewidgetitem155);
        QTableWidgetItem *__qtablewidgetitem156 = new QTableWidgetItem();
        __qtablewidgetitem156->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(30, 0, __qtablewidgetitem156);
        QTableWidgetItem *__qtablewidgetitem157 = new QTableWidgetItem();
        __qtablewidgetitem157->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(30, 1, __qtablewidgetitem157);
        QTableWidgetItem *__qtablewidgetitem158 = new QTableWidgetItem();
        __qtablewidgetitem158->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(30, 2, __qtablewidgetitem158);
        QTableWidgetItem *__qtablewidgetitem159 = new QTableWidgetItem();
        __qtablewidgetitem159->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(30, 3, __qtablewidgetitem159);
        QTableWidgetItem *__qtablewidgetitem160 = new QTableWidgetItem();
        __qtablewidgetitem160->setCheckState(Qt::Checked);
        tableWidget->setItem(31, 0, __qtablewidgetitem160);
        QTableWidgetItem *__qtablewidgetitem161 = new QTableWidgetItem();
        __qtablewidgetitem161->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(31, 1, __qtablewidgetitem161);
        QTableWidgetItem *__qtablewidgetitem162 = new QTableWidgetItem();
        __qtablewidgetitem162->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(31, 2, __qtablewidgetitem162);
        QTableWidgetItem *__qtablewidgetitem163 = new QTableWidgetItem();
        __qtablewidgetitem163->setCheckState(Qt::PartiallyChecked);
        tableWidget->setItem(31, 3, __qtablewidgetitem163);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_2->addWidget(tableWidget, 1, 2, 6, 2);

        area1 = new QRadioButton(page_3);
        area1->setObjectName(QStringLiteral("area1"));
        area1->setChecked(true);

        gridLayout_2->addWidget(area1, 2, 0, 1, 1);

        value2 = new QTreeWidget(page_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(value2);
        __qtreewidgetitem->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem2->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem1);
        __qtreewidgetitem3->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem4->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem4);
        __qtreewidgetitem5->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem6->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem7->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem8->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem9->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem10->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem11 = new QTreeWidgetItem(__qtreewidgetitem6);
        __qtreewidgetitem11->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem12 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem12->setCheckState(0, Qt::Unchecked);
        QTreeWidgetItem *__qtreewidgetitem13 = new QTreeWidgetItem(__qtreewidgetitem12);
        __qtreewidgetitem13->setCheckState(0, Qt::Unchecked);
        value2->setObjectName(QStringLiteral("value2"));
        value2->setEnabled(false);
        value2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        value2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        value2->header()->setDefaultSectionSize(200);
        value2->header()->setMinimumSectionSize(200);

        gridLayout_2->addWidget(value2, 4, 0, 2, 2);

        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        label_8 = new QLabel(page_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 3, 1, 1);

        comboBox_method = new QComboBox(page_3);
        comboBox_method->setObjectName(QStringLiteral("comboBox_method"));

        gridLayout_2->addWidget(comboBox_method, 1, 0, 1, 2);

        pushButton_9 = new QPushButton(page_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_2->addWidget(pushButton_9, 6, 0, 1, 2);

        area2 = new QComboBox(page_3);
        area2->setObjectName(QStringLiteral("area2"));
        area2->setEditable(false);

        gridLayout_2->addWidget(area2, 2, 1, 1, 1);

        label_11 = new QLabel(page_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 0, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        gridLayout_4->addWidget(stackedWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        exit = new QPushButton(Evaluate);
        exit->setObjectName(QStringLiteral("exit"));

        horizontalLayout->addWidget(exit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(Evaluate);

        stackedWidget->setCurrentIndex(2);
        comboArea_2->setCurrentIndex(0);
        area2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Evaluate);
    } // setupUi

    void retranslateUi(QDialog *Evaluate)
    {
        Evaluate->setWindowTitle(QApplication::translate("Evaluate", "\344\273\277\347\234\237\350\257\204\344\273\267", 0));
        pushButton_2->setText(QApplication::translate("Evaluate", "\345\217\226\346\266\210", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Evaluate", "\347\224\237\350\202\262\346\224\277\347\255\226\344\273\277\347\234\237\347\273\223\346\236\234\346\226\207\344\273\2660926", 0)
        );
        label->setText(QApplication::translate("Evaluate", "\344\273\277\347\234\237\347\273\223\346\236\234\351\233\206\357\274\232", 0));
        pushButton->setText(QApplication::translate("Evaluate", "\345\274\200\345\247\213\350\257\204\344\273\267", 0));
        groupBox->setTitle(QApplication::translate("Evaluate", "\344\273\277\347\234\237\347\273\223\346\236\234\351\233\206\344\277\241\346\201\257", 0));
        label_4->setText(QApplication::translate("Evaluate", "\344\273\277\347\234\237\350\265\267\345\247\213\345\271\264\357\274\232", 0));
        label_5->setText(QApplication::translate("Evaluate", "\345\234\260\345\214\272\350\214\203\345\233\264\357\274\232 \345\205\250\345\233\275", 0));
        label_6->setText(QApplication::translate("Evaluate", "2010", 0));
        groupBox_2->setTitle(QApplication::translate("Evaluate", "\344\273\277\347\234\237\350\257\204\344\273\267\346\226\271\346\263\225", 0));
        checkBox_1->setText(QApplication::translate("Evaluate", "\344\271\230\346\263\225\345\220\210\346\210\220\345\222\214\344\274\230\351\200\211", 0));
        checkBox_2->setText(QApplication::translate("Evaluate", "\345\212\240\346\263\225\345\220\210\346\210\220\345\222\214\344\274\230\351\200\211", 0));
        checkBox_3->setText(QApplication::translate("Evaluate", "\345\244\232\346\214\207\346\240\207\350\201\224\345\220\210\351\200\220\346\255\245\346\267\230\346\261\260\344\270\216\344\274\230\351\200\211", 0));
        label_2->setText(QApplication::translate("Evaluate", "\345\274\200\345\247\213\350\257\204\344\273\267\350\256\241\347\256\227", 0));
        pushButton_3->setText(QApplication::translate("Evaluate", "\346\237\245\347\234\213\350\257\204\344\273\267\347\273\223\346\236\234", 0));
        groupBox_4->setTitle(QApplication::translate("Evaluate", "\346\257\224\350\276\203\346\226\271\346\241\210", 0));
        pushButton_4->setText(QApplication::translate("Evaluate", "\345\233\276\345\203\217\346\274\224\347\244\272\346\211\200\351\200\211\346\226\271\346\241\210", 0));
        label_10->setText(QApplication::translate("Evaluate", "\351\200\211\346\213\251\346\214\207\346\240\207", 0));
        label_7->setText(QApplication::translate("Evaluate", "\345\275\223\345\211\215\351\200\211\344\270\255\347\232\204\346\226\271\346\241\210", 0));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Evaluate", "\346\200\273\350\247\204\346\250\241", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_2->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Evaluate", "\345\207\272\347\224\237\350\247\204\346\250\241", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_2->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Evaluate", "\345\207\272\347\224\237\347\216\207", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_2->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Evaluate", "\350\207\252\347\204\266\345\242\236\351\225\277\347\216\207", 0));
        QListWidgetItem *___qlistwidgetitem4 = listWidget_2->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Evaluate", "\347\224\237\350\202\262\347\216\207", 0));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_2->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Evaluate", "\345\212\263\345\212\250\345\271\264\351\276\204\344\272\272\345\217\243\345\215\240\346\200\273\344\272\272\345\217\243\346\257\224\351\207\215", 0));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_2->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("Evaluate", "\351\235\222\345\271\264\345\212\263\345\212\250\345\212\233\345\215\240\345\212\263\345\212\250\345\271\264\351\276\204\344\272\272\345\217\243\346\257\224\351\207\215", 0));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_2->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("Evaluate", "\345\271\264\351\276\204\344\270\255\344\275\215\346\225\260", 0));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_2->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("Evaluate", "\350\200\201\345\271\264\344\272\272\345\217\243\346\257\224\351\207\215", 0));
        QListWidgetItem *___qlistwidgetitem9 = listWidget_2->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("Evaluate", "\350\264\237\346\213\205\350\200\201\345\271\264\347\263\273\346\225\260", 0));
        QListWidgetItem *___qlistwidgetitem10 = listWidget_2->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("Evaluate", "\350\264\237\346\213\205\345\260\221\345\204\277\347\263\273\346\225\260", 0));
        QListWidgetItem *___qlistwidgetitem11 = listWidget_2->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("Evaluate", "\346\200\273\350\264\237\346\213\205\347\263\273\346\225\260", 0));
        QListWidgetItem *___qlistwidgetitem12 = listWidget_2->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("Evaluate", "\345\271\264\351\276\204\351\207\221\345\255\227\345\241\224\345\235\207\350\241\241\346\200\247", 0));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        groupBox_3->setTitle(QApplication::translate("Evaluate", "\346\237\245\350\257\242\346\226\271\346\241\210", 0));
        label_9->setText(QApplication::translate("Evaluate", "\351\200\211\346\213\251\345\234\260\345\214\272\357\274\232", 0));
        comboArea_2->clear();
        comboArea_2->insertItems(0, QStringList()
         << QApplication::translate("Evaluate", "\345\214\227\344\272\254", 0)
         << QApplication::translate("Evaluate", "\345\244\251\346\264\245", 0)
         << QApplication::translate("Evaluate", "\346\262\263\345\214\227", 0)
         << QApplication::translate("Evaluate", "\345\261\261\350\245\277", 0)
         << QApplication::translate("Evaluate", "\345\206\205\350\222\231\345\217\244", 0)
         << QApplication::translate("Evaluate", "\350\276\275\345\256\201", 0)
         << QApplication::translate("Evaluate", "\345\220\211\346\236\227", 0)
         << QApplication::translate("Evaluate", "\351\273\221\351\276\231\346\261\237", 0)
         << QApplication::translate("Evaluate", "\344\270\212\346\265\267", 0)
         << QApplication::translate("Evaluate", "\346\261\237\350\213\217", 0)
         << QApplication::translate("Evaluate", "\346\265\231\346\261\237", 0)
         << QApplication::translate("Evaluate", "\345\256\211\345\276\275", 0)
         << QApplication::translate("Evaluate", "\347\246\217\345\273\272", 0)
         << QApplication::translate("Evaluate", "\346\261\237\350\245\277", 0)
         << QApplication::translate("Evaluate", "\345\261\261\344\270\234", 0)
         << QApplication::translate("Evaluate", "\346\262\263\345\215\227", 0)
         << QApplication::translate("Evaluate", "\346\271\226\345\214\227", 0)
         << QApplication::translate("Evaluate", "\346\271\226\345\215\227", 0)
         << QApplication::translate("Evaluate", "\345\271\277\344\270\234", 0)
         << QApplication::translate("Evaluate", "\345\271\277\350\245\277", 0)
         << QApplication::translate("Evaluate", "\346\265\267\345\215\227", 0)
         << QApplication::translate("Evaluate", "\351\207\215\345\272\206", 0)
         << QApplication::translate("Evaluate", "\345\233\233\345\267\235", 0)
         << QApplication::translate("Evaluate", "\350\264\265\345\267\236", 0)
         << QApplication::translate("Evaluate", "\344\272\221\345\215\227", 0)
         << QApplication::translate("Evaluate", "\350\245\277\350\227\217", 0)
         << QApplication::translate("Evaluate", "\351\231\225\350\245\277", 0)
         << QApplication::translate("Evaluate", "\347\224\230\350\202\203", 0)
         << QApplication::translate("Evaluate", "\351\235\222\346\265\267", 0)
         << QApplication::translate("Evaluate", "\345\256\201\345\244\217", 0)
         << QApplication::translate("Evaluate", "\346\226\260\347\226\206", 0)
        );
        label_12->setText(QApplication::translate("Evaluate", "\351\200\211\346\213\251\346\226\271\346\241\210\357\274\232", 0));
        pushButton_5->setText(QApplication::translate("Evaluate", "\345\210\227\350\241\250\346\230\276\347\244\272\350\257\246\347\273\206\344\277\241\346\201\257", 0));
        pushButton_6->setText(QApplication::translate("Evaluate", "\345\212\240\345\205\245\345\210\260\346\226\271\346\241\210\346\257\224\350\276\203\344\270\255", 0));
        pushButton_7->setText(QApplication::translate("Evaluate", "\345\233\276\345\203\217\346\274\224\347\244\272", 0));
        value1->setText(QApplication::translate("Evaluate", "\351\200\211\346\213\251\346\214\207\346\240\207", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Evaluate", "\346\234\200\344\274\230\346\226\271\346\241\210", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Evaluate", "\346\254\241\344\274\230\346\226\271\346\241\210", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Evaluate", "\347\254\254\344\270\211\346\226\271\346\241\210", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Evaluate", "0", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Evaluate", "1", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Evaluate", "2", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Evaluate", "3", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("Evaluate", "4", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("Evaluate", "5", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("Evaluate", "6", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("Evaluate", "7", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("Evaluate", "8", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem12->setText(QApplication::translate("Evaluate", "9", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem13->setText(QApplication::translate("Evaluate", "10", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem14->setText(QApplication::translate("Evaluate", "11", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem15->setText(QApplication::translate("Evaluate", "12", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem16->setText(QApplication::translate("Evaluate", "13", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem17->setText(QApplication::translate("Evaluate", "14", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem18->setText(QApplication::translate("Evaluate", "15", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem19->setText(QApplication::translate("Evaluate", "16", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem20->setText(QApplication::translate("Evaluate", "17", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem21->setText(QApplication::translate("Evaluate", "18", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem22->setText(QApplication::translate("Evaluate", "19", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem23->setText(QApplication::translate("Evaluate", "20", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(21);
        ___qtablewidgetitem24->setText(QApplication::translate("Evaluate", "21", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(22);
        ___qtablewidgetitem25->setText(QApplication::translate("Evaluate", "22", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(23);
        ___qtablewidgetitem26->setText(QApplication::translate("Evaluate", "23", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(24);
        ___qtablewidgetitem27->setText(QApplication::translate("Evaluate", "24", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(25);
        ___qtablewidgetitem28->setText(QApplication::translate("Evaluate", "25", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(26);
        ___qtablewidgetitem29->setText(QApplication::translate("Evaluate", "26", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(27);
        ___qtablewidgetitem30->setText(QApplication::translate("Evaluate", "27", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(28);
        ___qtablewidgetitem31->setText(QApplication::translate("Evaluate", "28", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(29);
        ___qtablewidgetitem32->setText(QApplication::translate("Evaluate", "29", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->verticalHeaderItem(30);
        ___qtablewidgetitem33->setText(QApplication::translate("Evaluate", "30", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->verticalHeaderItem(31);
        ___qtablewidgetitem34->setText(QApplication::translate("Evaluate", "31", 0));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->item(0, 3);
        ___qtablewidgetitem35->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->item(1, 3);
        ___qtablewidgetitem36->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->item(2, 3);
        ___qtablewidgetitem37->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->item(3, 3);
        ___qtablewidgetitem38->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->item(4, 3);
        ___qtablewidgetitem39->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget->item(5, 3);
        ___qtablewidgetitem40->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget->item(6, 3);
        ___qtablewidgetitem41->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget->item(7, 3);
        ___qtablewidgetitem42->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget->item(8, 3);
        ___qtablewidgetitem43->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget->item(9, 3);
        ___qtablewidgetitem44->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget->item(10, 3);
        ___qtablewidgetitem45->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget->item(11, 3);
        ___qtablewidgetitem46->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget->item(12, 3);
        ___qtablewidgetitem47->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem48 = tableWidget->item(13, 3);
        ___qtablewidgetitem48->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem49 = tableWidget->item(14, 3);
        ___qtablewidgetitem49->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem50 = tableWidget->item(15, 3);
        ___qtablewidgetitem50->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem51 = tableWidget->item(16, 3);
        ___qtablewidgetitem51->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem52 = tableWidget->item(17, 3);
        ___qtablewidgetitem52->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem53 = tableWidget->item(18, 3);
        ___qtablewidgetitem53->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem54 = tableWidget->item(19, 3);
        ___qtablewidgetitem54->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem55 = tableWidget->item(20, 3);
        ___qtablewidgetitem55->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem56 = tableWidget->item(21, 3);
        ___qtablewidgetitem56->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem57 = tableWidget->item(22, 3);
        ___qtablewidgetitem57->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem58 = tableWidget->item(23, 3);
        ___qtablewidgetitem58->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem59 = tableWidget->item(24, 3);
        ___qtablewidgetitem59->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem60 = tableWidget->item(25, 3);
        ___qtablewidgetitem60->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem61 = tableWidget->item(26, 3);
        ___qtablewidgetitem61->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem62 = tableWidget->item(27, 3);
        ___qtablewidgetitem62->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem63 = tableWidget->item(28, 3);
        ___qtablewidgetitem63->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem64 = tableWidget->item(29, 3);
        ___qtablewidgetitem64->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem65 = tableWidget->item(30, 3);
        ___qtablewidgetitem65->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        QTableWidgetItem *___qtablewidgetitem66 = tableWidget->item(31, 3);
        ___qtablewidgetitem66->setText(QApplication::translate("Evaluate", "\345\205\250\351\200\211", 0));
        tableWidget->setSortingEnabled(__sortingEnabled1);

        area1->setText(QApplication::translate("Evaluate", "\351\200\211\346\213\251\345\234\260\345\214\272", 0));
        QTreeWidgetItem *___qtreewidgetitem = value2->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Evaluate", "\346\214\207\346\240\207", 0));

        const bool __sortingEnabled2 = value2->isSortingEnabled();
        value2->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = value2->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("Evaluate", "\347\273\274\345\220\210\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("Evaluate", "\350\265\204\346\272\220\347\216\257\345\242\203\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("Evaluate", "\350\247\204\346\250\241\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("Evaluate", "\344\272\272\345\235\207\350\265\204\346\272\220\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("Evaluate", "\345\242\236\351\225\277\351\200\237\345\272\246\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("Evaluate", "\345\242\236\351\225\277\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem7->setText(0, QApplication::translate("Evaluate", "\345\256\217\350\247\202\347\273\223\346\236\204\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem7->child(0);
        ___qtreewidgetitem8->setText(0, QApplication::translate("Evaluate", "\345\233\275\351\231\205\350\200\201\351\276\204\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem7->child(1);
        ___qtreewidgetitem9->setText(0, QApplication::translate("Evaluate", "\345\233\275\351\231\205\350\264\237\346\213\205\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem7->child(2);
        ___qtreewidgetitem10->setText(0, QApplication::translate("Evaluate", "\345\233\275\351\231\205\345\212\263\345\212\233\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem7->child(3);
        ___qtreewidgetitem11->setText(0, QApplication::translate("Evaluate", "\345\233\275\351\231\205\350\247\206\347\252\227\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem7->child(4);
        ___qtreewidgetitem12->setText(0, QApplication::translate("Evaluate", "\345\271\264\351\276\204\345\235\207\350\241\241\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem13->setText(0, QApplication::translate("Evaluate", "\345\276\256\350\247\202\347\273\223\346\236\204\350\257\204\344\273\267", 0));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem13->child(0);
        ___qtreewidgetitem14->setText(0, QApplication::translate("Evaluate", "\345\256\266\345\272\255\351\243\216\351\231\251\350\257\204\344\273\267", 0));
        value2->setSortingEnabled(__sortingEnabled2);

        label_3->setText(QApplication::translate("Evaluate", "\350\257\204\344\273\267\347\273\223\346\236\234", 0));
        label_8->setText(QApplication::translate("Evaluate", "\346\263\250\357\274\232\345\217\214\345\207\273\350\241\250\346\240\274\351\241\271\345\217\257\344\273\245\345\210\227\350\241\250\346\230\276\347\244\272\350\257\204\344\273\267\350\257\246\347\273\206\344\277\241\346\201\257", 0));
        comboBox_method->clear();
        comboBox_method->insertItems(0, QStringList()
         << QApplication::translate("Evaluate", "\345\244\232\346\214\207\346\240\207\350\201\224\345\220\210\351\200\220\346\255\245\346\267\230\346\261\260\344\270\216\344\274\230\351\200\211", 0)
         << QApplication::translate("Evaluate", "\344\271\230\346\263\225\345\220\210\346\210\220\345\222\214\344\274\230\351\200\211", 0)
         << QApplication::translate("Evaluate", "\345\212\240\346\263\225\345\220\210\346\210\220\345\222\214\344\274\230\351\200\211", 0)
        );
        pushButton_9->setText(QApplication::translate("Evaluate", "\346\230\276\347\244\272\350\257\204\344\273\267\347\273\223\346\236\234", 0));
        area2->clear();
        area2->insertItems(0, QStringList()
         << QApplication::translate("Evaluate", "\345\214\227\344\272\254", 0)
         << QApplication::translate("Evaluate", "\345\244\251\346\264\245", 0)
         << QApplication::translate("Evaluate", "\344\270\212\346\265\267", 0)
         << QApplication::translate("Evaluate", "\351\207\215\345\272\206", 0)
         << QApplication::translate("Evaluate", "\346\262\263\345\214\227", 0)
         << QApplication::translate("Evaluate", "\345\261\261\350\245\277", 0)
         << QApplication::translate("Evaluate", "\350\276\275\345\256\201", 0)
         << QApplication::translate("Evaluate", "\345\220\211\346\236\227", 0)
         << QApplication::translate("Evaluate", "\351\273\221\351\276\231\346\261\237", 0)
         << QApplication::translate("Evaluate", "\346\261\237\350\213\217", 0)
         << QApplication::translate("Evaluate", "\346\265\231\346\261\237", 0)
         << QApplication::translate("Evaluate", "\345\256\211\345\276\275", 0)
         << QApplication::translate("Evaluate", "\347\246\217\345\273\272", 0)
         << QApplication::translate("Evaluate", "\346\261\237\350\245\277", 0)
         << QApplication::translate("Evaluate", "\345\261\261\344\270\234", 0)
         << QApplication::translate("Evaluate", "\346\262\263\345\215\227", 0)
         << QApplication::translate("Evaluate", "\346\271\226\345\214\227", 0)
         << QApplication::translate("Evaluate", "\346\271\226\345\215\227", 0)
         << QApplication::translate("Evaluate", "\345\271\277\344\270\234", 0)
         << QApplication::translate("Evaluate", "\346\265\267\345\215\227", 0)
         << QApplication::translate("Evaluate", "\345\233\233\345\267\235", 0)
         << QApplication::translate("Evaluate", "\350\264\265\345\267\236", 0)
         << QApplication::translate("Evaluate", "\344\272\221\345\215\227", 0)
         << QApplication::translate("Evaluate", "\351\231\225\350\245\277", 0)
         << QApplication::translate("Evaluate", "\347\224\230\350\202\203", 0)
         << QApplication::translate("Evaluate", "\351\235\222\346\265\267", 0)
         << QApplication::translate("Evaluate", "\345\206\205\350\222\231\345\217\244", 0)
         << QApplication::translate("Evaluate", "\345\271\277\350\245\277", 0)
         << QApplication::translate("Evaluate", "\350\245\277\350\227\217", 0)
         << QApplication::translate("Evaluate", "\345\256\201\345\244\217", 0)
         << QApplication::translate("Evaluate", "\346\226\260\347\226\206", 0)
        );
        label_11->setText(QApplication::translate("Evaluate", "\350\257\204\344\273\267\346\226\271\346\263\225\357\274\232", 0));
        exit->setText(QApplication::translate("Evaluate", "\351\200\200\345\207\272\350\257\204\344\273\267", 0));
    } // retranslateUi

};

namespace Ui {
    class Evaluate: public Ui_Evaluate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVALUATE_H
