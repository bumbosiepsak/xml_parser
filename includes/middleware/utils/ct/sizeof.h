/**
    @b Project: Wump
    @file        sizeof.h
    @author      Szymon Gutaj
    @brief       
    @date        09-02-2011
    @b History:
     - 09-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_SIZEOF_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_SIZEOF_H_INCLUDED_

#include <middleware/utils/ct/integral_c.h>

namespace middleware { namespace utils { namespace ct {

template<typename T>
struct sizeof_ :
    ct::integral_c<std::size_t, sizeof(T)> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_SIZEOF_H_INCLUDED_ */
