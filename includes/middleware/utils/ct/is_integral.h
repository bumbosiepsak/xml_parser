/**
    @b Project: Wump
    @file        is_integral.h
    @author      Szymon Gutaj
    @brief       Equivalent to 'true_' for integral fundamental types
    @date        25-04-2011
    @b History:
     - 25-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_INTEGRAL_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_INTEGRAL_H_INCLUDED_

#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/remove_cv.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<typename T>
struct is_integral :
    false_ {};

template<>
struct is_integral<bool> :
    true_ {};

template<>
struct is_integral<char> :
    true_ {};

template<>
struct is_integral<unsigned char> :
    true_ {};

template<>
struct is_integral<signed char> :
    true_ {};

template<>
struct is_integral<unsigned short> :
    true_ {};

template<>
struct is_integral<signed short> :
    true_ {};

template<>
struct is_integral<unsigned int> :
    true_ {};

template<>
struct is_integral<signed int> :
    true_ {};

template<>
struct is_integral<unsigned long> :
    true_ {};

template<>
struct is_integral<signed long> :
    true_ {};

template<>
struct is_integral<unsigned long long> :
    true_ {};

template<>
struct is_integral<signed long long> :
    true_ {};

template<>
struct is_integral<wchar_t> :
    true_ {};
}

template<typename T>
struct is_integral :
    local::is_integral<typename ct::remove_cv<T>::type> {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_IS_INTEGRAL_H_INCLUDED_ */
