#include "Scheme.hpp"
#include "SchemeInstance.hpp"
#include "SchemeIndicator.hpp"
#include "exceptions/IndicatorIndexOutOfRange.hpp"
#include "ConfigMan.hpp"

#include <QDebug>

#include <Qdir>

SchemeIndicator<schInt> Scheme::getIndicatorInt(size_t index) {
    if (meta->hasCol(index)) return SchemeIndicator<schInt>(this, index);
    throw IndicatorIndexOutOfRange(this, index);
}

SchemeIndicator<schString> Scheme::getIndicatorString(size_t index) {
    if (meta->hasCol(index)) return SchemeIndicator<schString>(this, index);
    throw IndicatorIndexOutOfRange(this, index);
}

SchemeIndicator<schDouble> Scheme::getIndicatorDouble(size_t index) {
    if (meta->hasCol(index))return SchemeIndicator<schDouble>(this,index);
    throw IndicatorIndexOutOfRange(this, index);
}

SchemeIndicator<schInt> Scheme::getIndicatorInt(const QString& name) {
    auto index = meta->colAt(name);
    // if (index == -1) throw IndicatorNameNotFound(this, name); TODO: this is thrown by schememetadata
    return SchemeIndicator<schInt>(this, index.getindex());
}

SchemeIndicator<schString> Scheme::getIndicatorString(const QString& name) {
    auto index = meta->colAt(name);
    // if (index == -1) throw IndicatorNameNotFound(this, name);
    return SchemeIndicator<schString>(this, index.getindex());
}

SchemeIndicator<schDouble> Scheme::getIndicatorDouble(const QString& name) {
    auto index = meta->colAt(name);
    // if (index == -1) throw IndicatorNameNotFound(this, name);
    return SchemeIndicator<schDouble>(this, index.getindex());
}

size_t Scheme::startYear() const {
    return meta->startYear();
}

size_t Scheme::endYear() const {
    return meta->endYear();
}

SchemeInstance Scheme::getInstance(size_t year) {
    if (! meta->validateYear(year) ) {
        throw InstanceIndexOutOfRange(this, year);
    }
    return SchemeInstance(this, year);
}

SchemeInstance Scheme::operator [] (size_t year ) {return getInstance(year);}

namespace toInternalNameHelper {
inline bool hasTxTSuffix(const QString& str) {
    return str.endsWith(".txt", Qt::CaseInsensitive);
}

inline bool isRelativePath(const QString& str) {
    return QDir(str).isRelative();
}
}

/**
 * @brief convert the name of the scheme into readable format. Which means(currently)
 *        convert relative/absulote path with / w\o .txt into a uniformed format
 * @return if the internal storage is placed in the files(currently)
 * 				then this function returns the filename.
 * 		   if the internal storage is placed in the database
 * 		   		then this function returns the scheme name
 */
QString Scheme::toInternalName() const {
    using namespace toInternalNameHelper;
    QString tmp = name;

    if (isRelativePath(tmp))
        tmp = Config::config.value("DATA_PATH")+"\\"+tmp;

    if (! hasTxTSuffix(tmp))
        tmp += ".txt";

    return tmp;
}
