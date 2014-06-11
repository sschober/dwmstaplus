#include <iostream>
#include <sstream>
#include <unistd.h>

#include "config.h"

#include "X11.h"
#include "Daemon.h"


using std::cout;
using std::cerr;
using std::endl;


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

  try {
    if(consoleOutputMode){
      Daemon<ostreamPutter> d;
    }
    else{
      Daemon<X11> d;
    }
  } catch (std::exception &e ){
    cerr << e.what() << endl;
  }
}
