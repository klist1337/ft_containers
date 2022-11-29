#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft
{
  template <class T>
  class My_iterator
  {
    public:
      typedef T iterator_type;
      typedef iterator_traits<T>::difference_type difference_type;
      typedef iterator_traits<T>::value_type value_type;
      typedef iterator_traits<T>::pointer pointer;
      typedef iterator_traits<T>::reference reference;
      typedef iterator_traits<T>::iterator_category iterator_category;
    
    private:
      iterator_type m_ptr;
    public:
    My_iterator() : m_ptr(nullptr) {}
    explicit My_iterator(iterator_type pt) : m_ptr(pt) {}
    template <class iter>
    My_iterator(const My_iterator<iter>& itr) : m_ptr(itr.m_ptr) {}
    template <class iter>
    My_iterator operator=(const My_iterator<iter>& iter) {m_ptr = iter.m_ptr; return *this;}
    iterator_type base() const { return m_ptr;}
    reference operator*() { return *m_ptr;}
    My_iterator operator+(difference_type n) const {return My_iterator(m_ptr + n);}
    My_iterator operator-(difference_type n) const {return My_iterator(m_ptr - n);}

    My_iterator operator--(int)
    {
      My_iterator temp(*this);
      --(*this);
      return (temp);
    }

    My_iterator operator++(int)
    {
      My_iterator tmp(*this);
      ++(*this);
      return (tmp);
    }

    My_iterator& operator++()
    {
      ++(*this);
      return (*this);
    }

    My_iterator& operator--()
    {
      --(*this);
      return (*this);
    }

    My_iterator& operator-=(difference_type n)
    {
      m_ptr -= n;
      return (*this);
    }

    My_iterator& operator+=(difference_type n)
    {
      m_ptr+= n;
      return (*this);
    }
    pointer operator->() {return m_ptr;}
    reference operator[](difference_type n) { return m_ptr[n];}
  };
  
  //Non members function
  template <class iter>
  bool operator==(const My_iterator<iter>& rhs, const My_iterator<iter>& lhs)
  {
    return (rhs.base() == lhs.base());
  }
  template <class iter>
  bool operator!=(const My_iterator<iter>& rhs, const My_iterator<iter>& lhs)
  {
    return (rhs.base() != lhs.base());
  }
  template <class iter>
  bool operator>(const My_iterator<iter>& rhs, const My_iterator<iter>& lhs)
  {
    return (rhs.base() > lhs.base());
  }
  template <class iter>
  bool operator<(const My_iterator<iter>& rhs, const My_iterator<iter>& lhs)
  {
    return (rhs.base() < lhs.base());
  }
  template <class iter>
  bool operator>=(const My_iterator<iter>& rhs, const My_iterator<iter>& lhs)
  {
    return (rhs.base() >= lhs.base());
  }
  template <class iter>
  bool operator<=(const My_iterator<iter>& rhs, const My_iterator<iter>& lhs)
  {
    return (rhs.base() <= lhs.base());
  }
  template<class iter>
  My_iterator<iter> operator+(typename My_iterator<iter>::difference_type n
                                , const My_iterator<iter> &lhs)
  {
    return (static_cast<My_iterator<iter>>(lhs.base()+ n)); 
  }
  template<class iter>
  typename My_iterator<iter>::difference_type operator-(const My_iterator<iter>& rhs, 
                                                          const My_iterator<iter>& lhs)
  {
    return (rhs.base() - lhs.base()); 
  }
}

#endif
