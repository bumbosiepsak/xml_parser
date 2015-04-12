/**
    @b Project: Wump
    @file        is_class.h
    @author      Szymon Gutaj
    @brief       Equivalent to 'true_' for class types
    @date        16-03-2011
    @b History:
     - 16-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef UOAM_RP1_INNER_IS_CLASS_H_INCLUDED_
#define UOAM_RP1_INNER_IS_CLASS_H_INCLUDED_

#include <middleware/utils/ct/bool.h>
#include <middleware/utils/ct/yes_no_type.h>

namespace middleware { namespace utils { namespace ct {

namespace local {

template<typename T>
ct::yes_type isClass(void(T::*)(void));

template<typename T>
ct::no_type isClass(...);

}

template<typename T>
struct is_class :
    ct::bool_<sizeof(ct::yes_type) == sizeof(local::isClass<T>(0))> {};

}}}


#endif /* UOAM_RP1_INNER_IS_CLASS_H_INCLUDED_ */
