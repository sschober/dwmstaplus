#pragma once
#include <sstream>

using std::ostringstream;
using std::cout;
using std::endl;

struct ostreamPutter {
  void put( string s ) { cout << s << endl; }
};

template <class OUT, int sleepTime = 2>
class Daemon {
  OUT o;
  InfoModules &modules;
public:
  Daemon(InfoModules &mods) :  modules(mods) {
    for(;;sleep(sleepTime)){
      ostringstream os;
      os << modules;
      o.put(os.str());
    }
  }
};
