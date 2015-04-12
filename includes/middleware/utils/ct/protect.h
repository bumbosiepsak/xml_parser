/**
    @b Project: Wump
    @file        protect.h
    @author      Szymon Gutaj
    @brief       
    @date        03-05-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_PROTECT_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_PROTECT_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<class T>
struct protect : T
{
    typedef ct::protect<T> type;
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_PROTECT_H_INCLUDED_ */
