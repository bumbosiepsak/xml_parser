/**
    @b Project: Wump
    @file        is_placeholder.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IS_PLACEHOLDER_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IS_PLACEHOLDER_H_INCLUDED_

#include <middleware/utils/ct/arg.h>
#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/ice_or.h>

namespace middleware { namespace utils { namespace ct {

template<class F>
struct is_placeholder :
    ct::false_ {};

template <int N>
struct is_placeholder<ct::arg<N> > :
    ct::true_{};

template<
    template<
        class T1
    > class F
   ,class T1
>
struct is_placeholder<F<T1> > :
    ct::is_placeholder<T1> {};

template<
    template<
        class T1
       ,class T2
    > class F
   ,class T1
   ,class T2
>
struct is_placeholder<F<T1,T2> > :
    ct::ice_or<
        ct::is_placeholder<T1>::value
       ,ct::is_placeholder<T2>::value
    > {};

template<
    template<
        class T1
       ,class T2
       ,class T3
    > class F
   ,class T1
   ,class T2
   ,class T3
>
struct is_placeholder<F<T1,T2,T3> > :
    ct::ice_or<
        ct::is_placeholder<T1>::value
       ,ct::is_placeholder<T2>::value
       ,ct::is_placeholder<T3>::value
    > {};

template<
    template<
        class T1
       ,class T2
       ,class T3
       ,class T4
    > class F
   ,class T1
   ,class T2
   ,class T3
   ,class T4
>
struct is_placeholder<F<T1,T2,T3,T4> > :
    ct::ice_or<
        ct::is_placeholder<T1>::value
       ,ct::is_placeholder<T2>::value
       ,ct::is_placeholder<T3>::value
       ,ct::is_placeholder<T4>::value
    > {};

template<
    template<
        class T1
       ,class T2
       ,class T3
       ,class T4
       ,class T5
    > class F
   ,class T1
   ,class T2
   ,class T3
   ,class T4
   ,class T5
>
struct is_placeholder<F<T1,T2,T3,T4,T5> > :
    ct::ice_or<
        ct::is_placeholder<T1>::value
       ,ct::is_placeholder<T2>::value
       ,ct::is_placeholder<T3>::value
       ,ct::is_placeholder<T4>::value
       ,ct::is_placeholder<T5>::value
    > {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_IS_PLACEHOLDER_H_INCLUDED_ */
