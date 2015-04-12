/**
    @b Project: Wump
    @file        decode_function.h
    @author      Szymon Gutaj
    @brief       Trait metafunction that creates a decoder function type for a given XML stream type.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_DECODE_FUNCTION_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_DECODE_FUNCTION_H_INCLUDED_

#include <middleware/xml/impl/code_point.h>

namespace middleware { namespace xml { namespace impl {

/**
 * Trait metafunction that creates a decoder function type for a given XML stream type.
 * \tparam Decoded stream type.
 */
template<class XmlStream>
struct decode_function
{
    typedef code_point (*type)(XmlStream &); //!< Returns function type.
};

}}}

#endif /* MIDDLEWARE_XML_IMPL_DECODE_FUNCTION_H_INCLUDED_ */
