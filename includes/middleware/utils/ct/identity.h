/**
    @b Project: Wump
    @file        identity.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_IDENTITY_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_IDENTITY_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<typename T>
struct identity {
    typedef T type;
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_IDENTITY_H_INCLUDED_ */
