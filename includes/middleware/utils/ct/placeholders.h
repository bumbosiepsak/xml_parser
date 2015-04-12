/**
    @b Project: Wump
    @file        placeholders.h
    @author      Szymon Gutaj
    @brief       
    @date        07-02-2011
    @b History:
     - 07-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_PLACEHOLDERS_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_PLACEHOLDERS_H_INCLUDED_

#include <middleware/utils/ct/arg.h>

namespace middleware { namespace utils { namespace ct {

namespace placeholders {

    typedef ct::arg<-1> _;

    typedef ct::arg<1> _1;
    typedef ct::arg<2> _2;
    typedef ct::arg<3> _3;
    typedef ct::arg<4> _4;
    typedef ct::arg<5> _5;
}

}}}


#endif /* MIDDLEWARE_UTILS_CT_PLACEHOLDERS_H_INCLUDED_ */
