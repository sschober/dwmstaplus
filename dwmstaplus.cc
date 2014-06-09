#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <ctime>
#include <future>

#include <X11/Xlib.h>

using namespace std;

string get_proc_file_line(string path){
  ifstream file(path.c_str());
  if(file.good()){
    string ln;
    if(getline(file,ln)){
      return ln;
    }
  }
  return "";
}

string get_battery_capacity(){
  return get_proc_file_line("/sys/class/power_supply/BAT0/capacity");
}

string get_load_avgs(){
  return get_proc_file_line("/proc/loadavg");
}

string get_date_time(){
  time_t t = time(0);
  struct tm * now = localtime(&t);
  ostringstream res;
  res << setfill('0')
      << setw(2) << now->tm_mday  << "."
      << setw(2) << now->tm_mon   << "."
      << setw(4) << now->tm_year + 1900
      << " "
      << setw(2) << now->tm_hour  << ":"
      << setw(2) << now->tm_min   << ":"
      << setw(2) << now->tm_sec;
  return res.str();
}

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
    future<string> capacity = async(get_battery_capacity);
    future<string> load_avgs = async(get_load_avgs);
    future<string> date_time = async(get_date_time);

    ostringstream status_line;
    status_line << capacity.get() << " | " << load_avgs.get() <<   " | " << date_time.get();
    set_status(dpy, status_line.str());
  }
}
