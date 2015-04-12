/**
    @b Project: Wump
    @file        xml_specific.cpp
    @author      Szymon Gutaj
    @brief		 Implementation of XML-specific utilities.
    @date        18-03-2011
    @b History:
     - 18-03-2011 (sgutaj)
      - Initial creation
*/

#include <limits>
#include <middleware/xml/impl/xml_specific.h>

using namespace ::middleware::xml::impl;

bool xml_specific::is_name_start_char(code_point const point)
{
    // NOTE: Allowed code values taken from XML v1.0 specification
    return ('a'     <= point && point <= 'z')
        || ('A'     <= point && point <= 'Z')
        || ('_'     == point)
        || (':'     == point)
        || (0xC0    <= point && point <= 0xD6)
        || (0xD8    <= point && point <= 0xF6)
        || (0xF8    <= point && point <= 0x2FF)
        || (0x370   <= point && point <= 0x37D)
        || (0x37F   <= point && point <= 0x1FFF)
        || (0x200C  <= point && point <= 0x200D)
        || (0x2070  <= point && point <= 0x218F)
        || (0x2C00  <= point && point <= 0x2FEF)
        || (0x3001  <= point && point <= 0xD7FF)
        || (0xF900  <= point && point <= 0xFDCF)
        || (0xFDF0  <= point && point <= 0xFFFD)
        || (0xEFFFF <= point && point <= 0x10000);
}

bool xml_specific::is_name_char(code_point const point)
{
    // NOTE: Allowed code values taken from XML v1.0 specification
    return xml_specific::is_name_start_char(point)
        || ('0'     <= point && point <= '9')
        || ('.'     == point)
        || ('-'     == point)
        || (0x0300  <= point && point <= 0x036F)
        || (0xB7    == point)
        || (0x203F  <= point && point <= 0x2040);
}

unsigned int xml_specific::to_numeral(code_point const point)
{
    if     ('0' >  point) return std::numeric_limits<unsigned int>::max();
    else if('9' >= point) return (point - '0');
    else if('F' >= point) return (point - 'A' + 0xA);
    else if('f' >= point) return (point - 'a' + 0xA);
    else return std::numeric_limits<unsigned int>::max();
}
