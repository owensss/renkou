#pragma once
#include "Scheme.hpp"
#include "SchemeDef.hpp"
#include "schememetadata.h"
#include "SchemeBuffer.hpp"
#include "exceptions/InstanceIndexOutOfRange.hpp"
// wrapper class
namespace __SchemeIndicatorWrapper__ {

template <typename T>
class wrapper {
};

template <>
class wrapper<schInt> {
    public:
         static schInt value(const Scheme* scheme, size_t year, size_t index) {
            if (! scheme->getMetadata()->validateYear(year)) {
                throw InstanceIndexOutOfRange(scheme, year);
            }
            return scheme->getBuffer()->toInt(scheme, year, index);
        }
};

template <>
class wrapper<schDouble> {
  public:
        static schDouble value(const Scheme* scheme, size_t year, size_t index) {
            if (! scheme->getMetadata()->validateYear(year)) {
                throw InstanceIndexOutOfRange(scheme, year);
            }
            return scheme->getBuffer()->toDouble(scheme, year, index);
        }
};

template <>
class wrapper<schString> {
  public:
        static schString value(const Scheme* scheme, size_t year, size_t index) {
            if (! scheme->getMetadata()->validateYear(year)) {
                throw InstanceIndexOutOfRange(scheme, year);
            }
            return scheme->getBuffer()->toString(scheme, year, index);
        }
};
}

/**
 * note: 方案指标，方案某个指标在所有年份的值
 * 		 并可以计算一些统计数据(最大最小值，均值、方差 等)
 * 		 Scheme Indicator, Scheme one Indicator at all years of data
 * 		 this class stands for an indicator in a scheme, which shall access the records of the specific indicator
 * 		 and provide interface to evaluate some basic mathmatical statistics (max, min, variance, avarage, etc)
 * */


template <typename T>
class SchemeIndicator {
    public:
        SchemeIndicator(const Scheme* _scheme, size_t _index) : scheme(_scheme), index(_index) {
        }
        const Scheme* getScheme(void) const {return scheme;}
        size_t getIndex(void) const {return index;}
        /**
         * scheme Item: represents a record in a scheme. not a class
         */
        /**
         * @params: the absolute year
         * @return: return the record in the specific type
         * 			if no record on that year
         * 				throw RecordError("record not exist")
         */
        T operator [] (size_t year) const {get(year);}
        T get(size_t year) const { return __SchemeIndicatorWrapper__::wrapper<T>::value(scheme, year, index); }
        size_t startYear(void) const {return scheme->startYear();}
        size_t endYear(void) const {return scheme->endYear();}
        size_t size(void) const {return scheme->endYear() - startYear();} // UNSCIENTIIC = =b
    // some methematical statistics functions
    /**
     * 1, function type1: the value has an index (max, min)
     * @param: the value to be set, start_year(default to startYear()), end_year(default to endYear())
     * @return: the year that value occurs
     * 2, function type2: the value has no index (average, variant)
     * @param: start_year, end_end (both have default value)
     * @return: the value
     */
    public:
        // type1 funtions
        size_t maxYear		(size_t start_year= UINT_MAX, size_t end_year=UINT_MAX) {
            this->resetYear(start_year, end_year);
            if (start_year == end_year) return start_year;
            size_t year = start_year;
            T value = get(start_year);
            for (size_t i = start_year+1; i != end_year; ++i) {
                auto t = get(i);
                if (t>value) {
                    value = t;
                    year = i;
                }
            }
            return year;
        }
        T max(size_t start_year = UINT_MAX, size_t end_year = UINT_MAX) {
            return get(maxYear(start_year, end_year));
        }

        size_t minYear		(size_t start_year=UINT_MAX, size_t end_year=UINT_MAX) {
            this->resetYear(start_year, end_year);
            if (start_year == end_year) return start_year;
            size_t year = start_year;
            T value = get(start_year);
            for (size_t i = start_year+1; i != end_year; ++i) {
                auto t = get(i);
                if (t<value) {
                    value = t;
                    year = i;
                }
            }
            return year;
        }
        T min(size_t start_year=UINT_MAX, size_t end_year=UINT_MAX) {
            return get(minYear(start_year, end_year));
        }


        // type2 functions
        double mean		    (size_t start_year=UINT_MAX, size_t end_year=UINT_MAX) {
            resetYear(start_year, end_year);
            if (start_year==end_year) return get(start_year);
            double res = 0.0;
            for (size_t i = start_year; i != end_year; ++i) {
                res += get(i);
            }
            res = res/(size());

            return res;
        }
        double variance		(size_t start_year=UINT_MAX, size_t end_year=UINT_MAX) {
            resetYear(start_year, end_year);
            if (start_year == end_year) return 0;
            double _mean= mean(start_year, end_year);

            double res = 0.0;
            for (size_t i = start_year; i != end_year; ++i)
                res += (get(i)-_mean)*(get(i)-_mean);

            return res/(size()-1);
        }

        // double& expectation	(size_t start_year=-1, size_t end_year=-1);
    private:
        // reset start year and end year if needed(year == -1)
        void resetYear(size_t& start_year, size_t& end_year) {
            if (start_year>end_year) { // swap
                size_t t = start_year;
                start_year = end_year;
                end_year = t;
            }
            if (start_year==UINT_MAX) start_year = scheme->getMetadata()->startYear();
            if ( end_year ==UINT_MAX)  end_year  = scheme->getMetadata()->endYear();
        }
    private:
        const Scheme* scheme;
        const size_t index;
};
