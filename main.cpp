#include <memory>
#include <iostream>
#include <vector>
#include "vector.hpp"
#include <map>
#include <set>
#include "pair.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "set.hpp"

template<class U>
void print_container(ft::vector<U>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (typename ft::vector<U>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}
template<class U>
void print_container(std::vector<U>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (typename std::vector<U>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}
 
template<class U, class V>
void print_map(ft::map<U, V> & c)
{
   if (c.empty())
    throw std::exception();
  for (typename ft::map<U, V>::iterator it = c.begin(); it != c.end(); it++)
  {
    std::cout << " first =  "<<  it->first << " ------- "
    << " second = "  << it->second;
  }
}
template<class U, class V>
void print_map(std::map<U, V> & c)
{
  if (c.empty())
    throw std::exception();
  for (typename std::map<U, V>::iterator it = c.begin(); it != c.end(); it++)
  {
    std::cout << " first =  "<<  it->first << " ------"
    << " second = "  << it->second;
  }
}
template <class U>
void print_container(ft::set<U>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (typename ft::set<U>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}
template <class U>
void print_container(std::set<U>& c)
{
  if (c.empty())
    std::cout << "container is empty" << std::endl;
  for (typename std::set<U>::iterator it = c.begin(); it != c.end() ; it++)
    std::cout << *it << " ";
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

// int main()
// {
//   ft::vector<std::string> v;
//   std::vector<std::string> s;

//   ft::vector<std::string>::iterator it = v.insert(v.end(), "salut");
//   it = v.insert(v.end() , "hello");
//   it = v.insert(v.begin(), "hi");
//   print_container(v);
// }
  // struct CityRecord
  // {
  //   std::string Name;
  //   uint64_t Population;
  //   double Latitude, Longititude;
  // };
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
  // std::cout << "my ft::map" << std::endl;
  // std::cout << "----------------" <<std::endl;
  // ft::pair<int, std::string> P(2, "geeks");
  //std::cout << P.first;
  ft::map<std::string, int> m, e;
  m["goku"] = 15000;
  m["vegeta"] = 10000;
  m["gohan"] = 9000;
  m["piccolo"] = 8000;
  print_map(m);
  std::cout << std::endl;
  ft::map<std::string, int>::iterator iter;
  iter = m.erase(m.begin());
  std::cout << "iter->first =  " << iter->first << std::endl;
  try
  {
    print_map(m);
  }
  catch (const std::exception& e)
  {
    std::cout << "empty container" << std::endl;
  }
  std::cout << std::endl;
  std::cout << "-----------" << std::endl;
  std::cout << std::endl;
  // ft::pair<ft::map<std::string, int>::const_iterator, ft::map<std::string, int>::const_iterator> pr;
  // pr = m.equal_range("vegeta");
  // for (ft::map<std::string, int>::const_iterator it = pr.first; it != pr.second; ++it)
  //   std::cout << it->first << "  ----  " << it->second ;
  iter = m.lower_bound("pic"); 
  for (; iter != m.end(); ++iter)
    std::cout << iter->first << "  ----  " << iter->second << " ";
  ft::vector<int> vec(3, 2);
  ft::stack<int> s(vec);
  while (!s.empty())
  {
    std::cout << s.top() << std::endl;
    s.pop();
  }
  s.push(5);
  s.push(6);
  while (!s.empty())
  {
    std::cout << s.top() << std::endl;
    s.pop();
  }
  // ft::map<std::string, int>::iterator itero = m.find("goku");
  // std::cout << itero->first << " ---- " << itero->second;
  // ft::map<std::string, int>::const_iterator iteri = m.find("vegeta");
  // std::cout << iteri->first << " ---- " << iteri->second;
  // e["freezer"] = 2500;
  // e["cell"] = 4000;
  // e["buu"] = 5000;
  // m.swap(e);
  // print_map(e);
  // std::cout << std::endl;
  // std::cout << "---------" << std::endl;
  // print_map(m);
  // std::cout << std::endl;
  // std::cout << "---------" << std::endl;
  // std::cout << "count = " << m.count("cell") << std::endl;
  //----------------------------------------------//
  // m.insert(ft::pair<std::string, int>("hello", 3));
  // m.insert(ft::pair<std::string, int>("merci", 0));
  // m.insert(ft::pair<std::string, int>("salut", 1));
  // ft::map<std::string, int>::iterator it;
  // //m.erase(ft::pair<const std::string, int>("hello", 3));
  // //m.erase(ft::pair<const std::string, int>("salut", 1));
  // ft::map<std::string, int> n(m.begin(), m.end());
  // for (it = m.begin(); it != m.end(); it++)
  // {
  //   std::cout << " first = " << it->first << " ---- "
  //   << " second = " << it->second;
  // }
  // std::cout << std::endl;
  // std::cout << m.at("hello") << std::endl;
  // m["hi"] = 15;
  // std::cout << m["salut"] << std::endl;
  // print_map(m);
  // std::cout << std::endl;
  // std::cout << "---------- " << std::endl;
  // print_map(n);
  // std::cout << std::endl;
  // std::cout << m.empty() << std::endl;
  // std::cout << "m.size = " << m.size() << std::endl;
  // std::cout <<"m.max_size = " << m.max_size() << std::endl;
  // m.clear();
  // try 
  // {
  //   print_map(m);
  // }
  // catch(const std::exception &c)
  // {
  //   std::cout << "the map is empty" << std::endl;
  // }
  // std::cout << "m.size = " <<  m.size() << std::endl;
  // m["hi"] = 3;
  // m["bonjour"] = 0;
  // m["new"] = -1;
  // print_map(m);
  // std::cout << std::endl;
  // ft::map<std::string, int> miP(m);
  // ft::map<std::string, int> niP, tiP;
  // print_map(miP);
  // std::cout << std::endl;
  // niP = m;
  // print_map(niP);
  // std::cout << std::endl;
  // niP["goku"] = 500;
  // niP["vegeta"] = 450;
  // tiP.insert(niP.begin(), niP.end());
  // tiP.insert(tiP.begin(), ft::pair<std::string, int>("freezer", 500));
  // print_map(tiP);
  // tiP.erase(tiP.begin());
  // std::cout << std::endl;
  // print_map(tiP);
  // std::cout << std::endl;
  // tiP.erase(tiP.begin(), tiP.end());
  // std::cout << std::endl;
  // try 
  // {
  //   print_map(tiP);
  // }
  // catch(std::exception &c)
  // {
  //   std::cout << "the map is empty" << std::endl;
  // }
  // std::cout << "-----------------------" << std::endl;
  // std::cout << "-----------------------" << std::endl;
  // niP.swap(m);
  // print_map(niP);
  // std::cout << "-----------------------" << std::endl;
  // print_map(m);
  //-----------------------------------//
  // Section std::map //
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "STD::map" << std::endl;
  std::map<std::string, int> mprime, eprime;
  mprime["goku"] = 15000;
  mprime["vegeta"] = 10000;
  mprime["gohan"] = 9000;
  mprime["piccolo"] = 8000;
  std::map<std::string, int>::iterator ity;
  print_map(mprime);
  std::cout << std::endl;
  std::map<std::string, int>::const_iterator mbegin = mprime.begin();
  ity = mprime.erase(mbegin);
  std::cout << "iterator ity->first = " << ity->first << std::endl;
  print_map(mprime);
  std::cout << std::endl;
  std::cout << "-----------" << std::endl;
  std::cout << std::endl;
  std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> p;
  //p = mprime.equal_range("goku");
  // for (std::map<std::string, int>::iterator it = p.first; it != p.second; ++it)
  //   std::cout << it->first << "  ----  " << it->second;
  std::map<std::string, int>::const_iterator it;
  it = mprime.lower_bound("pic");
  for (; it != mprime.end(); ++it)
    std::cout << it->first << "  ----  " << it->second << " ";
  std::set<int> s1;
  s1.insert(1);
  s1.insert(2);
  s1.insert(4);
  s1.insert(15);
  s1.insert(9);
  std::set<int>::iterator ite;
  // std::set<int>::const_iterator begin = s1.begin();
  // std::set<int>::const_iterator end = s1.end();
  for (ite = s1.begin(); ite != s1.end(); ++ite)
    std::cout << *ite << std::endl;
  std::cout << s1.max_size() << std::endl;
  ite = s1.insert(s1.begin(), 42);
  print_container(s1);
  //ite = s1.erase(s1.begin());
  //ite = s1.erase(begin, end);
  //std::cout << "ite = "<< *ite << std::endl;
  //print_container(s1);
  std::pair<std::set<int>::iterator, std::set<int>::iterator> eq;
  eq = s1.equal_range(15);
  ite = s1.upper_bound(9);
  for (; ite != s1.end(); ++ite)
    std::cout << "*ite = " << *ite << std::endl;
  for (std::set<int>::iterator it = eq.first; it != eq.second; ++it)
    std::cout << "it == " << *it << std::endl;
  
  
  std::cout << "--------------" << std::endl;
  std::cout << "my set::container" << std::endl;
  std::cout << "--------------" << std::endl;
  ft::set<int> s2, swp;
  ft::set<int>::iterator itra;

  s2.insert(15);
  s2.insert(13);
  s2.insert(1);
  s2.insert(2);
  s2.insert(0);
  s2.insert(30);
  s2.insert(25);
  // s2.insert(25);
  //s2.insert(s2.begin(), 42);
  // ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> eql;
  // eql = s2.equal_range(0);
  // itra = s2.upper_bound(13);
  // for (; itra != s2.end(); ++itra)
  //   std::cout << "*itra = " << *itra << std::endl;
  // for (ft::set<int>::iterator it = eql.first; it != eql.second; ++it)
  //   std::cout << "it == " << *it << std::endl;
  // swp.insert(4);
  // swp.insert(16);
  // swp.insert(3);
  // //s2.swap(swp);
  // //std::cout << "itra = " << *itra << std::endl;
  // std::cout << "size = " << s2.size() << std::endl;

    // s2.erase(1);
    // s2.erase(13);
    // s2.erase(0);
    // s2.erase(2);
    // s2.erase(30);
    // s2.erase(15);
    // s2.erase(25);
  // s2.erase(42);
  // itra = s2.begin();
  // std::cout << "itra = "<< *itra << std::endl;
  // s2.erase(s2.begin()÷);
  // s2.erase(s2.begin());
  // s2.erase(s2.begin());
  // s2.erase(s2.begin());
  // s2.erase(s2.begin());
  // s2.erase(s2.begin());
  // s2.erase(s2.begin());
  //print_container(s2);
  s2.erase(s2.begin(), s2.end());
  print_container(s2);
  // ft::set<int> ft_m1;
  // for (size_t i = 0; i < 1e6; i++)
  // {
  //     ft_m1.insert(i);
  // }

  //std::cout << "set::container swp" << std::endl;
  //print_container(swp);
  std::cout << "size = " << s2.size() << std::endl;
  s2.printTree();
  std::cout << s2.max_size() << std::endl;
  // ft_m1.erase(ft_m1.begin(), ft_m1.end());
  // print_container(ft_m1);
  // std::map<std::string, int>::iterator it = mprime.find("goku");
  // std::cout << it->first << "  ----  " << it->second;
  // std::map<std::string, int>::const_iterator iter =  mprime.find("vegeta");
  // std::cout << iter->first << "  ----  " << iter->second;

  // eprime["freezer"] = 2500;
  // eprime["cell"] = 4000;
  // eprime["buu"] = 5000;
  // mprime.swap(eprime);
  // print_map(eprime);
  // std::cout << std::endl;
  // std::cout << "---------" << std::endl;
  // print_map(mprime);
  // std::cout << std::endl;
  // std::cout << "---------" << std::endl;
  // std::cout << "count = " << mprime.count("cell") << std::endl;
  //--------------------------------------//
  // mep.insert(std::pair<std::string, int>("hello", 3));
  // mep.insert(std::pair<std::string, int>("merci", 0));
  // mep.insert(std::pair<std::string, int>("salut", 1));
  // std::map<std::string, int>::iterator iter;
  // std::cout << "----------------" <<std::endl;
  // std::map<std::string, int> nep(mep.begin(), mep.end());
  // for (iter = mep.begin(); iter != mep.end(); iter++)
  // {
  //   std::cout << " first = " << iter->first << " ---- "
  //   << " second = " << iter->second;
  // }
  // std::cout << std::endl;
  // std::cout << mep.at("hello") << std::endl;
  // mep["hi"] = 15;
  // std::cout << mep["salut"] << std::endl;
  // print_map(mep);
  // std::cout << std::endl;
  // std::cout << "---------- " << std::endl;
  // print_map(nep);
  // std::cout << std::endl;
  // std::cout << mep.empty() << std::endl;
  // std::cout << "mep.size = " << mep.size() << std::endl;
  // std::cout <<"mep.max_size = " << mep.max_size() << std::endl;
  // mep.clear();
  // try 
  // {
  //   print_map(mep);
  // }
  // catch(const std::exception &c)
  // {
  //   std::cout << "the map is empty" << std::endl;
  // }
  // mep["hi"] = 3;
  // mep["bonjour"] = 0;
  // mep["new"] = -1;
  // print_map(mep);
  // std::cout << std::endl;
  // std::map<std::string, int> maP(mep);
  // std::map<std::string, int> na, tp;
  // print_map(maP);
  // std::cout << std::endl;
  // na = maP;
  // print_map(na);
  // std::cout << std::endl;
  // na["goku"] = 500;
  // na["vegeta"] = 450;
  // tp.insert(na.begin(), na.end());
  // tp.insert(tp.begin(), std::pair<std::string, int>("freezer", 500));
  // print_map(tp);
  // tp.erase(tp.begin());
  // print_map(tp);
  // std::cout << std::endl;
  // tp.erase(tp.begin(), tp.end());
  // std::cout << std::endl;
  // try 
  // {
  //   print_map(tp);
  // }
  // catch(std::exception &c)
  // {
  //   std::cout << "the map is empty" << std::endl;
  // }
  // std::cout << "-----------------------" << std::endl;
  // std::cout << "-----------------------" << std::endl;
  // na.swap(mep);
  // print_map(na);
  // std::cout << "-----------------------" << std::endl;
  // print_map(mep);

}

// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter); 
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }