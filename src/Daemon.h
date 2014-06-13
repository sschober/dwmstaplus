#pragma once
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::runtime_error;

struct ostreamPutter {
  void put( string s ) { cout << s << endl; }
  bool isValid(){ return true; }
};

template <class OUT, int sleepTime = 2>
class Daemon {
  OUT o;
  InfoModules modules;
public:
   Daemon(){
    if(!o.isValid()){
      throw runtime_error("cannot open display!");
    }

    for(;;sleep(sleepTime)){
      o.put(modules.get());
    }
  }
};
