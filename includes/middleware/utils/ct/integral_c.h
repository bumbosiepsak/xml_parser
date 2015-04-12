/**
    @b Project: Wump
    @file        integral_c.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_INTEGRAL_C_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_INTEGRAL_C_H_INCLUDED_

#include <middleware/utils/ct/next.h>
#include <middleware/utils/ct/previous.h>

namespace middleware { namespace utils { namespace ct {

template<
    typename T
   ,T N
>
struct integral_c
{
    static T const value = N;

    typedef integral_c<T,N> type;

    typedef T value_type;

    operator T() const { return N; }
};

template<
    typename T
   ,T N
>
struct next<ct::integral_c<T,N> >
{
    typedef ct::integral_c<T,N+1> type;
};

template<
    typename T
   ,T N
>
struct previous<ct::integral_c<T,N> >
{
    typedef ct::integral_c<T,N-1> type;
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_INTEGRAL_C_H_INCLUDED_ */
