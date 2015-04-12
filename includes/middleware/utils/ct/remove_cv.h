/**
    @b Project: Wump
    @file        remove_cv.h
    @author      Szymon Gutaj
    @brief       Removes 'const' and 'volatile' qualifier from type T
    @date        25-04-2011
    @b History:
     - 25-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_REMOVE_CV_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_REMOVE_CV_H_INCLUDED_

#include <middleware/utils/ct/remove_const.h>
#include <middleware/utils/ct/remove_volatile.h>

namespace middleware { namespace utils { namespace ct {

template<typename T>
struct remove_cv :
    ct::remove_const<
        typename ct::remove_volatile<T>::type
    > {};

}}}

#endif /* MIDDLEWARE_UTILS_CT_REMOVE_CV_H_INCLUDED_ */
