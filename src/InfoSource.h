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
  virtual string get() = 0;

};

