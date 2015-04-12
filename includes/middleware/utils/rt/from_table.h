/**
    @b Project: Wump
    @file        from_table.h
    @author      Szymon Gutaj
    @brief       Initialization helper
    @date        19-04-2011
    @b History:
     - 19-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_RT_FROM_TABLE_H_INCLUDED_
#define MIDDLEWARE_UTILS_RT_FROM_TABLE_H_INCLUDED_

namespace middleware { namespace utils { namespace rt {

template<
    class T
   ,unsigned int Trim = 0U
>
class from_table : public T
{
public:
    template<
        class Type
       ,unsigned int Size
    >
    from_table(Type (&table)[Size]) : T(table, table + Size - Trim)
    {
    }
};

}}}
//#include <middleware/utils/rt/from_table.h>

#endif /* MIDDLEWARE_UTILS_RT_FROM_TABLE_H_INCLUDED_ */
