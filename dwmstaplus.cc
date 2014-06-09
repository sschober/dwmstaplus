#include <iostream>
#include <unistd.h>

#include "BatteryInfo.h"
#include "LoadInfo.h"
#include "TimeInfo.h"
#include "Chain.h"
#include "X11.h"

typedef Chain<BatteryInfo, Chain<LoadInfo, TimeInfo> > InfoModules;

int main(){

  X11 x11;

  if(!x11.isValid()){
    std::cerr << "Cannot open display!" << std::endl;
    return 1;
  }

  for(;;sleep(2)){
    x11.set_status(InfoModules().get());
  }
}
