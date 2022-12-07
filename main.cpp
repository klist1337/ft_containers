#include <memory>
#include <iostream>
#include <vector>
#include "vector.hpp"

void print_container(ft::vector<int>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (unsigned long i = 0; i < c.size() ; i++)
    std::cout << c[i] << " ";
}

void print_container(std::vector<int>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (unsigned long i = 0; i < c.size() ; i++)
    std::cout << c[i] << " ";
}
int main()
{
  // int *a;  
  // std::allocator<int> alloc;

  // a = alloc.allocate(2);
  // alloc.construct(&a[0], 2);
  // alloc.construct(&a[1], 3);
  // for (int i = 0; i < 2; i++)
  //   std::cout << a[i] << std::endl;
  // alloc.destroy(&a[0]);
  // alloc.deallocate(a, 2);
  // for (int i = 0; i < 2; i++)
  //   std::cout << a[i] << std::endl;
  // system ("leaks vector");
  ft::vector<int> v(6, 3);
  ft::vector<int> c(2, 100);
  ft::vector<int>::iterator it;
  print_container(v);

  //v.assign(5, 3);
  // v.push_back(6);
  // v.push_back(9);
  // v.push_back(10);
  //it = v.erase(v.begin() + 2, v.begin() + 5);
  v.insert(v.begin() + 3, c.begin(), c.end());
  std::cout << std::endl;
  //std::cout << *it << std::endl;
  print_container(v);
  //v.clear();
  std::cout << std::endl;
  //print_container(v);
}