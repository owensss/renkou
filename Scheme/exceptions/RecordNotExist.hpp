#ifndef RECORDNOTEXIST_HPP
#define RECORDNOTEXIST_HPP
#include <QString>

class RecordNotExist {
    public:
        RecordNotExist(const QString& name__) :name_(name__) {}
        const QString& name(void) const {return name_;}
    private:
        QString name_;

};

#endif // RECORDNOTEXIST_HPP
