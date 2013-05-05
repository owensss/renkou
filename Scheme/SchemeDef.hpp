#ifndef _SCHEME_DEF_HPP
#define _SCHEME_DEF_HPP

#include <memory>
#include <QString>
#include "ConfigMan.hpp"
class Scheme;
class schememetadata;
class SchemeBuffer;
class SchemeInstance;
template <typename T> class SchemeIndicator;

typedef std::shared_ptr<Scheme> SchemePtr;
typedef std::shared_ptr<schememetadata> schememetadataPtr;
typedef std::shared_ptr<SchemeBuffer> SchemeBufferPtr;
typedef std::shared_ptr<SchemeInstance> SchemeInstancePtr;
template <typename T> using SchemeIndicatorPtr = std::shared_ptr<SchemeIndicator<T> >;

typedef int32_t schInt;
typedef double schDouble;
typedef QString schString;

#endif
