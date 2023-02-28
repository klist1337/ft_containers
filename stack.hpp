#ifndef STACK_HPP
# define STACK_HPP
#include "vector.hpp"
namespace ft
{
  template<class T, class _Container = ft::vector<T> >
  class stack
  {
    public:
    typedef _Container container_type;
    typedef typename container_type::value_type value_type;
    typedef typename container_type::reference reference;
    typedef typename container_type::const_reference const_reference;
    typedef typename container_type::size_type size_type;
    
    protected:
    container_type c;

    public:
    // ctor / ctor_cpy/ assignment operator
      stack(const stack& _q) : c(_q.c) {}
      explicit stack(const container_type& cont = container_type()): c(cont)
      {}
      stack& operator=(const stack& _q)
      {
        c = _q.c ;
        return (*this);
      }
      container_type base() const { return c;}
      // Element access
      reference top() { return c.back();}
      const_reference top() const { return c.back();}
      //Capacity
      bool empty() const { return c.empty();}
      size_type size() const { return c.size();};
      //Modifiers
      void push(const value_type& val) {c.push_back(val);}
      void pop() { c.pop_back();}
  };
  template<class T, class _Container>
  inline bool operator==(const stack<T, _Container>& x, const stack<T, _Container>& y)
  {
    return x.base() == y.base();
  }
  template<class T, class _Container>
  inline bool operator<(const stack<T, _Container>& x, const stack<T, _Container>& y)
  {
    return x.base() < y.base();
  }
  template<class T, class _Container>
  inline bool operator!=(const stack<T, _Container>& x, const stack<T, _Container>& y)
  {
    return !(x == y);
  }
  template<class T, class _Container>
  inline bool operator>(const stack<T, _Container>& x, const stack<T, _Container>& y)
  {
    return y < x;
  }
  template<class T, class _Container>
  inline bool operator>=(const stack<T, _Container>& x, const stack<T, _Container>& y)
  {
    return !(x < y);
  }
  template<class T, class _Container>
  inline bool operator<=(const stack<T, _Container>& x, const stack<T, _Container>& y)
  {
    return !(y < x);
  }
}
#endif
