/**
    @b Project: Wump
    @file        xml_buffer_raw_utf.h
    @author      Szymon Gutaj
    @brief       Type for holding raw UTF code points (for exchange between parser and processor).
    @date        19-04-2011
    @b History:
     - 19-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_BUFFER_RAW_UTF_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_BUFFER_RAW_UTF_H_INCLUDED_

#include <deque>
#include <middleware/xml/impl/code_point.h>

namespace middleware { namespace xml { namespace impl {

//!< Type for holding raw UTF code points (for exchange between parser and processor).
typedef std::deque<code_point> xml_buffer_raw_utf;

}}}
//#include <middleware/xml/impl/xml_buffer_raw_utf.h>

#endif /* MIDDLEWARE_XML_IMPL_XML_BUFFER_RAW_UTF_H_INCLUDED_ */
