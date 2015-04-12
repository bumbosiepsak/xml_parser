/**
    @b Project: Wump
    @file        apply_wrap.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_APPLY_WRAP_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_APPLY_WRAP_H_INCLUDED_

#include <middleware/utils/ct/void.h>

namespace middleware { namespace utils { namespace ct {

template<class F>
struct apply_wrap0 {
    typedef typename F::apply::type type;
};

template<
    class F
   ,class A0
>
struct apply_wrap1 {
    typedef typename F::template apply<A0>::type type;
};

template<
    class F
   ,class A0
   ,class A1
>
struct apply_wrap2 {
    typedef typename F::template apply<A0,A1>::type type;
};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
>
struct apply_wrap3 {
    typedef typename F::template apply<A0,A1,A2>::type type;
};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
>
struct apply_wrap4 {
    typedef typename F::template apply<A0,A1,A2,A3>::type type;
};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct apply_wrap5 {
    typedef typename F::template apply<A0,A1,A2,A3,A4>::type type;
};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct apply_wrap :
    ct::apply_wrap5<F,A0,A1,A2,A3,A4> {};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
   ,class A3
>
struct apply_wrap<F,A0,A1,A2,A3,ct::void_> :
    ct::apply_wrap4<F,A0,A1,A2,A3> {};

template<
    class F
   ,class A0
   ,class A1
   ,class A2
>
struct apply_wrap<F,A0,A1,A2,ct::void_,ct::void_> :
    ct::apply_wrap3<F,A0,A1,A2> {};

template<
    class F
   ,class A0
   ,class A1
>
struct apply_wrap<F,A0,A1,ct::void_,ct::void_,ct::void_> :
    ct::apply_wrap2<F,A0,A1> {};

template<
    class F
   ,class A0
>
struct apply_wrap<F,A0,ct::void_,ct::void_,ct::void_,ct::void_> :
    ct::apply_wrap1<F,A0> {};

template<class F>
struct apply_wrap<F,ct::void_,ct::void_,ct::void_,ct::void_,ct::void_> :
    ct::apply_wrap0<F> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_APPLY_WRAP_H_INCLUDED_ */
