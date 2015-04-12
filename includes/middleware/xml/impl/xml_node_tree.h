/**
    @b Project: Wump
    @file        xml_node_tree.h
    @author      Szymon Gutaj
    @brief       Composite (tree) part of XML node.
    @date        19-04-2011
    @b History:
     - 19-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_NODE_TREE_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_NODE_TREE_H_INCLUDED_

#include <algorithm>
#include <deque>
#include <middleware/xml/impl/xml_node_tree_statics.h>

namespace middleware { namespace xml { namespace impl {

/**
 * Composite (tree) part of XML node.
 * \tparam Payload Node contents (provided using Curiously Recurring Template Pattern)
 */
template<class Payload>
class xml_node_tree
{
public:
    typedef xml_node_tree type; //!< Returns self.
    typedef Payload value_type; //!< Returns value type (payload).
    typedef std::deque<value_type> children_type; //!< Returns children type (collection).

private:
    typedef xml::impl::xml_node_tree_statics<value_type> statics;

public:
    /**
     * Default constructor, creates empty tree.
     */
    xml_node_tree() :
        children(const_cast<children_type*>(&statics::no_children)) // NOTE: We can cast "const" away here and guarantee that "no_children" never gets modified.
    {
    }

    /**
     * Copy constructor
     * @param original Source of data.
     */
    xml_node_tree(xml_node_tree const &original) :
        children(const_cast<children_type*>(&statics::no_children))
    {
        if(&statics::no_children != original.children)
        {
            this->children = new children_type(*original.children);
        }
    }

    /**
     * Destructor
     */
    ~xml_node_tree()
    {
        if(&statics::no_children != this->children)
        {
            delete this->children;
        }
    }

    /**
     * Assign operator
     * @param rhs Source of data.
     * @return Reference to self.
     */
    xml_node_tree &operator=(xml_node_tree rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    /**
     * Equals operator
     * @param rhs Right hand side data.
     * @return Returns true if value same.
     */
    bool operator==(xml_node_tree const &rhs) const
    {
        return this->children ==  rhs.children
           || *this->children == *rhs.children;
    }

public:
    /**
     * Exception safe swap.
     * @param node Node to be swapped with.
     */
    void swap(xml_node_tree &node) throw()
    {
        std::swap(this->children, node.children);
    }

    /**
     * Getter of children (leafs)
     * @return Reference to children.
     */
    inline children_type const &get_children() const
    {
        return *(this->children);
    }

    /**
     * Setter of children (leafs)
     * @return Reference to children.
     */
    children_type &set_children()
    {
        if(&statics::no_children == this->children)
        {
            this->children = new children_type;
        }
        return *(this->children);
    }

private:
    children_type *children;
};

}}}
//#include <middleware/xml/impl/xml_node_tree.h>

#endif /* MIDDLEWARE_XML_IMPL_XML_NODE_TREE_H_INCLUDED_ */
