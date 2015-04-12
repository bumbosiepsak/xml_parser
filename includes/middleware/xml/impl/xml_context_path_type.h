/**
    @b Project: Wump
    @file        xml_context_path_type.h
    @author      Szymon Gutaj
    @brief       Trait metafunction returning path (internal stack) type used during parsing.
    @date        23-05-2011
    @b History:
     - 23-05-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_CONTEXT_PATH_TYPE_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_CONTEXT_PATH_TYPE_H_INCLUDED_

namespace middleware { namespace xml { namespace impl {

/**
 * Trait metafunction returning path (internal stack) type used during parsing.
 * \tparam Context Context type.
 */
template<
    class Context
>
struct xml_context_path_type
{
    typedef typename Context::path_type type; //!< Returns path type.
};

}}}
//#include <middleware/xml/impl/xml_context_path_type.h>

#endif /* MIDDLEWARE_XML_IMPL_XML_CONTEXT_PATH_TYPE_H_INCLUDED_ */
