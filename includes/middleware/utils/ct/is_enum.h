/**
    @b Project: Wump
    @file        is_enum.h
    @author      Szymon Gutaj
    @brief       
    @date        10-06-2011
    @b History:
     - 10-06-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_ENUM_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_ENUM_H_INCLUDED_

#include <middleware/utils/ct/if.h>
#include <middleware/utils/ct/ice_or.h>
#include <middleware/utils/ct/is_class.h>
#include <middleware/utils/ct/is_union.h>
#include <middleware/utils/ct/is_reference.h>

#include <middleware/utils/ct/yes_no_type.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<
    typename T
>
struct is_convertible_to_int_but_not_from_int
{
    static yes_type toInt(int);
    static no_type toInt(...);

    static yes_type fromInt(T const &); // 'T' is not a reference
    static no_type fromInt(...);

    static T t;
    static int i;

    enum
    {
        value = (sizeof(yes_type) == sizeof(toInt(t))
              && sizeof(no_type) == sizeof(fromInt(i)))
    };
};

}

template<
    typename T
>
struct is_enum :
    ct::bool_<
        ct::if_<
            ct::ice_or<
                ct::is_class<T>::value
               ,ct::is_union<T>::value
               ,ct::is_reference<T>::value
            >
           ,ct::false_
           ,local::is_convertible_to_int_but_not_from_int<T>
        >::type::value
    > {};

}}}
//#include <middleware/utils/ct/is_enum.h>

#endif /* MIDDLEWARE_UTILS_CT_IS_ENUM_H_INCLUDED_ */
