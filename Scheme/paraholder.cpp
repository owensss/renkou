#include "paraholder.hpp"
#include <algorithm>
#include <vector>
#include <QFile>
#include <QRegExp>
#include <QObject>
#include <QtCore/QStringList>

// reture no_duplicate ? true : false
bool ParaHolder::add(const QString& key) {
    if(!locked) {
        if (std::find(keys.begin(), keys.end(), key) != keys.end())
            return false;
        keys.push_back(key);
    }

    return false;
}

// return true iff input vector.no_dup itself and
// vector.no_dup with_set
bool ParaHolder::add(const std::vector<QString>& _keys) {
    if (!locked) {
        for (unsigned i=0; i< _keys.size(); ++i)
            add(_keys[i]);
    }
    return false;
}

bool ParaHolder::set(const std::vector<QString>& _keys) {
    if (!locked) {
        keys.clear();
        return add(_keys);
    }

    return false;
}

bool ParaHolder::find(const QString& para) const {
    return std::find(keys.begin(), keys.end(), para)!=keys.end();
}
#include <QDebug>
void ParaHolder::Print() {
    std::vector<QString>::const_iterator i;
    for (i = keys.begin(); i != keys.end(); ++i)
        qDebug ()<< *i << " ";
}
