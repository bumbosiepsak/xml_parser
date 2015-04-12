/**
    @b Project: Wump
    @file        is_arithmetic.h
    @author      Szymon Gutaj
    @brief       
    @date        10-06-2011
    @b History:
     - 10-06-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_ARITHMETIC_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_ARITHMETIC_H_INCLUDED_

#include <middleware/utils/ct/is_float.h>
#include <middleware/utils/ct/is_integral.h>

namespace middleware { namespace utils { namespace ct {

template<
    typename T
>
struct is_arithmetic :
    ct::ice_or<
        ct::is_float<T>::value
       ,ct::is_integral<T>::value
    > {};

}}}
//#include <middleware/utils/ct/is_arithmetic.h>

#endif /* MIDDLEWARE_UTILS_CT_IS_ARITHMETIC_H_INCLUDED_ */
