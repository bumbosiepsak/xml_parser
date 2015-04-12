/**
    @b Project: Wump
    @file        typeof.h
    @author      Szymon Gutaj
    @brief       
    @date        11-02-2011
    @b History:
     - 11-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_TYPEOF_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_TYPEOF_H_INCLUDED_

#include <middleware/utils/ct/typeof/typeof_impl.h>

// Register built-in types
register_type bool                  for_typeof;
register_type char                  for_typeof;
register_type signed   char         for_typeof;
register_type unsigned char         for_typeof;
register_type signed   short        for_typeof;
register_type unsigned short        for_typeof;
register_type signed   int          for_typeof;
register_type unsigned int          for_typeof;
register_type signed   long         for_typeof;
register_type unsigned long         for_typeof;
register_type float                 for_typeof;
register_type double                for_typeof;
register_type long double           for_typeof;

register_type wchar_t               for_typeof;
register_type signed   long long    for_typeof;
register_type unsigned long long    for_typeof;

#endif /* MIDDLEWARE_UTILS_CT_TYPEOF_H_INCLUDED_ */

// Generate next bank of unique id's (once every inclusion of typedef.h)
#include MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID_GROUP_INCREMENT()
