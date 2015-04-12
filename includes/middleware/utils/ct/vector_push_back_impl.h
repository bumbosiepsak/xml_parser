/**
    @b Project: Wump
    @file        vector_push_back_impl.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_VECTOR_PUSH_BACK_IMPL_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_VECTOR_PUSH_BACK_IMPL_H_INCLUDED_

#include <middleware/utils/ct/vector.h>

namespace middleware { namespace utils { namespace ct {

template<class Vector, class T, int N> struct vector_push_back_impl {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,0> :
    ct::vector<
        T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,1> :
    ct::vector<
        typename Vector::T0
       ,T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,2> :
    ct::vector<
        typename Vector::T0
       ,typename Vector::T1
       ,T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,3> :
    ct::vector<
        typename Vector::T0
       ,typename Vector::T1
       ,typename Vector::T2
       ,T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,4> :
    ct::vector<
        typename Vector::T0
       ,typename Vector::T1
       ,typename Vector::T2
       ,typename Vector::T3
       ,T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,5> :
    ct::vector<
        typename Vector::T0
       ,typename Vector::T1
       ,typename Vector::T2
       ,typename Vector::T3
       ,typename Vector::T4
       ,T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,6> :
    ct::vector<
        typename Vector::T0
       ,typename Vector::T1
       ,typename Vector::T2
       ,typename Vector::T3
       ,typename Vector::T4
       ,typename Vector::T5
       ,T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,7> :
    ct::vector<
        typename Vector::T0
       ,typename Vector::T1
       ,typename Vector::T2
       ,typename Vector::T3
       ,typename Vector::T4
       ,typename Vector::T5
       ,typename Vector::T6
       ,T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,8> :
    ct::vector<
        typename Vector::T0
       ,typename Vector::T1
       ,typename Vector::T2
       ,typename Vector::T3
       ,typename Vector::T4
       ,typename Vector::T5
       ,typename Vector::T6
       ,typename Vector::T7
       ,T
    > {};

template<
    class Vector
   ,class T
>
struct vector_push_back_impl<Vector,T,9> :
    ct::vector<
        typename Vector::T0
       ,typename Vector::T1
       ,typename Vector::T2
       ,typename Vector::T3
       ,typename Vector::T4
       ,typename Vector::T5
       ,typename Vector::T6
       ,typename Vector::T7
       ,typename Vector::T8
       ,T
    > {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_VECTOR_PUSH_BACK_IMPL_H_INCLUDED_ */
