#pragma once
template <class T, class U>
struct Chain {
  typedef T head;
  typedef U tail;
  string get(){ return T().get() + " | " + U().get();}
};

