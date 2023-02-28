#ifndef TRAITS_HPP
#define TRAITS_HPP

namespace ft
{
  template <bool, class T = void>
  struct enable_if
  {};

  template <class T>
  struct enable_if<true, T>
  {
    typedef T type;
  };

template <class T, T v>
struct integral_constant
{
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T, v> type;
  operator value_type() { return value;}
};
template <class T, T v>
const T integral_constant<T, v>::value;
typedef integral_constant<bool , true> true_type;
typedef integral_constant<bool, false> false_type;

template<class T, class U>
struct is_same : public false_type {};
template<class T>
struct is_same<T, T> : public true_type{};

template <class T>
struct is_integral_impl : public false_type {};
template <>
struct is_integral_impl<bool> : public true_type {};
template <>
struct is_integral_impl<char> : public true_type {};
template <>
struct is_integral_impl<unsigned char> : public true_type {};
template <>
struct is_integral_impl<signed char> : public true_type {};
template <>
struct is_integral_impl<short> : public true_type {};
template <>
struct is_integral_impl<unsigned short> : public true_type {};
template <>
struct is_integral_impl<int> : public true_type {};
template <>
struct is_integral_impl<unsigned int> : public true_type {};
template <>
struct is_integral_impl<long> : public true_type {};
template <>
struct is_integral_impl<unsigned long> : public true_type {};
template <>
struct is_integral_impl<long long> : public true_type {};
template <>
struct is_integral_impl<unsigned long long> : public true_type {};

template<class T>
struct is_integral : is_integral_impl<T> {};

}
#endif