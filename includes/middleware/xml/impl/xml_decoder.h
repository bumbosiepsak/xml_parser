/**
    @b Project: Wump
    @file        xml_decoder.h
    @author      Szymon Gutaj
    @brief       Applies a decoder to a stream and creates a decoded stream.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_DECODER_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_DECODER_H_INCLUDED_

#include <middleware/xml/impl/decode_function.h>

namespace middleware { namespace xml { namespace impl {

/**
 * Applies a decoder to a stream and creates a decoded stream.
 * \tparam XmlStream Type of source XML stream.
 */
template<class XmlStream>
class xml_decoder
{
    typedef typename decode_function<XmlStream>::type decode_function;

public:
    /**
     * @param stream Input XML stream.
     * @param decode Functor used to decode stream.
     */
    explicit xml_decoder(XmlStream &stream, decode_function decode) :
        stream(stream)
       ,decode(decode)
    {
    }

public:
    /**
     * Fetches one code point from (decoded) stream.
     * @return One code point. Returns "invalid_code_point" if conversion fails or stream empty.
     */
    inline code_point get()
    {
        return (*this->decode)(this->stream);
    }

protected:
    XmlStream &stream;
    decode_function decode;
};

}}}

#endif /* MIDDLEWARE_XML_IMPL_XML_DECODER_H_INCLUDED_ */
