#ifndef PARASETTER_HPP
#define PARASETTER_HPP
#include <map>
#include <set>
#include <vector>
#include <memory>
#include "paraholder.hpp"
#include "exceptions/ExceptionNoParaName.hpp"
/*
 * @update:
 * 	now use shared_ptr to maintain parameterholder
 * 	remove throw() spec
 * 	add const & non-const version of some key functions = =b
 */

/*
 * interface to set parameters
 * usage:
 *
一、初始化：(1, initialization)
    使用 ParaHolder 的 shared_ptr
二、读 (2, read)
    1, const QString operator (size_t index | QString key) const => 只读，不掷出异常，index 版本的如果 out_of_range 会去死，key 版本的会返回 ""
    2, const QString at(size_t index | QString key) const => 只读，掷出 out_of_range 或 ExceptionNoParaName 异常
三、写 (3, write)
    bool set(size_t index | QString key, value) => 如果成功(有这个 parameter)，返回 true, 否则 false
四、测试 (4, test)
    1, state(size_t index | QString key) => value_not_set, okey, key_not_exist, 前者表示参数数值未设置、后者表示该参数不存在

五、用法 (5, usage)
    std::shared_ptr<ParaHolder> holder(new ParaHolder);
    // set holder
    holder.add(QString("first"));
    holder.add(QString("second"));

    ParaSetter setter(holder);
    setter.set("first", "rm");
    setter.set(1, "-rf /");
    qDebug() << setter[0] << setter.at(QString("second"));
    qDebug() << setter["first"] << setter.at(1);
    qDebug() << setter.size();

    size_t size = setter.size();
    for (size_t i = 0; i<size; ++i)
        qDebug() << setter[i];

 * =>
 * rm -rf /
 * rm -rf /
 * 2
 * rm
 * rf
 */
class ParaSetter
{
public:
    enum STATE {value_not_set, okey, key_not_exist};
    ParaSetter(void) = delete; // disable default constructor
    // 我想把它改成
    ParaSetter(std::shared_ptr<ParaHolder> ph);
    ~ParaSetter(void) {}
public:
    // returns the value corrensponding to the key
    // string input const non-throw version
    const QString& operator [] (const QString& key) const;
    // index input const non-throw version
    const QString& operator [] (size_t   index) const;
    const QString& value(const QString& key) const {return operator[](key);}
    const QString& value(size_t index) const {return operator[](index);}
    // string input const throw(ExceptionNoParaName) version
    const QString&          at (const QString& key) const;
    // index input const throw(ExceptionNoParaName) version
    const QString&          at (size_t index) const;
    // @return: key_not_exist if key not exist, value_not_set if value not set
    //          okey if okey
    STATE state(const QString& key);
    STATE state(size_t index);
public:
    // set this[key] = value;
    bool set(const QString& key, const QString& value);
    bool set(size_t index, const QString& value);
    // find by index. this is useful when iterating through the map
    size_t size(void) const {return holder->size();}
private:
    // 呵呵神一般的变量名有意见不？
    std::shared_ptr<ParaHolder> holder;
    // map from key to value
    std::map<QString, QString> m;
    // map from key to defined
    std::map<QString, bool> m_d;
    // undefined value;
    static const QString UNDEFINED;
};

#endif // PARASETTER_HPP

