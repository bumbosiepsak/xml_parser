/**
    @b Project: Wump
    @file        quote.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_QUOTE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_QUOTE_H_INCLUDED_

#include <middleware/utils/ct/type_wrap.h>

namespace middleware { namespace utils { namespace ct {

template<
    class F
>
struct quote0 {
    struct apply : ct::type_wrap<F> {};
};

template<
    template<
        class A0
    > class F
>
struct quote1 {
    template<class A0>
    struct apply : ct::type_wrap<F<A0> > {};
};

template<
    template<
        class A0
       ,class A1
    > class F
>
struct quote2 {
    template<
        class A0
       ,class A1
    >
    struct apply : ct::type_wrap<F<A0,A1> > {};
};

template<
    template<
        class A0
       ,class A1
       ,class A2
    > class F
>
struct quote3 {
    template<
        class A0
       ,class A1
       ,class A2
    >
    struct apply : ct::type_wrap<F<A0,A1,A2> > {};
};

template<
    template<
        class A0
       ,class A1
       ,class A2
       ,class A3
    > class F
>
struct quote4 {
    template<
        class A0
       ,class A1
       ,class A2
       ,class A3
    >
    struct apply : ct::type_wrap<F<A0,A1,A2,A3> > {};
};

template<
    template<
        class A0
       ,class A1
       ,class A2
       ,class A3
       ,class A4
    > class F
>
struct quote5 {
    template<
        class A0
       ,class A1
       ,class A2
       ,class A3
       ,class A4
    >
    struct apply : ct::type_wrap<F<A0,A1,A2,A3,A4> > {};
};

template<
    class F
>
struct quote :
    ct::quote0<F> {};

template<
    template<
        class A0
    > class F
   ,class A0
>
struct quote<F<A0> > :
    ct::quote1<F> {};

template<
    template<
        class A0
       ,class A1
    > class F
   ,class A0
   ,class A1
>
struct quote<F<A0,A1> > :
    ct::quote2<F> {};

template<
    template<
        class A0
       ,class A1
       ,class A2
    > class F
   ,class A0
   ,class A1
   ,class A2
>
struct quote<F<A0,A1,A2> > :
    ct::quote3<F> {};

template<
    template<
        class A0
       ,class A1
       ,class A2
       ,class A3
    > class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
>
struct quote<F<A0,A1,A2,A3> > :
    ct::quote4<F> {};

template<
    template<
        class A0
       ,class A1
       ,class A2
       ,class A3
       ,class A4
    > class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct quote<F<A0,A1,A2,A3,A4> > :
    ct::quote5<F> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_QUOTE_H_INCLUDED_ */
