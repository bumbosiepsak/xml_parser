/**
    @b Project: Wump
    @file        encoding_specific.h
    @author      Szymon Gutaj
    @brief       Base template for core encoders/decoders. Needs specialisation for a particular encoding.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_H_INCLUDED_

#include <middleware/xml/impl/code_point.h>
#include <middleware/xml/impl/xml_decl.h>

namespace middleware { namespace xml { namespace impl {

/**
 * Base template for core encoders/decoders. Needs specialisation for a particular encoding.
 */
template<class Encoding>
struct encoding_specific
{
// Required interface
//    template<class XmlStream>
//    static code_point decode(XmlStream &stream);
//
//    template<class XmlStream>
//    static void encode(code_point const point, XmlStream &stream);
};

}}}

#endif /* MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_H_INCLUDED_ */
