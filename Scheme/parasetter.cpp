#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "parasetter.hpp"

using std::set;
using std::map;
using std::vector;

const QString ParaSetter::UNDEFINED = "#undef#";
namespace {
    const QString blank = "";
};

ParaSetter::ParaSetter(std::shared_ptr<ParaHolder> ph)
    :holder(ph)
{
    // initialize all parameters to undefined
    for (size_t i = 0; i < holder->size(); ++i) {
        m[holder->operator [](i)] = "";
        m_d[holder->operator [](i)] = false;
    }
}

/*
 * @params: the name of the parameter
 * @return: the value of the parameter, default value will be set to $UNDEFINED
 * 			throw ExceptionNoParaName if the parameter name was not recorded
 */
const QString& ParaSetter::operator [] (const QString& key) const
{
    // prevent insertion
    if (! holder->find(key)) return blank;
    // if key is in the holder but not in m, this will acturally create one.
    return m.find(key)->second;
}

const QString& ParaSetter::operator [] (size_t index) const {
    return m.find(holder->operator[] (index))->second;
}

const QString& ParaSetter::at(const QString& key) const {
    if (! holder->find(key)) throw ExceptionNoParaName(key);
    return m.find(key)->second;
}

const QString& ParaSetter::at(size_t index) const {
    return m.at(holder->at(index));
}

ParaSetter::STATE ParaSetter::state(const QString& key) {
    if (! holder->find(key)) return key_not_exist;
    else if (m_d[key] == false) return value_not_set;

    return okey;
}

ParaSetter::STATE ParaSetter::state(size_t index) {
    if (index >= holder->size()) return key_not_exist;
    else if (m_d[holder->at(index)] == false) return value_not_set;
    else return okey;
}

bool ParaSetter::set(const QString& key, const QString& value) {
    if  ( m.find(key) == m.end() )
        return false;

    m[key] = value; // change the content
    m_d[key] = true; // mark value is set
    return true;
}

bool ParaSetter::set(size_t index, const QString& value) {
    if (index >= holder->size()) return false;

    QString key = holder->operator [](index);
    m[key] = value; // change the content
    m_d[key] = true; // mark value is set
    return true;
}
