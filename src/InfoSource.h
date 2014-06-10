#pragma once
#include <string>
#include <ostream>

using std::string;
using std::ostream;

struct InfoSource {
  virtual string get() = 0;
  virtual ostream& operator<<( ostream &os ) = 0;
};

