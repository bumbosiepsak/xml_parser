/**
    @b Project: Wump
    @file        code_point.h
    @author      Szymon Gutaj
    @brief       Code point type (32 bits, unsigned)
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_CODE_POINT_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_CODE_POINT_H_INCLUDED_

namespace middleware { namespace xml { namespace impl {

typedef unsigned long code_point; //!< Code point type (32 bits, unsigned).

static code_point const invalid_code_point = ~0x0; //!< Invalid code point (special value).

}}}

#endif /* MIDDLEWARE_XML_IMPL_CODE_POINT_H_INCLUDED_ */
