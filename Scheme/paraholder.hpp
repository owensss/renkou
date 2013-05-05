#ifndef PARAHOLDER_HPP_
#define PARAHOLDER_HPP_

#include <QString>
#include <map>
#include <set>
#include <vector>

/*
 * a simple parameter holder class for
 * a class (reporter, etc.) that need a lot of parameters
 */
/*
 * meta class, generate the 'meta' data for a
 * ParaSetter
 */

class ParaHolder
{
public:
    ParaHolder(void) :locked(false) {}
    ParaHolder(std::initializer_list<QString> list) {keys = list;}
    ~ParaHolder() {}

    bool add(const QString& key) ;
    bool add(const std::vector<QString>& _keys);
    // removed, will be removed the next time I remeber
    // bool addAll(const QString& fileName);

    bool set(const std::vector<QString>& _keys);
    bool find(const QString& para) const;
    size_t size(void) const { return keys.size(); }
    // do not handle overflow problem
    const QString& operator [] (size_t index) const { return keys[index] ;}
    // handle overflow problem
    const QString& at          (size_t index) const { return keys.at(index);}

    // lock the instance so that nobody can change it value
    void lock(void) {locked=true;}
    void unlock(void) {locked=false;}

private:
    std::vector<QString> keys;
    bool locked;
    void Print();//only for debug
};


#endif
