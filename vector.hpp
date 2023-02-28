#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>
#include "my_iterator.hpp"
#include "reverse_iterator.hpp"
#include "traits.hpp"
#include <algorithm>
#include "utils.hpp"

namespace ft
{
  template <class T, class Allocator = std::allocator<T> >
  class vector
  {
  private:
    /* data */
  public:
    //member types
    typedef T value_type;
    typedef Allocator allocator_type;
    typedef typename allocator_type::reference reference; // Providede reference to an element
    // stored in vector.
    typedef typename allocator_type::const_reference const_reference;
    // Provide a pointer to an element stored in the vector.
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::size_type size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef ft::my_iterator<pointer> iterator;
    typedef ft::my_iterator<const_pointer> const_iterator;
    typedef ft::reverse_iterator<iterator> reverse_iterator;
    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    private:
    pointer _arr;
    pointer _end;
    size_type _size;
    size_type _capacity;
    allocator_type _alloc;
    template<class U>
    void swap(U &a, U&b)
    {
      U tmp;
      tmp = a;
      a = b;
      b = tmp;
    }

    public:
    // Construct/ Copy / Destroy 
    explicit vector(const allocator_type& alloc = allocator_type()) : _arr(nullptr), _end(nullptr), _size(0), _capacity(0), _alloc(alloc)
    {}
    explicit vector(size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()) : _arr(nullptr), _size(0), _capacity(0), _alloc(alloc)
    {
      if (n > 0)
      {
        _size = n;
        _capacity = n;
        _arr = _alloc.allocate(_capacity);
        while (n--)
          _alloc.construct(_arr + n, val);
        }
    }
    template<class InputIterator>
    vector(InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type()
            , typename ft::enable_if<!ft::is_integral<InputIterator>::value,
              InputIterator>::type = InputIterator()) : _arr(nullptr)
    {
      _alloc = alloc;
      size_type i = -1;
      size_type _n = static_cast<size_type>(std::distance(first, last));
      _capacity = _n;
      _size = _n;
      _arr = _alloc.allocate(_capacity);
      while (++i < _n)
      {
        _alloc.construct(_arr + i, *first);
        first++;
      }
    }
    vector(const vector& x) : _arr(nullptr), _end(nullptr), _size(0), _capacity(0)
    {
      *this = x;
    }
    // assignement operator
    vector& operator=(const vector &x)
    {
      if (this == &x)
        return (*this);
      this->clear();
      this->assign(x.begin(), x.end());
      return (*this);
    }
    ~vector() 
    {
      this->clear();
      if (_arr)
        _alloc.deallocate(_arr, _capacity);
      _arr = nullptr;
    }
    // Iterator

    iterator begin()
    {
      return (iterator(_arr));
    }
    const_iterator begin() const
    {
      return(const_iterator(_arr));
    }
    iterator end()
    {
      return (iterator(_arr + _size));
    }
    const_iterator end() const
    {
      return (const_iterator(_arr + _size));
    }
    reverse_iterator rbegin()
    {
      return (reverse_iterator(end()));
    }
    const_reverse_iterator rbegin() const
    {
      return (const_reverse_iterator(end()));
    }
    reverse_iterator rend()
    {
      return (reverse_iterator(begin()));
    }
    const_reverse_iterator rend() const
    {
      return (const_reverse_iterator(begin()));
    }
  
    // allocator
    allocator_type get_allocator() const { return (_alloc); }
    //reference operator
    reference operator[](size_type n) {return _arr[n];}
    const_reference operator[](size_type n)  const { return _arr[n];}
    //Member functions
    template<class InputIterator>
    void assign(InputIterator first, InputIterator last,
                  typename ft::enable_if<!ft::is_integral<InputIterator>::value, 
                  InputIterator>::type = InputIterator())
    {
      size_type i = -1;
      size_type size;
      size = static_cast<size_type>(std::distance(first, last));
      _end = _arr;
      this->clear();
      if (size <= _capacity)
      {
        while (++i < size)
          _alloc.construct(_end++, *(first++));
        _size = size;
      }
      else
      {
      	this->clear();
        if (_capacity)
          _alloc.deallocate(_arr, _capacity);
        _capacity = size;
        _arr = _alloc.allocate(_capacity);
        _end = _arr;
        _size = size;
        while (++i < size)
          _alloc.construct(_end++, *(first++));
      }
    }
    void assign(size_type n, const value_type& val)
    {
      size_type i = -1;
      size_type size = n;
      _end = _arr;
      this->clear();
      if (n <= _capacity)
      {
        while (++i < n)
          _alloc.construct(_end++, val);
        _size = n;
      }
      else
      {
        this->clear(); 
        if (_capacity)
          _alloc.deallocate(_arr, _capacity);
        _capacity = size;
        _size = size;
        _arr = _alloc.allocate(_capacity);
        _end = _arr;
        while (++i < _size)
          _alloc.construct(_end++, val);
      }
    }
    reference at(size_type n)
    {
      if (n >= _size)
        throw(std::out_of_range("vector"));
      return (_arr[n]);
    }
    const_reference at(size_type n) const
    {
      if (n >= _size)
        throw(std::out_of_range("vector"));
      return (_arr[n]);
    }
    reference back() { return (_arr[_size - 1]);}
    const_reference back() const { return (_arr[_size - 1]);}
    size_type capacity() const { return _capacity; }
    void clear()
    {
      size_type i = -1;
      while (++i < _size)
        _alloc.destroy(&_arr[i]);
      _size = 0;
    }
    bool empty() const { return (_size == 0 ? true : false);}
    iterator erase(iterator position)
    {
      iterator _r = position;
      std::copy(position + 1, this->end(), _r);
      --_size;
      return _r;
    }
    iterator erase(iterator first, iterator last)
    {
      difference_type d = std::distance(first, last);
      iterator _r = first;
      std::copy(last, this->end(), _r);
      _size -= d;
      return _r;
    }
    reference front() { return *_arr;}
    const_reference front() const { return *_arr;}
    iterator insert(iterator position, const value_type& x) // insert x before pos
    {
      pointer tmp;
      size_type old_cap = _capacity;
      size_type i = -1;
      size_type pos = static_cast<size_type>(position - this->begin());
      size_type new_size = (pos >= _size) ? pos : _size;
      ++new_size;
      if (_capacity == 0)
      {
        _capacity = new_size;
        _arr = _alloc.allocate(_capacity);
      }
      else if (new_size > _capacity && _capacity > 0)
      {
        tmp = _arr;
        _capacity *= 2;
        _arr = _alloc.allocate(_capacity);
        while (++i < _size)
            _alloc.construct(&_arr[i], tmp[i]);
        if (tmp)
        {
          for (size_type i = 0; i < _size; i++)
            _alloc.destroy(&tmp[i]);
          _alloc.deallocate(tmp ,old_cap);
        }
      }
      _size = new_size;
      while (--new_size > pos)
        _alloc.construct(&_arr[new_size], _arr[new_size - 1]);
          //_arr[new_size] = _arr[new_size - 1];
      _alloc.construct(&_arr[pos], x);
      //_arr[pos] = x;
      return (this->begin() + pos);
    }
    void insert(iterator position, size_type n, const value_type& x)
    {
      pointer tmp;
      size_type old_cap = _capacity;
      //size_type sz = 0;
      size_type pos = position - this->begin();
      size_type new_size = (pos + n >= _size + n) ? (pos + n) : (_size + n);
      if (_capacity == 0)
      {
        _capacity = n;
        _arr = _alloc.allocate(_capacity);
      }
      else if (new_size > _capacity && _capacity > 0)
      {
        tmp = _arr;
        _capacity =(_capacity * 2 > _size + n) ? (_capacity * 2) : (_size + n);
        _arr = _alloc.allocate(_capacity);
        for (size_type i = 0; i < _size; i++)
          _arr[i] = tmp[i];
        _alloc.deallocate(tmp ,old_cap);
      }
      size_type it = _size - pos;
      _size = new_size;
      while (it-- > 0 && pos > 0 && new_size--)
          _arr[new_size] = _arr[new_size - n];
      while (n--) 
        _arr[pos++] = x;
    }
    template <class InputIterator>
    void insert(iterator position, InputIterator first, InputIterator last, 
                typename ft::enable_if<!ft::is_integral<InputIterator>::value, 
                InputIterator>::type = InputIterator())
    {
      pointer tmp;
      size_type n = static_cast<size_type>(std::distance(first, last));
      size_type old_cap = _capacity;
      size_type pos = position - this->begin();
      size_type new_size = (pos + n >= _size + n) ? (pos + n) : (_size + n);
      if (_capacity == 0)
      {
        _capacity = n;
        _arr = _alloc.allocate(_capacity);
      }
      else if (new_size > _capacity && _capacity > 0)
      {
        tmp = _arr;
        _capacity = (_capacity * 2 > _size + n) ? (_capacity * 2) : (_size + n);
        _arr = _alloc.allocate(_capacity);
        for (size_type i = 0; i < _size; i++)
          _alloc.construct(_arr + i, tmp[i]);
         // _arr[i] = tmp[i];
        _alloc.deallocate(tmp ,old_cap);
      }
      size_type it = _size - pos;
      _size = new_size;
      while (it-- > 0 && pos > 0 && new_size--)
        _alloc.construct(_arr + new_size, _arr[new_size - n]);
        //_arr[new_size] = _arr[new_size - n];
      while (n--)
      {
        //_arr[pos] = *(first++);
        _alloc.construct(_arr + pos, *(first++));
        pos++;
      }
    }
    size_type max_size() const 
    {
      return (std::min<size_type>(_alloc.max_size(), 
              std::numeric_limits<difference_type>::max()));
    }
    void pop_back()
    {
      if (this->empty())
        std::cerr << "vector::pop_back called on an empty vector" << std::endl;
      else
      {
        _alloc.destroy(&_arr[_size - 1]);
      --_size;
      }
    }
    void push_back(const value_type& x)
    {
      pointer tmp;
      size_type i = -1;
      size_type old_cap = _capacity;
      size_type new_size = _size + 1;
      if (_capacity == 0)
      {
        _capacity = new_size;
        _arr = _alloc.allocate(_capacity);
      }
      if (new_size <= _capacity)
      {
	      _alloc.construct(_arr + new_size - 1, x);
        _size = new_size;
      }
      else if (new_size > _capacity && _capacity > 0)
      {
        tmp = _arr;
        _capacity *= 2;
        _arr = _alloc.allocate(_capacity);
        while (++i < _size)
	        _alloc.construct(_arr + i, tmp[i]);
        if (tmp)
        {
          i = -1;
          while (++i < _size)
            _alloc.destroy(&tmp[i]);
          _alloc.deallocate(tmp, old_cap);
        }
	      _alloc.construct(_arr + new_size - 1, x);
        _size = new_size;
      }
    }

    void reserve(size_type n)
    {
      pointer tmp;
      size_type i = -1;
      tmp = _arr;
      if (n > this->max_size())
          throw std::length_error("vector::reserve");
      if (n > this->capacity())
      {
        size_type old_cap = _capacity;
        _capacity = n;
        _arr = _alloc.allocate(_capacity);
        while (++i < _size)
          _alloc.construct(_arr + i, tmp[i]);
        if (tmp)
        {
          i = -1;
          while (++i < _size)
            _alloc.destroy(&tmp[i]);
          _alloc.deallocate(tmp, old_cap);
        }
      }
    }
    void resize(size_type sz, value_type c = value_type())
    {
      pointer tmp;
      size_type old_cap = _capacity;
      size_type i = -1;
      size_type s = _size;
      if (sz <= _capacity && sz > _size)
      {
        while (_size < sz)
        {
          _alloc.construct(_arr + _size, c);
          _size++;
        }
      }
      else if (sz > _size && sz > _capacity)
      {
        tmp = _arr;
        _capacity = (sz >= _capacity * 2) ? sz : (_capacity * 2);
        size_type it = sz;
        _arr = _alloc.allocate(_capacity);
        while (++i < _size)
          _alloc.construct(_arr + i, tmp[i]);
        if (tmp)
        {
          for (size_type i = 0; i < _size; i++)
            _alloc.destroy(&tmp[i]);
        _alloc.deallocate(tmp, old_cap);
        }
        _size = sz;
        while (it-- > s)
          _alloc.construct(&_arr[it], c);
      }
      else if (sz <= _size)
      {
        while (_size-- > sz)
          _alloc.destroy(_arr + _size);
        _size = sz;
      }
    }
    size_type size() const { return _size;}
    void swap(vector &x)
    {
       if (&x == this)
        return ;
      swap(this->_arr, x._arr);
      swap(this->_end, x._end);
      swap(this->_size, x._size);
      swap(this->_capacity, x._capacity);
      swap(this->_alloc, x._alloc);
    }
    
  };
  //Non-member operators 
  template <class T, class Alloc>
  inline bool operator==(const vector<T, Alloc>& x, const vector<T, Alloc>& y)
  {
    if (x.size() != y.size())
      return (false);
    return (ft::equal(x.begin(), x.end(), y.begin(), y.end()));
  }
  template <class T, class Alloc>
  inline bool operator!=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
  {
    return (!(x == y));
  }
  
  template <class T, class Alloc>
  inline bool operator<(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
  {
    return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
  }
  template <class T, class Alloc>
  inline bool operator<=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
  {
    return (!(x > y));
  }
  template <class T, class Alloc>
  inline bool operator>(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
  {
    return (ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()));
  }
  template <class T, class Alloc>
  inline bool operator>=(const vector<T, Alloc> &x, const vector<T, Alloc> &y)
  {
    return (!(x < y));
  }
  template<class T, class Alloc>
  void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
  {
    x.swap(y);
  }
}
#endif
