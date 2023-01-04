#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include <algorithm>
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
    Node() : parent(nullptr), left(nullptr), right(nullptr), height(1)
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
   typedef T value_type;
   typedef Compare key_compare;
   typedef Node<T>* nodePtr;
   typedef typename Alloc::template rebind<Node<T>>::other allocator_type;
   typedef typename allocator_type::size_type size_type;

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
     _alloc.allocate(1);
     _alloc.construct(_end);
   }
   ~Avltree()
   {
    clear();
    _alloc.deallocate(_end);
    _end = nullptr;
    }
    // ft::Map member function
    allocator_type get_allocator() const { return this->_alloc;}
    //:: Capacity function
    size_type size() const { return _size;}
    bool empty() const { return (!size) ? true : false ;}
    size_type max_size() const { return _alloc.max_size;}
    nodePtr Get_end() const {return this->_end;}
    int height(nodePtr node)
    {
      if (node == nullptr) 
        return 0;
      return node->height;
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
    }
    nodePtr lowerbound(const value_type& value)
    {
      nodePtr node = Get_min();
      while (node != _end)
      {
        if (!_cmp(node->value.first, value.first))
          return(node);
        node = successor();
      }
      return(_end);
    }
    nodePtr upperbound(const value_type& value)
    {
      nodePtr node = Get_min();
      while (node != _end)
      {
        if (_cmp(node->value.first, value.first))
          return(node);
        node = successor();
      }
      return(_end);
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
      if (!node)
        return (nullptr);
      if (node->value.first == value.first)
        return (node);
      if (_cmp(node->value.first, value.first))
        return (find(node->right, value));
      return(find(node->left, value));
    }
    void insert(const value_type& value)
    {
      _root = insertNode(_root, value);
    }
    void erase(const value_type& value)
    {
      _root = eraseNode(_root, value);
    }
    nodePtr insertNode(nodePtr node, const value_type& value)
    {
      //find the correct position to insert the value;
      if (node == nullptr)
      {
        _alloc.allocate(1);
        _alloc.construct(_end, value);
        _size++;
        return _end;
      }
      if (_cmp(node->value.first, value.first))
        node = insertNode(node->right, value);
      else if (_cmp(value.first , node->value.first))
        node = insertNode(node->left, value);
      node->height = 1 + std::max(height(node->right), height(node->left));
      node->balance_factor = (height(node->left) - height(node->right));
      if (node->balance_factor > 1)
      {
        if (_cmp(node->left->value.first, value.first))
          return (right_rotation(node));
        else
        {
          node->left = left_rotation(node->left);
          return (right_rotation(node->right));
        }
      }
      else if (node->balance_factor < -1)
      {
        if (_cmp(value.first, node->right->value.first))
          return (left_rotation(node));
        else
        {
          node->right = right_rotation(node->right);
          return(left_rotation(node));
        }
      }
    }
    nodePtr eraseNode(nodePtr node, const value_type)
    {
      if (node == nullptr)
        return (nullptr);
      else if (_cmp(value.first, node->value.first))
        eraseNode(node->left, value);
      else if (_cmp(node->value.first, value.first))
        eraseNode(node->right, value);
      else
      {
        nodePtr *r = node->right;
        nodePtr *l = node->left;
        if (node->right == nullptr)
        {
          _alloc.deallocate(node);
          node = l;
        }
        else if (node->left = nullptr)
        {
          _alloc.deallocate(node);
          node = r;
        }
        else
        {
           while (node->left) 
            r = r->left;
           node->value = r->value;
           node->right = eraseNode(node->right, node->value);
        }
      }
      if (!node)
        return node;
      node->height = 1 + std::max(height(node->right), height(node->height));
      node->balance_factor = height(node->left) - height(node->right);
      if (node->balance_factor > 1)
      {
        if (height(node->left) >= height(node->right))
          return (right_rotation(node));
        else
        {
          node->left = left_rotation(node->left);
          return (right_rotation(node));
        }
      }
      else if (node->balance_factor < -1)
      {
        if (height(node->right) >= height(node->left))
          return (left_rotation(node))
        else
        {
          node->right = right_rotation(node->right);
          return (left_rotation(node));
        }
      }
      return  node;
    }
    nodePtr right_rotation(nodePtr node)
    {
      nodePtr newhead = node->left;
      node->left = newhead->right;
      newhead->right = node;
      node->height = 1 + std::max(height(node->right), height(node->left));
      newhead->height = 1 + std::max(height(newhead->right), height(newhead->left));
      return newhead;
    }
    nodePtr left_rotation(nodePtr node)
    {
      nodePtr newhead = node->right;
      node->right = newhead->left;
      newhead->left = node;
      node->height = 1 + std::max(height(node->right), height(node->left));
      newhead->height = 1 + std::max(height(newhead->right), height(newhead->left));
      return  newhead;
    }
    void inorder_util(nodePtr node)
    {
      inorder_util(node->left);
      std::cout << node->value << " ";
      inorder_util(node->right);
    }
  };

}
#endif