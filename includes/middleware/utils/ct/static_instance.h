/**
    @b Project: Wump
    @file        static_instance.h
    @author      Szymon Gutaj
    @brief       
    @date        09-02-2011
    @b History:
     - 09-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_CT_STATIC_INSTANCE_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_STATIC_INSTANCE_H_INCLUDED_

namespace middleware { namespace utils { namespace ct {

template<typename T>
struct static_instance
{
    typedef static_instance<T> type;

    typedef T value_type;

    static T value;
};

}}}


#endif /* MIDDLEWARE_UTILS_CT_STATIC_INSTANCE_H_INCLUDED_ */
