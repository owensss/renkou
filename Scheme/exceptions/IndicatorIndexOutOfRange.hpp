#ifndef INDICATORINDEXOUTOFRANGE_HPP
#define INDICATORINDEXOUTOFRANGE_HPP

class IndicatorIndexOutOfRange {
    public:
        IndicatorIndexOutOfRange(const Scheme* _e, size_t _index)
            :__e(_e), __index(_index) {}
        const Scheme* what() const {return __e;}
        size_t index() const {return __index;}
    private:
        const Scheme* __e;
        size_t __index;
};


#endif

