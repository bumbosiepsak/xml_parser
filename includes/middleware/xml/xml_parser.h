/**
    @b Project: Wump
    @file        xml_parser.h
    @author      Szymon Gutaj
    @brief       Default XML parser type (typedef increasing user-friendliness).
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_PARSER_H_INCLUDED_
#define MIDDLEWARE_XML_XML_PARSER_H_INCLUDED_

#include <middleware/xml/xml_encodings.h>
#include <middleware/xml/xml_error_printer_silent.h>
#include <middleware/xml/xml_parser_basic.h>
#include <middleware/xml/xml_parser_if.h>

namespace middleware { namespace xml {

/**
 * \typedef xml_parser
 * Easy name for parser with default parameters.
 */
typedef xml_parser_if<xml_parser_basic<xml_encodings, xml_error_printer_silent> > xml_parser;

}}

#endif /* MIDDLEWARE_XML_XML_PARSER_H_INCLUDED_ */
