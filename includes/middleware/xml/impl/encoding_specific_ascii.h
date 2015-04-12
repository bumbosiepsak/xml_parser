/**
    @b Project: Wump
    @file        encoding_specific_ascii.h
    @author      Szymon Gutaj
    @brief       Core encoder/decoder for ASCII encoding.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_ASCII_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_ASCII_H_INCLUDED_

#include <middleware/xml/fwd/ct/static_assert.h>
#include <middleware/xml/fwd/ct/is_same.h>
#include <middleware/xml/impl/encoding_specific.h>

namespace middleware { namespace xml {

/**
 * Tag/metafunction for ASCII encoding.
 */
struct ascii
{
    typedef char type;  //!< Returns character type for encoding.
};

}}

namespace middleware { namespace xml { namespace impl {

/**
 * Core encoder/decoder for ASCII encoding.
 */
template<>
struct encoding_specific<ascii>
{
	/**
	 * Decodes data taken from input stream.
	 * @param stream Input stream.
	 * @return Returns one decoded code point. Returns invalid_code_point on error and empty stream.
	 */
    template<class XmlStream>
    static code_point decode(XmlStream &stream)
    {
        if(!stream.empty())
        {
            return static_cast<code_point>(stream.get());
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
        ct_static_assert((fwd::ct::is_same<char_type, ascii::type>::value)
           ,character_types_of_stream_and_encoding_specific_dont_match);

        stream.put(static_cast<char_type>(point));
    }

    static xml_decl const decl;
    static xml_encoding_name const encoding_name;
};

}}}

#endif /* MIDDLEWARE_XML_IMPL_ENCODING_SPECIFIC_ASCII_H_INCLUDED_ */
