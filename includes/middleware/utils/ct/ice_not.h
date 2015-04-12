/**
    @b Project: Wump
    @file        ice_not.h
    @author      Szymon Gutaj
    @brief       
    @date        09-02-2011
    @b History:
     - 09-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_ICE_NOT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_ICE_NOT_H_INCLUDED_

#include <middleware/utils/ct/bool.h>

namespace middleware { namespace utils { namespace ct {

template<bool A0>
struct ice_not :
    ct::bool_<true> {};

template<>
struct ice_not<true> :
    ct::bool_<false> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_ICE_NOT_H_INCLUDED_ */
