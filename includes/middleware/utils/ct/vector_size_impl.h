/**
    @b Project: Wump
    @file        vector_size_impl.h
    @author      Szymon Gutaj
    @brief
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_VECTOR_SIZE_IMPL_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_VECTOR_SIZE_IMPL_H_INCLUDED_

#include <middleware/utils/ct/void.h>

namespace middleware { namespace utils { namespace ct {

template<
    class T0
   ,class T1
   ,class T2
   ,class T3
   ,class T4
   ,class T5
   ,class T6
   ,class T7
   ,class T8
   ,class T9
>
struct vector_size_impl {
    static int const size_ = 10;
};

template<
    class T0
   ,class T1
   ,class T2
   ,class T3
   ,class T4
   ,class T5
   ,class T6
   ,class T7
   ,class T8
>
struct vector_size_impl <
    T0
   ,T1
   ,T2
   ,T3
   ,T4
   ,T5
   ,T6
   ,T7
   ,T8
   ,ct::void_
> {
    static int const size_ = 9;
};

template<
    class T0
   ,class T1
   ,class T2
   ,class T3
   ,class T4
   ,class T5
   ,class T6
   ,class T7
>
struct vector_size_impl <
    T0
   ,T1
   ,T2
   ,T3
   ,T4
   ,T5
   ,T6
   ,T7
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 8;
};

template<
    class T0
   ,class T1
   ,class T2
   ,class T3
   ,class T4
   ,class T5
   ,class T6
>
struct vector_size_impl <
    T0
   ,T1
   ,T2
   ,T3
   ,T4
   ,T5
   ,T6
   ,ct::void_
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 7;
};

template<
    class T0
   ,class T1
   ,class T2
   ,class T3
   ,class T4
   ,class T5
>
struct vector_size_impl <
    T0
   ,T1
   ,T2
   ,T3
   ,T4
   ,T5
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 6;
};

template<
    class T0
   ,class T1
   ,class T2
   ,class T3
   ,class T4
>
struct vector_size_impl <
    T0
   ,T1
   ,T2
   ,T3
   ,T4
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 5;
};

template<
    class T0
   ,class T1
   ,class T2
   ,class T3
>
struct vector_size_impl <
    T0
   ,T1
   ,T2
   ,T3
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 4;
};

template<
    class T0
   ,class T1
   ,class T2
>
struct vector_size_impl <
    T0
   ,T1
   ,T2
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 3;
};

template<
    class T0
   ,class T1
>
struct vector_size_impl <
    T0
   ,T1
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 2;
};

template<
    class T0
>
struct vector_size_impl <
    T0
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 1;
};

template<
>
struct vector_size_impl <
    ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
   ,ct::void_
> {
    static int const size_ = 0;
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_VECTOR_SIZE_IMPL_H_INCLUDED_ */
