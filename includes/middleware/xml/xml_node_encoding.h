/**
    @b Project: Wump
    @file        xml_node_encoding.h
    @author      Szymon Gutaj
    @brief       Trait metafunction for retrieving encoding of a given node type.
    @date        05-03-2011
    @b History:
     - 05-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_NODE_ENCODING_H_INCLUDED_
#define MIDDLEWARE_XML_XML_NODE_ENCODING_H_INCLUDED_

namespace middleware { namespace xml {

/**
 * Trait metafunction returning the node encoding's tag (utf8, utf16..etc).
 * \tparam Node Input node type.
 */
template<class Node>
struct xml_node_encoding
{
    typedef typename Node::encoding type; //!< Returns node encoding's tag.
};

}}

#endif /* MIDDLEWARE_XML_XML_NODE_ENCODING_H_INCLUDED_ */
