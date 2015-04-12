/**
    @b Project: Wump
    @file        xml_buffer.h
    @author      Szymon Gutaj
    @brief       String buffer with stream<->container adaptor properties and graceful memory management.
    @date        18-03-2011
    @b History:
     - 18-03-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_XML_XML_BUFFER_H_INCLUDED_
#define MIDDLEWARE_XML_XML_BUFFER_H_INCLUDED_

#include <deque>
#include <algorithm>

namespace middleware { namespace xml { namespace impl {

/**
 * String buffer with stream<->container adaptor properties and graceful memory management.
 * \tparam ValueType Internal character type of buffer.
 */
template<class ValueType>
class xml_buffer
{
    typedef std::deque<ValueType> buffer_t;

public:
    typedef ValueType char_type;
    typedef typename buffer_t::iterator iterator;

public:
    /**
     * Appends internal buffer contents to given string.
     * @param string Input/output string.
     */
    template<class StringType>
    void append_to(StringType &string) const
    {
        string.reserve(string.size() + this->buffer.size());
        string.append(this->buffer.begin(), this->buffer.end());
    }

    /**
     * Assigns internal buffer contents to given string.
     * @param string Input/output string.
     */
    template<class StringType>
    void assign_to(StringType &string) const
    {
        string.reserve(this->buffer.size());
        string.assign(this->buffer.begin(), this->buffer.end());
    }

    /**
     * Compares internal buffer contents to contents of given string.
     * @param string Input string
     * @return Returns true if contents equal.
     */
    template<class StringType>
    bool compare(StringType &string) const
    {
        return (string.size() == this->buffer.size())
            && (std::equal(string.begin(), string.end(), this->buffer.begin()));
    }

    /**
     * Puts one character to buffer.
     * @param value Inserted character.
     */
    inline void put(ValueType value)
    {
        this->buffer.push_back(value);
    }

    /**
     * Clears buffer contents.
     */
    inline void clear()
    {
        this->buffer.clear();
    }

    /**
     * Checks if buffer empty.
     * @return Returns true if buffer is empty.
     */
    inline bool empty() const
    {
        return this->buffer.empty();
    }

private:
    buffer_t buffer;
};

}}}

#endif /* MIDDLEWARE_XML_XML_BUFFER_H_INCLUDED_ */
