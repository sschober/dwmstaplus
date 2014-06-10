#pragma once

#include <string>
#include <ostream>

using std::string;
using std::ostream;

template <class T, class U>
class Chain {
  U u;
  T t;
  public:
  string get(){ return T().get() + " | " + U().get();}
  // TODO: kann man den Delimiter noch konfigurabel machen?
  friend inline ostream& operator<<( ostream &os, const Chain<T,U> &c ){
    return os << c.u << " | " << c.t;
  }
};

