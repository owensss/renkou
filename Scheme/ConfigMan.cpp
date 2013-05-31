#include <iostream>
#include <cstdlib>
#include <QTextStream>
#include <QFile>
#include "ConfigMan.hpp"
#include "exceptions/ValueNotExist.hpp"
#include <QTextCodec>
#include <QDebug>

using namespace Config;

ConfigMan Config::config;

bool ConfigMan::read(const QString& _filename)
{
    __filename = _filename;
    QFile file(__filename);
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        valid = false;
        return success();
    }

    QTextStream config_file(&file);
    config_file.setCodec(QTextCodec::codecForName("utf-8"));
    QString tmpline;
    QString property_name;
    QString property_value;
    int count = 0;
    while (!config_file.atEnd())
    {
        tmpline = config_file.readLine();
        qDebug() << tmpline;
        ++count;
        int split = tmpline.indexOf("=");
        if (  split == -1) {
            std::cerr << "[config]format incorrect at line " << count << "\n";
            std::cerr << "\t--> " << tmpline.toStdString() << "\n"; // it's okay, because streams are not buffered in cerr
            continue;
        }


        property_value = tmpline.right(tmpline.size()-split-1).simplified();
        property_name = tmpline.left(split-1).simplified();
        map.insert(property_name, property_value);
    }
    file.close();

    return true;
}

const QString& ConfigMan::value(const QString& key) const {
    try {
        QMap<QString, QString>::const_iterator iter = map.find(key);
        if (iter == map.end()) throw ValueNotExist(key);
        return iter.value();
    } catch (ValueNotExist& e) {
        throw ValueNotExist(key);
    }
}

/*
 *#include "ConfigMan.hpp"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextCodec>
#include <QDebug>
#include <QObject>

const QString ConfigMan::META_RenKouGaiYao = QString(QObject::tr("人口概要类字段和对应指标名.txt"));
const QString ConfigMan::META_ShengYuHaiCi = QString(QObject::tr("生育孩次类字段和对应指标名.txt"));
const QString ConfigMan::META_ZhengCeShengYu = QString(QObject::tr("政策生育类字段和对应指标名.txt"));
const QString ConfigMan::META_FuFuZiNv = QString(QObject::tr("夫妇子女类字段和对应指标名.txt"));
QString ConfigMan::confFilePath;
QString ConfigMan::dataPath;
QString ConfigMan::dataStructPath;
int ConfigMan::start_year;
int ConfigMan::end_year;
QString ConfigMan::location;

void ConfigMan::readConfig(void)
{
    QFile file(confFilePath);
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(NULL, QString("注意"), QString("打不开配置文件!"));
        file.setFileName(QFileDialog::getOpenFileName(NULL,
             QString("打开配置文件")));
        if (! file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(NULL, QString("注意"), QString("无法打开配置文件!"));
            // 扔的应该是一个 ConfigureFileNotFoundException = =b
            // 以后填坑...
            throw -1;
        }
    }

    QTextStream config_file(&file);

    QString tmpline;
    QStringList tmplines;
    QString property_name;
    QString property_value;
    while (!config_file.atEnd())
    {
        tmpline = config_file.readLine();
        tmplines = tmpline.split("=");
        property_name = tmplines[0].simplified();
        property_value = tmplines[1].simplified();
        if( property_name == "DATA_STRUCT_PATH")
            dataStructPath = property_value;
        else if( property_name == "DATA_PATH")
            dataPath = property_value;
        else if (property_name == "START_YEAR")
            start_year = property_value.toInt();
        else if (property_name == "END_YEAR")
            end_year = property_value.toInt();
        else if (property_name == "LOCATION")
            location = property_value;
        else
        {
            qDebug() << "[ConfigMan]unknown property " << property_name;
        }
    }
    file.close();
// #define _DEBUG_
#ifdef _DEBUG_
    qDebug() << dataStructPath;
    qDebug() << dataPath;
#endif
}

 */

