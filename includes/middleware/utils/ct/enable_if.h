/**
    @b Project: Wump
    @file        enable_if.h
    @author      Szymon Gutaj
    @brief       
    @date        09-02-2011
    @b History:
     - 09-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_ENABLE_IF_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_ENABLE_IF_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<bool, typename T = void>
struct enable_if_c {};

template<typename T>
struct enable_if_c<true, T>
{
    typedef T type;
};

template<class Cond, typename T = void>
struct enable_if :
    ct::enable_if_c<Cond::value, T> {};

}}}


#endif /* MIDDLEWARE_UTILS_CT_ENABLE_IF_H_INCLUDED_ */
