/**
    @b Project: Wump
    @file        xml_node_basic.h
    @author      Szymon Gutaj
    @brief       Basic XML node type. Holds elemental XML data in a tree structure.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_NODE_BASIC_H_INCLUDED_
#define MIDDLEWARE_XML_XML_NODE_BASIC_H_INCLUDED_

#include <algorithm>
#include <string>
#include <middleware/xml/xml_node_type.h>
#include <middleware/xml/impl/xml_node_tree.h>

namespace middleware { namespace xml {

/**
 * Basic XML node type. Holds elemental XML data in a tree structure.
 * \tparam Encoding Encoding of node's textual content.
 */
template<
    class Encoding
>
class xml_node_basic :
    public impl::xml_node_tree<xml_node_basic<Encoding> >
{
public:
    typedef xml_node_basic type; //!< Returns self type.
    typedef Encoding encoding; //!< Returns supported encodings list (for internal use)
    typedef std::basic_string<typename Encoding::type> value_type; //!< Returns type of textual node members.

private:
    typedef impl::xml_node_tree<xml_node_basic<Encoding> > base;

public:
    /**
     * Default constructor.
     */
    xml_node_basic() :
        base()
       ,node_type()
       ,name()
       ,value()
    {
    }

    /**
     * Constructor taking initial node type.
     * @param node_type Initial node type.
     */
    explicit xml_node_basic(xml_node_type::value_type node_type) :
        base()
       ,node_type(node_type)
       ,name()
       ,value()
    {
    }

    /**
     * Copy constructor.
     * @param original Source node.
     */
    xml_node_basic(xml_node_basic const &original) :
        base()
       ,node_type(original.node_type)
       ,name()
       ,value()
    {
        this->base::operator=(original);
        this->name.assign(original.name);
        this->value.assign(original.value);
    }

    /**
     * Assign operator.
     * @param rhs Source node.
     * @return Reference to self.
     */
    xml_node_basic &operator=(xml_node_basic rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    /**
     * Equals operator.
     * @param rhs Right hand side comparison argument.
     * @return Returns true if all node members' values equal.
     */
    bool operator==(xml_node_basic const &rhs) const
    {
        return this->base::operator==(rhs)
             &&this->node_type  == rhs.node_type.value
             &&this->name       == rhs.name
             &&this->value      == rhs.value;
    }

    /**
     * Different operator.
     * @param rhs Right hand side comparison argument.
     * @return Returns true if any of node members' values different.
     */
    inline bool operator!=(xml_node_basic const &rhs) const
    {
        return !this->operator==(rhs);
    }

public:

    /**
     * Exception-safe swap function.
     * @param node Node to be swapped with.
     */
    void swap(xml_node_basic &node) throw()
    {
        this->base::swap(node);

        std::swap(this->node_type, node.node_type);
        this->name.swap (node.name);
        this->value.swap(node.value);
    }

    /**
     * Node's metadata getter.
     * @return Returns node's metadata.
     */
    inline value_type const &get_name() const
    {
        return this->name;
    }

    /**
     * Node's data getter.
     * @return Returns node's value.
     */
    inline value_type const &get_value() const
    {
        return this->value;
    }

    /**
     * Node's type (root/attribute/element..etc) getter.
     * @return Returns node's type.
     */
    inline xml_node_type get_type() const
    {
        return this->node_type;
    }

    /**
     * Node's type setter.
     * @return Reference to node's type.
     */
    inline xml_node_type &set_type()
    {
        return this->node_type;
    }

    inline void set_type(xml_node_type::value_type node_type)
    {
        this->node_type = node_type;
    }

    /**
     * Node's metadata setter.
     * @return Reference to node's name.
     */
    inline value_type &set_name()
    {
        return this->name;
    }

    /**
     * Node's metadata setter.
     */
    inline void set_name(value_type const &name)
    {
        this->name = name;
    }

    /**
     * Node's data setter.
     * @return Reference to node's value.
     */
    inline value_type &set_value()
    {
        return this->value;
    }

    /**
     * Node's data setter.
     */
    inline void set_value(value_type const &value)
    {
        this->value = value;
    }

private:
    xml_node_type  node_type;
    value_type     name;
    value_type     value;
};


}}

#endif /* MIDDLEWARE_XML_XML_NODE_BASIC_H_INCLUDED_ */
