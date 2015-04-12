/*
 * compose.h
 *
 *  Created on: 12-01-2011
 *      Author: gutaj
 */

#ifndef COMPOSE_H_
#define COMPOSE_H_

#include <functional>

namespace utils { namespace rt {

template <typename F1, typename F2>
struct composer :
    std::unary_function
    <
        typename F2::argument_type,
        typename F1::result_type
    >
{
    composer(F1 f1_, F2 f2_) :
        f1(f1_),
        f2(f2_)
    {
    }

    typename F1::result_type
    operator()(typename F2::argument_type x)
    {
        return f1(f2(x));
    }

private:
    F1 f1;
    F2 f2;
};

template <typename F1, typename F2>
composer<F1, F2> compose(F1 f1, F2 f2)
{
    return composer<F1, F2>(f1, f2);
}

}}


#endif /* COMPOSE_H_ */
