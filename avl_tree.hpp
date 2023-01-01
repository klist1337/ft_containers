#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
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
    nodePtr Get_end const(this->_end);
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
    nodePtr lowerBound(const value_type& value)
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
    nodePtr Upper_Bound(const value_type& value)
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

  };

}
#endif