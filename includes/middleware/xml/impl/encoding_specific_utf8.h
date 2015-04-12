/**
    @b Project: Wump
    @file        encoding_specific_utf8.h
    @author      Szymon Gutaj
    @brief       Core encoder/decoder for UTF-8 encoding.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_UTF8_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_UTF8_H_INCLUDED_

#include <middleware/xml/fwd/ct/static_assert.h>
#include <middleware/xml/fwd/ct/is_same.h>
#include <middleware/xml/impl/encoding_specific.h>

namespace middleware { namespace xml {

/**
 * Tag/metafunction for UTF-8 encoding.
 */
struct utf8
{
    typedef char type; //!< Returns character type for encoding.
};

}}

namespace middleware { namespace xml { namespace impl {

/**
 * Core encoder/decoder for UTF-8 encoding.
 */
template<>
struct encoding_specific<utf8>
{
	/**
	 * Decodes data taken from input stream.
	 * @param stream Input stream.
	 * @return Returns one decoded code point. Returns invalid_code_point on error and empty stream.
	 */
    template<class XmlStream>
    static code_point decode(XmlStream &stream)
    {
        //UTF-8 encoding rules ('v' means bits that belong to the code point):

        //bytes | representation
        //    1 | 0vvvvvvv
        //    2 | 110vvvvv 10vvvvvv
        //    3 | 1110vvvv 10vvvvvv 10vvvvvv
        //    4 | 11110vvv 10vvvvvv 10vvvvvv 10vvvvvv

        if(!stream.empty())
        {
            unsigned int const b0 = stream.get();

            if(0x0 == (0x80 & b0)) // Case 1-octet-long code point
            {
                return b0;
            }
            else if(!stream.empty())
            {
                unsigned int const b1 = stream.get();

                if(0xA0 == (0xE0 & b0)) // Case 2-octets-long code point
                {
                    code_point const point = (0x1F & b0) << 6U
                                           | (0x3F & b1);
                    return point;
                }
                else if(!stream.empty())
                {
                    unsigned int const b2 = stream.get();

                    if(0xE0 == (0xF0 & b0)) // Case 3-octets-long code point
                    {
                        code_point const point = (0x0F & b0) << 12U
                                               | (0x3F & b1) << 6U
                                               | (0x3F & b2);
                        return point;
                    }
                    else if(!stream.empty())
                    {
                        unsigned int const b3 = stream.get();

                        if(0xF0 == (0xF8 & b0)) // Case 4-octets-long code point
                        {
                            code_point const point = (0x07 & b0) << 18U
                                                   | (0x3F & b1) << 12U
                                                   | (0x3F & b2) << 6U
                                                   | (0x3F & b3);
                            return point;
                        }
                    }
                }
            }
        }

        return invalid_code_point;
    }

    /**
     * Encodes given code point and inserts into output stream.
     * @param point Input code point.
     * @param stream Output XML stream. Must contain "put(char_type)" member function.
     */
    template<class XmlStream>
    static void encode(code_point const point, XmlStream &stream)
    {
        typedef typename XmlStream::char_type char_type;

        // NOTE: If you get a compile error here, it means that your (output) stream has a wrong character type
        ct_static_assert((fwd::ct::is_same<char_type, utf8::type>::value)
           ,character_types_of_stream_and_encoding_specific_dont_match);

        unsigned int bytes_needed = (0x80    > point) ? 1U :
                                    (0x0800  > point) ? 2U :
                                    (0x10000 > point) ? 3U :
                                                        4U;
        switch(bytes_needed)
        {
            case 1U:{
                stream.put(static_cast<char_type>(point));
                break;
            }
            case 2U:{
                stream.put(static_cast<char_type>((point >> 6U)         | 0xC0));
                stream.put(static_cast<char_type>((point        & 0x3F) | 0x80));
                break;
            }
            case 3U:{
                stream.put(static_cast<char_type>((point >> 12U)        | 0xE0));
                stream.put(static_cast<char_type>((point >> 6U  & 0x3F) | 0x80));
                stream.put(static_cast<char_type>((point        & 0x3F) | 0x80));
                break;
            }
            case 4U:{
                stream.put(static_cast<char_type>((point >> 18U)        | 0xF0));
                stream.put(static_cast<char_type>((point >> 12U & 0x3F) | 0x80));
                stream.put(static_cast<char_type>((point >> 6U  & 0x3F) | 0x80));
                stream.put(static_cast<char_type>((point        & 0x3F) | 0x80));
                break;
            }
        }
    }

    static xml_decl const decl;
    static xml_encoding_name const encoding_name;
};

}}}

#endif /* MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_UTF8_H_INCLUDED_ */
