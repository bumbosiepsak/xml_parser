/**
    @b Project: Wump
    @file        if.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IF_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IF_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<bool cond, class T1, class T2> struct if_c {};

template<
    class T1
   ,class T2
>
struct if_c<true,T1,T2>
{
    typedef T1 type;
};

template<
    class T1
   ,class T2
>
struct if_c<false,T1,T2>
{
    typedef T2 type;
};

template<
    class C
   ,class T1
   ,class T2
>
struct if_ :
    ct::if_c<C::value,T1,T2> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_IF_H_INCLUDED_ */
