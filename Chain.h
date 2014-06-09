#pragma once
#include <string>
template <class T, class U>
struct Chain {
  typedef T head;
  typedef U tail;
  // TODO: kann man den Delimiter noch konfigurabel machen?
  std::string get(){ return T().get() + " | " + U().get();}
};

