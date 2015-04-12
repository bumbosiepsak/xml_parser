/**
    @b Project: Wump
    @file        pop_front.h
    @author      Szymon Gutaj
    @brief       
    @date        11-02-2011
    @b History:
     - 11-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_POP_FRONT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_POP_FRONT_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<class T> struct pop_front_impl {};

template<
    class Seq
   ,class T
>
struct pop_front :
    ct::pop_front_impl<typename Seq::tag>:: template apply<Seq,T> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_POP_FRONT_H_INCLUDED_ */
