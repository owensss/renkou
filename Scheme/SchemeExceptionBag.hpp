#pragma once
#include <exception>
#include <string>
#include <iostream>
#include "SchemeDef.hpp"
/*
class SchemeException : public std::exception {
    public:
        SchemeException(SchemePtr _scheme) :scheme(_scheme) noexcept(true) {
        }
        virtual ~SchemeException(void) noexcept(true) {
        }
        virtual const char * what(void) noexcept(true) const {
            return "Scheme Error";
        }
    private:
        SchemeException(void) noexcept(true);
        SchemePtr scheme;
};

*/
