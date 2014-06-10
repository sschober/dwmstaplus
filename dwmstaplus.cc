#include <iostream>
#include <sstream>
#include <unistd.h>

#include "X11.h"
#include "config.h"

using std::cerr;
using std::endl;
using std::ostringstream;

int main(){

  X11 x11;
  InfoModules modules;

  if(!x11.isValid()){
    cerr << "Cannot open display!" << endl;
    return 1;
  }

  for(;;sleep(SLEEP_TIME)){
    ostringstream os;
    os << modules;
    x11.set_status(os.str());
  }
}
