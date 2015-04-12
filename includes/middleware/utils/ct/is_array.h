/**
    @b Project: Wump
    @file        is_array.h
    @author      Szymon Gutaj
    @brief       
    @date        10-06-2011
    @b History:
     - 10-06-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_ARRAY_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_ARRAY_H_INCLUDED_

#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/static_instance.h>
#include <middleware/utils/ct/yes_no_type.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<
    typename T
   ,int N
>
yes_type isArray(T (&table)[N]);

no_type isArray(...);

}

template<
    typename T
>
struct is_array :
    ct::bool_<
        (sizeof(yes_type) == sizeof(local::isArray(ct::static_instance<T>::value)))
    > {};

}}}
//#include <middleware/utils/ct/is_array.h>

#endif /* MIDDLEWARE_UTILS_CT_IS_ARRAY_H_INCLUDED_ */
