#pragma once

#include <string>

using std::string;


char DEFAULT_DELIMITER[] = "  ";
/**
 * Utility template to chain InfoSources
 *
 * For usage example see `config.h`
 *
 */
template <class T, class U, const char *delim = DEFAULT_DELIMITER>
class Chain {
  // When an instance of this chain element is created we create
  // instances of our children as well.
  U u;
  T t;

public:
  string get() const {
    return string( t.get() + delim + u.get() );
  }
};

