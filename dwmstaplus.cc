#include <iostream>
#include <unistd.h>

#include "X11.h"
#include "config.h"

int main(){

  X11 x11;

  if(!x11.isValid()){
    std::cerr << "Cannot open display!" << std::endl;
    return 1;
  }

  for(;;sleep(SLEEP_TIME)){
    x11.set_status(InfoModules().get());
  }
}
