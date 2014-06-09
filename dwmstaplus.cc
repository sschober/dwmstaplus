#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <ctime>
#include <future>
#include <X11/Xlib.h>

using namespace std;

#include "BatteryInfo.h"
#include "LoadInfo.h"
#include "TimeInfo.h"
#include "Chain.h"

typedef Chain<BatteryInfo, Chain<LoadInfo, TimeInfo> > InfoModules;

void set_status(Display *dpy, string status_line){
  XStoreName(dpy, DefaultRootWindow(dpy), status_line.c_str());
  XSync(dpy, False);
}

int main(){

  Display *dpy = XOpenDisplay(NULL);

  if(!dpy){
    cerr << "Cannot open display!" << endl;
    return 1;
  }

  for(;;sleep(2)){
    ostringstream status_line;
    status_line << InfoModules().get();
    set_status(dpy, status_line.str());
  }
}
