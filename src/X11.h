#pragma once
#include <X11/Xlib.h>
#include <string>

using std::string;

class X11 {
  Display *dpy = XOpenDisplay(NULL);
  public:
  bool isValid(){ return dpy; }
  void put(string status_line){
    XStoreName(dpy, DefaultRootWindow(dpy), status_line.c_str());
    XSync(dpy, False);
  }
};
