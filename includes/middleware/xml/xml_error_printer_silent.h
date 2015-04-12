/**
    @b Project: Wump
    @file        xml_error_printer_silent.h
    @author      Szymon Gutaj
    @brief       Silent error printer, does no printing
    @date        15-03-2011
    @b History:
     - 15-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_ERROR_PRINTER_SILENT_H_INCLUDED_
#define MIDDLEWARE_XML_XML_ERROR_PRINTER_SILENT_H_INCLUDED_

namespace middleware { namespace xml {

/**
 * Basic error printer, silent (does nothing).
 */
class xml_error_printer_silent
{
public:
	/**
	 * Prints the error details.
	 * @param context Context of parsing (parser's internal state).
	 */
    template<class Context>
    void print(Context &context)
    {
        (void)(context);
    }
};

}}

#endif /* MIDDLEWARE_XML_XML_ERROR_PRINTER_SILENT_H_INCLUDED_ */
