/**
    @b Project: Wump
    @file        add_reference.h
    @author      Szymon Gutaj
    @brief
    @date        12-06-2011
    @b History:
     - 12-06-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_ADD_REFERENCE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_ADD_REFERENCE_H_INCLUDED_

#include <middleware/utils/ct/if.h>
#include <middleware/utils/ct/identity.h>
#include <middleware/utils/ct/is_reference.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<
    typename T
>
struct add_reference_impl
{
    typedef T& type;
};

}

template<
    typename T
>
struct add_reference :
    ct::if_<
        ct::is_reference<T>
       ,ct::identity<T>
       ,local::add_reference_impl<T>
    > {};

template<>
struct add_reference<void>
{
    typedef void type;
};

template<>
struct add_reference<void const>
{
    typedef void const type;
};

template<>
struct add_reference<void volatile>
{
    typedef void volatile type;
};

template<>
struct add_reference<void const volatile>
{
    typedef void const volatile type;
};

}}}

#endif /* MIDDLEWARE_UTILS_CT_ADD_REFERENCE_H_INCLUDED_ */
