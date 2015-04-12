/**
    @b Project: Wump
    @file        xml_parser_basic.h
    @author      Szymon Gutaj
    @brief       Basic XML parser.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_PARSER_BASIC_H_INCLUDED_
#define MIDDLEWARE_XML_XML_PARSER_BASIC_H_INCLUDED_

#include <middleware/xml/xml_node_type.h>
#include <middleware/xml/xml_error_printer_silent.h>
#include <middleware/xml/impl/xml_decoder_selector.h>
#include <middleware/xml/impl/xml_context.h>
#include <middleware/xml/impl/xml_parser_basic.h>

namespace middleware { namespace xml {

/**
 * Implementation of XML parser, basic class.
 * \tparam XmlEncodings Iterable collection of encodings to be supported on input.
 * \tparam ErrorPrinter Printer for outputting parsing error information.
 */
template<
    class XmlEncodings
   ,class ErrorPrinter = xml_error_printer_silent
>
class xml_parser_basic
{
public:
	/**
	 * Default constructor.
	 * @param preserve_whitespace Enforces strict whitespace preservation.
	 */
    explicit xml_parser_basic(bool preserve_whitespace = false) :
        printer()
       ,preserve_whitespace(preserve_whitespace)
    {
    }

    /**
     * Constructor that enables providing custom ErrorPrinter instance.
     * @param printer Error printer, provided externally.
     * @param preserve_whitespace Enforces strict whitespace preservation.
     */
    explicit xml_parser_basic(ErrorPrinter const &printer, bool preserve_whitespace = false) :
        printer(printer)
       ,preserve_whitespace(preserve_whitespace)
    {
    }

public:
    /**
     * Responsible for choosing the encoder, running the parser and error printer.
     * @param stream Stream (input).
     * @param root Root node instance (output).
     * @return Status of parsing.
     */
    template<
        class XmlStream
       ,class XmlNode
    >
    xml_parser_status parse(XmlStream &stream, XmlNode &root)
    {
        typedef impl::xml_decoder_selector<XmlEncodings, XmlStream> selector;
        typedef impl::xml_context<typename selector::decoder_type, XmlNode> context;
        typedef impl::xml_parser_basic<context> parser;

        root.set_type(xml_node_type::root);

        context c(selector::select(stream), root, this->preserve_whitespace);

        parser p;

        p.parse(c);

        if(!c.status.is_ok())
        {
            this->printer.print(c);

            root.set_children().clear();
        }

        return c.status;
    }

private:
    ErrorPrinter printer;
    bool preserve_whitespace;
};

}}

#endif /* MIDDLEWARE_XML_XML_PARSER_BASIC_H_INCLUDED_ */
