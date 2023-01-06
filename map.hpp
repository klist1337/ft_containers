#ifndef MAP_HPP
#define MAP_HPP
#include "map_iterator.hpp"
#include "avl_tree.hpp"
#include "reverse_iterator.hpp"
#include "traits.hpp"
#include "pair.hpp"
#include <iostream>
#include <memory>
namespace ft
{
  template<class Key, class T, class Compare=std::less<Key>, class Allocator=std::allocator <ft::pair<const Key, T> > >
  class map
  {
    public:
      typedef Key key_type;
      typedef T mapped_type;
      typedef ft::pair<const key_type, mapped_type> value_type;
      typedef Allocator allocator_type;
      typedef typename allocator_type::size_type size_type;
      typedef typename allocator_type::difference_type difference_type;
      typedef Compare key_compare;
      typedef typename allocator_type::reference reference;
      typedef typename allocator_type::const_reference const_reference;
      typedef typename allocator_type::pointer pointer;
      typedef typename allocator_type::const_pointer const_pointer;
      typedef ft::Avltree<value_type, key_compare, allocator_type> tree;
      typedef typename tree::nodePtr nodePtr;
      typedef ft::Mapiterator<pointer, nodePtr> iterator;
      typedef ft::Mapiterator<const_pointer, nodePtr> const_iterator;
      typedef ft::reverse_iterator<iterator> reverse_iterator;
      typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

    class value_compare : public std::binary_function<value_type, value_type, bool>
    {
      friend class map;
      protected:
        key_compare comp;
        value_compare(key_compare c) : comp(c) {}
      public:
        bool operator()(const value_type& lhs, const value_type& rhs) const
        {
          return comp(lhs.first, rhs.first);
        }
    };
    private:
      key_compare _cmp;
      allocator_type _alloc;
      tree _tree;
    public:
    //construct / Cpy/ Destroy
    explicit map(const key_compare& cmp = key_compare(), const allocator_type& alloc = allocator_type()): 
    _cmp(cmp), _alloc(alloc), _tree()
    {}
    template <class InputIterator>
    map(InputIterator first, InputIterator last, const key_compare& cmp = key_compare(), const allocator_type& alloc = allocator_type())
    : _cmp(cmp), _alloc(alloc), _tree()
    {
      while (first != last)
        _tree.insert(*(first++));
    }
    ~map() {}
    allocator_type get_allocator() const { return _tree.get_allocator();}
    //iterator
    iterator begin() {return iterator(_tree.Get_min());}
    const_iterator begin() const { return const_iterator(_tree.Get_min());}
    iterator end() { return iterator(_tree.Get_end());}
    const_iterator end() const { return const_iterator(_tree.Get_end());}
    reverse_iterator rbegin() { return reverse_iterator(begin());}
    const_reverse_iterator rbegin() const { return const_reverse_iterator(begin());}
    reverse_iterator rend() { return reverse_iterator(end());}
    const_reverse_iterator rend() const { return const_reverse_iterator(end());}
    // Members operator

    //Member_function
    ft::pair<iterator, bool> insert(const value_type& value)
    {
      bool is_inserted = false;
      nodePtr node = _tree.find(value);
      if (!node || node == _tree.Get_end())
      {
        is_inserted = true;
        _tree.insert(value);
        node = _tree.find(value);
      }
      return (ft::make_pair(iterator(node), is_inserted));
    }
  };
}
#endif