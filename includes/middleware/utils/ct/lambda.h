/**
    @b Project: Wump
    @file        lambda.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
     - 20-05-2011 (sgutaj)
         - Fixed for lambda expression forwarding
     - 21-05-2011 (sgutaj)
         - Added 'using namespace placeholders'
*/

#ifndef MIDDLEWARE_UTILS_CT_LAMBDA_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_LAMBDA_H_INCLUDED_

#include <middleware/utils/ct/bind.h>
#include <middleware/utils/ct/quote.h>
#include <middleware/utils/ct/protect.h>
#include <middleware/utils/ct/identity.h>
#include <middleware/utils/ct/placeholders.h>
#include <middleware/utils/ct/is_placeholder.h>

namespace middleware { namespace utils { namespace ct {

using namespace ::middleware::utils::ct::placeholders;

template<
    class F
>
struct lambda :
    ct::identity<F> {};

template<
    class F
>
struct lambda<ct::lambda<F> > :
    ct::identity<
        ct::lambda<F>
    > {};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct lambda<ct::bind<F,A0,A1,A2,A3,A4> > :
    ct::identity<
        ct::bind<F,A0,A1,A2,A3,A4>
    > {};

template<
    int N
>
struct lambda<ct::arg<N> > :
//    ct::protect<arg<N> > {}; // TODO: Revise this.
    ct::identity<
        ct::arg<N>
    > {};

template<
    class T
>
struct lambda<ct::protect<T> > :
    ct::identity<
        ct::protect<T>
    > {};

template<
    template<
        class A0
    > class F
   ,class A0
>
struct lambda<F<A0> > :
    ct::if_<
        ct::is_placeholder<F<A0> >
       ,ct::protect<
            ct::bind1<
                ct::quote1<F>
               ,typename ct::lambda<A0>::type
            >
        >
       ,F<A0>
    > {};

template<
    template<
        class A0
       ,class A1
    > class F
   ,class A0
   ,class A1
>
struct lambda<F<A0,A1> > :
    ct::if_<
        ct::is_placeholder<F<A0,A1> >
       ,ct::protect<
            ct::bind2<
                ct::quote2<F>
               ,typename ct::lambda<A0>::type
               ,typename ct::lambda<A1>::type
            >
        >
       ,F<A0,A1>
    > {};

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
struct lambda<F<A0,A1,A2> > :
    ct::if_<
        ct::is_placeholder<F<A0,A1,A2> >
       ,ct::protect<
            ct::bind3<
                ct::quote3<F>
               ,typename ct::lambda<A0>::type
               ,typename ct::lambda<A1>::type
               ,typename ct::lambda<A2>::type
            >
        >
       ,F<A0,A1,A2>
    > {};

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
struct lambda<F<A0,A1,A2,A3> > :
    ct::if_<
        ct::is_placeholder<F<A0,A1,A2,A3> >
       ,ct::protect<
            ct::bind4<
                ct::quote4<F>
               ,typename ct::lambda<A0>::type
               ,typename ct::lambda<A1>::type
               ,typename ct::lambda<A2>::type
               ,typename ct::lambda<A3>::type
            >
        >
       ,F<A0,A1,A2,A3>
    > {};

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
struct lambda<F<A0,A1,A2,A3,A4> > :
    ct::if_<
        ct::is_placeholder<F<A0,A1,A2,A3,A4> >
       ,ct::protect<
            ct::bind5<
                ct::quote5<F>
               ,typename ct::lambda<A0>::type
               ,typename ct::lambda<A1>::type
               ,typename ct::lambda<A2>::type
               ,typename ct::lambda<A3>::type
               ,typename ct::lambda<A4>::type
            >
        >
       ,F<A0,A1,A2,A3,A4>
    > {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_LAMBDA_H_INCLUDED_ */
