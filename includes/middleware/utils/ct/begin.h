/**
    @b Project: Wump
    @file        begin.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_BEGIN_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_BEGIN_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<class T> struct begin_impl {};

template<
    class T
>
struct begin :
    ct::begin_impl<typename T::tag>::template apply<T> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_BEGIN_H_INCLUDED_ */
