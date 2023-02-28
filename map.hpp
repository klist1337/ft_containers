#ifndef MAP_HPP
#define MAP_HPP
#include "map_iterator.hpp"
#include "avl_tree.hpp"
#include "reverse_iterator.hpp"
#include "traits.hpp"
#include "pair.hpp"
#include "utils.hpp"
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
      typedef ft::map_iterator<pointer, nodePtr> iterator;
      typedef ft::map_iterator<const_pointer, nodePtr> const_iterator;
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
    _cmp(cmp), _alloc(alloc), _tree(alloc, _cmp)
    {}
    template <class InputIterator>
    map(InputIterator first, InputIterator last, const key_compare& cmp = key_compare(), const allocator_type& alloc = allocator_type())
    : _cmp(cmp), _alloc(alloc), _tree(alloc, cmp)
    {
      while (first != last)
         _tree.insert(*(first++));
    }
    map(const map& other) : _cmp(other._cmp), _alloc(other._alloc)
    {
      *this = other;
    }
    map& operator=(const map& other)
    {
      // if (this == &other)
      //   return (*this);
      _tree.clear();
      this->_alloc = other._alloc;
      this->_cmp = other._cmp; 
      if (other.size())
        insert(other.begin(), other.end());
      return (*this);
    }
    ~map() {}
    allocator_type get_allocator() const { return _tree.get_allocator();}
    //Element access
    mapped_type& at(const key_type& key) 
    {
      iterator it = begin();
      while (it != end())
      {
        if (it->first == key)
          return it->second;
        it++;
      }
      throw std::out_of_range("map::at: key not found");
    }
    mapped_type& operator[](const key_type& key)
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr node = _tree.find(value);
      if (!node || node == _tree.Get_end())
      {
        _tree.insert(value);
        node = _tree.find(value);
      }
      return (node->value.second);
    }
    //iterator
    iterator begin() {return iterator(_tree.Get_min(), _tree.getRoot());}
    const_iterator begin() const { return const_iterator(_tree.Get_min(), _tree.getRoot());}
    iterator end() { return iterator(nullptr, _tree.getRoot());}
    const_iterator end() const { return const_iterator(nullptr, _tree.getRoot());}
    reverse_iterator rbegin() { return reverse_iterator(end());}
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end());}
    reverse_iterator rend() { return reverse_iterator(begin());}
    const_reverse_iterator rend() const { return const_reverse_iterator(begin());}
    // Capacity
    bool empty() const { return (_tree.size() == 0) ? true : false ;}
    size_type size() const {return _tree.size();}
    size_type max_size() const { return _tree.max_size();}
    //Modifiers
    void clear() {_tree.clear();}
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
      return (ft::make_pair(iterator(node, _tree.getRoot()), is_inserted));
    }
    iterator insert(iterator pos, const value_type& value)
    {
      static_cast<void>(pos);
      nodePtr node = _tree.find(value);
      if (!node || node == _tree.Get_end())
      {
        _tree.insert(value);
        node = _tree.find(value);
      }
      return(iterator(node, _tree.getRoot()));
    }
    template<class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
      while (first != last)
        _tree.insert(*(first++));
    }
    iterator erase(iterator pos)
    {
      value_type value = ft::make_pair(pos->first, pos->second);
      iterator _r(pos);
      ++_r;
      nodePtr node = _tree.find(value);
      if (node)
        _tree.erase(value);
      return (_r);
    }
    iterator erase(iterator first, iterator last)
    {
      while (first != last)
      {
        first = erase(first);
        if (first == iterator(_tree.Get_end(), _tree.getRoot()))
        return first ;
      }
      return first;
    }
    size_type erase(const key_type& key)
    {
      size_type is_exist = 0;
      nodePtr node = _tree.find(ft::make_pair(key, mapped_type()));
      if (node)
      {
        is_exist = 1;
        _tree.erase(node->value);
      }
      return is_exist;
    }
    void swap(map& other)
    {
      key_compare cmp = _cmp;
      allocator_type alloc = this->get_allocator();
      _cmp = other._cmp;
      _alloc = other._alloc;

      other._cmp = cmp;
      other._alloc = alloc; 
      _tree.swap(other._tree);
    }
    //Lookup
    size_type count(const key_type& key) const
    {
      return _tree.count(key);
    }
    iterator find(const key_type& key)
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr node = _tree.find(value);
      if (node)
        return(iterator(node, _tree.getRoot()));
      return (end());
    }
    const_iterator find(const key_type& key) const
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr node = _tree.find(value);
      if (node)
        return(const_iterator(node, _tree.getRoot()));
      return (const_iterator(nullptr, _tree.getRoot()));
    }
    ft::pair<iterator, iterator> equal_range(const key_type& key)
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr first = _tree.lowerbound(value);
      nodePtr second = _tree.upperbound(value);
      return (ft::make_pair(iterator(first, _tree.getRoot()), iterator(second, _tree.getRoot())));
    }
    ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr first = _tree.lowerbound(value);
      nodePtr second = _tree.upperbound(value);
      return (ft::make_pair(const_iterator(first, _tree.getRoot()), const_iterator(second, _tree.getRoot())));
    }
    iterator lower_bound(const key_type& key)
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr node = _tree.lowerbound(value);
      return(iterator(node, _tree.getRoot()));
    }
    const_iterator lower_bound(const key_type& key) const
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr node = _tree.lowerbound(value);
      return(const_iterator(node, _tree.getRoot()));
    }
    iterator upper_bound(const key_type& key)
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr node = _tree.upperbound(value);
      return(iterator(node, _tree.getRoot()));
    }
    const_iterator upper_bound(const key_type& key) const
    {
      value_type value = ft::make_pair(key, mapped_type());
      nodePtr node = _tree.upperbound(value);
      return (const_iterator(node, _tree.getRoot()));
    }
    key_compare key_comp() const { return _cmp;}
    value_compare value_comp() const { return value_compare(_cmp);}
  };
  //Non-members functions
  template<class Key, class T, class Compare, class Alloc>
  inline bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
  {
    return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
  }
  template<class Key, class T, class Compare, class Alloc>
  inline bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
  {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
  }
  template<class Key, class T, class Compare, class Alloc>
  inline bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
  {
    return !(lhs == rhs);
  }
  template<class Key, class T, class Compare, class Alloc>
  inline bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
  {
    return (rhs < lhs);
  }
  template<class Key, class T, class Compare, class Alloc>
  inline bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
  {
    return !(lhs < rhs);
  }
  template<class Key, class T, class Compare, class Alloc>
  inline bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
  {
    return !(rhs < lhs);
  }
  template<class Key, class T, class Compare, class Alloc>
  void swap(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
  {
    lhs.swap(rhs);
  }
}
#endif
