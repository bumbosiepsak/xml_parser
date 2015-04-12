/**
    @b Project: Wump
    @file        int.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_INT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_INT_H_INCLUDED_

#include <middleware/utils/ct/integral_c.h>

namespace middleware { namespace utils { namespace ct {

template<
    int C
>
struct int_ :
    ct::integral_c<int, C>
{
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_INT_H_INCLUDED_ */
