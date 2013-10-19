#ifndef _VALUENOETEXIST_HPP
#define _VALUENOETEXIST_HPP

#include <QString>

class ValueNotExist {
    public:
        explicit ValueNotExist(const QString _value) {__value = _value;}
        virtual ~ValueNotExist() {}
        const QString& value(void) const {return __value;}
    private:
        ValueNotExist();
        QString __value;
};

#endif
