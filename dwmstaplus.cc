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

#include "TypeList.h"

void set_status(Display *dpy, string status_line){
  XStoreName(dpy, DefaultRootWindow(dpy), status_line.c_str());
  XSync(dpy, False);
}

int main(){
  typedef TypeList<BatteryInfo, TypeList<LoadInfo, TypeList<TimeInfo, NullType> > > InfoModules;
  InfoSource* sources[Length<InfoModules>::value];

  for(unsigned int i = 0; i < Length<InfoModules>::value; i ++){
    sources[i] = new TypeAt<InfoModules,i>::Result;
  }

  Display *dpy = XOpenDisplay(NULL);
  if(!dpy){
    cerr << "Cannot open display!" << endl;
    return 1;
  }

  for(;;sleep(2)){
    ostringstream status_line;
    for(unsigned int i = 0; i < Length<InfoModules>::value; i ++){
      sources[i] = new TypeAt<InfoModules,0>::Result;
      status_line << sources[i]->get() << " | ";
    }
    set_status(dpy, status_line.str());
  }
}
