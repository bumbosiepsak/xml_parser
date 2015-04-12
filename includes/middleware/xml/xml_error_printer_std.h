/**
    @b Project: Wump
    @file        xml_error_printer_std.h
    @author      Szymon Gutaj
    @brief       XML parsing error printer for STD environment.
    @date        21-05-2011
    @b History:
     - 21-05-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_ERROR_PRINTER_STD_H_INCLUDED_
#define MIDDLEWARE_XML_XML_ERROR_PRINTER_STD_H_INCLUDED_

#include <string>
#include <iostream>
#include <middleware/xml/xml_node_encoding.h>
#include <middleware/xml/impl/xml_transcoder.h>
#include <middleware/xml/impl/xml_error_detail.h>
#include <middleware/xml/impl/xml_context_path_type.h>

namespace middleware { namespace xml {

/**
 * STD error printer, uses standard output stream
 */
class xml_error_printer_std
{
public:
	/**
	 * Prints the error details.
	 * @param context Context of parsing (parser's internal state).
	 */
    template<class Context>
    void print(Context &context)
    {
        using namespace std;
        using namespace ::middleware::xml::impl;

        // Print introduction
        cout << "Parsing failed: " << context.status.to_string() << endl;

        string scratchpad; // Little scratchpad for indentation and other string operations
        scratchpad.reserve(20);

        typedef typename Context::type node_type;
        typedef typename xml_node_encoding<node_type>::type node_encoding;
        typedef xml_transcoder<node_encoding, utf8> transcoder;

        // Print path
        cout << "In context of:" << endl;
        cout << "\"root\"" << endl;

        typedef typename xml_context_path_type<Context>::type::const_iterator const_iterator;

        for(const_iterator p = ++context.path.begin(); p != context.path.end(); ++p)
        {
            scratchpad.push_back(' '); // Indentation

            cout << scratchpad
                 << transcoder::transcode((*p)->get_name())
                 << " = "
                 << transcoder::transcode((*p)->get_value())
                 << endl;
        }

        // Print buffer
        context.out.get_buffer().assign_to(scratchpad);

        cout << "While processing: " << transcoder::transcode(scratchpad) << endl;

        // Print description
        cout << "Failure details: " << context.error_detail.what() << endl;
    }
};

}}

#endif /* MIDDLEWARE_XML_XML_ERROR_PRINTER_STD_H_INCLUDED_ */
