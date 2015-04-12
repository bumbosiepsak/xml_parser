/**
    @b Project: Wump
    @file        xml_node.gtest.h
    @author      Szymon Gutaj
    @brief       Unit tests for 'xml_node' class.
    @date        31-03-2011
    @version     0.1
    @b History:
     - 31-03-2011
       - sgutaj
         - Initial creation
*/

#include <gtest/gtest.h>
#include <middleware/xml/xml_node.h>

namespace uoam_tests { namespace middleware { namespace xml {

class xml_node_test : public ::testing::Test
{
protected:
};

TEST_F(xml_node_test, constructor_scenario)
{
    using namespace ::middleware::xml;

    xml_node n1(xml_node_type::root);
    ASSERT_TRUE(n1.get_type() == xml_node_type::root);

    xml_node n2;
    ASSERT_TRUE(n2.get_type() == xml_node_type::not_set);
}

TEST_F(xml_node_test, set_children_scenario)
{
    using namespace ::middleware::xml;

    xml_node n;

    ASSERT_EQ(n.get_children().size(), 0U);

    n.set_children().push_back(xml_node(xml_node(xml_node_type::attribute)));

    ASSERT_TRUE(n.get_children().begin()->get_type() == xml_node_type::attribute);
}

TEST_F(xml_node_test, equals_operator_scenario)
{
    using namespace ::middleware::xml;

    xml_node lhs;
    xml_node rhs;

    ASSERT_TRUE(lhs == rhs) << "Empty node comparison test failed";

    lhs.set_children().push_back(xml_node(xml_node(xml_node_type::attribute)));
    rhs.set_children().push_back(xml_node(xml_node(xml_node_type::attribute)));

    ASSERT_TRUE(lhs == rhs) << "Node with child comparison test failed";

    lhs.set_name("name1");
    rhs.set_name("name1");

    lhs.set_value("value1");
    rhs.set_value("value1");

    lhs.set_children()[0].set_name("name2");
    rhs.set_children()[0].set_name("name2");

    lhs.set_children()[0].set_value("value2");
    rhs.set_children()[0].set_value("value2");

    ASSERT_TRUE(lhs == rhs) << "Node with child and contents comparison test failed";
}

TEST_F(xml_node_test, differs_operator1_scenario)
{
    using namespace ::middleware::xml;

    xml_node lhs;
    xml_node rhs;

    lhs.set_children().push_back(xml_node(xml_node(xml_node_type::element)));
    rhs.set_children().push_back(xml_node(xml_node(xml_node_type::attribute)));

    ASSERT_TRUE(lhs != rhs);
}

TEST_F(xml_node_test, differs_operator2_scenario)
{
    using namespace ::middleware::xml;

    xml_node lhs;
    xml_node rhs;

    lhs.set_name("name1");
    rhs.set_name("nameX");

    ASSERT_TRUE(lhs != rhs);

    rhs.set_name("name1");

    ASSERT_FALSE(lhs != rhs);
}

TEST_F(xml_node_test, differs_operator3_scenario)
{
    using namespace ::middleware::xml;

    xml_node lhs;
    xml_node rhs;

    lhs.set_value("value1");
    rhs.set_value("valueX");

    ASSERT_TRUE(lhs != rhs);

    rhs.set_value("value1");

    ASSERT_FALSE(lhs != rhs);
}

TEST_F(xml_node_test, differs_operator4_scenario)
{
    using namespace ::middleware::xml;

    xml_node lhs;
    xml_node rhs;

    lhs.set_children().push_back(xml_node(xml_node(xml_node_type::attribute)));
    rhs.set_children().push_back(xml_node(xml_node(xml_node_type::element)));

    ASSERT_TRUE(lhs != rhs);

    rhs.set_children().back().set_type(xml_node_type::attribute);

    ASSERT_FALSE(lhs != rhs);
}

TEST_F(xml_node_test, large_tree_scenario)
{
    using namespace ::middleware::xml;

    unsigned int const nodes_count = 10000;
    xml_node n;
    xml_node c;
    c.set_name("d");

    std::vector<xml_node const*> v;
    v.reserve(nodes_count);

    for(unsigned int i = 0; i < nodes_count; ++i)
    {
        c.set_name()[0] = static_cast<xml_node::value_type::value_type>(i % 123);
        n.set_children().push_back(c);
        v.push_back(&n.get_children().back());
    }

    ASSERT_EQ(n.get_children().size(), nodes_count);

    std::vector<xml_node const*>::const_iterator vi = v.begin();
    for(xml_node::children_type::const_iterator ci  = n.get_children().begin();
                                                ci != n.get_children().end();
                                              ++ci, ++vi)
    {
        ASSERT_EQ((*vi)->get_name(), ci->get_name()) << "Node container invalidates references on expansion";
        ASSERT_EQ((*vi), &(*ci)) << "Node container invalidates references on expansion";
    }

    SUCCEED();
}

TEST_F(xml_node_test, assign_scenario)
{
    using namespace ::middleware::xml;

    unsigned int const nodes_count = 10;
    xml_node lhs;
    xml_node rhs;

    xml_node c;
    c.set_name("d");

    for(unsigned int i = 0; i < nodes_count; ++i)
    {
        c.set_name()[0] = static_cast<xml_node::value_type::value_type>(i % 123);
        lhs.set_children().push_back(c);

        for(unsigned int i = 0; i < nodes_count; ++i)
        {
            c.set_name()[0] = static_cast<xml_node::value_type::value_type>(i % 123);
            lhs.set_children().back().set_children().push_back(c);
        }
    }

    rhs = lhs;

    ASSERT_TRUE(lhs == rhs);
}

TEST_F(xml_node_test, copy_construct_scenario)
{
    using namespace ::middleware::xml;

    unsigned int const nodes_count = 10;
    xml_node lhs;

    xml_node c;
    c.set_name("d");

    for(unsigned int i = 0; i < nodes_count; ++i)
    {
        c.set_name()[0] = static_cast<xml_node::value_type::value_type>(i % 123);
        lhs.set_children().push_back(c);

        for(unsigned int i = 0; i < nodes_count; ++i)
        {
            c.set_name()[0] = static_cast<xml_node::value_type::value_type>(i % 123);
            lhs.set_children().back().set_children().push_back(c);
        }
    }

    xml_node rhs(lhs);

    ASSERT_TRUE(lhs == rhs);
}

}}}

