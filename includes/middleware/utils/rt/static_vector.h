/**
    @b Project: Wump
    @file        static_vector.h
    @author      Szymon Gutaj
    @brief       Vector with static c-style buffer
    @date        09-12-2010
    @b History:
     - 09-12-2010 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_RT_STATIC_VECTOR_H_INCLUDED_
#define MIDDLEWARE_UTILS_RT_STATIC_VECTOR_H_INCLUDED_

namespace middleware { namespace utils { namespace rt {

template<class T>
class static_vector
{
public:
    typedef T         value_type;

    typedef void      allocator_type;

    typedef size_t    size_type;
    typedef ptrdiff_t difference_type;

    typedef T       * iterator;
    typedef T       * reverse_iterator;
    typedef T       * pointer;
    typedef T       & reference;

    typedef T const * const_iterator;
    typedef T const * const_reverse_iterator;
    typedef T const * const_pointer;
    typedef T const & const_reference;

    static_vector() :
        first(static_cast<iterator>(0)), last(static_cast<iterator>(0))
    {
    }

    static_vector(iterator const first, iterator const last) :
        first(first), last(last)
    {
    }

    inline iterator begin() const
    {
        return this->first;
    }

    inline iterator end() const
    {
        return this->last;
    }

    inline void assign(iterator const first, iterator const last)
    {
        this->first = first;
        this->last  = last;
    }

    inline reference operator[](size_type n)
    {
        return *(this->first + n);
    }

    inline const_reference operator[](size_type n) const
    {
        return *(this->first + n);
    }

    inline reference at(size_type n)
    {
        return *(this->first + n); // TODO: Throw out_of_range exception
    }

    inline const_reference at(size_type n) const
    {
        return *(this->first + n); // TODO: Throw out_of_range exception
    }

    inline reference front()
    {
        return *this->first;
    }

    inline const_reference front() const
    {
    	return *this->first;
    }

    inline reference back()
    {
        return *(this->last - 1);
    }

    inline const_reference back() const
    {
    	return *(this->last - 1);
    }

    inline size_type size() const
    {
        return this->last - this->first;
    }

    bool empty() const
    {
    	return this->last == this->first;
    }

    void swap(static_vector<T> &v)
    {
        register iterator t(this->first);
        this->first = v.first;
        v.first = t;

        t = this->last;
        this->last = v.last;
        v.last = t;
    }

private:
    iterator first;
    iterator last;
};

}}}

#endif /* MIDDLEWARE_UTILS_RT_STATIC_VECTOR_H_INCLUDED_ */
