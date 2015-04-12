/**
    @b Project: Wump
    @file        rt.h
    @author      Szymon Gutaj
    @brief       Namespace "::middleware::xml::fwd::rt".
    @date        20-04-2011
    @b History:
     - 20-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_FWD_RT_H_INCLUDED_
#define MIDDLEWARE_XML_FWD_RT_H_INCLUDED_

namespace middleware { namespace utils { namespace rt { }}}

namespace middleware { namespace xml { namespace fwd {

/**
 * @brief Aliases/imports the "rt" (run time) utilities to ::middleware::xml::fwd::rt namespace.
 */
namespace rt = ::middleware::utils::rt;

}}}
//#include <middleware/xml/fwd/rt.h>

#endif /* MIDDLEWARE_XML_FWD_RT_H_INCLUDED_ */
