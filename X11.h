#pragma once
#include <X11/Xlib.h>
#include <string>
class X11{
  Display *dpy = XOpenDisplay(NULL);
  public:
  bool isValid(){ return dpy; }
  void set_status(std::string status_line){
    XStoreName(dpy, DefaultRootWindow(dpy), status_line.c_str());
    XSync(dpy, False);
  }
};
