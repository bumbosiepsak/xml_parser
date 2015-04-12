/**
    @b Project: Wump
    @file        accumulate.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_ACCUMULATE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_ACCUMULATE_H_INCLUDED_

#include <middleware/utils/ct/fold.h>

namespace middleware { namespace utils { namespace ct {

template<
    class Sequence
   ,class State
   ,class ForwardOp
>
struct accumulate :
    ct::fold<Sequence,State,ForwardOp> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_ACCUMULATE_H_INCLUDED_ */
