#ifndef _COLNOETEXIST_HPP
#define _COLNOETEXIST_HPP

#include <QString>

class ColNotExist {
    public:
        explicit ColNotExist(const QString _value,int _index):__value(_value),__index(_index){}
        virtual ~ColNotExist() {}
        const QString& value(void) const {return __value;}
        int index(void) const { return __index;}
    private:
        ColNotExist();
        QString __value;
	int __index;
};

#endif
