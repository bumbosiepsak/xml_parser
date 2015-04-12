/**
    @b Project: Wump
    @file        xml_parser_ccs.h
    @author      Szymon Gutaj
    @brief       Default XML parser type for CCS environment (typedef increasing user-friendliness).
    @date        21-05-2011
    @b History:
     - 21-05-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_PARSER_CCS_H_INCLUDED_
#define MIDDLEWARE_XML_XML_PARSER_CCS_H_INCLUDED_

#include <middleware/xml/xml_encodings.h>
#include <middleware/xml/xml_error_printer_ccs.h>
#include <middleware/xml/xml_parser_basic.h>
#include <middleware/xml/xml_parser_if.h>

namespace middleware { namespace xml {

/**
 * Easy name for parser printing to CCS printer.
 */
typedef xml_parser_if<xml_parser_basic<xml_encodings, xml_error_printer_ccs> > xml_parser_ccs;

}}

#endif /* MIDDLEWARE_XML_XML_PARSER_CCS_H_INCLUDED_ */
