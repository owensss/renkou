#ifndef SCHEMEMETADATA_H
#define SCHEMEMETADATA_H
#include "metadataItem.h"
#include "configMan.hpp"
#include <QMap>
#include <string>

/*
 * schememetadata 负责从元文件中读取数据并将metadata初始化
 *
 * */
namespace scheme {
    class schememetadata;
}

class schememetadata
{
public:
    schememetadata(const QString& filename)
    {
        readMetadata(filename);
        metadataName = filename;
    }

    const metadataItem& getMetadata(const QString& field_name)const ;
    const metadataItem& operator[] (const QString& field_name) const ;
    const metadataItem& operator[] (const int index) const ;
    const metadataItem& colAt(const QString& field_name) const ;
    const metadataItem& colAt(const int index) const ;
    bool hasCol(size_t index)const ;
    bool hasCol(const QString& )const ;
    bool hasRow(size_t index)const{return validateYear(index);}
    bool validateYear(size_t year)const {return (year>=startYear()&&year<=endYear())
        ? true : false; }
    size_t rowSize(void) const; //	这里的rowSize是指的所有的colSize的和，不是startYear-endYear
    size_t colSize(const int index) const;
    size_t colOffset(const QString& field_name )const ;
    size_t colOffset(const int index )const ;
    size_t colCount() const { return mtdMap.size(); }
    size_t rowCount()const
    {
        return endYear()-startYear()+1;
    }
    size_t size() const { return rowSize()*rowCount(); }
    size_t startYear(void) const
    {
       return Config::config.Int("START_YEAR");
    }
    size_t endYear(void) const
    {
        return Config::config.Int("END_YEAR");
    }
    QString name(){
        return metadataName;
    }

private:
    schememetadata(const schememetadata&);
    schememetadata& operator= (const schememetadata&);
    void readMetadata(const QString&);
private:
    QString metadataName;
    QMap<QString , metadataItem> mtdMap;
    QMap<int , QString> indexMap;
};

#endif // SCHEMEMETADATA_H
