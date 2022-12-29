#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
namespace ft
{
  template <class T>
  struct Node
  {
    T value;
    Node *head;
    Node *left;
    Node *right;
    int   balance_factor;
    int   height;
    Node() : head(nullptr), left(nullptr), right(nullptr)
    {} 
    Node(const T& value) : value(value)
    {}
    Node(const T& value, const int& height) : value(value), head(nullptr), left(nullptr), right(nullptr), balance_factor(0)
    , height(height)
    {}
  };
}
#endif