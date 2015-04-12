/**
    @b Project: Wump
    @file        is_same.h
    @author      Szymon Gutaj
    @brief
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_SAME_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_SAME_H_INCLUDED_

#include <middleware/utils/ct/ice_and.h>
#include <middleware/utils/ct/is_reference.h>
#include <middleware/utils/ct/static_instance.h>
#include <middleware/utils/ct/yes_no_type.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<typename T>
yes_type isSame(T*, T*);

no_type isSame(...);

}

template<
    typename T
   ,typename U
>
struct is_same :
    ct::ice_and<
        sizeof(yes_type) == sizeof(local::isSame(&ct::static_instance<T>::value, &ct::static_instance<U>::value))
       ,ct::is_reference<T>::value == ct::is_reference<U>::value
       ,sizeof(T) == sizeof(U)
    > {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_IS_SAME_H_INCLUDED_ */
