/**
    @b Project: Wump
    @file        fold.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_FOLD_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_FOLD_H_INCLUDED_

#include <middleware/utils/ct/apply.h>
#include <middleware/utils/ct/deref.h>
#include <middleware/utils/ct/next.h>
#include <middleware/utils/ct/begin.h>
#include <middleware/utils/ct/end.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<
     class Current
    ,class End
    ,class State
    ,class ForwardOp
>
struct fold_impl
{
    typedef typename ct::apply2<
        ForwardOp
       ,State
       ,typename ct::deref<Current>::type
    >::type current_;

    typedef typename fold_impl<
        typename ct::next<Current>::type
       ,End
       ,current_
       ,ForwardOp
    >::type type;
};

template<
     class Current
    ,class State
    ,class ForwardOp
>
struct fold_impl <
    Current
   ,Current
   ,State
   ,ForwardOp
>
{
    typedef State type;
};

}

template<
    class Sequence
   ,class State
   ,class ForwardOp
>
struct fold
{
    typedef typename local::fold_impl<
        typename ct::begin<Sequence>::type
       ,typename ct::end<Sequence>::type
       ,State
       ,ForwardOp
    >::type type;
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_FOLD_H_INCLUDED_ */
