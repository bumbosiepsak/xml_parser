/**
    @b Project: Wump
    @file        remove_const.h
    @author      Szymon Gutaj
    @brief       Removes 'const' qualifier from type T
    @date        25-04-2011
    @b History:
     - 25-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_REMOVE_CONST_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_REMOVE_CONST_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

namespace local {

template<typename T>
struct remove_const_impl
{
    typedef T type;
};

template<typename T>
struct remove_const_impl<T const>
{
    typedef typename remove_const_impl<T>::type type;
};

}

template<typename T>
struct remove_const :
    local::remove_const_impl<T> {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_REMOVE_CONST_H_INCLUDED_ */
