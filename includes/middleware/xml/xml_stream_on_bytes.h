/**
    @b Project: Wump
    @file        xml_stream_on_bytes.h
    @author      Szymon Gutaj
    @brief       Simple wrapper for providing stream-like access to table of bytes.
    @date        27-02-2011
    @b History:
     - 27-02-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_STREAM_ON_BYTES_H_INCLUDED_
#define MIDDLEWARE_XML_XML_STREAM_ON_BYTES_H_INCLUDED_

#include <stddef.h>

namespace middleware { namespace xml {

/**
 * Provides stream interface to table of bytes.
 */
class xml_stream_on_bytes
{
public:
	/**
	 * Returns stream's character type.
	 */
    typedef char char_type;

public:
    /**
     * Constructor taking the buffer.
     * @param buffer Pointer to buffer's base address.
     * @param size Size of buffer in bytes.
     */
    xml_stream_on_bytes(void const *buffer, size_t size);
    virtual ~xml_stream_on_bytes();

private:
    /**
     * Default constructor disabled.
     */
    xml_stream_on_bytes();

public:
    /**
     * Removes and returns one character from the stream.
     * @return Returned character.
     */
    char_type get();

    /**
     * Inserts the recently returned character back into stream.
     */
    void unget();

    /**
     * Checks if stream empty.
     * @return Returns true if stream empty (all characters retrieved).
     */
    bool empty() const;

private:
    char_type const *cursor;
    char_type const *last;
};


inline xml_stream_on_bytes::char_type xml_stream_on_bytes::get()
{
    return *(++this->cursor);
}

inline void xml_stream_on_bytes::unget()
{
    --this->cursor;
}

inline bool xml_stream_on_bytes::empty() const
{
    return this->last <= this->cursor;
}

}}

#endif /* MIDDLEWARE_XML_XML_STREAM_ON_BYTES_H_INCLUDED_ */
