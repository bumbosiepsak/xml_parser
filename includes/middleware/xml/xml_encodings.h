/**
    @b Project: Wump
    @file        xml_encodings.h
    @author      Szymon Gutaj
    @brief       Default outer encodings list (ones that are recognized by parser)
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_ENCODINGS_H_INCLUDED_
#define MIDDLEWARE_XML_XML_ENCODINGS_H_INCLUDED_

#include <middleware/xml/fwd/ct/vector.h>
#include <middleware/xml/impl/encoding_specific_ascii.h>
#include <middleware/xml/impl/encoding_specific_utf8.h>

namespace middleware { namespace xml {

class unspecified_xml_encoding {};

// NOTE: This is a vector of types (encodings), not instances.
typedef fwd::ct::vector<utf8> xml_encodings; /**< Default list of supported encodings (stored in a static vector) */

}}

#endif /* MIDDLEWARE_XML_XML_ENCODINGS_H_INCLUDED_ */
