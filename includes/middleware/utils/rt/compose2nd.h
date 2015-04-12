/*
 * compose2nd.h
 *
 *  Created on: 12-01-2011
 *      Author: gutaj
 */

#ifndef COMPOSE2ND_H_
#define COMPOSE2ND_H_

#include <functional>

namespace utils { namespace rt {

template <typename F1, typename F2>
struct composer2nd :
    std::binary_function
    <
        typename F1::first_argument_type,
        typename F2::argument_type,
        typename F1::result_type
    >
{
    composer2nd(F1 f1_, F2 f2_) :
        f1(f1_),
        f2(f2_)
    {
    }

    result_type
    operator()(first_argument_type a1, second_argument_type a2)
    {
        return f1(a1, f2(a2));
    }

private:
    F1 f1;
    F2 f2;
};

template <typename F1, typename F2>
inline composer2nd<F1, F2> compose2nd(F1 f1, F2 f2)
{
    return composer2nd<F1, F2>(f1, f2);
}

}}

#endif /* COMPOSE2ND_H_ */
