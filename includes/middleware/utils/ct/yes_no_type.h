/**
    @b Project: Wump
    @file        yes_no_type.h
    @author      Szymon Gutaj
    @brief       
    @date        08-02-2011
    @b History:
     - 08-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_YES_NO_TYPE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_YES_NO_TYPE_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

typedef char yes_type;

class no_type
{
    char filling[8];
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_YES_NO_TYPE_H_INCLUDED_ */
