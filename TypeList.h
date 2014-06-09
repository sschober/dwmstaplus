#pragma once
template <class T, class U>
struct TypeList {
  typedef T head;
  typedef U tail;
};

class NullType {};

// LENGTH
//
template <class TList> struct Length;
template <> struct Length<NullType> {
  enum { value = 0 };
};
template <class T, class U>
struct Length< TypeList<T, U> >{
  enum { value = 1 + Length<U>::value };
};

// TYPEAT
//
template <class TList, unsigned int i> struct TypeAt;
template <class Head, class Tail>
struct TypeAt<TypeList<Head, Tail>, 0>{
  typedef Head Result;
};
template <class Head, class Tail, unsigned int i>
struct TypeAt<TypeList<Head, Tail>, i> {
  typedef typename TypeAt<Tail, i - 1 >::Result Result;
};
