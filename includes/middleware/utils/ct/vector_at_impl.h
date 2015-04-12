/**
    @b Project: Wump
    @file        vector_at_impl.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_VECTOR_AT_IMPL_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_VECTOR_AT_IMPL_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<class Vector, int Pos> struct vector_at_impl {};

template<
    class Vector
>
struct vector_at_impl <Vector,0> {
    typedef typename Vector::T0 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,1> {
    typedef typename Vector::T1 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,2> {
    typedef typename Vector::T2 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,3> {
    typedef typename Vector::T3 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,4> {
    typedef typename Vector::T4 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,5> {
    typedef typename Vector::T5 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,6> {
    typedef typename Vector::T6 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,7> {
    typedef typename Vector::T7 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,8> {
    typedef typename Vector::T8 type;
};

template<
    class Vector
>
struct vector_at_impl <Vector,9> {
    typedef typename Vector::T9 type;
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_VECTOR_AT_IMPL_H_INCLUDED_ */
