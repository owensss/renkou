#pragma once
#include <memory>
#include "SchemeDef.hpp"
/* note: 方案实例，方案在某一年的具体数值 */

class SchemeInstance {
    public:
        SchemeInstance(Scheme* const sch, size_t _year);	// ctor
        virtual ~SchemeInstance() {}
        Scheme* getScheme(void) {return scheme;}
        const Scheme* getScheme(void) const {return scheme;}
        size_t getYear(void) const {return year;}

        /*
         * note: double is most commonly used type in all schemes
         *
         * @params: index of the indicator
         * @return: return the record in the specific type
         * 			if no record on that index
         * 					indicator index out of range
         * 					TODO: this could be moved to Scheme::getInstance:instance not exist
         * 				throw RecordError("record not exist")
         * 			if type mismatch, go die!
         */
        schDouble operator [] (size_t index) const {return getDouble(index);}
        schInt getInt(size_t index) const;
        schDouble getDouble(size_t index) const;
        schString getString(size_t index) const;
    private:
        Scheme* scheme;
        const size_t year;
};

