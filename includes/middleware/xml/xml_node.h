/**
    @b Project: Wump
    @file        xml_node.h
    @author      Szymon Gutaj
    @brief       Default node type (typedef increasing user-friendliness).
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_NODE_H_INCLUDED_
#define MIDDLEWARE_XML_XML_NODE_H_INCLUDED_

#include <middleware/xml/xml_encodings.h>
#include <middleware/xml/xml_node_basic.h>
#include <middleware/xml/xml_node_string_type.h>
#include <middleware/xml/xml_node_children_type.h>

namespace middleware { namespace xml {

/**
 * \typedef xml_node
 * Easy name for default node type.
 */
typedef xml_node_basic<xml::utf8> xml_node;

}}

#endif /* MIDDLEWARE_XML_XML_NODE_H_INCLUDED_ */
