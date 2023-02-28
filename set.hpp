#ifndef SET_HPP
#define SET_HPP
#include "red_black_tree.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "utils.hpp"
#include "vector.hpp"
namespace ft
{
  template<class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
  class set 
  {
    public:
      typedef Key key_type;
      typedef Key value_type;
      typedef Allocator allocator_type;
      typedef typename allocator_type::size_type size_type;
      typedef typename allocator_type::difference_type difference_type;
      typedef typename allocator_type::reference reference;
      typedef typename allocator_type::const_reference const_reference;
      typedef Compare key_compare;
      typedef Compare value_compare;
      typedef typename allocator_type::pointer pointer;
      typedef typename allocator_type::const_pointer const_pointer;
      typedef RBTree<key_type, key_compare, allocator_type> tree;
      typedef typename tree::nodePtr nodePtr;
      typedef ft::map_iterator<pointer, nodePtr> iterator;
      typedef ft::map_iterator<const_pointer, nodePtr> const_iterator;
      typedef ft::reverse_iterator<iterator> reverse_iterator;
      typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
    
    private:
      key_compare _cmp;
      allocator_type _alloc;
      tree _tree;

    public:
    //construct / C_Cpy/ Destroy
    explicit set(const key_compare& cmp = key_compare(), const allocator_type& alloc = allocator_type())
    :_cmp(cmp), _alloc(alloc), _tree(_alloc, _cmp)
    {}
    template<class InputIt>
    set(InputIt first, InputIt last, const key_compare& cmp = key_compare(), const allocator_type& alloc = allocator_type())
    : _cmp(cmp), _alloc(alloc), _tree(_alloc, _cmp)
    {
      while (first != last)
        _tree.insert(*(first++));
    }
    set(const set& other): _cmp(other._cmp), _alloc(other._alloc)
    {
      *this = other;
    }
    set& operator=(const set& other)
    {
      this->clear();
      this->_alloc = other._alloc;
      this->_cmp = other._cmp;
      if (other.size())
        insert(other.begin(), other.end());
      return (*this);
    }
    ~set() {}
    allocator_type get_allocator() const { return _tree.get_allocator();}
    //iterators
    iterator begin() { return iterator(_tree.Get_min(), _tree.getRoot());}
    const_iterator begin() const {return const_iterator(_tree.Get_min(), _tree.getRoot());}
    iterator end() { return iterator(nullptr, _tree.getRoot());}
    const_iterator end() const { return const_iterator(nullptr, _tree.getRoot());}
    reverse_iterator rbegin() { return reverse_iterator(end());}
    const_reverse_iterator rbegin() const { return const_reverse_iterator(end());}
    reverse_iterator rend() { return reverse_iterator(begin());}
    const_reverse_iterator rend() const { return const_reverse_iterator(rbegin());}
    //Capacity
    bool empty() const { return (_tree.size() == 0) ? true : false ;}
    size_type size() const { return _tree.size();}
    size_type max_size() const { return _tree.max_size();}
    //Modifiers
    void clear() { _tree.clear() ;}

    ft::pair<iterator, bool> insert(const value_type& value)
    {
      bool is_inserted = false;
      nodePtr node = _tree.find(value);
      if (!node)
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
      if (!node)
      {
        _tree.insert(value);
        node = _tree.find(value);
      }
      return (iterator(node, _tree.getRoot()));
    }
    template<class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
      while (first != last)
        _tree.insert(*(first++));
    }
    void erase(iterator pos)
    {
      value_type value = *pos;
      nodePtr node = _tree.find(value);
      if (node)
        _tree.erase(value);
    }
    void erase(iterator first, iterator last)
    {
      ft::vector<value_type>  p;
      while (first != last)
      {
        p.push_back(*first);
        first++;
      }
      size_t i = 0;
      while (i < p.size())
      {
        erase(p[i]);
        i++;
      }
    }
    size_type erase(const key_type& key)
    {
      size_type is_exist = 0;
      nodePtr node = _tree.find(key);
      if (node)
      {
        is_exist = 1;
        _tree.erase(key);
      }
      return is_exist;
    }
    void swap(set &other)
    {
      key_compare cmp = this->_cmp;
      allocator_type alloc = this->get_allocator();
      _cmp = other._cmp;
      _alloc = other._alloc;

      other._cmp = cmp;
      other._alloc = alloc;
      _tree.swap(other._tree);
    }
    //Lookup
    size_type count (const key_type& key) const 
    {
      return _tree.count(key);
    }
    iterator find (const key_type& key)
    {
      nodePtr node = _tree.find(key);
      if (node)
        return (iterator(node, _tree.getRoot()));
      return (end());
    }
    const_iterator find(const key_type& key) const
    {
      nodePtr node = _tree.find(key);
      if (node)
        return (const_iterator(node, _tree.getRoot()));
      return (const_iterator(nullptr, _tree.getRoot()));
    }
    ft::pair<iterator, iterator> equal_range(const key_type &key)
    {
      nodePtr first = _tree.lowerbound(key);
      nodePtr second = _tree.upperbound(key);
      return (ft::make_pair(iterator(first, _tree.getRoot()), iterator(second, _tree.getRoot())));
    }

    ft::pair<const_iterator, const_iterator> equal_range(const key_type &key) const
    {
      nodePtr first = _tree.lowerbound(key);
      nodePtr second = _tree.upperbound(key);
      return (ft::make_pair(const_iterator(first, _tree.getRoot()), const_iterator(second, _tree.getRoot())));
    }

    iterator lower_bound(const key_type& key)
    {
      nodePtr node = _tree.lowerbound(key);
      return (iterator(node, _tree.getRoot()));
    }

    const_iterator lower_bound(const key_type& key) const
    {
      nodePtr node = _tree.lowerbound(key);
      return (const_iterator(node, _tree.getRoot()));
    }

    iterator upper_bound(const key_type& key)
    {
      nodePtr node = _tree.upperbound(key);
      return (iterator(node, _tree.getRoot()));
    }

    const_iterator upper_bound(const key_type& key) const
    {
      nodePtr node = _tree.upperbound(key);
      return (const_iterator(node, _tree.getRoot()));
    }
    key_compare key_comp() const { return _cmp;}
    value_compare value_comp() const { return value_compare(_cmp);}
    void printTree()
    {
      _tree.printTree();
    }
  };
  template<class Key, class Compare, class Alloc>
  inline bool operator==(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
  {
    return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
  }
  template<class Key, class Compare, class Alloc>
  inline bool operator<(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
  {
    return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
  }
  template<class Key, class Compare, class Alloc>
  inline bool operator!=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
  {
    return !(lhs == rhs);
  }
  template<class Key, class Compare, class Alloc>
  inline bool operator>(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
  {
    return (rhs < lhs);
  }
  template<class Key, class Compare, class Alloc>
  inline bool operator>=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
  {
    return !(lhs < rhs);
  }
  template<class Key, class Compare, class Alloc>
  inline bool operator<=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
  {
    return !(rhs < lhs);
  }
  template<class Key, class Compare, class Alloc>
  void swap(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
  {
    lhs.swap(rhs);
  }
}
#endif