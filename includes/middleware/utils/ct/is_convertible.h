/**
    @b Project: Wump
    @file        is_convertible.h
    @author      Szymon Gutaj
    @brief       
    @date        10-06-2011
    @b History:
     - 10-06-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_CONVERTIBLE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_CONVERTIBLE_H_INCLUDED_

#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/is_void.h>
#include <middleware/utils/ct/yes_no_type.h>
#include <middleware/utils/ct/add_reference.h>
#include <middleware/utils/ct/static_instance.h>

#include <middleware/utils/ct/static_assert.h>

namespace middleware { namespace utils { namespace ct {

ct_static_assert(false, this_implementation_has_not_been_tested_at_all);

namespace local {

template<
   ,typename To
>
struct is_convertible_impl
{
    template<
       ,typename From
    >
    struct from
    {
        static yes_type matchesTo(typename ct::add_reference<To>::type const &);
        static no_type  matchesTo(...);

        enum
        {
            value = (sizeof(yes_type) == sizeof(matchesTo(ct::static_instance<From>::value)))
        };
    };
};

template<>
struct is_convertible_impl<void>
{
    template<
       ,typename From
    >
    struct from :
        ct::is_void<From> {};
};

}

template<
    typename From
   ,typename To
>
struct is_convertible :
    ct::bool_<
        local::is_convertible_impl<To>::template from<From>::value
    > {};

}}}
//#include <middleware/utils/ct/is_convertible.h>

#endif /* MIDDLEWARE_UTILS_CT_IS_CONVERTIBLE_H_INCLUDED_ */
