/**
    @b Project: Wump
    @file        at.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_AT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_AT_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<class T, int Pos> struct at_impl {};

template<
    class T
   ,int Pos
>
struct at :
    ct::at_impl<typename T::tag,Pos>::template apply<T> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_AT_H_INCLUDED_ */
