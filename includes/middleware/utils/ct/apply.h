/**
    @b Project: Wump
    @file        apply.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_APPLY_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_APPLY_H_INCLUDED_

#include <middleware/utils/ct/apply_wrap.h>
#include <middleware/utils/ct/lambda.h>
#include <middleware/utils/ct/void.h>

namespace middleware { namespace utils { namespace ct {

template<
    class F
>
struct apply0 :
    ct::apply_wrap0<typename lambda<F>::type> {};

template<
    class F
   ,class A1
>
struct apply1 :
    ct::apply_wrap1<typename lambda<F>::type,A1> {};

template<
    class F
   ,class A1
   ,class A2
>
struct apply2 :
    ct::apply_wrap2<typename lambda<F>::type,A1,A2> {};

template<
    class F
   ,class A1
   ,class A2
   ,class A3
>
struct apply3 :
    ct::apply_wrap3<typename lambda<F>::type,A1,A2,A3> {};

template<
    class F
   ,class A1
   ,class A2
   ,class A3
   ,class A4
>
struct apply4 :
    ct::apply_wrap4<typename lambda<F>::type,A1,A2,A3,A4> {};

template<
    class F
   ,class A1
   ,class A2
   ,class A3
   ,class A4
   ,class A5>
struct apply5 :
    ct::apply_wrap5<typename lambda<F>::type,A1,A2,A3,A4,A5> {};

template<
    class F
   ,class A1=ct::void_
   ,class A2=ct::void_
   ,class A3=ct::void_
   ,class A4=ct::void_
   ,class A5=ct::void_
>
struct apply :
    ct::apply_wrap<typename lambda<F>::type,A1,A2,A3,A4,A5> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_APPLY_H_INCLUDED_ */
