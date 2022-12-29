#include <iostream>
#include <utility>

template<typename T>
class BST
{
  public :
    class node
    {
    public:
    T key;
    node *left;
    node *right;
    node(T k)
    {
      key = k;
      left = NULL;
      right = NULL;
    }
    };
  node *root;
  int n;
  BST(): root(NULL), n(0) 
  {}
  void  insert(T x)
  {
    root = insertUtil(root , x);
  }
  void remove (T x)
  {
    root = removeUtil(root, x);
  }
  node* search(T x)
  {
    return searchUtil(root, x);
  }
  void inorder()
  {
    inorderUtil(root);
    std::cout << std::endl;
  }
  private:
    void inorderUtil(node *head)
    {
      if (head == NULL) return ;
      inorderUtil(head->left);
      std::cout << head->key << " ";
      inorderUtil(head->right);
    }
    node *insertUtil(node* head, T x)
    {
      if (head == NULL)
      {
        n++;
        node *temp = new node(x);
        return temp;
      }
      if (x > head->key) head->right = insertUtil(head->right, x);
      else if (x < head->key) head->left = insertUtil(head->left, x);
      return (head);
    }
    node *searchUtil(node *head, T x)
    {
      if (head == NULL) return NULL;
      T k = head->key;
      if (x == k) return head;
      if (x > k)  return searchUtil(head->right, x);
      if (x < k)  return searchUtil(head->left, x);
    }
    node *removeUtil(node *head, T x)
    {
      if (head == NULL) return NULL;
      if (x == head->key)
      {
        node *l = head->left;
        node *r = head->right;
        if (l == NULL)
        {
          delete (head);
          return r;
        }
        if (r == NULL)
        {
          delete (head);
          return l;   
        }
        while (r->left != NULL) r = r->left;
        head->key = r->key;
        head->right = removeUtil(head->right, r->key);
        return head;
      }
      if (x < head->key) head->left = removeUtil(head->left, x);
      else head->right = removeUtil(head->right, x);
      return head;
    }
};

int main()
{
  // BST<float> t;
  // t.insert(4.1);
  // t.insert(2.3);
  // t.insert(1.5);
  // t.insert(3.7);
  // t.insert(6.5);
  // t.insert(5.4);
  // t.insert(7.2);
  // t.inorder();
  // t.remove(2.3);
  // t.inorder();
  std::pair<int, std::string> Pair(2, "Geeks");
  std::cout << Pair.first << std::endl;
  std::cout << Pair.second ;
}