#ifndef METADATAITEM_H
#define METADATAITEM_H

#include <string>
#include <QString>

/* metadataItem 是关于整个scheme的元信息
 *
 *  由schemeMetadata类进行初始化
 * 1. 包括了scheme中每个数据的元信息
 * 2. 额外包括了整个scheme的startYear和endYear信息
 *
 * */
namespace scheme{
    class metadataItem;
}
class metadataItem
{
public:
    enum TYPE {NONE, STRING, INT, DOUBLE};

    metadataItem(QString,QString,int,int,int,QString);
    //字段名 类型 长度 小数 指标index 指标描述 起始年份 结束年份
    inline QString getfield_name() const {return field_name;}
    inline TYPE getfield_type() 	const {return field_type;}
    inline int getfield_len() 	const {return field_len;}
    inline int getfield_dec() 	const {return field_dec;}
    inline int getindex() 		const {return index;}
    inline QString getindicator() const	{return indicator;}

private:
    QString field_name;
    TYPE field_type;
    int field_len;
    int field_dec;
    int index;
    QString indicator;
};



#endif // METADATAITEM_H
