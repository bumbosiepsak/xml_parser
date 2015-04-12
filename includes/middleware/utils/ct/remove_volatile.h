/**
    @b Project: Wump
    @file        remove_volatile.h
    @author      Szymon Gutaj
    @brief       Removes 'volatile' qualifier from type T
    @date        25-04-2011
    @b History:
     - 25-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_REMOVE_VOLATILE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_REMOVE_VOLATILE_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

namespace local {

template<typename T>
struct remove_volatile_impl
{
    typedef T type;
};

template<typename T>
struct remove_volatile_impl<T volatile>
{
    typedef typename remove_volatile_impl<T>::type type;
};

}

template<typename T>
struct remove_volatile :
    local::remove_volatile_impl<T> {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_REMOVE_VOLATILE_H_INCLUDED_ */
