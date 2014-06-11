#include <iostream>
#include <sstream>
#include <unistd.h>

#include "X11.h"
#include "config.h"

using std::cout;
using std::cerr;
using std::endl;
using std::ostringstream;


/**
 * Main-Loop
 *
 * Initializes X11 class and InfoModules-Chain and loops forever.
 * Sleeps for SLEEP_TIME seconds and reads from InfoModules and
 * writes acquired information to X11 using our X11 class.
 *
 */
int main(int argc, char* argv[]){

  bool consoleOutputMode = false;
  bool showVersion = false;

  for(int i = 0; i < argc; i++){
    if( 0 == strcmp(argv[i],"-c") ){
      consoleOutputMode = true;
    }
    else if( 0 == strcmp(argv[i],"-v") ){
      showVersion = true;
    }
  }

  if(showVersion){
    cout << NAME << " - version " << VERSION << endl;
    return 0;
  }

  X11 x11;
  InfoModules modules;

  if(!x11.isValid()){
    cerr << "Cannot open display!" << endl;
    return 1;
  }

  for(;;sleep(SLEEP_TIME)){
    ostringstream os;
    os << modules;
    if(consoleOutputMode){
      cout << os.str() << endl;
    }
    else{
      x11.set_status(os.str());
    }
  }
}
