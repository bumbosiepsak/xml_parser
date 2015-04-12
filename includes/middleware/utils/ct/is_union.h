/**
    @b Project: Wump
    @file        is_union.h
    @author      Szymon Gutaj
    @brief       
    @date        10-06-2011
    @b History:
     - 10-06-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_UNION_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_UNION_H_INCLUDED_

#include <middleware/utils/ct/bool.h>

namespace middleware { namespace utils { namespace ct {

template<
    typename T
>
struct is_union :
    ct::false_ {}; // NOTE: No way to detect union type without (non-standard) compiler support

}}}
//#include <middleware/utils/ct/is_union.h>

#endif /* MIDDLEWARE_UTILS_CT_IS_UNION_H_INCLUDED_ */
