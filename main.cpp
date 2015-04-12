
// NOTE: For unit tests of xml parser, see "tests/uoam_tests/gtest/middleware/xml/*.cpp"

#include <iostream>
#include <algorithm>

// Header for xml node
#include <middleware/xml/xml_node.h>

// Header for simple buffer-to-stream adapter
#include <middleware/xml/xml_stream_on_bytes.h>

// Header for xml parser (includes xml node header if more convenient)
#include <middleware/xml/xml_parser.h>

// Header for xml utilities, not neccessary in most cases
#include <middleware/xml/xml_node_utilities.h>

int main()
{
    using namespace std;
    using namespace ::middleware::xml;

    string xml("<?xml version=\"1.0\"?><greeting when='now'>hello world</greeting>");

    // xml_stream_on_bytes - a nice wrapper allowing stream-like access to bytes array.

    // NOTE: This can be any class that implements an interface with three member functions:
    // get()
    // unget()
    // empty()
    xml_stream_on_bytes stream(xml.data(), xml.size());

    // xml_node is equivalent to xml_node_basic<xml::utf8>
    // Specialisation of this type defines string type and its encoding at inner side
    xml_node root;

    // xml_parser is equivalent to xml_parser_if<xml_parser_basic<xml_encodings, xml_error_printer_silent> >, where:
    // xml_encodings: list of accepted (outer side) encodings (by default: UTF-8 only)
    // xml_error_printer_silent: error printer
    xml_parser parser;

    // xml_parser_status is a status-holding type with nice features: convenient 'is_ok()' and 'to_string()' members

    // use 'xml_parser::parse()' to convert xml text to xml tree
    xml_parser_status status = parser.parse(stream, root); // Most important line here!

    cout << "status: " << status.to_string() << endl;

    if(!status.is_ok()) return 1;

    // xml_node is a composite with following fields:
    // - type
    // - name
    // - value
    // - children

    // each field has a getter and setter in form:
    // - get_xxx (returning const reference to field's value)
    // - set_xxx (returning reference to field's value)

    // children is an (iterable) STL collection of type 'children_type'
    // checking if 'children' is empty is not necessary, but possible via 'empty()' member function
    for(xml_node::children_type::const_iterator c  = root.get_children().begin();
                                                c != root.get_children().end();
                                              ++c)
    {
        // you can use STL-like traits
        xml_node::value_type const &name = c->get_name();

        // you can use MPL-like traits (see: xml_node_string_type, xml_node_children_type & xml_node_encoding)
        xml_node_string_type<xml_node>::type const &value = c->get_value();

        string t(c->get_type() == xml_node_type::element ? "element" : // you can compare the type directly
                 is_attribute(*c) ? "attribute" : // you can use the "shim" pattern to check node type
                 c->get_type().is_root() ? "root" : // you can use the member function to check node type
                 is_instruction(*c) ? "instruction" :
                 is_valid(*c) ? "some valid type" : "invalid");

        xml_node_type type = c->get_type();

        // you can access the node's type directly via 'xml_node::value' field
        switch(type.value){
            case xml_node_type::element: break;
            case xml_node_type::root: break;
            default: break;
        }

        cout << name << ": " << value << ": " << t << endl;
    }

    // you can use tiny utilities for extra node operations
    // see:
    // - is_node_name_substr_of
    // - is_node_name_same_as
    // - is_node_name_same
    // - is_node_value_less
    // - etc
    xml_node::children_type::const_iterator i = find_if(root.get_children().begin()
                                                       ,root.get_children().end()
                                                       ,is_node_name_substr_of<xml_node>("greeting node1"));

    if(root.set_children().end() != i)
    {
        cout << "Found node: " << i->get_name() << endl;
    }
    else
    {
        cout << "Found no nodes." << endl;
    }

    return 0;
}
