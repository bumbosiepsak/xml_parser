/**
    @b Project: Wump
    @file        xml_node_children_type.h
    @author      Szymon Gutaj
    @brief       Trait metafunction for retrieving children type of a given node type.
    @date        05-03-2011
    @b History:
     - 05-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_NODE_CHILDREN_TYPE_H_INCLUDED_
#define MIDDLEWARE_XML_XML_NODE_CHILDREN_TYPE_H_INCLUDED_

namespace middleware { namespace xml {

/**
 * Trait metafunction returning the type of node's children (some collection type).
 * \tparam Node Input node type.
 */
template<class Node>
struct xml_node_children_type
{
    typedef typename Node::children_type type; //!< Returns node's children type.
};

}}

#endif /* MIDDLEWARE_XML_XML_NODE_CHILDREN_TYPE_H_INCLUDED_ */
