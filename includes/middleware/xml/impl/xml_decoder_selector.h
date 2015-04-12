/**
    @b Project: Wump
    @file        xml_decoder_selector.h
    @author      Szymon Gutaj
    @brief       Decoder selector - chooses the XML decoder based on first bytes of data or encoding name given in XML declaration.
    @date        01-03-2011
    @b History:
     - 01-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_IMPL_XML_DECODER_SELECTOR_H_INCLUDED_
#define MIDDLEWARE_XML_IMPL_XML_DECODER_SELECTOR_H_INCLUDED_

#include <algorithm>
#include <functional>
#include <utility>

#include <middleware/xml/fwd/ct/begin.h>
#include <middleware/xml/fwd/ct/deref.h>
#include <middleware/xml/fwd/ct/for_each.h>
#include <middleware/xml/fwd/ct/size.h>

#include <middleware/xml/impl/xml_decl.h>
#include <middleware/xml/impl/xml_decoder.h>
#include <middleware/xml/impl/decode_function.h>
#include <middleware/xml/impl/encoding_specific.h>

namespace middleware { namespace xml { namespace impl {

/**
 * @brief Local scope classes.
 */
namespace local {

/**
 * General version of selector if many encodings possible.
 * \tparam XmlEncodingsCount Count of supported encodings.
 * \tparam XmlEncodings List of supported encodings.
 * \tparam XmlStream Type of input stream.
 */
template<
    int   XmlEncodingsCount
   ,class XmlEncodings
   ,class XmlStream
>
class xml_decoder_selector_optimized
{
    typedef typename decode_function<XmlStream>::type decode_function;

    typedef std::pair<
        xml_decl_type const*
       ,decode_function
    > xml_decl_to_decoding_function; // Entry: [key:first bytes, value:decoder].

    // Functor that adds one [key, value] pair to supported encodings map.
    class register_decoding_function
    {
        register_decoding_function();

    public:
        register_decoding_function(xml_decl_to_decoding_function *&decoding_functions_map) :
            decoding_functions_map(&decoding_functions_map) {}

        template<class T>
        inline void operator()(T) const
        {
            typedef encoding_specific<T> e;

            **this->decoding_functions_map = xml_decl_to_decoding_function(e::decl, &e::decode);

            ++(*this->decoding_functions_map);

        }

    private:
        // Double pointer used here so that the state of functor (pointer position)
        // is kept externally (register_decoding_function copying inside algorithms is safe)
        xml_decl_to_decoding_function **decoding_functions_map;
    };

    // Functor that provides 'less' operator used in sorting.
    struct xml_decl_less :
        public std::binary_function<
            xml_decl_to_decoding_function
           ,xml_decl_to_decoding_function
           ,bool
        >
    {
        inline bool operator()(xml_decl_to_decoding_function const &lhs, xml_decl_to_decoding_function const &rhs) const
        {
            return std::lexicographical_compare(lhs.first, lhs.first + xml_decl_size
                                               ,rhs.first, rhs.first + xml_decl_size);
        }
    };

public:
    typedef xml_decoder<XmlStream> decoder_type; //!< Type of decoder returned by decoder selector.

public:
    /**
     * Constructor: fill and sort the decoders' map entries
     */
    xml_decoder_selector_optimized()
    {
        xml_decl_to_decoding_function *map = decoding_functions_map;

        fwd::ct::for_each<XmlEncodings>(register_decoding_function(map)); // Decoders' map filling done here.

        std::sort(decoding_functions_map + 1 // Don't sort the first, default encoding
                 ,decoding_functions_map + XmlEncodingsCount
                 ,xml_decl_less());
    }

    /**
     * Returns the decoder of detected encoding (actual implementation).
     * @param stream Input XML stream.
     * @return Detected decoder (default if not found an exact match).
     */
    decoder_type select(XmlStream &stream) const
    {
        return decoder_type(stream, this->fetch_decoding_function(stream));
    }

private:
    decode_function fetch_decoding_function(XmlStream &stream) const
    {
        // Fetch first octets in the stream to xml declaration buffer
        xml_decl decl_buffer;
        for(int i = 0; i < xml_decl_size; ++i) decl_buffer[i] = stream.get();

        // Unget first octets
        for(int i = xml_decl_size; i != 0; --i) stream.unget();

        // Search the available decoders for matching encodings
        xml_decl_to_decoding_function decl(decl_buffer, 0);
        xml_decl_less less;

        typedef xml_decl_to_decoding_function const *entry;

        entry e = std::lower_bound(decoding_functions_map + 1 // Don't search the first, default encoding
                                  ,decoding_functions_map + XmlEncodingsCount
                                  ,decl
                                  ,less);

        // Return matching or default encoding function
        return (e == decoding_functions_map + XmlEncodingsCount || less(decl, *e)) ?
                decoding_functions_map[0].second : e->second;
    }

private:
    xml_decl_to_decoding_function decoding_functions_map[XmlEncodingsCount];
};

/**
 * Optimized version of selector if one encoding possible only
 * \tparam XmlEncodings List of supported encodings.
 * \tparam XmlStream Type of input stream.
 */
template<
    class XmlEncodings
   ,class XmlStream
>
class xml_decoder_selector_optimized<1, XmlEncodings, XmlStream>
{
public:
    typedef xml_decoder<XmlStream> decoder_type;

public:
    xml_decoder_selector_optimized() {}

    decoder_type select(XmlStream &stream) const
    {
        typedef typename fwd::ct::deref<typename fwd::ct::begin<XmlEncodings>::type>::type Encoding;

        return decoder_type(stream, &encoding_specific<Encoding>::decode);
    }
};

}

/**
 * Selects the decoder basing on input XML data.
 * \tparam XmlEncodings List of supported input encodings (a static, iterable collection).
 *         Input data will be compared to members of this list.
 *         First encoding on the list is considered default.
 * \tparam XmlStream Type of input stream, containing XML data.
 */
template<
    class XmlEncodings
   ,class XmlStream
>
class xml_decoder_selector
{
    typedef local::xml_decoder_selector_optimized<
        fwd::ct::size<XmlEncodings>::value
       ,XmlEncodings
       ,XmlStream
    > selector;

public:
    typedef typename selector::decoder_type decoder_type; //!< Decoder's interface type.
    typedef typename selector::decoder_type type; //!< Returns decoder's interface type.

private:
    /**
     * Disabled constructor.
     */
    xml_decoder_selector(); // No instances of xml_decoder_selector allowed

public:
    /**
     * Detects encoding basing on first bytes of XML data.
     * @param stream XML data to be recognized.
     * @return Detected decoder. Default decoder (first from XmlEncodings list) returned on match error.
     */
    inline static decoder_type select(XmlStream &stream)
    {
        return selector_instance.select(stream);
    }

    /**
     * Detects encoding basing on encoding's name (provided in XML declaration).
     * @param name Encoding name (provided in <?xml encoding="UTF-8" ?>)
     * @return Detected decoder. Default decoder (first from XmlEncodings list) returned on match error.
     */
    inline static decoder_type select(/*xml_encoding_name &name*/)
    {
        return 0; // FIXME (sgutaj)!
    }

private:
    static selector const selector_instance;
};

template<
    class XmlEncodings
   ,class XmlStream
>
typename xml_decoder_selector<XmlEncodings, XmlStream>::selector const
xml_decoder_selector<XmlEncodings, XmlStream>::selector_instance;

}}}

#endif /* MIDDLEWARE_XML_IMPL_XML_DECODER_SELECTOR_H_INCLUDED_ */
