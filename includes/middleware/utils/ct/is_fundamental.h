/**
    @b Project: Wump
    @file        is_fundamental.h
    @author      Szymon Gutaj
    @brief       Equivalent to 'true_' for fundamental types
    @date        25-04-2011
    @b History:
     - 25-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_FUNDAMENTAL_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_FUNDAMENTAL_H_INCLUDED_

#include <middleware/utils/ct/ice_or.h>
#include <middleware/utils/ct/is_integral.h>
#include <middleware/utils/ct/is_float.h>
#include <middleware/utils/ct/is_void.h>

namespace middleware { namespace utils { namespace ct {

template<typename T>
struct is_fundamental :
    ct::ice_or<
        ct::is_integral<T>::value
       ,ct::is_float<T>::value
       ,ct::is_void<T>::value
    > {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_IS_FUNDAMENTAL_H_INCLUDED_ */
