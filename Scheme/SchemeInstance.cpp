#include "SchemeInstance.hpp"
#include "Scheme.hpp"
#include "SchemeBuffer.hpp"

SchemeInstance::SchemeInstance(Scheme* __scheme, size_t __year)
    :scheme(__scheme), year(__year)
{

}

schDouble SchemeInstance::getDouble(size_t index) const {
    return scheme->getBuffer()->toDouble(scheme, year, index);
}

schString SchemeInstance::getString(size_t index) const {
    return scheme->getBuffer()->toString(scheme, year, index);
}
