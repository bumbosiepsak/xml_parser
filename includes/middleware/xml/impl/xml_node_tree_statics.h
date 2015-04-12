/**
    @b Project: Wump
    @file        xml_node_tree_statics.h
    @author      Szymon Gutaj
    @brief       Static part of xml_node_tree, separated here for greater compiler compatibility.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_NODE_TREE_STATICS_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_NODE_TREE_STATICS_H_INCLUDED_

namespace middleware { namespace xml { namespace impl {

template<class XmlNode>
struct xml_node_tree_statics
{
    static typename XmlNode::children_type const no_children;
};

template<class XmlNode>
typename XmlNode::children_type const xml_node_tree_statics<XmlNode>::no_children;

}}}

#endif /* MIDDLEWARE_XML_IMPL_XML_NODE_TREE_STATICS_H_INCLUDED_ */
