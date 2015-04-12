/**
    @b Project: Wump
    @file        xml_stream_on_string.h
    @author      Szymon Gutaj
    @brief       Simple wrapper for providing stream-like access to standard string.
    @date        14-02-2012
    @b History:
     - 14-02-2012 (sgutaj)
         - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_STREAM_ON_STRING_H_INCLUDED_
#define MIDDLEWARE_XML_XML_STREAM_ON_STRING_H_INCLUDED_

#include <string>
#include <middleware/xml/xml_stream_on_bytes.h>

namespace middleware { namespace xml {

/**
 * Provides stream interface to std::string
 */
class xml_stream_on_string : public xml_stream_on_bytes
{
public:
	/**
	 * Constructor.
	 * @param xml Input string containing XML data
	 */
	explicit xml_stream_on_string(std::string const &xml) :
		xml_stream_on_bytes(xml.c_str(), xml.size())
	{
	}
};

}}

#endif /* MIDDLEWARE_XML_XML_STREAM_ON_STRING_H_INCLUDED_ */
