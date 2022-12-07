#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>
#include "my_iterator.hpp"
#include "reverse_iterator.hpp"
#include "traits.hpp"
#include <algorithm>

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
    size_type _size;
    size_type _capacity;
    allocator_type _alloc;

    public:
    // Construct/ Copy / Destroy 
    explicit vector(const allocator_type& alloc = allocator_type()) : _arr(nullptr), _size(0), _capacity(0), _alloc(alloc)
    {}
    explicit vector(size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type())
    {
      size_type i = -1;
      _size = n;
      _capacity = n;
      _alloc = alloc;
      _arr = _alloc.allocate(_capacity);
      while (++i < _capacity)  
      {
        _arr[i] =  val;
      }
    }
    template<class InputIterator>
    vector(InputIterator first, InputIterator last,
            const allocator_type& alloc = allocator_type()
            , typename ft::enable_if<!ft::is_integral<InputIterator>::value,
              InputIterator>::type* = nullptr)
    {
      _alloc = alloc;
      size_type i = -1;
      _capacity = last - first;
      _size = _capacity;
      _arr = _alloc.allocate(_capacity);
      while (++i < _capacity)
      {
        _arr[i] = *(first++); 
      }
    }
    vector(const vector& x) : _arr(nullptr), _size(0), _capacity(0)
    {
      *this = x;
    }
    // assignement operator
    vector& operator=(const vector &x)
    {
      size_type i = -1;
      if (this == &x)
        return (*this);
      if (_capacity)
        _alloc.deallocate(_arr, _capacity);
      _alloc(x._alloc);
      _capacity = x._capacity;
      _size = x._size;
      _arr = _alloc.allocate(_capacity);
      while (++i < _capacity)
        _arr[i] = x._arr[i];
      return (*this);
    }
    ~vector() 
    {
      _alloc.deallocate(_arr, _capacity);
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
                  InputIterator>::type* = nullptr)
    {
      size_type i = -1;
      size_type size;
      size = last - first;
      if (size <= _capacity)
      {
        while (++i < size)
          _arr[i] = *(first++);
      }
      else
      {
        _alloc.deallocate(_arr, _capacity);
        _capacity = size;
        _arr = _alloc.allocate(_capacity);
        while (++i < size)
          _arr[i] = *(first++);
      }
    }
    void assign(size_type n, const value_type& val)
    {
      size_type i = -1;
      _size = n;
      if (_size <= _capacity)
      {
        while (++i < _size)
          _arr[i] = val;
      }
      else
      {
        _alloc.deallocate(_arr, _capacity);
        _capacity = _size;
        _arr = _alloc.allocate(_capacity);
        while (++i < _size)
          _arr[i] = val;
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
      iterator _r =  first;
      difference_type _d = last - first;
      std::copy(last, this->end(), _r);
      _size -= _d;
      return _r;
    }
    reference front() { return *_arr;}
    const_reference front() const { return *_arr;}
    iterator insert(iterator position, const value_type& x) // insert x before pos
    {
      size_type _oldsize = _size;
      pointer _cpy = _alloc.allocate(_oldsize);
      size_type pos =  position - this->begin();
      std::copy(this->begin(), this->end(), _cpy);
      _size += 1;
      _alloc.deallocate(_arr, _oldsize);
      _arr = _alloc.allocate(_size);
      for (size_type i = 0; i < _size; i++)
      {
        if (i < pos)
          _arr[i] = _cpy[i];
        if (i == pos)
          _arr[i] = x;
        if (i > pos)
        _arr[i] = _cpy[i - 1]; 
      }
      _alloc.deallocate(_cpy, _oldsize);
      return (this->begin() + pos);
    }
    void insert(iterator position, size_type n, const value_type& x)
    {
      size_type _oldsize = _size;
      size_type pos = position - this->begin();
      pointer _cpy =  _alloc.allocate(_oldsize);
      std::copy(this->begin(), this->end(), _cpy);
      _size += n;
      _alloc.deallocate(_arr, _oldsize);
      _arr = _alloc.allocate(_size);
      for (size_type i = 0; i < _size; i++)
      {
        if (i < pos)
          _arr[i] = _cpy[i];
        if (i == pos)
        {
          size_t it = i;
          for (size_type j = 0; j < n; j++)
          {
            _arr[it] = x;
            it++;
          }
          i = it;
        }
        if (i > pos)
        {
          _arr[i] = _cpy[i - n];
        }
      }
      _alloc.deallocate(_cpy, _oldsize);
    }
    template <class InputIterator>
    void insert(iterator position, InputIterator first, 
                InputIterator last, 
                typename std::enable_if<!std::is_integral<InputIterator>::value, 
                InputIterator>::type* = nullptr)
    {
      size_type _oldsize = _size; 
      size_type n = last - first;
      size_type pos = position - this->begin();
      pointer _cpy =  _alloc.allocate(_oldsize);
      std::copy(this->begin(), this->end(), _cpy);
      _size += n;
      _alloc.deallocate(_arr, _oldsize);
      _arr = _alloc.allocate(_size);
      for (size_type i = 0; i < _size; i++)
      {
        if (i < pos)
          _arr[i] = _cpy[i];
        if (i == pos)
        {
          size_t it = i;
          for (size_type j = 0; j < n; j++)
          {
            _arr[it] = *(first++);
            it++;
          }
          i = it;
        }
        if (i > pos)
        {
          _arr[i] = _cpy[i - n];
        }
      }
      _alloc.deallocate(_cpy, _oldsize);
    }
    size_type size() const { return _size;}
  };
}
#endif