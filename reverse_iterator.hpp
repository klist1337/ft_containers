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
      reverse_iterator(const reverse_iterator<iter>& it) {current = it.current;}
      template <class iter>
      reverse_iterator& operator=(const reverse_iterator<iter>& it) {current = it.base(); return *this;}
      iterator_type base() const {return current;}
      reference operator*() const {deref_tmp = current; --deref_tmp; return *deref_tmp;}
      pointer operator->() const {return (&(operator*()));}
      reverse_iterator& operator++() {--current; return *this;}
      reverse_iterator& operator++(int) {reverse_iterator tmp(*this); --current; return tmp;}
      reverse_iterator& operator--() { ++current; return *this;}
      reverse_iterator& operator--(int) {reverse_iterator tmp(*this); ++current; return tmp;}
      reverse_iterator& operator+(difference_type n) const {return reverse_iterator(current - n);}
      reverse_iterator& operator-(difference_type n) const {return reverse_iterator(current + n);}
      reverse_iterator& operator-=(difference_type n) { current += n ; return *this;}
      reverse_iterator& operator+=(difference_type n) { current -= n ; return *this;}
      reference operator[](difference_type n) const { return current[-n - 1];}
  };
  //Non members function
  template <class iter>
  bool operator==(const reverse_iterator<iter>& x,  const reverse_iterator<iter>& y)
  {
    return (x.current == y.current);
  }
  template <class iter>
  bool operator!=(const reverse_iterator<iter>& x,  const reverse_iterator<iter>& y)
  {
    return (x.current != y.current);
  }
  template <class iter>
  bool operator>(const reverse_iterator<iter>& x,  const reverse_iterator<iter>& y)
  {
    return (x.current < y.current);
  }
  template <class iter>
  bool operator<(const reverse_iterator<iter>& x,  const reverse_iterator<iter>& y)
  {
    return (x.current > y.current);
  }
  template <class iter>
  bool operator>=(const reverse_iterator<iter>& x,  const reverse_iterator<iter>& y)
  {
    return (x.current <= y.current);
  }
  template <class iter>
  bool operator<=(const reverse_iterator<iter>& x,  const reverse_iterator<iter>& y)
  {
    return (x.current >= y.current);
  }
  template<class iter>
  typename reverse_iterator<iter>::difference_type operator-(const reverse_iterator<iter>& x
                                                ,  const reverse_iterator<iter>& y)
  {
    return (y.current - x.current);
  }
  template<class iter>
  reverse_iterator<iter> operator+(typename reverse_iterator<iter>::difference_type n,
                                    const reverse_iterator<iter>& x)
  {
    return (reverse_iterator<iter>(x.current - n));
  }
}
#endif