#include <iostream>
#include <cstdlib>
#include <QTextStream>
#include <QFile>
#include "ConfigMan.hpp"
#include "exceptions/ValueNotExist.hpp"

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

    QString tmpline;
    QString property_name;
    QString property_value;
    int count = 0;
    while (!config_file.atEnd())
    {
        tmpline = config_file.readLine();
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

