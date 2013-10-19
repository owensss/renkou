#ifndef EXCEPTIONNOPARANAME_HPP
#define EXCEPTIONNOPARANAME_HPP
#include <QString>


class ExceptionNoParaName {
    public:
        explicit ExceptionNoParaName(const QString& name)
            :_name(name) {}
        ~ExceptionNoParaName() {}
        const QString& what(void) const {return _name;}
    private:
        QString _name;
};

#endif // EXCEPTIONNOPARANAME_HPP
