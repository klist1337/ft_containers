#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>

namespace ft
{
  template <class T, class Allocator = std::allocator<T> >
  class vector
  {
  private:
    /* data */
  public:
    //member types
    typedef T value_type;
    typedef Allocator allocator_type;

    typedef typename allocator_type::reference reference; // Providede reference to an element
    // stored in vector.

    typedef typename allocator_type::const_reference const_reference;
    // Provide a pointer to an element stored in the vector.
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename allocator_type::size_type size_type;

    // Construct/ Copy / Destroy 
    explicit vector(const Allocator& = Allocator());
    ~vector();
  };

  
}
#endif