#pragma once

#include <string>

#include "InfoSource.h"

using std::stoi;
using std::to_string;
using std::string;

template <class T>
class KBToMBDecorator : public T {
  T t;
  public:
  string get() const {
    string res = t.get();
    if( res.size() > 5 ){
      int kbytes = stoi( res );
      res = to_string( kbytes / 1024 ) + " MB";
    }
    return res;
  }
};
