/**
    @b Project: Wump
    @file        push_back.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_PUSH_BACK_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_PUSH_BACK_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<class T> struct push_back_impl {};

template<
    class Seq
   ,class T
>
struct push_back :
    ct::push_back_impl<typename Seq::tag>:: template apply<Seq,T> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_PUSH_BACK_H_INCLUDED_ */
