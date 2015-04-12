/**
    @b Project: Wump
    @file        is_void.h
    @author      Szymon Gutaj
    @brief       Equivalent to 'true_' for 'void' type
    @date        25-04-2011
    @b History:
     - 25-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_VOID_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_VOID_H_INCLUDED_

#include <middleware/utils/ct/bool.h>

namespace middleware { namespace utils { namespace ct {

template<typename T>
struct is_void :
    false_ {};

template<>
struct is_void<void> :
    true_ {};

template<>
struct is_void<void const> :
    true_ {};

template<>
struct is_void<void volatile> :
    true_ {};

template<>
struct is_void<void const volatile> :
    true_ {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_IS_VOID_H_INCLUDED_ */
