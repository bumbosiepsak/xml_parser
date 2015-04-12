/**
    @b Project: Wump
    @file        is_float.h
    @author      Szymon Gutaj
    @brief       
    @date        10-06-2011
    @b History:
     - 10-06-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_FLOAT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_FLOAT_H_INCLUDED_

#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/remove_cv.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<typename T>
struct is_float_impl :
    false_ {};

template<>
struct is_float_impl<float> :
    true_ {};

template<>
struct is_float_impl<double> :
    true_ {};

template<>
struct is_float_impl<long double> :
    true_ {};

}

template<typename T>
struct is_float :
    local::is_float_impl<typename ct::remove_cv<T>::type> {};

}}}
//#include <middleware/utils/ct/is_float.h>

#endif /* MIDDLEWARE_UTILS_CT_IS_FLOAT_H_INCLUDED_ */
