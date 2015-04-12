/**
    @b Project: Wump
    @file        xml_node_type.h
    @author      Szymon Gutaj
    @brief       Augumented enum holding the node's type.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_NODE_TYPE_H_INCLUDED_
#define MIDDLEWARE_XML_XML_NODE_TYPE_H_INCLUDED_

namespace middleware { namespace xml {

/**
 * Augumented enum holding the node's type.
 */
struct xml_node_type
{
    typedef xml_node_type type; //!< Returns self type.

    /**
     * Possible node types.
     */
    enum value_type
    {
        element = 0//!< Parsed from "<Node>Element</Node>".
       ,attribute  //!< Parsed from "<Node Attribute="AttrubuteValue"/>"
       ,instruction//!< Parsed from "<?Instruction ?>"
       ,not_set    //!< Node type not set.
       ,comment	   //!< Parsed from "<!-- Comment -->"
       ,root       //!< Node is the root.
       ,last_enum  //!< Helper value (not to be used).
    };

    /**
     * Default constructor.
     */
    xml_node_type() : value(not_set) {}

    /**
     * Constructor/converter from value_type.
     * @param value Source node type
     */
    xml_node_type(value_type value) : value(value) {} // Intentionally implicit

    /**
     * Enables comparison with value_type.
     * @param value Right hand side comparison argument.
     * @return Returns true if nodes have same type.
     */
    inline bool operator==(value_type value) const
    {
        return this->value == value;
    }

    /**
     * @return Returns true if node type is set/valid.
     */
    inline bool is_valid() const
    {
        return (not_set != this->value);
    }

    /**
     * @return Returns true if node type is root.
     */
    inline bool is_root() const
    {
        return (root == this->value);
    }

    /**
     * @return Returns true if node type is attribute.
     */
    inline bool is_attribute() const
    {
        return (attribute == this->value);
    }

    /**
     * @return Returns true if node type is element.
     */
    inline bool is_element() const
    {
        return (element == this->value);
    }

    /**
     * @return Returns true if node type is instruction.
     */
    inline bool is_instruction() const
    {
        return (instruction == this->value);
    }

    /**
     * @return Returns true if node type is comment.
     */
    inline bool is_comment() const
    {
        return (comment == this->value);
    }

    value_type value; //!< Returns node type.
};


/**
 * Shim utility for node type queries.
 * @param node Checked node. Must contain "get_type()" member function.
 * @return Returns true if node type is set/valid.
 */
template<class XmlNode>
inline bool is_valid(XmlNode const &node)
{
    return !(node.get_type() == xml_node_type::not_set);
}

/**
 * Shim utility for node type queries.
 * @param node Checked node. Must contain "get_type()" member function.
 * @return Returns true if node type is root.
 */
template<class XmlNode>
inline bool is_root(XmlNode const &node)
{
    return (node.get_type() == xml_node_type::root);
}

/**
 * Shim utility for node type queries.
 * @param node Checked node. Must contain "get_type()" member function.
 * @return Returns true if node type is attribute.
 */
template<class XmlNode>
inline bool is_attribute(XmlNode const &node)
{
    return (node.get_type() == xml_node_type::attribute);
}

/**
 * Shim utility for node type queries.
 * @param node Checked node. Must contain "get_type()" member function.
 * @return Returns true if node type is element.
 */
template<class XmlNode>
inline bool is_element(XmlNode const &node)
{
    return (node.get_type() == xml_node_type::element);
}

/**
 * Shim utility for node type queries.
 * @param node Checked node. Must contain "get_type()" member function.
 * @return Returns true if node type is instruction.
 */
template<class XmlNode>
inline bool is_instruction(XmlNode const &node)
{
    return (node.get_type() == xml_node_type::instruction);
}

/**
 * Shim utility for node type queries.
 * @param node Checked node. Must contain "get_type()" member function.
 * @return Returns true if node type is comment.
 */
template<class XmlNode>
inline bool is_comment(XmlNode const &node)
{
    return (node.get_type() == xml_node_type::comment);
}

}}

#endif /* MIDDLEWARE_XML_XML_NODE_TYPE_H_INCLUDED_ */
