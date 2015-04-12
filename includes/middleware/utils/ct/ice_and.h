/**
    @b Project: Wump
    @file        ice_and.h
    @author      Szymon Gutaj
    @brief       
    @date        09-02-2011
    @b History:
     - 09-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_ICE_AND_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_ICE_AND_H_INCLUDED_

#include <middleware/utils/ct/bool.h>

namespace middleware { namespace utils { namespace ct {

template<
    bool A0
   ,bool A1
   ,bool A2=true
   ,bool A3=true
   ,bool A4=true
   ,bool A5=true
   ,bool A6=true
>
struct ice_and :
    ct::bool_<false> {};

template<>
struct ice_and<true,true,true,true,true,true,true> :
    ct::bool_<true> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_ICE_AND_H_INCLUDED_ */
