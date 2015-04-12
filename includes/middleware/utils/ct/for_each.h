/**
    @b Project: Wump
    @file        for_each.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_FOR_EACH_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_FOR_EACH_H_INCLUDED_

#include <middleware/utils/ct/begin.h>
#include <middleware/utils/ct/end.h>
#include <middleware/utils/ct/deref.h>
#include <middleware/utils/ct/next.h>

namespace middleware { namespace utils { namespace ct {

template<
    class Seq
   ,class Iter1 = typename ct::begin<Seq>::type
   ,class Iter2 = typename ct::end<Seq>::type
>
struct for_each {
    template<typename Op>
    for_each(Op const &op)
    {
        op(typename ct::deref<Iter1>::type());

        for_each<
            Seq
           ,typename ct::next<Iter1>::type
           ,Iter2
        > f(op);
    }
};

template<
    class Seq
   ,class Iter1
>
struct for_each<
    Seq
   ,Iter1
   ,Iter1
> {
    template<typename Op>
    for_each(Op const &op) {}
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_FOR_EACH_H_INCLUDED_ */
