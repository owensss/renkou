#pragma once
#include <memory>
#include "SchemeDef.hpp"
#include <QTextCodec>
/* note: scheme: 方案 */
/**
 * note: All data are stored in SchemeBuffer and schememetadata, Scheme do not store any data
 *     Scheme
 *                      SchemeIndicator----------------------------->
 * SchemeInstance      Indicator1 Indicator2 Indicator3 ...
 *     |    year1        Item00    Item01    Item02 ...
 *     |    year2        Item10    Item11    Item12 ...
 *     |    year3        .        .
 *     |    .            .        .
 *     |    .            .        .
 *     v
 */
/**
 * TODO:
 * 		把 schemeItem 写成 class,
 * 		create a new class SchemeItem
 * 		有下列方法:
 * 		has the following methods:
 * 			toString();
 * 			toDouble();
 * 			toInt();
 * 			toXXX;
 *		难点:
 *		difficulties:
 *			1, if stores data itself: data shall be variant length(变长) and type free(类型无关)
 *			2, if fetchs data from SchemeBuffer: shall store extra information of its location( SchemeName, row, col)
 *		advantages:
 *		优势:
 *			1, remove toString, toInt, toBlabla from both SchemeIndicator and SchemeInstance
 *			2, that, is, the CPP STYLE = =b
 * TODO:
 * 		注意到，方案的命名是有规律的，所以只需要把一些信息(地区，改变政策时间等等)确定一下就能确定一个方案了，这样就不需要方案名了，而且也可以在 Buffer 和这个间做无缝 map, 不需要 toInternalName() 函数
 */

// TODO: use a wrapper to avoid toString, toDouble, toInt functions
class Scheme : public std::enable_shared_from_this<Scheme> {
    public:
        enum ItemType {sch_none, sch_double, sch_int, sch_string};
    public:
        /**
         * @brief   create a scheme using meta, buffer and name
         * @params  metadata this scheme's metadata
         * 			buffer the buffer associated with this scheme
         * 			scheme_name the scheme name: currently, the name shall be the filename-".txt"
         * 			note: the sheme name is the name used in the program(used by Prof. Yin.), NOT the name of the txt file or the pri-key value in the relation
         * @note: please use SchemePtr to create instance of this class (just recommended)
         */
        Scheme(schememetadataPtr metadata, SchemeBufferPtr buffer, const QString& scheme_name) :meta(metadata), buf(buffer), name(scheme_name) {
            // check existance
        }
        std::shared_ptr<Scheme> that() {
            return shared_from_this();
        }
        SchemeBufferPtr getBuffer(void) const {return buf;}
        schememetadataPtr getMetadata(void) const {return meta;}
        /**
         * @brief getName get the name of the scheme.
         * @return
         */
        const QString& getName(void) const {return name;}
        virtual ~Scheme(void) {}
    public:
        /**
         * @brief convert the name of the scheme into readable format. Which means(currently)
         *        convert relative/absulote path with / w\o .txt into a uniformed format
         * @return if the internal storage is placed in the files(currently)
         * 				then this function returns the filename.
         * 		   if the internal storage is placed in the database
         * 		   		then this function returns the scheme name
         */
        QString toInternalName(void) const;
    public:
        /**
         * @params: the index of the indicator
         * @return: the indicator of the scheme at the index
         * 		if the index is out of range, throws IndicatorOutOfRange
         * 		if type mismatch, go die o(≧v≦)o~~
         *
         */
        SchemeIndicator<schInt> getIndicatorInt(size_t index) ;
        SchemeIndicator<schString> getIndicatorString(size_t index) ;
        SchemeIndicator<schDouble> getIndicatorDouble(size_t index) ;
        template <typename T> SchemeIndicator<T> getIndicator(size_t index);

        /**
         * @param the name of the indicator, this is not the name used
         * @return the indicator of the scheme of such name
         * 		if scheme has no indicator with such name, throws IndicatorNameNotFound
         * 		if type mismatch, go die, too!
         */
        SchemeIndicator<schInt> getIndicatorInt(const QString& name) ;
        SchemeIndicator<schString> getIndicatorString(const QString& name) ;
        SchemeIndicator<schDouble> getIndicatorDouble(const QString& name) ;

        /**
         * @params: the absulote year(say, >=start_year, <= end_year)
         * @return: throws InstanceIndexOutOfRange if year outof range
         *			return the intance on success
         */
        SchemeInstance getInstance(size_t year) ;
        SchemeInstance operator [] (size_t year) ;
        size_t startYear(void) const;
        size_t endYear(void) const;
    private:
        const schememetadataPtr meta;
        mutable SchemeBufferPtr buf;
        const QString name;
};

#include "SchemeIndicator.hpp"
template <typename T> SchemeIndicator<T> Scheme::getIndicator(size_t index) {
           return SchemeIndicator<T>(this, index);
}
