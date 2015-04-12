/**
    @b Project: Wump
    @file        disable_if.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_DISABLE_IF_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_DISABLE_IF_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<bool, typename T = void>
struct disable_if_c {};

template<typename T>
struct disable_if_c<false, T>
{
    typedef T type;
};

template<class Cond, typename T = void>
struct disable_if :
    ct::disable_if_c<Cond::value, T> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_DISABLE_IF_H_INCLUDED_ */
