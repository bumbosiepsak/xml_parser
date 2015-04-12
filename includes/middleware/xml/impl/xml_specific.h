/**
    @b Project: Wump
    @file        xml_specific.h
    @author      Szymon Gutaj
    @brief       Provides an XML-specific information about a given code point.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_SPECIFIC_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_SPECIFIC_H_INCLUDED_

#include <middleware/xml/impl/code_point.h>

namespace middleware { namespace xml { namespace impl {

/**
 * Provides an XML-specific information about a given code point.
 */
struct xml_specific
{
	/**
	 * Checks if given code point is a NameStartChar.
	 * @param point Checked code point.
	 * @return Returns true if is a NameStartChar.
	 */
    static bool is_name_start_char(code_point const point);

	/**
	 * Checks if given code point is a NameChar.
	 * @param point Checked code point.
	 * @return Returns true if is a NameChar.
	 */
    static bool is_name_char(code_point const point);

    /**
     * Converts given code point to its numeral value.
     * @param point Converted code point.
     * @return Numeral value of code point. Values bigger than 0xA indicate a conversion error.
     */
    static unsigned int to_numeral(code_point const point);
};

}}}

#endif /* MIDDLEWARE_XML_IMPL_XML_SPECIFIC_H_INCLUDED_ */
