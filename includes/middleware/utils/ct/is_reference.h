/**
    @b Project: Wump
    @file        is_reference.h
    @author      Szymon Gutaj
    @brief       
    @date        11-02-2011
    @b History:
     - 11-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_REFERENCE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_REFERENCE_H_INCLUDED_

#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/ice_or.h>

namespace middleware { namespace utils { namespace ct {

template<typename T>
struct is_lvalue_reference :
    ct::false_ {};

template<typename T>
struct is_lvalue_reference<T&> :
    ct::true_ {};

template<typename T>
struct is_lvalue_reference<T const&> :
    ct::true_ {};

template<typename T>
struct is_lvalue_reference<T volatile&> :
    ct::true_ {};

template<typename T>
struct is_lvalue_reference<T const volatile&> :
    ct::true_ {};

template<typename T>
struct is_rvalue_reference :
    ct::false_ {};

template<typename T>
struct is_reference :
    ct::ice_or<
        is_lvalue_reference<T>::value
       ,is_rvalue_reference<T>::value
    > {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_IS_REFERENCE_H_INCLUDED_ */
