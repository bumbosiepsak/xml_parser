/**
    @b Project: Wump
    @file        bool.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_BOOL_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_BOOL_H_INCLUDED_

#include <middleware/utils/ct/integral_c.h>
#include <middleware/utils/ct/next.h>
#include <middleware/utils/ct/previous.h>

namespace middleware { namespace utils { namespace ct {

template<
    bool C
>
struct bool_ :
    ct::integral_c<bool, C>
{
    typedef bool_<true> next;
    typedef bool_<false> prior;
};

typedef ct::bool_<true> true_;
typedef ct::bool_<false> false_;

template<
    bool B
>
struct next<ct::bool_<B> >
{
    typedef ct::true_ type;
};

template<
    bool B
>
struct previous<ct::bool_<B> >
{
    typedef ct::false_ type;
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_BOOL_H_INCLUDED_ */
