#ifndef PAIR_HPP
#define PAIR_HPP
namespace ft
{
  template <class T1, class T2>
  struct pair
  {
    typedef T1 first_type;
    typedef T2 second_type;
    
     first_type first;
     second_type second;
     ///ctor, cpy ctor, assignment operator
     pair() : first(), second()
     {}
     pair(const T1& _a, const T2& _b) : first(_a), second(_b)
     {}
     template<class U1, class U2>
     pair(const pair<U1, U2>& _p) : first(_p.first), second(_p.second)
     {}
     pair& operator=(const pair& pa)
     {
      if (this == &pa)
        return (*this);
      first = pa.first;
      second = pa.second; 
      return (*this);
     }
  };
  //Non Members function
  template<class T1, class T2>
  bool operator==(const pair<T1, T2>& _x,const pair<T1, T2>& _y)
  {
    return ((_x.first == _y.first) && (_x.second == _y.second));
  }
  template<class T1, class T2>
  bool operator<(const pair<T1, T2>& _x,const pair<T1, T2>& _y)
  {
    return ((_x.first < _y.first) || (!(_y.first <  _x.first) && (_x.second < _y.second)));
  }
  template<class T1, class T2>
  bool operator!=(const pair<T1, T2>& _x,const pair<T1, T2>& _y)
  {
    return (!(_x == _y));
  }
  template<class T1, class T2>
  bool operator>(const pair<T1, T2>& _x,const pair<T1, T2>& _y)
  {
    return (_y < _x);
  }
  template<class T1, class T2>
  bool operator<=(const pair<T1, T2>& _x,const pair<T1, T2>& _y)
  {
    return (!(_y < _x));
  }
  template<class T1, class T2>
  bool operator>=(const pair<T1, T2>& _x,const pair<T1, T2>& _y)
  {
    return (!(_x < _y));
  }
  template<class T1, class T2>
  pair<T1, T2> make_pair(T1 _x, T2 _y)
  {
    return pair<T1, T2>(_x, _y);
  }
}
#endif