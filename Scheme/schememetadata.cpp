#include "schememetadata.h"
#include "configMan.hpp"
#include "exceptions/ColumnNotExist.hpp"
#include <QFile>
#include <QString>
#include <QTextCodec>
#include <QObject>
#include <QStringList>
#include <map>
#include <iterator>
#include <string>
#include <cassert>
#include <iostream>
#include <QTextStream>
#include <QDebug>

/*@descr: schememetadata 负责从元文件中读取数据并将其初始化
 *	@params: 元信息文件的文件名,包括路径
 *
 *TODO 在configMan文件中需要包括下面信息 :
 *		const QString METADATA_DIR	= "G:\\renkou\\data\\sim\\0816\\";
        const QString RenKouGaiYao	= QObject::tr("人口概要类字段名和对应指标名.txt");
        const QString ShengYuHaiCi	= QObject::tr("生育孩次类字段名和对应指标名.txt");
        const QString ZhengCeShengYu	= QObject::tr( "政策生育类字段名和对应指标名.txt");
        const QString FuFuZiNv		= QObject::tr("夫妇子女类字段名和对应指标名.txt");
 *
 *		然后 filename 应该是这样的 METADATA_DIR+[RenKouGaiYao,...,]
 *
 *				其实这样非常不nice, 当初考虑的是enum {源文件1,元文件2.... }
 *				传入上述enum flag,
 *				由schememetadata负责生成文件路径,这样就科学了
 *				QString filepath[4] ;
                filepath[0] = METADATA_DIR+RenKouGaiYao;
                filepath[1] = METADATA_DIR+ShengYuHaiCi;
                filepath[2] = METADATA_DIR+ZhengCeShengYu;
                filepath[3] = METADATA_DIR+FuFuZiNv;

 *				但是有了configMan文件的存在就不科学了,因为要是路径改了就不需在这里改代码了
 *
 *
 *	@note: 元文件的txt文件中需要去掉第一行中的"字段名,field_type,....,对应指标名"
 *
 *
 * */
void schememetadata::readMetadata(const QString& filename)
{
//	QFile file(filepath[0]);
    //To owensss : 正确使用方式
    QFile file(Config::config.value("DATA_STRUCT_PATH")+Config::config.value(filename));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream mtdfile(&file);
    qDebug() << "reading " << Config::config.value("DATA_STRUCT_PATH")+Config::config.value(filename);
    QString tmpline;
    QStringList tmplines;
    QString field_name,
            indicator;
    QString field_type,
            field_len,
            field_dec,
            index;

    while (!mtdfile.atEnd())
    {
        tmpline = mtdfile.readLine();
        tmplines = tmpline.split("\t");
        qDebug() << tmpline;

        field_name	= tmplines[0].simplified();
        field_type	= tmplines[1].simplified();
        field_len	= tmplines[2].simplified();
        field_dec	= tmplines[3].simplified();
        index		= tmplines[4].simplified();
        indicator	= tmplines[5].simplified();


        bool ok1,ok2,ok3;
        metadataItem mtdItem(field_name,
                field_type,
                field_len.toInt(&ok1,10),
                field_dec.toInt(&ok2,10),
                index.toInt(&ok3,10),
                indicator);

        mtdMap.insert(field_name, mtdItem);
        indexMap.insert(index.toInt(&ok3,10), field_name);

    }
    qDebug() << indexMap;
    file.close();
}


const metadataItem& schememetadata::operator[] (const QString& field_name) const
{
    return getMetadata(field_name);
}
const metadataItem& schememetadata::operator[] (const int index) const
{
    auto itr = indexMap.find(index);
    if(itr==indexMap.end())
    {
        throw ColNotExist("column not exit", index);
    }

    else
    {
        return getMetadata(itr.value());
    }
}

const metadataItem& schememetadata::colAt(const QString& field_name) const
{
    return getMetadata(field_name);
}
const metadataItem& schememetadata::colAt(const int index) const
{
    auto itr = indexMap.find(index);
    if(itr==indexMap.end()){
        throw ColNotExist("column not exit", index);
    }
    else
    {
        return getMetadata(itr.value());
    }
}

bool schememetadata::hasCol( size_t index)const
{
    QMap<int , QString>::const_iterator itr ;
    itr = indexMap.find(index);
    if(itr != indexMap.end())
    {
        return true;
    }
    return false;
}
bool schememetadata::hasCol(const QString &filename)const
{
    auto itr = mtdMap.find(filename);
    if(itr != mtdMap.end())
    {
        return true;
    }
    return false;
}

size_t schememetadata::rowSize() const
{
    int tempRowCount = 0;
    for (auto itr=mtdMap.begin() ; itr != mtdMap.end(); ++itr )
        tempRowCount += itr.value().getfield_len();
    return tempRowCount;

}
size_t schememetadata::colSize(const int index) const
{
    auto itr = indexMap.find(index);
    if(itr==indexMap.end())
    {
        throw ColNotExist("column not exit", index);
    }
    else
    {
        return getMetadata(itr.value()).getfield_len();
    }

}
size_t schememetadata::colOffset(const QString& field_name ) const
{
    auto itr = mtdMap.find(field_name);
    if(itr==mtdMap.end()){
        throw ColNotExist("column"+field_name,-1);
    }
    else
    {
        int tempRowOffset = 0;
        int index = itr.value().getindex();

        for(int i = 1; i < index; ++i )
        {
            auto itr2 = indexMap.find(i);
            if(itr2 == indexMap.end()){
                throw ColNotExist("column not exist", index);
            }

            else
                tempRowOffset += getMetadata(itr2.value()).getfield_len();

        }
        return tempRowOffset;
    }
    return -1;
}

size_t schememetadata::colOffset(int index) const
{
    assert(index <= 116 && index > 0);
    auto itr = indexMap.find(index);
    if (itr == indexMap.end()) throw ColNotExist("coloumn not exist", index);
    return colOffset(itr.value());
}

const metadataItem& schememetadata::getMetadata(const QString& field_name)const
{
    auto itr = mtdMap.find(field_name);
    if(itr==mtdMap.end()){
        throw ColNotExist("column"+field_name,-1);
    }
    else return itr.value();

}
