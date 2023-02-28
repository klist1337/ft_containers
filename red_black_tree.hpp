#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
#include <iostream>
namespace ft
{
	template <class T>
		struct RB_node
		{
			T value;
			RB_node *parent;
			RB_node *left;
			RB_node *right;
			std::string color;

			RB_node() : parent(nullptr), left(nullptr), right(nullptr), color(nullptr)
			{}
			RB_node(const T& value) : value(value)
			{}
			RB_node(const T& value, const std::string& color) : value(value), parent(nullptr), left(nullptr), right(nullptr), color(color)
			{}
		};

	//Red Black Tree
	template<class Key, class Compare, class Alloc>
		class RBTree
		{
			public:
				typedef Key key_type;
				typedef Compare key_compare;
				typedef RB_node<key_type>* nodePtr;
				typedef typename Alloc::template rebind<RB_node<key_type> >::other allocator_type;
				typedef typename allocator_type::size_type size_type;

			private:
				nodePtr _root;
				nodePtr _end;
				allocator_type _alloc;
				key_compare _cmp;
				size_type _size;

			public:
				RBTree(const allocator_type& alloc = allocator_type(), const key_compare cmp = key_compare()) :
					_root(nullptr), _end(nullptr), _alloc(alloc), _cmp(cmp), _size(0)
			{
				_end = _alloc.allocate(1);
				_alloc.construct(_end, key_type());
			}
				~RBTree()
				{
					clear();
					_alloc.deallocate(_end, 1);
					_end = nullptr;
				}
				nodePtr getRoot() const
				{
					return (_root);
				}
				allocator_type get_allocator() const { return this->_alloc;}
				size_type size() const { return _size;}
				size_type max_size() const { return _alloc.max_size();}
				nodePtr Get_end() const { return nullptr;}
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
					return (node);
				}
				nodePtr Get_max(nodePtr node = nullptr) const
				{
					if (!node)
						node = _root;
					while (node && node->right)
					{
						node = node->right;
					}
					return (node);
				}
				nodePtr lowerbound(const key_type& key) const
				{
					nodePtr node = _root;
					nodePtr r = nullptr;
					while (node)
					{
						if (!_cmp(node->value, key))
						{
							r = node;
							node = node->left;
						}
						else
							node = node->right;
					}
					return (r);
				}
				nodePtr upperbound(const key_type& key) const
				{
					nodePtr node = _root;
					nodePtr r = nullptr;
					while (node)
					{
						if (_cmp(key, node->value))
						{
							r = node;
							node = node->left;
						}
						else
							node = node->right;
					}
					return (r);
				}
				size_type count (const key_type& key) const
				{
					nodePtr node = _root;
					while (node)
					{
						if (_cmp(key, node->value))
							node = node->left;
						else if (_cmp(node->value, key))
							node = node->right;
						else
							return 1;
					}
					return 0;
				}
				void swap(RBTree& tree)
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
				nodePtr find(const key_type& key)
				{
					return find(_root, key);
				}
				nodePtr find(nodePtr& node, const key_type& key)
				{
					if (!node)
						return (nullptr);
					if (node->value == key)
						return (node);
					if (_cmp(node->value, key))
						return (find(node->right, key));
					return (find(node->left, key));
				}
				
				void insert(const key_type& key)
				{
					insertNode(_end, _root, key);
					_end->left = _root;
					_root->parent = nullptr;
				}
				void insertNode(nodePtr &parent, nodePtr &node, const key_type& key)
				{
					static_cast<void>(parent);
					if (node == nullptr)
					{
						_root = _alloc.allocate(1);
						_alloc.construct(_root, key);
						_root->left = nullptr;
						_root->right = nullptr;
						_root->color = "BLACK";
						_size++;
					}
					else
					{
						nodePtr linker = getRoot();
						nodePtr newnode = _alloc.allocate(1);
						_alloc.construct(newnode, key);
						newnode->left = nullptr;
						newnode->right = nullptr;
						while (linker != nullptr)
						{
							if (_cmp(key, linker->value))
							{
								if (linker->left == nullptr)
								{
									linker->left = newnode;
									newnode->color = "RED";
									newnode->parent = linker;
									_size++;
									break;
								}
								else
									linker = linker->left;
							}
							else
							{
								if (linker->right == nullptr)
								{
									linker->right = newnode;
									newnode->color = "RED";
									newnode->parent = linker;
									_size++;
									break;
								}
								else
									linker = linker->right;
							}
						}
						insertFix(newnode);
					}
				}
				// bool _tree_is_left_child(nodePtr x)
				// {
				// 		return x == x->parent->left;
				// }
				// void _tree_remove(nodePtr root, nodePtr z)
				// {
				// 	if (!z)
				// 		return ;
				// 	nodePtr y = (z->left == nullptr || z->right == nullptr) ? z : successor(z);
				// 	nodePtr x = y->left != nullptr ? y->left : y->right;
				// 	nodePtr uncle = nullptr;
					
				// 	if (x != nullptr)
				// 		x->parent = y->parent;
				// 	if (_tree_is_left_child(y))
				// 	{
				// 		y->parent->left = x;
				// 		if (y != root)
				// 			uncle = y->parent->right;
				// 		else
				// 			root = x;
				// 	}
				// 	else
				// 	{
				// 		y->parent->right = x;
				// 		uncle = y->parent->left;
				// 	}
				// 	std::string removed_black = y->color;
				// 	if (y != z)
				// 	{
				// 		if (z->parent)
				// 		{
				// 			y->parent = z->parent;
				// 			if (_tree_is_left_child(z))
				// 				y->parent->left = y;
				// 			else
				// 				y->parent->right = y;
				// 			y->left = z->left;
				// 			y->parent->left = y;
				// 			y->right = z->right;
				// 			if (y->right != nullptr)
				// 				y->right->parent = y;
				// 			y->color = z->color;
				// 			if (root == z)
				// 				root = y;
				// 		}
				// 	}
				// 	if (y->color == "RED" && root != nullptr)
				// 	{
				// 		// if (x == root || x != nullptr && x->color == "RED")
				// 		if (x != nullptr)
				// 			x->color = "BLACK";
				// 		else
				// 		{
				// 			while (true)
				// 			{
				// 				if (!_tree_is_left_child(uncle))
				// 				{
				// 					if (uncle->color == "RED")
				// 					{
				// 						uncle->color = "BLACK";
				// 						uncle->parent->color = "BLACK";
				// 						right_rotate(uncle->parent);
				// 						if (root == uncle->left)
				// 							root = uncle;
				// 						if (uncle && uncle->left && uncle->left->right)
				// 							uncle = uncle->left->right;
				// 					}
				// 					if ((uncle->left == nullptr || uncle->left->color == "BLACK") &&
				// 							(uncle->right == nullptr || uncle->right->color == "BLACK"))
				// 					{
				// 						uncle->color = "RED";
				// 						x = uncle->parent;
				// 						if ( x == root || x->color == "RED")
				// 						{
				// 							x->color = "BLACK";
				// 							break;
				// 						}
				// 						uncle = _tree_is_left_child(x) ? x->parent->right : x->parent->left;
				// 					}
				// 					else
				// 					{
				// 						if (uncle->right == nullptr || uncle->right->color == "BLACK")
				// 						{
				// 							uncle->left->color = "BLACK";
				// 							uncle->color = "RED";
				// 							right_rotate(uncle);
				// 						}
				// 						uncle->color = uncle->parent->color;
				// 						uncle->parent->color = "BLACK";
				// 						uncle->right->color = "BLACK";
				// 						break;
				// 					}
				// 				}
				// 				else
				// 				{
				// 					if (uncle->color == "RED")
				// 					{
				// 						uncle->color = "BLACK";
				// 						uncle->parent->color = "RED";
				// 						right_rotate(uncle->parent);
				// 						if (root == uncle->right)
				// 								root = uncle;
				// 						uncle = uncle->right->left;
				// 					}
				// 					if ((uncle->left == nullptr || uncle->left->color == "BLACK") && 
				// 							(uncle->right == nullptr || uncle->right->color == "BLACK"))
				// 						{
				// 							uncle->color = "RED";
				// 							x = uncle->parent;
				// 							if (x->color == "RED" || x == root)
				// 							{
				// 								x->color = "BLACK";
				// 								break;
				// 							}
				// 							uncle = _tree_is_left_child(x) ? x->parent->right : x->parent->left;
				// 						}
				// 						else
				// 						{
				// 							if (uncle->left == nullptr || uncle->left->color == "BLACK")
				// 							{
				// 								uncle->right->color = "BLACK";
				// 								uncle->color = "RED";
				// 								left_rotate(uncle);
				// 								uncle  = uncle->parent;
				// 							}
				// 							uncle->color = uncle->parent->color;
				// 							uncle->parent->color = "BLACK";
				// 							uncle->left->color = "BLACK";
				// 							right_rotate(uncle->parent);
				// 							break;
				// 						}
				// 				}
				// 			}
				// 		}
				// 	}
				// }
				void erase(const key_type &key)
				{
					eraseNode(_end->left, _root, key);
					_end->left = _root;
					if (_root)
						_root->parent = nullptr;
				}
				void eraseNode(nodePtr &parent ,nodePtr &node, const key_type &key)
				{
					nodePtr curr = node;
				  while (curr->left != nullptr ||  curr->right != nullptr)
				  {
				    if (curr->value == key)
				      break;
				    if (_cmp(key, curr->value))
				      curr = curr->left;
				    else
				      curr = curr->right;
				  }
				  if (curr->value != key)
				    return ;
				  removeNode(curr);
					parent = curr;
				  _size--;
				}
				void removeNode(nodePtr &node)
				{
				  if (node->color == "RED")
				  {
				    if (node->left != nullptr && node->left != nullptr)
				    {
				      nodePtr successor = node->right;
				      while (successor->left)
				        successor = successor->left;
				      node->value = successor->value;
				      removeNode(successor);
				    }
				    else if (node->left != nullptr)
				    {
				      node->value = node->left->value;
				      node->color = node->left->color;
				      removeNode(node->left);
				    }
				    else if (node->right != nullptr)
				    {
				      node->value = node->right->value;
				      node->color = node->right->color;
				      removeNode(node->right);
				    }
				    else
				    {
				      if (node == _root)
				      {
				        _alloc.deallocate(node, 1);
				        _root = nullptr;
				        return ;
				      }
				      if (node->parent->left == node)
				        node->parent->left = nullptr;
				      else
				        node->parent->right = nullptr;
							//_alloc.destroy(node);
				      _alloc.deallocate(node, 1);
							//node = nullptr;
				    }
				  }
				  else
				  {
				    if (node->left != nullptr && node->right != nullptr)
				    {
				      nodePtr successor = node->right;
				      while (successor->left)
				        successor = successor->left;
				      node->value = successor->value;
				      removeNode(successor);
							successor = nullptr;
				    }
				    else if (node->left != nullptr)
				    {
				      node->value = node->left->value;
				      removeNode(node->left);
				    }
				    else if (node->right != nullptr)
				    {
				      node->value = node->right->value;
				      removeNode(node->right);
				    }
				    else
				    {
				      if (node->parent == nullptr)
				      {
				        _alloc.deallocate(node, 1);
				        _root = nullptr;
				        return ;
				      }
				      if (node->parent->left == node)
				      {
				        node->parent->left = nullptr;
				        if (node && node->parent->right && node->parent->right->color == "RED")
				        {
				          node->parent->right->color = "BLACK";
				          left_rotate(node->parent);
				        }
				      }
				      else
				      {
				        node->parent->right = nullptr;
				        if (node && node->parent && node->parent->left && node->parent->left->color == "RED")
				        {
				          node->parent->left->color = "BLACK";
				          right_rotate(node->parent);
				        }
				      }
				      if (node && node->parent && node->parent->left == nullptr && node->parent->right == nullptr
				          && node->parent->parent != nullptr)
				      {
				        right_rotate(node->parent->parent);
				      }
							_alloc.deallocate(node, 1);
				    }
				  }
				}
				void insertFix(nodePtr &node)
				{
					nodePtr uncle;
					nodePtr grandparent;
					while (node->parent->color == "RED")
					{
						grandparent = node->parent->parent;
						uncle = getRoot();
						if (node->parent == grandparent->left)
						{
							if (grandparent->right)
								uncle = grandparent->right;
							if (uncle->color == "RED")
							{
								node->parent->color = "BLACK";
								uncle->color = "BLACK";
								grandparent->color = "RED";
								if (grandparent->value != _root->value)
									node = grandparent;
								else
									break;
							}
							else if  (node == grandparent->left->right)
								left_rotation(node->parent);
							else
							{
								node->parent->color = "BLACK";
								grandparent->color = "RED";
								right_rotation(grandparent);
								if (grandparent->value != _root->value)
									node = grandparent;
								else
									break;
							}
						}
						else
						{
							if (grandparent->left)
								uncle = grandparent->left;
							if (uncle->color == "RED")
							{
								node->parent->color = "BLACK";
								uncle->color = "BLACK";
								grandparent->color = "RED";
								if (grandparent->value != _root->value)
									node = grandparent;
								else
									break;
							}
							else if (node == grandparent->right->left)
								right_rotation(node->parent);
							else
							{  
								node->parent->color = "BLACK";
								grandparent->color = "RED";
								left_rotation(grandparent);
								if (grandparent->value != _root->value)
									node = grandparent;
								else
									break;
							}
						}
					}
					_root->color = "BLACK";
				}

				void printHelper(nodePtr root, std::string indent, bool last)
				{
					if (root != nullptr)
					{
						std::cout << indent;
						if (last)
						{
							std::cout << "R----";
							indent += "   ";
						}
						else
						{
							std::cout << "L----";
							indent += "|  ";
						}
						std::cout << root->value << "(" << root->color << ")" << std::endl;
						printHelper(root->left, indent, false);
						printHelper(root->right, indent, true);
					}
				}
				void printTree()
				{
					if (_root)
						printHelper(_root, "", true);
				}
				void right_rotate(nodePtr node)
				{
					nodePtr temp = nullptr;
					if (node->left)
					{
						temp = node->left;
						node->left = temp->right;
					}
					if (temp && temp->right)
					{
						temp->right->parent = node;
						temp->right = node;
					}
					if (temp)
						temp->parent = node->parent;
					node->parent = temp;
					if (_root == node)
					{
						_root = temp;
						return ;
					}
					if (temp && temp->parent->left == node)
						temp->parent->left = temp;
					else if (temp && temp->parent->right == node)
						temp->parent->right = temp;
				}
				void left_rotate(nodePtr node)
				{
					nodePtr temp = nullptr;
					if (node->right != nullptr)
					{
						temp = node->right;
						node->right = temp->left;
					}
					if (temp && temp->left)
					{
						temp->left->parent = node;
						temp->left = node;
					}
					if (temp)
						temp->parent = node->parent;
					node->parent = temp;
					if (_root == node)
					{
						_root = temp;
						return ;
					}
					if (temp && temp->parent->left == node)
						temp->parent->left = temp;
					else if (temp && temp->parent->right == node)
						temp->parent->right = temp;
				}
				void left_rotation(nodePtr &x)
				{
					nodePtr newnode = _alloc.allocate(1);
					newnode->left = nullptr;
					newnode->right = nullptr; 
					if (x->right && x->right->left)
						newnode->right = x->right->left;
					newnode->left = x->left;
					_alloc.construct(newnode, x->value);
					newnode->color = x->color;
					x->value = x->right->value;
					x->color = x->right->color;
					x->left = newnode;
					if (newnode->left)
						newnode->left->parent = newnode;
					if (newnode->right)
						newnode->right->parent = newnode;
					newnode->parent = x;
					if (x->right && x->right->right)
						x->right = x->right->right;
					else
						x->right = nullptr;
					if (x->right)
						x->right->parent = x;
				}
					void right_rotation(nodePtr &x)
					{
						nodePtr newnode = _alloc.allocate(1);
						newnode->left = nullptr;
						newnode->right = nullptr;
						if (x->left && x->left->right)
							newnode->left = x->left->right;
						newnode->right = x->right;
						_alloc.construct(newnode, x->value);
						newnode->color = x->color;
						if (x->left)
						{
							x->value = x->left->value;
							x->color = x->left->color;
						}
						x->right = newnode;
						if (newnode->left)
							newnode->left->parent = newnode;
						if (newnode->right)
							newnode->right->parent = newnode;
						newnode->parent = x;
						if (x->left && x->left->left)
							x->left = x->left->left;
						else
							x->left = nullptr;
						if (x->left)
							x->left->parent = x;
					}
				void clear()
				{
					clear(_root);
					_size = 0;
				}
				void clear(nodePtr& node)
				{
					if (node)
					{
						clear(node->left);
						clear(node->right);
						_alloc.deallocate(node, 1);
						node = nullptr;
					}
				}
		};


}
#endif
