#pragma onve
#include <sstream>
#include <iomanip>
#include <ctime>

#include "InfoSource.h"

struct TimeInfo : public InfoSource {
  std::string get(){
    time_t t = time(0);
    struct tm * now = localtime(&t);
    std::ostringstream res;
    res << std::setfill('0')
      << std::setw(2) << now->tm_mday  << "."
      << std::setw(2) << now->tm_mon   << "."
      << std::setw(4) << now->tm_year + 1900
      << " "
      << std::setw(2) << now->tm_hour  << ":"
      << std::setw(2) << now->tm_min   << ":"
      << std::setw(2) << now->tm_sec;
    return res.str();
  }
};

