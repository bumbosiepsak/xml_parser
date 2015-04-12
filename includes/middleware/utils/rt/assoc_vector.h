/**
    @b Project: Wump
    @file        assoc_vector.h
    @author      Szymon Gutaj
    @brief
    @date        18-04-2011
    @b History:
     - 18-04-2011 (sgutaj)
      - Initial creation
*/

#ifndef MIDDLEWARE_UTILS_RT_ASSOC_VECTOR_H_INCLUDED_
#define MIDDLEWARE_UTILS_RT_ASSOC_VECTOR_H_INCLUDED_

#include <vector>
#include <algorithm>

namespace middleware { namespace utils { namespace rt {

template<
    class Key
   ,class T
   ,class Compare = std::less<Key>
   ,class Alloc = std::allocator<T>
>
class assoc_vector
{
    typedef std::vector<std::pair<Key, T>, Alloc> vector_t;

public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef Compare key_compare;
    typedef Alloc allocator_type;
    typedef std::pair<Key, T> value_type;

    typedef typename vector_t::iterator iterator;
    typedef typename vector_t::const_iterator const_iterator;

    typedef typename vector_t::pointer pointer;
    typedef typename vector_t::const_pointer const_pointer;

    typedef typename vector_t::reference reference;
    typedef typename vector_t::const_reference const_reference;

    typedef typename vector_t::size_type size_type;

private:
    class value_compare :
        public std::binary_function<value_type, value_type, bool>
    {
    public:
        inline bool operator()(value_type const &lhs, value_type const &rhs) const
        {
            return key_compare()(lhs.first, rhs.first);
        }
    };

public:
    assoc_vector() : v()
    {
    }

    inline void swap(assoc_vector v)
    {
        v.swap(this->v);
    }

    inline assoc_vector &operator=(assoc_vector const &v)
    {
        this->swap(v);
        return *this;
    }

    iterator find(key_type const &key)
    {
        using namespace std;

        iterator i = lower_bound(this->v.begin()
                                ,this->v.end()
                                ,value_type(key, mapped_type())
                                ,value_compare());

        return (i == this->v.end() || key_compare()(key, i->first)) ? this->v.end() : i;
    }

    inline iterator begin()
    {
        return this->v.begin();
    }

    inline iterator end()
    {
        return this->v.end();
    }

    inline bool empty() const
    {
        return this->v.empty();
    }

    inline void reserve(size_type size)
    {
        this->v.reserve(size);
    }

    std::pair<iterator, bool> insert(value_type const &value)
    {
        bool found(true);

        iterator i = this->find();

        if(i == this->v.end() || value_compare()(*i, value))
        {
            i = this->v.insert(i, value);
            found = false;
        }

        return make_pair(i, false);
    }

    assoc_vector &operator()(key_type const &key, mapped_type const &t)
    {
        this->v.push_back(value_type(key, t));
        return *this;
    }

    assoc_vector &sort()
    {
        std::sort(this->v.begin(), this->v.end(), value_compare());
        return *this;
    }

private:
    vector_t v;
};

}}}

#endif /* MIDDLEWARE_UTILS_RT_ASSOC_VECTOR_H_INCLUDED_ */
