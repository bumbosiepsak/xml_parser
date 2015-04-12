/**
    @b Project: Wump
    @file        ice_or.h
    @author      Szymon Gutaj
    @brief       
    @date        09-02-2011
    @b History:
     - 09-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_NOT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_NOT_H_INCLUDED_

#include <middleware/utils/ct/bool.h>

namespace middleware { namespace utils { namespace ct {

template<bool A0> struct not_c {};

template<>
struct not_c<false> :
    ct::true_ {};

template<>
struct not_c<true> :
    ct::false_ {};

template<
    class A0
>
struct not_ :
    ct::not_c<A0::value> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_NOT_H_INCLUDED_ */
