/**
    @b Project: Wump
    @file        xml_node_string_type.h
    @author      Szymon Gutaj
    @brief       Trait metafunction for retrieving string type of a given node type.
    @date        16-03-2011
    @b History:
     - 16-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_NODE_STRING_TYPE_H_INCLUDED_
#define MIDDLEWARE_XML_XML_NODE_STRING_TYPE_H_INCLUDED_

namespace middleware { namespace xml {

/**
 * Trait metafunction returning the type of node's textual content (some string type).
 * \tparam Node Input node type.
 */
template<class XmlNode>
struct xml_node_string_type
{
    typedef typename XmlNode::value_type type; //!< Returns node's textual content type.
};

}}

#endif /* MIDDLEWARE_XML_XML_NODE_STRING_TYPE_H_INCLUDED_ */
