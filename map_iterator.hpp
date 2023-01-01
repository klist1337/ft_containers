#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft
{
  template<class T, class Nodeptr>
  class Mapiterator
  {
    typedef typename iterator_traits<T>::difference_type difference_type;
    typedef typename iterator_traits<T>::value_type value_type;
    typedef typename iterator_traits<T>::pointer pointer;
    typedef typename iterator_traits<T>::reference reference;
    typedef std::bidirectional_iterator_tag iterator_category

    private:
      Nodeptr node;
    public:
    Mapiterator() : node(nullptr) {};
    explicit Mapiterator(const Nodeptr& ptr) : node(ptr) {}
    template<class Iter, class nodeptr>
    Mapiterator(const Mapiterator<Iter, nodeptr>& mapitr) : node(mapitr.base()) {}
    template<class Iter, class nodeptr>
    Mapiterator& operator=(const Mapiterator<Iter, nodeptr>& mapitr)
    {
      if (this == &mapitr)
        return (*this);
      node = mapitr.base();
      return (*this);
    }
    Nodeptr base() const {return node;}
    reference operator*() { return node->value;}
    pointer operator->() { return (&(operator*()));}
    Mapiterator& operator++()
    {
      node = successor();
      return (*this);
    }
    Mapiterator operator++(int)
    {
      Mapiterator tmp(*this);
      ++(*this);
      return (tmp);
    }
    Mapiterator& operator--()
    {
      node = predecessor();
      return (*this);
    }
    Mapiterator operator--(int)
    {
      Mapiterator tmp(*this);
      --(*this);
      return (tmp);
    }
    private:
    Nodeptr successor()
    {
      Nodeptr parent = node->parent;
      Nodeptr tmp = node;
      if (tmp->right)
      {
        tmp = tmp->right;
        while (tmp->left)
          tmp = tmp->left;
        return (tmp);
      }
      else
      {
        while (parent && tmp == parent->right)
        {
          tmp = parent;
          parent = tmp->parent;
        }
        return (parent);
      }
    }
    Nodeptr predecessor()
    {
      Nodeptr parent = node->parent;
      Nodeptr tmp = node;
      if (tmp->left)
      {
        tmp = tmp->left;
        while (tmp->right)
          tmp = tmp->right;
        return(tmp);
      }
      else
      {
        while (parent && tmp == parent->left)
        {
          tmp = parent;
          parent = tmp->parent;
        }
        return (parent);
      }
    }
  };
  //Non Member function/operator
  template <class Iter, class nodeptr>
  bool operator==(const Mapiterator<Iter, nodeptr>& _x, const Mapiterator<Iter, nodeptr>& _y)
  {
    return (_x.base() == _y.base());
  }
  template <class Iter, class nodeptr>
  bool operator!=(const Mapiterator<Iter, nodeptr>& _x, const Mapiterator<Iter, nodeptr>& _y)
  {
    return (_x.base() != _y.base());
  }
  
}
#endif