#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
  template<class Iterator>
  class reverse_iterator
  {
    public:
      typedef Iterator iterator_type;
      typedef typename iterator_traits<Iterator>::difference_type difference_type;
      typedef typename iterator_traits<Iterator>::value_type value_type;
      typedef typename iterator_traits<Iterator>::reference reference;
      typedef typename iterator_traits<Iterator>::pointer pointer;
      typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
    
    protected:
    iterator_type current;
    private:
    iterator_type deref_tmp;
    public:
      reverse_iterator() : current(nullptr) {}
      explicit reverse_iterator(Iterator ptr) : current(ptr) {}
      template <class iter>
      reverse_iterator(const reverse_iterator<iter>& it) {current = it.base();}
      template <class iter>
      reverse_iterator& operator=(const reverse_iterator<iter>& it) {current = it.base(); return *this;}
      iterator_type base() const {return current;}
      reference operator*() const {return *(--base());}
      pointer operator->() const {return (&(operator*()));}
      reverse_iterator& operator++() {--current; return *this;}
      reverse_iterator operator++(int) {reverse_iterator tmp(*this); --current; return tmp;}
      reverse_iterator& operator--() { ++current; return *this;}
      reverse_iterator operator--(int) {reverse_iterator tmp(*this); ++current; return tmp;}
      reverse_iterator operator+(difference_type n) const {return reverse_iterator(current - n);}
      reverse_iterator operator-(difference_type n) const {return reverse_iterator(current + n);}
      reverse_iterator& operator-=(difference_type n) { current += n ; return *this;}
      reverse_iterator& operator+=(difference_type n) { current -= n ; return *this;}
      reference operator[](difference_type n) const { return *(--base() - n);}
  };
  //Non members function
  template <class iter1, class iter2>
  inline bool operator==(const reverse_iterator<iter1>& x,  const reverse_iterator<iter2>& y)
  {
    return (x.base() == y.base());
  }
  template <class iter1, class iter2>
  inline bool operator!=(const reverse_iterator<iter1>& x,  const reverse_iterator<iter2>& y)
  {
    return (x.base() != y.base());
  }
  template <class iter1, class iter2>
  inline bool operator>(const reverse_iterator<iter1>& x,  const reverse_iterator<iter2>& y)
  {
    return (x.base() < y.base());
  }
  template <class iter1, class iter2>
  inline bool operator<(const reverse_iterator<iter1>& x,  const reverse_iterator<iter2>& y)
  {
    return (x.base() > y.base());
  }
  template <class iter1, class iter2>
  inline bool operator>=(const reverse_iterator<iter1>& x,  const reverse_iterator<iter2>& y)
  {
    return (x.base() <= y.base());
  }
  template <class iter1, class iter2>
  inline bool operator<=(const reverse_iterator<iter1>& x,  const reverse_iterator<iter2>& y)
  {
    return (x.base() >= y.base());
  }
  template<class iter1, class iter2>
  typename reverse_iterator<iter1>::difference_type operator-(const reverse_iterator<iter1>& x, const reverse_iterator<iter2>& y)
  {
    return (y.base() - x.base());
  }
  template<class iter>
  reverse_iterator<iter> operator+(typename reverse_iterator<iter>::difference_type n,
                                    const reverse_iterator<iter>& x)
  {
    return (reverse_iterator<iter>(x.base() - n));
  }
}
#endif