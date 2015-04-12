/**
    @b Project: Wump
    @file        xml_parser.cpp
    @author      Szymon Gutaj
    @brief       Unit tests for 'xml_parser' class.
    @date        02-04-2011
    @version     0.1
    @b History:
     - 02-04-2011
       - sgutaj
         - Initial creation
*/

#include <gtest/gtest.h>
#include <middleware/xml/xml_node.h>
#include <middleware/xml/xml_stream_on_bytes.h>
#include <middleware/xml/xml_parser.h>

namespace uoam_tests { namespace middleware { namespace xml {

using namespace ::middleware::xml;

class xml_parser_test : public ::testing::Test
{
protected:
    xml_node root;
};

template<class String, class XmlNode>
xml_parser_status parse(String const &xml, XmlNode &root)
{
    xml_stream_on_bytes stream(xml.data(), xml.size());
    xml_parser parser;
    return parser.parse(stream, root);
}

TEST_F(xml_parser_test, parse_xml_declaration_ok_scenario)
{
    std::string xml("<?xml version=\"1.0\"?><n></n>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);
    ASSERT_EQ(root.get_name(), "");
    ASSERT_EQ(root.get_value(), "");

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "n");
    ASSERT_EQ(root.get_children()[0].get_value(), "");
}

TEST_F(xml_parser_test, node_ok_scenario)
{
    std::string xml("<node1>value1</node1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_EQ(root.get_children().size(), 1U);
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node1");
    ASSERT_EQ(root.get_children()[0].get_value(), "value1");
}

TEST_F(xml_parser_test, node_nested_ok_scenario)
{
    std::string xml("<?xml version=\"1.0\"?><node1>value1<node2>value2</node2></node1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);
    ASSERT_EQ(root.get_name(), "");
    ASSERT_EQ(root.get_value(), "");

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node1");
    ASSERT_EQ(root.get_children()[0].get_value(), "value1");
    ASSERT_EQ(root.get_children()[0].get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_children()[0].get_name(), "node2");
    ASSERT_EQ(root.get_children()[0].get_children()[0].get_value(), "value2");
}

TEST_F(xml_parser_test, comment_in_value_ok_scenario)
{
    std::string xml("<node1>value1<!-- -comment - --></node1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node1");
    ASSERT_EQ(root.get_children()[0].get_value(), "value1");
    ASSERT_TRUE(root.get_children()[0].get_children().empty());
}

TEST_F(xml_parser_test, comment_at_end_ok_scenario)
{
    std::string xml("<node1>value1</node1><!-- comment -->");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node1");
    ASSERT_EQ(root.get_children()[0].get_value(), "value1");
    ASSERT_TRUE(root.get_children()[0].get_children().empty());
}

TEST_F(xml_parser_test, comment_empty_tag_ok_scenario)
{
    std::string xml("<node1/><!-- comment -->");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node1");
    ASSERT_EQ(root.get_children()[0].get_value(), "");
    ASSERT_TRUE(root.get_children()[0].get_children().empty());
}

TEST_F(xml_parser_test, attribute_ok_scenario)
{
    std::string xml("<node1 attr1='attr_value1'>value1</node1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node1");
    ASSERT_EQ(root.get_children()[0].get_value(), "value1");
    ASSERT_EQ(root.get_children()[0].get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_children()[0].get_type().is_attribute());
    ASSERT_EQ(root.get_children()[0].get_children()[0].get_name(), "attr1");
    ASSERT_EQ(root.get_children()[0].get_children()[0].get_value(), "attr_value1");
}

TEST_F(xml_parser_test, content_with_whitespace_ok_scenario)
{
    std::string xml("<node1>value1a \n \r \t  value1b <node2/>value1c<!-- comment -->\r </node1>  ");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node1");
    ASSERT_EQ(root.get_children()[0].get_value(), "value1a value1b value1c");
    ASSERT_EQ(root.get_children()[0].get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_children()[0].get_name(), "node2");
    ASSERT_EQ(root.get_children()[0].get_children()[0].get_value(), "");
}

TEST_F(xml_parser_test, escaped_ok_scenario)
{
    std::string xml("<node&amp;1 att&#114;1='attr_valu&#x65;1'>value&lt;1<!-- &gt; - --></node&amp;1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node&1");
    ASSERT_EQ(root.get_children()[0].get_value(), "value<1");
    ASSERT_EQ(root.get_children()[0].get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_children()[0].get_type().is_attribute());
    ASSERT_EQ(root.get_children()[0].get_children()[0].get_name(), "attr1");
    ASSERT_EQ(root.get_children()[0].get_children()[0].get_value(), "attr_value1");
}

TEST_F(xml_parser_test, escaped_set_ok_scenario)
{
    std::string xml("<n&lt;&gt;&quot;&apos;&amp;&#x5a;&#x5A;&#90;/>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_EQ(root.get_children().size(), 1U);

    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "n<>\"\'&ZZZ");
    ASSERT_EQ(root.get_children()[0].get_value(), "");
    ASSERT_TRUE(root.get_children()[0].get_children().empty());
}

TEST_F(xml_parser_test, cdata_ok_scenario)
{
    std::string xml("<node1>value1<![CDATA[<![CDATA[>&\"\']] ]>]]]></node1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status.is_ok());
    ASSERT_EQ(root.get_children().size(), 1U);
    ASSERT_TRUE(root.get_type().is_root());
    ASSERT_TRUE(root.get_children()[0].get_type().is_element());
    ASSERT_EQ(root.get_children()[0].get_name(), "node1");
    ASSERT_EQ(root.get_children()[0].get_value(), "value1<![CDATA[>&\"\']] ]>]");
}

TEST_F(xml_parser_test, comment_begin_ok_scenario)
{
    std::string xml("<!-- bla --><node1>value1</node1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status == xml_parser_status::ok);
}

TEST_F(xml_parser_test, unpaired_brackets_err_scenario)
{
    std::string xml("<node1>value1</node1");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status == xml_parser_status::input_malformed);
}

TEST_F(xml_parser_test, unpaired_tags1_err_scenario)
{
    std::string xml("<node1>value1</node2>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status == xml_parser_status::input_malformed);
}

TEST_F(xml_parser_test, unpaired_tags2_err_scenario)
{
    std::string xml("<node1>value1<node2></node1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status == xml_parser_status::input_malformed);
}

TEST_F(xml_parser_test, crippled_begin_err_scenario)
{
    std::string xml("node1>value1</node1>");
    xml_parser_status status = parse(xml, root);

    ASSERT_TRUE(status == xml_parser_status::input_malformed);
}

}}}

