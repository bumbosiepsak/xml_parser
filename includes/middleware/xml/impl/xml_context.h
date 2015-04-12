/**
    @b Project: Wump
    @file        xml_context.h
    @author      Szymon Gutaj
    @brief       Local storage for XML parser.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_CONTEXT_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_CONTEXT_H_INCLUDED_

#include <deque>
#include <middleware/xml/xml_node_encoding.h>
#include <middleware/xml/xml_parser_status.h>
#include <middleware/xml/impl/xml_buffer_raw_utf.h>
#include <middleware/xml/impl/xml_encoder.h>
#include <middleware/xml/impl/xml_error_detail.h>


namespace middleware { namespace xml { namespace impl {

/**
 * Local storage for XML parser.
 * \tparam Decoder Type of decoder used for input stream conversion.
 * \tparam XmlNode Type of XML node being used (on output).
 */
template<
    class Decoder
   ,class XmlNode
>
struct xml_context
{
    typedef XmlNode type; //!< Returns XmlNode type.

    typedef std::deque<XmlNode*> path_type;
    typedef typename xml_node_encoding<XmlNode>::type out_encoding;

    /**
     * Constructor.
     * @param in Input stream decoder.
     * @param root Root node, which will grow to full XML tree.
     * @param preserve_whitespace Controls strict whitespace handling.
     */
    xml_context(Decoder in, XmlNode &root, bool preserve_whitespace) :
        in(in)
       ,out()
       ,path(1, &root)
       ,preserve_whitespace(preserve_whitespace)
       ,instruction()
       ,status()
       ,error_detail()
    {
    }

    Decoder in;
    xml_encoder<out_encoding> out;
    path_type path;
    bool preserve_whitespace;
    xml_buffer_raw_utf instruction;
    xml_parser_status status;
    xml_error_detail error_detail;
};

}}}

#endif /* MIDDLEWARE_XML_IMPL_XML_CONTEXT_H_INCLUDED_ */
