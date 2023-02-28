#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP
#include "iterator_traits.hpp"

namespace ft
{
  template <class T>
  class my_iterator
  {
    public:
      typedef T iterator_type;
      typedef typename iterator_traits<T>::difference_type difference_type;
      typedef typename iterator_traits<T>::value_type value_type;
      typedef typename iterator_traits<T>::pointer pointer;
      typedef typename iterator_traits<T>::reference reference;
      typedef typename iterator_traits<T>::iterator_category iterator_category;
    
    private:
      iterator_type m_ptr;
    public:
    my_iterator() : m_ptr(nullptr) {}
    explicit my_iterator(iterator_type pt) : m_ptr(pt) {}
    template <class iter>
    my_iterator(const my_iterator<iter>& itr) : m_ptr(itr.base()) {}
    template <class iter>
    my_iterator operator=(const my_iterator<iter>& it) {m_ptr = it.base(); return *this;}
    iterator_type base() const { return m_ptr;}
    reference operator*() { return *m_ptr;}
    my_iterator operator+(difference_type n) const {return my_iterator(m_ptr + n);}
    my_iterator operator-(difference_type n) const {return my_iterator(m_ptr - n);}

    my_iterator operator--(int)
    {
      my_iterator temp(*this);
      --(*this);
      return (temp);
    }

    my_iterator operator++(int)
    {
      my_iterator tmp(*this);
      ++(*this);
      return (tmp);
    }

    my_iterator& operator++()
    {
      ++m_ptr;
      return (*this);
    }

    my_iterator& operator--()
    {
      --m_ptr;
      return (*this);
    }

    my_iterator& operator-=(difference_type n)
    {
      m_ptr -= n;
      return (*this);
    }

    my_iterator& operator+=(difference_type n)
    {
      m_ptr+= n;
      return (*this);
    }
    pointer operator->() {return (&(operator*()));}
    reference operator[](difference_type n) { return m_ptr[n];}
  };
  
  //Non members function
  template <class iter1, class iter2>
  inline bool operator==(const my_iterator<iter1>& rhs, const my_iterator<iter2>& lhs)
  {
    return (rhs.base() == lhs.base());
  }
  template <class iter1, class iter2>
  inline bool operator<(const my_iterator<iter1>& rhs, const my_iterator<iter2>& lhs)
  {
    return (rhs.base() < lhs.base());
  }
  template<class iter1, class iter2>
  inline bool operator!=(const my_iterator<iter1>& rhs, const my_iterator<iter2>& lhs)
  {
    return !(rhs == lhs);
  }
  template <class iter1, class iter2>
  inline bool operator>(const my_iterator<iter1>& rhs, const my_iterator<iter2>& lhs)
  {
    return (lhs < rhs);
  }
  template <class iter1, class iter2>
  inline bool operator>=(const my_iterator<iter1>& rhs, const my_iterator<iter2>& lhs)
  {
    return !(rhs < lhs);
  }
  template <class iter1, class iter2>
  inline bool operator<=(const my_iterator<iter1>& rhs, const my_iterator<iter2>& lhs)
  {
    return !(lhs < rhs);
  }
  template<class iter1>
  inline bool operator!=(const my_iterator<iter1>& rhs, const my_iterator<iter1>& lhs)
  {
    return !(rhs == lhs);
  }
  template<class iter1>
  inline bool operator>(const my_iterator<iter1>& rhs, const my_iterator<iter1>& lhs)
  {
    return (lhs < rhs);
  }
  template<class iter1>
  inline bool operator>=(const my_iterator<iter1>& rhs, const my_iterator<iter1>& lhs)
  {
    return !(rhs < lhs);
  }
  template<class iter1>
  inline bool operator<=(const my_iterator<iter1>& rhs, const my_iterator<iter1>& lhs)
  {
    return !(lhs < rhs);
  }
  template<class iter>
  inline my_iterator<iter> operator+(typename my_iterator<iter>::difference_type n
                                , my_iterator<iter> lhs)
  {
    lhs += n;
    return lhs; 
  } 
  template<class iter1, class iter2>
  inline typename my_iterator<iter1>::difference_type operator-(const my_iterator<iter1>& rhs, const my_iterator<iter2>& lhs)
  {
    return (rhs.base() - lhs.base()); 
  }
}

#endif
