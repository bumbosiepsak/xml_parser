/**
    @b Project: Wump
    @file        xml_parser_if.h
    @author      Szymon Gutaj
    @brief       XML parser interface. Provides adapter to any parser implementation.
    @date        20-04-2011
    @b History:
     - 20-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_PARSER_IF_H_INCLUDED_
#define MIDDLEWARE_XML_XML_PARSER_IF_H_INCLUDED_

#include <middleware/xml/xml_parser_status.h>

namespace middleware { namespace xml {

/**
 * XML parser interface. Provides adapter to any parser implementation.
 */
template<
    class Parser
>
class xml_parser_if
{
public:
	/**
	 * Default constructor.
	 */
    xml_parser_if() :
        parser()
    {
    }

    /**
     * Constructor taking custom parser engine instance.
     * @param parser Custom parser instance.
     */
    explicit xml_parser_if(Parser const &parser) :
        parser(parser)
    {
    }

    /**
     * Destructor.
     */
    virtual ~xml_parser_if()
    {
    }

private:

public:
    /**
     * Runs parsing.
     * @param stream Stream (input).
     * @param root Root node instance (output).
     * @return Status of parsing.
     */
    template<
        class XmlStream
       ,class XmlNode
    >
    inline xml_parser_status parse(XmlStream &stream, XmlNode &root)
    {
        return this->parser.parse(stream, root);
    }

private:
    Parser parser;
};

}}
//#include <middleware/xml/xml_parser_if.h>

#endif /* MIDDLEWARE_XML_XML_PARSER_IF_H_INCLUDED_ */
