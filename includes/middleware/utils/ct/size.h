/**
    @b Project: Wump
    @file        size.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_SIZE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_SIZE_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<class T> struct size_impl {};

template<
    class T
>
struct size :
    ct::size_impl<typename T::tag>:: template apply<T> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_SIZE_H_INCLUDED_ */
