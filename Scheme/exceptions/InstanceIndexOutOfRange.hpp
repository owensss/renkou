#ifndef INSTANCEINDEXOUTOFRANGE_HPP
#define INSTANCEINDEXOUTOFRANGE_HPP
#include "..\SchemeDef.hpp"

class InstanceIndexOutOfRange {
    public:
        explicit InstanceIndexOutOfRange(const Scheme* ins, size_t idx) :sch_(ins), index_(idx) {}
        const Scheme* what(void) const {return sch_;}
        size_t index(void) const {return index_;}
    private:
        const Scheme* sch_;
        size_t index_;
};

#endif // INSTANCEINDEXOUTOFRANGE_HPP
