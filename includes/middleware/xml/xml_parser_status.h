/**
    @b Project: Wump
    @file        xml_parser_status.h
    @author      Szymon Gutaj
    @brief       Augumented enum holding the XML parsing status.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_PARSER_STATUS_H_INCLUDED_
#define MIDDLEWARE_XML_XML_PARSER_STATUS_H_INCLUDED_

#include <string>

namespace middleware { namespace xml {

/**
 * Augumented enum holding the XML parsing status.
 */
struct xml_parser_status
{
	/**
	 * Possible status values.
	 */
    enum value_type
    {
        ok = 0         //!< Parsing OK.
       ,input_malformed//!< Parsing failed, bad input.
       ,unknown_version//!< Parsing failed, parser incompatible with input.
       ,internal_error //!< Parsing failed, internal parser error.
       ,last_enum      //!< Helper value (not to be used).
    };

    /**
     * Default constructor.
     */
    xml_parser_status() : value(ok) {}

    /**
     * Constructor/converter from value_type.
     * @param value Source status.
     */
    xml_parser_status(value_type value) : value(value) {}// intentionally implicit

    /**
     * Enables comparison with value_type.
     * @param value Right hand side comparison argument.
     * @return Returns true if status same.
     */
    inline bool operator==(value_type value)
    {
        return this->value == value;
    }

    /**
     * Used to check if parsing fine.
     * @return Returns true if parsing OK.
     */
    inline bool is_ok() const
    {
        return ok == this->value;
    }

    /**
     * Returns status description in textual form.
     * @return Status description.
     */
    std::string const &to_string() const;

    value_type value; //!< Returns status value.
};

}}

#endif /* MIDDLEWARE_XML_XML_PARSER_STATUS_H_INCLUDED_ */
