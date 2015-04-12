/**
    @b Project: Wump
    @file        is_signed.h
    @author      Szymon Gutaj
    @brief
    @date        19-07-2011
    @b History:
     - 19-07-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_SIGNED_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_SIGNED_H_INCLUDED_

#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/ice_or.h>
#include <middleware/utils/ct/is_enum.h>
#include <middleware/utils/ct/is_integral.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<typename T>
struct is_signed_impl :
    ct::bool_<
        (static_cast<T>(-1) < static_cast<T>(0))
    > {};
}

template<typename T>
struct is_signed :
    ct::if_c<
        ct::ice_or<
            ct::is_enum<T>::value
           ,ct::is_integral<T>::value
        >::value
       ,local::is_signed_impl<T>
       ,ct::false_
    >::type {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_IS_SIGNED_H_INCLUDED_ */
