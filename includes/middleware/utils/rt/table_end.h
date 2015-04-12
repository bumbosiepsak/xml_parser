/**
    @b Project: Wump
    @file        table_end.h
    @author      Szymon Gutaj
    @brief       
    @date        19-04-2011
    @b History:
     - 19-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_RT_TABLE_END_H_INCLUDED_
#define MIDDLEWARE_UTILS_RT_TABLE_END_H_INCLUDED_

namespace middleware { namespace utils { namespace rt {

template<class Type, unsigned int Size>
inline Type* table_end(Type (&table)[Size])
{
    return (Table + Size);
}

}}}
//#include <middleware/utils/rt/table_end.h>

#endif /* MIDDLEWARE_UTILS_RT_TABLE_END_H_INCLUDED_ */
