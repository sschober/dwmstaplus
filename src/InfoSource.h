#pragma once
#include <string>
#include <ostream>

using std::string;
using std::ostream;

/**
 * Common InfoSource iterface
 *
 */

struct InfoSource {

  // Acquire info - has to be defined by sub-classes
  virtual string get() const = 0;

  // Common operator<< for all InfoSources; uses get()
  friend ostream& operator<<( ostream &os, const InfoSource &is ){
    return os << is.get();
  }

};

