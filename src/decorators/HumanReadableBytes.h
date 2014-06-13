#pragma once

#include <string>

#include "InfoSource.h"

using std::stoi;
using std::to_string;
using std::string;

template <class T, int limit = 5>
class HumanReadableBytes : public T {
  T t;
  public:
  string get() const {
    string res = t.get();
    if( res.size() > limit ){
      int kbytes = stoi( res );
      return to_string( kbytes / 1024 ) + " MB";
    }
    else{
      return res + " KB";
    }
  }
};
