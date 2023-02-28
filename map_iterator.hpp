#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft
{
  template<class T, class Nodeptr>
  class map_iterator
  {
    public:
      typedef typename iterator_traits<T>::difference_type difference_type;
      typedef typename iterator_traits<T>::value_type value_type;
      typedef typename iterator_traits<T>::pointer pointer;
      typedef typename iterator_traits<T>::reference reference;
      typedef std::bidirectional_iterator_tag iterator_category;

    private:
      Nodeptr node;
      Nodeptr root;
    public:
    map_iterator() : node(nullptr), root(nullptr) {};
    explicit map_iterator(const Nodeptr& ptr, const Nodeptr& rootPtr = nullptr) : node(ptr), root(rootPtr) {}
    template<class Iter, class nodeptr>
    map_iterator(const map_iterator<Iter, nodeptr>& mapitr) : node(mapitr.base()), root(mapitr.getRoot()) {}
    template<class Iter, class nodeptr>
    map_iterator& operator=(const map_iterator<Iter, nodeptr>& mapitr)
    {
      node = mapitr.base();
      root = mapitr.getRoot();
      return *this;
    }
    Nodeptr base() const {return node;}
    Nodeptr getRoot() const {return root;}
    reference operator*() {return node->value;}
    reference operator*() const { return node->value;}
    pointer operator->(){ return (&(operator*()));}
    pointer operator->() const { return (&(operator*()));}
    map_iterator& operator++()
    {
      if (node == nullptr)
      {
        node = root;
        while (node && node ->left)
        {
          node = node ->left;
        }
      }
      else
        node = successor();
      return (*this);
    }
    map_iterator operator++(int)
    {
      map_iterator tmp(*this);
      ++(*this);
      return (tmp);
    }
    map_iterator& operator--()
    {
      if (node == nullptr)
      {
        node = root;
        while (node && node ->right)
        {
          node = node ->right;
        }
      }
      else
        node = predecessor();
      return (*this);
    }
    map_iterator operator--(int)
    {
      map_iterator tmp(*this);
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
      Nodeptr parent;
      if (node)
      parent = node->parent;
      Nodeptr tmp = node;
      if (tmp && tmp->left)
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
  bool operator==(const map_iterator<Iter, nodeptr>& _x, const map_iterator<Iter, nodeptr>& _y)
  {
    return (_x.base() == _y.base());
  }
  template <class Iter, class nodeptr>
  bool operator!=(const map_iterator<Iter, nodeptr>& _x, const map_iterator<Iter, nodeptr>& _y)
  {
    return (_x.base() != _y.base());
  }
}
#endif