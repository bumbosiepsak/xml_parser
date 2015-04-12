/**
    @b Project: Wump
    @file        bind.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
     - 20-05-2011 (sgutaj)
         - 'bind' in general form added
         - 'hk' isolated in 'local' namespace
         - 'is_same' replaced with dedicated 'is_unnamed_placeholder'
*/

#ifndef MIDDLEWARE_UTILS_CT_BIND_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_BIND_H_INCLUDED_

#include <middleware/utils/ct/apply_wrap.h>
#include <middleware/utils/ct/arg.h>
#include <middleware/utils/ct/int.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<
    int k
   ,class A
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct hk { typedef A type; };

template<
    int k
   ,int N
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct hk<k,ct::arg<N>,A0,A1,A2,A3,A4> :
    ct::apply_wrap<ct::arg<N>,A0,A1,A2,A3,A4> {};

template<
    int k
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct hk<k,ct::arg<-1>,A0,A1,A2,A3,A4> :
    ct::apply_wrap<ct::arg<k>,A0,A1,A2,A3,A4> {};

template<class F>
struct is_unnamed_placeholder :
    ct::int_<0> {};

template <>
struct is_unnamed_placeholder<ct::arg<-1> > :
    ct::int_<1>{};

}

template<
    class F
>
struct bind0 {
    template<
        class U0=ct::void_
       ,class U1=ct::void_
       ,class U2=ct::void_
       ,class U3=ct::void_
       ,class U4=ct::void_
    >
    struct apply :
        ct::apply_wrap0<
            F
        > {};
};

template<
    class F
   ,class A0
>
struct bind1 {
    template<
        class U0=ct::void_
       ,class U1=ct::void_
       ,class U2=ct::void_
       ,class U3=ct::void_
       ,class U4=ct::void_
    >
    struct apply :
        ct::apply_wrap1<
            F
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               ,A0
               ,U0,U1,U2,U3,U4
            >::type
        > {};
};

template<
    class F
   ,class A0
   ,class A1
>
struct bind2 {
    template<
        class U0=ct::void_
       ,class U1=ct::void_
       ,class U2=ct::void_
       ,class U3=ct::void_
       ,class U4=ct::void_
    >
    struct apply :
        ct::apply_wrap2<
            F
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               ,A0
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               ,A1
               ,U0,U1,U2,U3,U4
            >::type
        > {};
};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
>
struct bind3 {
    template<
        class U0=ct::void_
       ,class U1=ct::void_
       ,class U2=ct::void_
       ,class U3=ct::void_
       ,class U4=ct::void_
    >
    struct apply :
        ct::apply_wrap3<
            F
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               ,A0
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               ,A1
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               +local::is_unnamed_placeholder<A2>::value
               ,A2
               ,U0,U1,U2,U3,U4
            >::type
        > {};
};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
>
struct bind4 {
    template<
        class U0=ct::void_
       ,class U1=ct::void_
       ,class U2=ct::void_
       ,class U3=ct::void_
       ,class U4=ct::void_
    >
    struct apply :
        ct::apply_wrap4<
            F
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               ,A0
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               ,A1
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               +local::is_unnamed_placeholder<A2>::value
               ,A2
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               +local::is_unnamed_placeholder<A2>::value
               +local::is_unnamed_placeholder<A3>::value
               ,A3
               ,U0,U1,U2,U3,U4
            >::type
        > {};
};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct bind5 {
    template<
        class U0=ct::void_
       ,class U1=ct::void_
       ,class U2=ct::void_
       ,class U3=ct::void_
       ,class U4=ct::void_
    >
    struct apply :
        ct::apply_wrap5<
            F
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               ,A0
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               ,A1
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               +local::is_unnamed_placeholder<A2>::value
               ,A2
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               +local::is_unnamed_placeholder<A2>::value
               +local::is_unnamed_placeholder<A3>::value
               ,A3
               ,U0,U1,U2,U3,U4
            >::type
           ,typename local::hk<
                local::is_unnamed_placeholder<A0>::value
               +local::is_unnamed_placeholder<A1>::value
               +local::is_unnamed_placeholder<A2>::value
               +local::is_unnamed_placeholder<A3>::value
               +local::is_unnamed_placeholder<A4>::value
               ,A4
               ,U0,U1,U2,U3,U4
            >::type
        > {};
};

template<
    class F
   ,class A0=ct::void_
   ,class A1=ct::void_
   ,class A2=ct::void_
   ,class A3=ct::void_
   ,class A4=ct::void_
>
struct bind;

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct bind :
    ct::bind5<F,A0,A1,A2,A3,A4> {};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
>
struct bind<F,A0,A1,A2,A3,ct::void_> :
    ct::bind4<F,A0,A1,A2,A3> {};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
>
struct bind<F,A0,A1,A2,ct::void_,ct::void_> :
    ct::bind3<F,A0,A1,A2> {};

template<
    class F
   ,class A0
   ,class A1
>
struct bind<F,A0,A1,ct::void_,ct::void_,ct::void_> :
    ct::bind2<F,A0,A1> {};

template<
    class F
   ,class A0
>
struct bind<F,A0,ct::void_,ct::void_,ct::void_,ct::void_> :
    ct::bind1<F,A0> {};

template<class F>
struct bind<F,ct::void_,ct::void_,ct::void_,ct::void_,ct::void_> :
    ct::bind0<F> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_BIND_H_INCLUDED_ */
