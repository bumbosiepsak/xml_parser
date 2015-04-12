/**
    @b Project: Wump
    @file        inherit.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_INHERIT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_INHERIT_H_INCLUDED_

#include <middleware/utils/ct/empty_base.h>

namespace middleware { namespace utils { namespace ct {

template<
    class T0
   ,class T1
>
struct inherit2 :
    T0
   ,T1
{
    typedef inherit2 type;
};

template<
    class T0
>
struct inherit2<T0,ct::empty_base>
{
    typedef T0 type;
};

template<
    class T1
>
struct inherit2<ct::empty_base,T1>
{
    typedef T1 type;
};

template<>
struct inherit2<ct::empty_base,ct::empty_base>
{
    typedef ct::empty_base type;
};

template<
    class T0 = ct::empty_base
   ,class T1 = ct::empty_base
   ,class T2 = ct::empty_base
   ,class T3 = ct::empty_base
   ,class T4 = ct::empty_base
>
struct inherit :
    ct::inherit2<
        T0
       ,typename ct::inherit2<
            T1
           ,typename ct::inherit2<
                T2
               ,typename ct::inherit2<
                    T3
                   ,T4
                >::type
            >::type
        >::type
    > {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_INHERIT_H_INCLUDED_ */
