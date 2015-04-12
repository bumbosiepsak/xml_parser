/**
    @b Project: Wump
    @file        has_type.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_HAS_TYPE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_HAS_TYPE_H_INCLUDED_

#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/yes_no_type.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<typename T>
ct::yes_type hasType(typename T::type*);

template<typename T>
ct::no_type hasType(...);

}

template<typename T>
struct has_type :
    ct::bool_<sizeof(ct::yes_type) == sizeof(local::hasType<T>(0))> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_HAS_TYPE_H_INCLUDED_ */
