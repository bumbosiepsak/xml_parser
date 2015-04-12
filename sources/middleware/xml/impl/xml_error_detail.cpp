/**
    @b Project: Wump
    @file        xml_error_detail.cpp
    @author      Szymon Gutaj
    @brief       Implementation of xml_error_detail.
    @date        21-05-2011
    @b History:
     - 21-05-2011 (sgutaj)
      - Initial creation
*/

#include <middleware/xml/impl/xml_error_detail.h>

using namespace std;
using namespace ::middleware::xml::impl;

namespace {

string const _no_details              (("no details"));
string const _memory_allocation_failed(("memory allocation failed"));
string const _unexpected_control_flow (("unexpected control flow"));

}

string const &xml_error_detail::what() const
{
    switch(this->value){
        case memory_allocation_failed   : return _memory_allocation_failed;
        case unexpected_control_flow    : return _unexpected_control_flow;
        default                         : return _no_details;
    }
}
