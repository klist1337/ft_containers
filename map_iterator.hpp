#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft
{
  template<class T, class Nodeptr>
  class Mapiterator
  {
    typedef typename iterator_traits<T>::difference_type difference_type;
    typedef typename iterator_traits<T>::value_type value_type;
    typedef typename iterator_traits<T>::pointer pointer;
    typedef typename iterator_traits<T>::reference reference;
    typedef std::bidirectional_iterator_tag iterator_category

    private:
      Nodeptr node;
    public:
    Map_iterator() : node(nullptr) {};
    explicit 
  };
}
#endif