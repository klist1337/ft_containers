#include <memory>
#include <iostream>
#include <vector>
#include "vector.hpp"
#include <map>
#include "pair.hpp"
#include "map.hpp"

void print_container(ft::vector<int>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (ft::vector<int>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}
void print_container(ft::vector<char>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (ft::vector<char>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}
void print_container(std::vector<char>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (std::vector<char>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}
void print_container(ft::vector<std::string>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (ft::vector<std::string>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}
void print_container(std::vector<std::string>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (std::vector<std::string>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void print_container(std::vector<int>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (unsigned long i = 0; i < c.size() ; i++)
    std::cout << c[i] << " ";
  std::cout << std::endl;
}
// int main()
// {
//   // int *a;  
//   // std::allocator<int> alloc;

//   // a = alloc.allocate(2);
//   // alloc.construct(&a[0], 2);
//   // alloc.construct(&a[1], 3);
//   // for (int i = 0; i < 2; i++)
//   //   std::cout << a[i] << std::endl;
//   // alloc.destroy(&a[0]);
//   // alloc.deallocate(a, 2);
//   // for (int i = 0; i < 2; i++)
//   //   std::cout << a[i] << std::endl;
//   // system ("leaks vector");
//  ft::vector<int> c(4, 100);
//  ft::vector<int> d(6);
//  ft::vector<int> v(4, 100);
//  ft::vector<int>::iterator it;
//  ft::vector<int> l;
//   l = c;
//   if (d != v)
//     std::cout << "v superieur à d " << std::endl;
//   ft::swap(d, v);
//    if (v >= d)
//      std::cout << "d superieur à v " << std::endl;
//   print_container(d);
//   std::cout << "-----" << std::endl;
//   print_container(v);
//   std::cout << "-----" << std::endl;
//   d.insert(d.begin() + 2, v.begin(), v.end());
//   //d.insert(d.begin() + 2, 5);
//   std::cout << "d.capacity = " << d.capacity() << std::endl; 
//   print_container(d);
//   std::cout << "l container" << std::endl;
//   print_container(l);
//   v.push_back(6);
//   v.push_back(9);
//   v.push_back(11);
//   //c.swap(v);
//   v.resize(5, 6);
//   // v.push_back(10);
//   //it = v.erase(v.begin() + 2, v.begin() + 5);
//   //v.insert(v.begin() + 3, 4);
//   //c.assign(v.begin(), v.end());
//   //std::cout << v.max_size() << std::endl;
//   // int i = 4;
//   // while (--i >= 0)
//   //   c.pop_back();
//   // c.pop_back();
//   print_container(v);
//   std::cout << "c.capacity = " << c.capacity() << std::endl; 
//   std::cout << "v.capacity = "  << v.capacity()
//    << " && v.size = " << v.size() <<  std::endl; 
//   //print_container(v);
//   std::cout << "c container " << std::endl;
//   print_container(c);
//   //v.clear();
//   //print_container(v);
//   //system("leaks vector");
// }
  struct CityRecord
  {
    std::string Name;
    uint64_t Population;
    double Latitude, Longititude;
  };
int main()
{
  // ft::vector<char> v;
  // ft::vector<char> b(6, 'b');

  // // v.assign(0, 'c');
  // // std::cout << v.capacity() << std::endl;
  // // std::cout << v.size() << std::endl;
  // // print_container(v);

  // // v.assign(64, 'A');
  // // std::cout << v.capacity() << std::endl;
  // // std::cout << v.size() << std::endl;
  // // print_container(v);
  // v.assign(b.begin(), b.end());
  // std::cout << v.capacity() << std::endl;
  // std::cout << v.size() << std::endl;
  // print_container(v);
  // ft::vector<std::string>::iterator it;
  // v.reserve(100);
  // v.insert(v.begin() + 15, 70,  "hello");

  ft::pair<int, std::string> P(2, "geeks");
  //std::cout << P.first;
  ft::map<std::string, int> m, n;
  m.insert(ft::pair<const std::string, int>("hello", 3));
  m.insert(ft::pair<const std::string, int>("salut", 1));
  ft::map<std::string, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++)
  {
    std::cout << "first = " << it->first << " "
    << "second = " << it->second;
  }
  // std::cout << v.capacity() << std::endl;
  // std::cout << v.size() << std::endl;
  // print_container(v);
//   std::map<std::string, CityRecord>  cityMap;
//   cityMap["Melbourne"] = CityRecord { "Melbourne", 50000000, 2.4, 9.4};
//   cityMap["Abidjan"] = CityRecord { "Abidjan", 50000000, 2.4, 9.4};
//   cityMap["Paris"] = CityRecord {"Pari`s", 50000000, 2.4, 9.4};
//   cityMap["Moscow"] = CityRecord {"Moscow", 50000000, 2.4, 9.4};
//   cityMap["Vienne"] = CityRecord {"Vienne", 50000000, 2.4, 9.4};

//   CityRecord& berlinData = cityMap["Abidjan"];
//   std::cout << berlinData.Population << std::endl;
}