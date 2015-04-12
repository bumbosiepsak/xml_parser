/**
    @b Project: Wump
    @file        xml_error_detail.h
    @author      Szymon Gutaj
    @brief       Augumented enum holding details of parsing-error.
    @date        20-04-2011
    @b History:
     - 20-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_ERROR_DETAIL_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_ERROR_DETAIL_H_INCLUDED_

#include <string>

namespace middleware { namespace xml { namespace impl {

/**
 * Augumented enum holding details of parsing-error.
 */
struct xml_error_detail
{
	/**
	 * Possible values.
	 */
    enum value_type
    {
        no_details              //!< No details available.
       ,memory_allocation_failed//!< Memory allocation failed
       ,unexpected_control_flow //!< Unexpected control flow, coding error.
       ,last_enum               //!< Helper value (not to be used).
    };

    /**
     * Default constructor.
     */
    xml_error_detail() : value(no_details) {}

    /**
     * Constructor/converter from value_type.
     * @param value Source status.
     */
    xml_error_detail(value_type value) : value(value) {} // Intentionally implicit

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
     * Returns error description in textual form.
     * @return Error description.
     */
    std::string const &what() const;

    value_type value; //!< Returns status value.
};

}}}
//#include <middleware/xml/impl/xml_error_detail.h>

#endif /* MIDDLEWARE_XML_IMPL_XML_ERROR_DETAIL_H_INCLUDED_ */
