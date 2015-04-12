/**
    @b Project: Wump
    @file        vector.h
    @author      Szymon Gutaj
    @brief
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_VECTOR_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_VECTOR_H_INCLUDED_

#include <middleware/utils/ct/at.h>
#include <middleware/utils/ct/vector_at_impl.h>
#include <middleware/utils/ct/begin.h>
#include <middleware/utils/ct/deref.h>
#include <middleware/utils/ct/end.h>
#include <middleware/utils/ct/next.h>
#include <middleware/utils/ct/push_back.h>
#include <middleware/utils/ct/size.h>
#include <middleware/utils/ct/vector_size_impl.h>
#include <middleware/utils/ct/void.h>

namespace middleware { namespace utils { namespace ct {

// tag
struct vector_tag {};

// container
template<
    class T0_=ct::void_
   ,class T1_=ct::void_
   ,class T2_=ct::void_
   ,class T3_=ct::void_
   ,class T4_=ct::void_
   ,class T5_=ct::void_
   ,class T6_=ct::void_
   ,class T7_=ct::void_
   ,class T8_=ct::void_
   ,class T9_=ct::void_
>
struct vector :
    ct::vector_size_impl<T0_,T1_,T2_,T3_,T4_,T5_,T6_,T7_,T8_,T9_>
{
    typedef vector_tag tag;
    typedef vector type;

    typedef T0_ T0;
    typedef T1_ T1;
    typedef T2_ T2;
    typedef T3_ T3;
    typedef T4_ T4;
    typedef T5_ T5;
    typedef T6_ T6;
    typedef T7_ T7;
    typedef T8_ T8;
    typedef T9_ T9;
};

// iterator
template<
    class Vector
   ,int Pos
>
struct vector_iterator {
    static int const value = Pos;
};

// size
template<>
struct size_impl<vector_tag> {
    template<class Vector>
    struct apply {
        static int const value = Vector::size_;
    };
};

// begin
template<>
struct begin_impl<vector_tag> {
    template<class Vector>
    struct apply {
        typedef ct::vector_iterator<Vector,0> type;
    };
};

// end
template<>
struct end_impl<vector_tag> {
    template<class Vector>
    struct apply {
        typedef ct::vector_iterator<Vector,Vector::size_> type;
    };
};

// next
template<
    class Vector
   ,int Pos
>
struct next<vector_iterator<Vector,Pos> > {
    typedef ct::vector_iterator<Vector,Pos+1> type;
};

// at
template<
    int Pos
>
struct at_impl<vector_tag, Pos> {
    template<class Vector>
    struct apply :
        ct::vector_at_impl<Vector,Pos> {};
};

// deref
template<
    class Vector
   ,int Pos
>
struct deref<vector_iterator<Vector,Pos> > :
    ct::at<Vector,Pos> {};

}}}

#include <middleware/utils/ct/vector_push_back_impl.h>

namespace middleware { namespace utils { namespace ct {

// push_back
template<>
struct push_back_impl<vector_tag> {
    template<
        class Vector
       ,class T
    >
    struct apply :
        ct::vector_push_back_impl<
            Vector
           ,T
           ,ct::size<Vector>::value
    > {};
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_VECTOR_H_INCLUDED_ */
