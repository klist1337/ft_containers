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
}
#endif