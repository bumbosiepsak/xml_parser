/**
    @b Project: Wump
    @file        xml_encoder.h
    @author      Szymon Gutaj
    @brief       Applies an encoder to input code point and feeds the stream with encoded data.
    @date        19-03-2011
    @b History:
     - 19-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_ENCODER_H_INCLUDED_
#define MIDDLEWARE_XML_XML_ENCODER_H_INCLUDED_

#include <middleware/xml/impl/encoding_specific.h>
#include <middleware/xml/impl/xml_buffer.h>

namespace middleware { namespace xml { namespace impl {

/**
 * Applies an encoder to input code point and feeds the stream with encoded data.
 * \tparam Encoding Output encoding.
 */
template<class Encoding>
class xml_encoder
{
    typedef encoding_specific<Encoding> encoder;
    typedef xml_buffer<typename Encoding::type> buffer;

public:
    /**
     * Puts a code point to the stream (with encoding under the hood).
     * @param point Code point to be stored.
     */
    inline void put(code_point point)
    {
        encoder::encode(point, this->buf);
    }

    /**
     * Provides access to encoded data, stored in buffer.
     * @return Returns encoded data.
     */
    inline buffer &get_buffer()
    {
        return this->buf;
    }

private:
    buffer buf;
};

}}}

#endif /* MIDDLEWARE_XML_XML_ENCODER_H_INCLUDED_ */
