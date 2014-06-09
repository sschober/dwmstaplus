#pragma onve
#include "InfoSource.h"
class TimeInfo : public InfoSource {
  public:
    string get(){
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
};

