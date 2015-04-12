/**
    @b Project: Wump
    @file        xml_transcoder.h
    @author      Szymon Gutaj
    @brief		 Offers transcoding of strings encoded with different encodings.
    @date        21-05-2011
    @b History:
     - 21-05-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_TRANSCODER_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_TRANSCODER_H_INCLUDED_

#include <string>

#include <middleware/xml/fwd/ct/is_same.h>
#include <middleware/xml/fwd/ct/static_assert.h>

#include <middleware/xml/xml_encodings.h>
#include <middleware/xml/xml_node_basic.h>
#include <middleware/xml/xml_stream_on_bytes.h>

namespace middleware { namespace xml { namespace impl {

/**
 * General transcoder for strings with any/different "in" and "out" encodings.
 * \tparam InEncoding Input string encoding (provided).
 * \tparam OutEncoding Output string encoding (requested).
 */
template<
    class InEncoding
   ,class OutEncoding
>
struct xml_transcoder
{
    // NOTE: Keep the input string type, change the encoding-related character type only
    typedef std::basic_string<typename OutEncoding::type> out_string_type;

    /**
     * Transcodes input string to output string.
     * @param in_string Input with std::basic_string properties.
     * @return Output with std::basic_string properties and requested encoding.
     */
    template<class InStringType>
    static out_string_type transcode(InStringType const &in_string)
    {
    	// This assertion enforces that provided string has a correct character type
        typedef fwd::ct::is_same<typename InEncoding::type, typename InStringType::value_type> strings_match;
        ct_static_assert(strings_match::value, input_string_doesnt_match_the_required_encoding);

        xml_stream_on_bytes stream(in_string.data(), in_string.size());

        xml_encoder<OutEncoding> encoder;

        while(!stream.empty())
        {
            encoder.put(encoding_specific<InEncoding>::decode(stream));
        }

        out_string_type out_string;

        encoder.get_buffer().assign_to(out_string);

        return out_string;
    }
};

/**
 * Optimized transcoder for strings with identical "in" and "out" encodings (no transcoding needed)
 * \tparam InEncoding Input/output string encoding.
 */
template<
    class InEncoding
>
struct xml_transcoder<InEncoding, InEncoding>
{
    /**
     * Transcodes input string to output string.
     * @param in_string Input with std::basic_string properties.
     * @return Output with std::basic_string properties and requested encoding.
     */
    template<class InStringType>
    static InStringType const &transcode(InStringType const &in_string)
    {
    	// This assertion enforces that provided string has a correct character type
        typedef fwd::ct::is_same<typename InEncoding::type, typename InStringType::value_type> strings_match;
        ct_static_assert(strings_match::value, input_string_doesnt_match_the_required_encoding);

        return in_string;
    }
};

}}}

#endif /* MIDDLEWARE_XML_IMPL_XML_TRANSCODER_H_INCLUDED_ */
