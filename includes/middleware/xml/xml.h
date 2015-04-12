/**
    @b Project: Wump
    @file        xml.h
    @author      Szymon Gutaj (sgutaj) <szymon.gutaj@nsn.com>
    @brief       Description of middleware/xml component.
    @date        13-02-2012
    @b History:
     - 13-02-2012 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_H_INCLUDED_
#define MIDDLEWARE_XML_XML_H_INCLUDED_

/** @defgroup xml_parser XML parser for embedded solutions. */

namespace middleware {

/**
 * @brief Contains XML parser classes.
 */
namespace xml { }
}

/**
@mainpage xml_parser: XML parser for embedded solutions.

<B>Greetings!</B>

I'm sending you some sample code.
Actually it's something that works (see description below)
and I'll do my best to make it as nice and easy for you as I can.

What I'll more less try to present here is:
- how I code,
- how I design code,
- what is my degree of C++ knowledge,
- what is my degree of Make knowledge,
- what is my approach to software production (documentation, unit tests, used tools, etc.).

<HR>

\section description Description

\subsection brief Brief

This sample code is a simple XML parser which I wrote for needs of my past embedded/real time projects.

The rationale behind writing this (although quite common) software was:
- urgent need for replacement of legacy code (with specific interface),
- company's copyright policy and project's guidelines,
- relatively high constraints (need for low program memory footprint and strictly deterministic run-time performance),
- requirement of high portability, quality and extensibility on demand.

During design and implementation phase, few lower-level requirements were formulated:
- the software shall be easy to use (at the interface level),
- the software can utilize all that's offered by C++ and available libraries (metaprogramming) to achieve type safety,
modularity and self-optimisation.
- the software shall be developed with test-driven approach: by being highly orthogonal and simultaneously unit tested.

\subsection introduction Introduction

XML (Extensive Markup Language) is a way of representing some data with its description (metadata) in a textual form.
Stand-alone piece of data is called an XML document. It possess a feature of being hierarchical and form a tree structure.
Each node of a tree consists of metadata field ("Name"), data field ("Value"), type field ("Type", explained later) and
list of node's leafs ("Children").

A piece of software that is able to convert XML document into its corresponding tree is called a parser.
And this is what our xml_parser basically does (to be specific: it is a DOM parser).

XML operates on Unicode data, where every character is a so called "code point" (32-bit unsigned integer).
Such code points are usually inconvenient to store/transmit and a concept called "encoding" comes to help.
Encoding is nothing more, than a strictly defined binary representation of code points. Various standard encodings,
like UTF-8 or UTF-16, exist and possess interesting features.

When we want to parse some input data, its encoding needs to be recognized. Then this data might need to be decoded
for processing. After that, during tree construction, data might need encoding again (to the desired output format).

\subsection usage Usage

Most basic usage of parser requires few lines of code:

\code

#include <string>
#include <middleware/xml/xml_stream_on_string.h>

#include <middleware/xml/xml_node.h>
#include <middleware/xml/xml_parser.h>

void parsing_hello_world()
{
    using namespace std;
    using namespace ::middleware::xml;

    string xml("\<?xml version=\"1.0\"?\>\<greeting when='now'\>hello world\</greeting\>");

    xml_stream_on_string stream(xml); // Input

    xml_node   root;                  // Output
    xml_parser parser;                // Parser

    xml_parser_status status = parser.parse(stream, root);

    \\ All done! Time to display what we have!

    cout << "status: " << status.to_string() << endl << endl;

    if(status.is_ok());
    {
        for(xml_node::children_type::const_iterator c  = root.get_children().begin();
                                                    c != root.get_children().end();
                                                  ++c)
        {
            xml_node::value_type const &name  = c->get_name();
            xml_node::value_type const &value = c->get_value();

            string type(
                is_element(*c)     ? "element"         :
                is_attribute(*c)   ? "attribute"       :
                is_valid(*c)       ? "some valid type" :
                                     "invalid");

            cout << name << ": " << value << ": " << type << endl;
        }
    }
}

\endcode

This will output something like:
\code
status: xml_parser_status::ok
greeting: hello world: element
\endcode

In case of more specific needs, there's extra flexibility available:

\li Any stream-like object may serve as XML data source, as long as it's interface contains three member functions:
<tt>get()</tt>, <tt>unget()</tt> and <tt>empty()</tt>.

\li The xml_node type is actually an <tt>xml_node_basic<utf8></tt> (same concept as with good old <tt>std::string</tt> bein a <tt>std::basic_string<char></tt>).
The <tt>utf8</tt> tag serves as a trait for <tt>xml_node_basic</tt> ("use 8-bit characters") and for the <tt>xml_parser</tt> itself ("encode output data as UTF-8").
By using different tags, different output encodings may be requested.

\li The xml_parser is actually an <tt>xml_node_if< xml_parser_basic< xml_encodings, xml_error_printer_silent> ></tt>.
This means that the default engine (<tt>xml_parser_basic</tt>) will be used with default input encodings support and a "silent" error printer.

\li The <tt>xml_encodings</tt> is actually a compile-time (MPL-like) <tt>ct::vector<utf8></tt>, which means that the parser will accept UTF-8-encoded data.
Defining it to be a <tt>ct::vector<utf8, utf16></tt> would allow UTF-16 data (at cost of some increase in code size).

\li The printer concept allows for customizing of how parser logs its operation. This way the parsing and printing are less coupled.
The <tt>xml_error_printer_std</tt>, for example, prints to standard output.

\li STL, as well as MPL style of traits exist. This exposes a metaprogramming interface.
For example, the <tt>xml_node::children_type</tt> equivalent is <tt>xml_node_children_type<xml_node>::type</tt>.

\subsection architecture Simplified architecture

The parsers operation is based on stream processing. The input stream is being decoded into code points.
These code points are being processed by the parser, which is (in simple words) a state machine, synchronized
with markup used in XML. Distinct XML parts are being extracted (metadata, data, instructions, comments etc.)
and, after passing an output stream/encoder, formed into a composite tree structure (XML nodes).

Each node has its type, reflecting its source (root, element, attribute, processing instruction).
Please see <tt>middleware::xml::xml_node_basic</tt> for documentation of the XML node.

Additionally, in first phase of XML stream processing, its encoding is being recognized by a decoder selector.
Appriopriate decoding function is being selected and plugged into the decoder.

XML instructions are being processed by a separate (higher level) instruction processor.

The architectural principle is: one functionality, one class (which increases orthogonality of the design).

\subsection key_points Key points

Worth noting:

\li Please see main.cpp for example use.

\li The parser engine (<tt>xml::impl::xml_parser_basic</tt>) does just one pass over XML data. The parsing complexity is O(n),
 where n is the XML input size. All internal data structures don't require memory re-allocation and allocate it gracefully,
 what is quite important in embedded/real-time computing.

\li The input encoding recognition is done two ways: by peeking first few bytes of data and by reading the XML declaration ("<?xml encoding="utf-8"?>").

\li STL is being used under the hood.

\li C++ metaprogramming is (not much, but anyway) used. Since my project's guidelines didn't allow usage of Boost,
 I implemented the (highly desired) equivalent of Boost::MPL myself. It is called middleware::utils::ct (compile time)
 and can be browsed in includes/middleware/utils/ct. Loose coupling to XML parser is achieved by namespace aliasing.
 This way original Boost::MPL could be used if needed (without need of touching the core code).

\li New encoding types can be added seamlessly - see encoding_specific_ascii.h and encoding_specific_utf8.h.

\li Unit tests are available under path: <tt>tests/uoam_tests/gtest/middleware/xml</tt>. The project's reality was
 quite harsh (required usage of 2 unit test frameworks: Googletest + CXX Test;
 4 compilers: GCC + MSVC + DIAB + LLVM; 3 platforms: x86 + PowerPC + ARM;
 2 build systems: GNU Make + Electric Make, 3 host environments: Linux + Windows + emulated Windows;
 need for on-target/radiomodule continuous integration),
 I wrote an extensible continuous integration meta-framework in Make, C++ and Python. It has a plugin-based architecture.
 It allows adding new toolchains, as well as new components, as plugins. For example it was possible to compile the
 unit tests-equipped code, upload it to the radiomodule, run tests there and download results with just one keyboard stroke.
 I can provide its documentation if necessary.

\li The code was slightly embellished with Doxygen documentation. What you read now is also a Doxygen-generated page!;)

\subsection building Building example code

In order to run the software and unit tests, you need GCC and GNU Make/Cygwin. You also need to update <tt>tests/environment/paths_custom.inc</tt> to match your configuration.

<b>Using pure Make</b>: you can build the working sample from command line (using GCC and GNU Make/Cygwin). After updating <tt>tests/environment/paths_custom.inc</tt>,
please open a command prompt at <tt>sample_code_szymon_gutaj</tt> location and type (for sample and tests, respectively):

\code
mingw32-make all
mingw32-make tests
\endcode

*/

#endif /* MIDDLEWARE_XML_XML_H_INCLUDED_ */
