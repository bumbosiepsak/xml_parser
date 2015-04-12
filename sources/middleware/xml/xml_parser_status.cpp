/**
    @b Project: Wump
    @file        xml_parser_status.cpp
    @author      Szymon Gutaj
    @brief       
    @date        20-04-2011
    @b History:
     - 20-04-2011 (sgutaj)
      - Initial creation
*/

#include <middleware/xml/xml_parser_status.h>

using namespace std;
using namespace ::middleware::xml;

namespace {

string const _ok             (("xml_parser_status::ok"));
string const _unknown_version(("xml_parser_status::unknown_version"));
string const _internal_error (("xml_parser_status::internal_error"));
string const _input_malformed(("xml_parser_status::input_malformed"));

}

std::string const &xml_parser_status::to_string() const
{
    switch(this->value){
        case ok             : return _ok;
        case unknown_version: return _unknown_version;
        case input_malformed: return _input_malformed;
        default             : return _internal_error;
    }
}
