#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include <algorithm>
#define INSERT 1
#define ERASE 2
namespace ft
{
  template <class T>
  struct Node
  {
    T value;
    Node *parent;
    Node *left;
    Node *right;
    int   balance_factor;
    int   height;
    Node() : parent(nullptr), left(nullptr), right(nullptr)
    {} 
    Node(const T& value) : value(value)
    {}
    Node(const T& value, const int& height) : value(value), parent(nullptr), left(nullptr), right(nullptr), balance_factor(0)
    , height(height)
    {}
  };
  //AVL Balancing tree
  template<class T, class Compare, class Alloc>
  class Avltree
  {
  public :
   typedef T value_type;
   typedef Compare key_compare;
   typedef Node<T>* nodePtr;
   typedef typename Alloc::template rebind<Node<T> >::other allocator_type;
   typedef typename allocator_type::size_type size_type;
   typedef typename value_type::first_type key_type;

   private:
   nodePtr _root;
   nodePtr _end;
   allocator_type _alloc;
   key_compare _cmp;
   size_type _size;

   public:
   Avltree(const allocator_type& alloc = allocator_type(), const key_compare& cmp = key_compare()) :
   _root(nullptr), _end(nullptr), _alloc(alloc), _cmp(cmp), _size(0)
   {
     _end = _alloc.allocate(1);
     _alloc.construct(_end);
   }
   ~Avltree()
   {
    clear();
    _alloc.deallocate(_end, 1);
    _end = nullptr;
    }

    nodePtr getRoot() const
    {
      return (_root);
    }
    // ft::map member function
    allocator_type get_allocator() const { return this->_alloc;}
    //:: Capacity function
    size_type size() const { return _size;}
    size_type max_size() const { return _alloc.max_size();}
    nodePtr Get_end() const {return nullptr;}
    int height(nodePtr node)
    {
      if (node == nullptr) 
        return 0;
      return node->height;
    }
    nodePtr successor(nodePtr node) const
    {
      nodePtr parent = node->parent;
      nodePtr tmp = node;
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
    nodePtr Get_min(nodePtr node = nullptr) const
    {
      if (!node)
       node = _root;
      while (node && node->left)
      {
        node = node->left;
      }
      return node;
    }
    nodePtr Get_max(nodePtr node = nullptr) const
    {
      if (!node)
        node = _root;
      while (node && node->right)
        node = node->right;
      return node;
    }
    nodePtr lowerbound(const value_type& value) const
    {
      nodePtr node = _root;
      nodePtr r = nullptr;
      while (node != nullptr)
      {
        if (!_cmp(node->value.first, value.first))
        {
          r = node;
          node = node->left;
        }
        else
          node = node->right;
      }
      return (r);
    }
    nodePtr upperbound(const value_type& value) const
    {
      nodePtr node = _root;
      nodePtr r = nullptr;
      while (node != nullptr)
      {
        if (_cmp(value.first, node->value.first))
        {
          r = node;
          node = node->left;
        }
        else
          node = node->right;
      }
      return (r);
    }
    size_type count(const key_type& key) const
    {
      nodePtr node = _root;
      while (node != nullptr)
      {
        if (_cmp(key, node->value.first))
          node = static_cast<nodePtr>(node->left);
        else if (_cmp(node->value.first, key))
          node = static_cast<nodePtr>(node->right);
        else
         return 1;
      }
       return 0;
    }
    void swap(Avltree& tree)
    {
      nodePtr root = tree._root;
      nodePtr end = tree._end;
      allocator_type alloc = tree._alloc;
      key_compare cmp = tree._cmp;
      size_type size = tree._size;

      tree._root = this->_root;
      tree._end = this->_end;
      tree._alloc = this->_alloc;
      tree._cmp = this->_cmp;
      tree._size = this->_size;

      this->_root = root;
      this->_end = end;
      this->_alloc = alloc;
      this->_cmp = cmp;
      this->_size = size;
    }
    nodePtr find(const value_type& value)
    {
      return find(_root, value);
    }
    nodePtr find(nodePtr& node, const value_type& value)
    {
      if (!node || node == nullptr)
        return (nullptr);
      if (node->value.first == value.first)
        return (node);
      if (_cmp(node->value.first, value.first))
        return (find(node->right, value));
      return(find(node->left, value));
    }
    void update(nodePtr node)
    {
      int LnodeHeight = -1;
      int RnodeHeight = -1;

      if (node->left)
        LnodeHeight = node->left->height;
      if (node->right)
        RnodeHeight = node->right->height;
      int diff = ((LnodeHeight > RnodeHeight) ? LnodeHeight : RnodeHeight);
      node->height = 1 + diff;
      node->balance_factor = RnodeHeight - LnodeHeight;
    }
    void balance(nodePtr& node)
    {
      if (node->balance_factor < -1)
      {
        if (node->left->balance_factor <= 0)
          right_rotation(node);
        else
        {
          left_rotation(node->left);
          right_rotation(node);
        }
      }
      else if (node->balance_factor > 1)
      {
        if (node->right->balance_factor >= 0)
          left_rotation(node);
        else
        {
          right_rotation(node->right);
          left_rotation(node);
        }
      }

    }
    void insert(const value_type value)
    {
      insertNode(_end, _root, value); 
      _end->left = _root;
      _root->parent = nullptr;
    }
    void erase(const value_type& value)
    {
      eraseNode(_root, value);
      _end->left = _root;
      if (_root)
        _root->parent = nullptr;
    }
  
    void insertNode(nodePtr& parent, nodePtr& node, const value_type& value)
    {
      if (node == nullptr)
      {
        node = _alloc.allocate(1);
        _alloc.construct(node, value, 0);
        node->parent = parent;
        _size++;
        return ;
      }
      if (_cmp(value.first, node->value.first))
        insertNode(node, node->left, value);
      else 
        insertNode(node, node->right, value);
      update(node);
      balance(node);
    }
    void eraseHelper(nodePtr& node, nodePtr& parent)
    {
      nodePtr tmp;
      if (node->right)
        tmp = node->right;
      else
        tmp = node->left;
      if (tmp)
        tmp->parent = parent;
      _alloc.deallocate(node, 1);
      node = tmp;
      _size--;
    }
    void eraseNode(nodePtr &node, const value_type& value)
    {
      if (!node)
        return ;
      if (node->value.first == value.first)
      {
        if (!node->left || !node->right)
        {
          eraseHelper(node, node->parent);
          return ;
        }
        else
        {
          if (node->left->height > node->right->height)
          {
            value_type value = Get_max(node->left)->value;
            _alloc.construct(node, value);
            eraseNode(node->left, value);
          }
          else
          {
            value_type value = Get_min(node->right)->value;
            _alloc.construct(node, value);
            eraseNode(node->right, value);
          }
        }
      }
      else if (_cmp(value.first, node->value.first))
        eraseNode(node->left, value);
      else
        eraseNode(node->right, value);
      update(node);
      balance(node);
    }
    void right_rotation(nodePtr &node)
    {
     nodePtr parent = node->parent;
     nodePtr root = node->left;
     node->left = root->right;
     if (node->left)
      node->left->parent = node;
     node->parent = root;
     root->right = node;
     root->parent = parent;
     node = root;
     update(node->right);
     update(node);
    }
    void  left_rotation(nodePtr &node)
    {
      nodePtr parent = node->parent;
      nodePtr root = node->right;
      node->right = root->left;
      if (node->right)
        node->right->parent = node;
      node->parent = root;
      root->left = node;
      root->parent = parent;
      node = root;
      update(node->left);
      update(node);
    }
    void clear()
    {
      clear(_root);
      _size = 0;
    }
    void clear(nodePtr &node)
    {
      if (node)
      {
        clear(node->left);
        clear(node->right);
        _alloc.deallocate(node, 1);
        node = nullptr;
      }
    }
    void inorder_util(nodePtr &node) const
    {
      inorder_util(node->left);
      std::cout << node->value.first << " ";
      inorder_util(node->right);
    }
  };

}
#endif