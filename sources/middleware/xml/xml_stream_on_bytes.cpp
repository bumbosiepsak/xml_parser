/**
    @b Project: Wump
    @file        xml_stream_on_bytes.cpp
    @author      Szymon Gutaj
    @brief
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#include <middleware/xml/xml_stream_on_bytes.h>

using namespace ::middleware::xml;

xml_stream_on_bytes::xml_stream_on_bytes(void const *buffer, size_t size) :
    cursor(static_cast<char_type const*>(buffer) - 1)
   ,last  (static_cast<char_type const*>(buffer) - 1 + size)
{
}

xml_stream_on_bytes::~xml_stream_on_bytes()
{
}
