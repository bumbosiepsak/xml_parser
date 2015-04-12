/**
    @b Project: Wump
    @file        arg.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_ARG_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_ARG_H_INCLUDED_

#include <middleware/utils/ct/void.h>

namespace middleware { namespace utils { namespace ct {

template<int N> struct arg {};

template<>
struct arg<1> {
    template<
        class A1
       ,class A2=ct::void_
       ,class A3=ct::void_
       ,class A4=ct::void_
       ,class A5=ct::void_
    >
    struct apply {
        typedef A1 type;
    };
};

template<>
struct arg<2> {
    template<
        class A1
       ,class A2
       ,class A3=ct::void_
       ,class A4=ct::void_
       ,class A5=ct::void_
    >
    struct apply {
        typedef A2 type;
    };
};

template<>
struct arg<3> {
    template<
        class A1
       ,class A2
       ,class A3
       ,class A4=ct::void_
       ,class A5=ct::void_
    >
    struct apply {
        typedef A3 type;
    };
};

template<>
struct arg<4> {
    template<
        class A1
       ,class A2
       ,class A3
       ,class A4
       ,class A5=ct::void_
    >
    struct apply {
        typedef A4 type;
    };
};

template<>
struct arg<5> {
    template<
        class A1
       ,class A2
       ,class A3
       ,class A4
       ,class A5
    >
    struct apply {
        typedef A5 type;
    };
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_ARG_H_INCLUDED_ */
