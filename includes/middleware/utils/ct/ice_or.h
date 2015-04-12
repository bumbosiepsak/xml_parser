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

#ifndef MIDDLEWARE_UTILS_CT_ICE_OR_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_ICE_OR_H_INCLUDED_

#include <middleware/utils/ct/bool.h>

namespace middleware { namespace utils { namespace ct {

template<
    bool A0
   ,bool A1
   ,bool A2=false
   ,bool A3=false
   ,bool A4=false
   ,bool A5=false
   ,bool A6=false
>
struct ice_or :
    ct::true_ {};

template<>
struct ice_or<false,false,false,false,false,false,false> :
    ct::false_ {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_ICE_OR_H_INCLUDED_ */
