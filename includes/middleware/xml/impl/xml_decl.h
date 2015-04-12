/**
    @b Project: Wump
    @file        xml_decl.h
    @author      Szymon Gutaj
    @brief       XML declaration (first four octets) used to auto-detect the encoding
    @date        28-02-2011
    @b History:
     - 28-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_DECL_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_DECL_H_INCLUDED_

#include <middleware/xml/impl/code_point.h>

namespace middleware { namespace xml { namespace impl {

typedef char            xml_decl_type; //!< XML declaration byte type.
static int const        xml_decl_size = 4; //!< Length of XML declaration in bytes.
typedef xml_decl_type   xml_decl[xml_decl_size]; //!< Type that reflects first few bytes of XML stream.

typedef code_point xml_encoding_name[]; //!< Type that reflects XML encoding name, provided in XML declaration.

}}}

#endif /* MIDDLEWARE_XML_IMPL_XML_DECL_H_INCLUDED_ */
// kupa jestes i tyle
