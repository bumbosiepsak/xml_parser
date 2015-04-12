/**
    @b Project: Wump
    @file        xml_node_utilities.h
    @author      Szymon Gutaj
    @brief       Nice-to-have utilities providing common operations on XML nodes.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_NODE_UTILITIES_H_INCLUDED_
#define MIDDLEWARE_XML_XML_NODE_UTILITIES_H_INCLUDED_

#include <functional>

namespace middleware { namespace xml {

/**
 * Binary predicate stating that node names are same (equality).
 */
template<class XmlNode>
struct is_node_name_same : public std::binary_function<XmlNode, XmlNode, bool>
{
    inline bool operator()(XmlNode const &lhs, XmlNode const &rhs) const
    {
        return lhs.get_name() == rhs.get_name();
    }
};

/**
 * Unary predicate stating that node name equals provided constant.
 */
template<class XmlNode>
struct is_node_name_same_as : public std::unary_function<XmlNode, bool>
{
    typedef typename XmlNode::value_type string_type;

public:
    is_node_name_same_as(string_type const &name) : name(name) {}

    inline bool operator()(XmlNode const &name) const
    {
        return this->name == name.get_name();
    }

private:
    string_type const &name;
};

/**
 * Unary predicate stating that node name is a substring of given constant.
 */
template<class XmlNode>
struct is_node_name_substr_of : public std::unary_function<XmlNode, bool>
{
    typedef typename XmlNode::value_type string_type;

    is_node_name_substr_of(string_type const &name) : name(name) {}

private:
    is_node_name_substr_of();

public:
    inline bool operator()(XmlNode const &node) const
    {
        return string_type::npos != this->name.find(node.get_name());
    }

private:
    string_type const &name;
};

/**
 * Binary predicate serving as 'less' operator for node names.
 */
template<class XmlNode>
struct is_node_name_less : public std::binary_function<XmlNode, XmlNode, bool>
{
    inline bool operator()(XmlNode const &lhs, XmlNode const &rhs) const
    {
        return lhs.get_name() < rhs.get_name();
    }
};

/**
 * Binary predicate serving as 'less' operator for node values.
 */
template<class XmlNode>
struct is_node_value_less : public std::binary_function<XmlNode, XmlNode, bool>
{
    inline bool operator()(XmlNode const &lhs, XmlNode const &rhs) const
    {
        return lhs.get_value() < rhs.get_value();
    }
};

}}

#endif /* MIDDLEWARE_XML_XML_NODE_UTILITIES_H_INCLUDED_ */
