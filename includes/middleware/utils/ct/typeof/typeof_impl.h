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

#ifndef MIDDLEWARE_UTILS_CT_TYPEOF_TYPEOF_IMPL_H_INCLUDED_
#define MIDDLEWARE_UTILS_CT_TYPEOF_TYPEOF_IMPL_H_INCLUDED_

#include <middleware/utils/ct/typeof/unique_id.h>

namespace middleware { namespace utils { namespace _typeof {

class typeof_not_registered_type;

// Function that matches expressions of unregistered type (error checking)
template<class T>
typeof_not_registered_type expr_to_id(T const&);

// Primary template of classes that translate unique id to corresponding type
template<int unique_id>
struct id_to_type{};

}}}

// Define template specialisation that translates unique id to (nested) type T
#define register_type                                           \
    namespace middleware { namespace utils { namespace _typeof {\
        template<>                                              \
        struct id_to_type<MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID> \
        { typedef

// Define function overload that translates expression of type T to (array of size equal to) unique id
#define for_typeof  \
            type; };\
        char (& expr_to_id(typename id_to_type<MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID>::type))[MIDDLEWARE_UTILS_CT_TYPEOF_UNIQUE_ID];\
    }}}

// Retrieve type of expression using chain: expr to id -> id to type
#define typeof_(EXPR) \
        middleware::utils::_typeof::id_to_type<sizeof(middleware::utils::_typeof::expr_to_id(EXPR))>::type

#endif /* MIDDLEWARE_UTILS_CT_TYPEOF_TYPEOF_IMPL_H_INCLUDED_ */


