/**
    @b Project: Wump
    @file        type_wrap.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_TYPE_WRAP_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_TYPE_WRAP_H_INCLUDED_

#include <middleware/utils/ct/has_type.h>
#include <middleware/utils/ct/identity.h>
#include <middleware/utils/ct/if.h>

namespace middleware { namespace utils { namespace ct {

template<typename T>
struct type_wrap :
    ct::if_<
        ct::has_type<T>
       ,T
       ,ct::identity<T>
    >::type {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_TYPE_WRAP_H_INCLUDED_ */
