#pragma once

#include <string>
#include <ostream>

using std::string;
using std::ostream;

/**
 * Utility template to chain InfoSources
 *
 * For usage example see `config.h`
 *
 */
template <class T, class U>
class Chain {
  // When an instance of this chain element is created we create
  // instances of our children as well.
  U u;
  T t;

public:
  // TODO: Make delimiter configurable (maybe template parameter)
  friend inline ostream& operator<<( ostream &os, const Chain<T,U> &c ){
    return os << c.t << " | " << c.u;
  }
};

