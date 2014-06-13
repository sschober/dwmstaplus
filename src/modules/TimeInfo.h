#pragma onve
#include <sstream>
#include <iomanip>
#include <ctime>

#include "InfoSource.h"

using std::string;
using std::ostringstream;
using std::setfill;
using std::setw;

/**
 * TimeInfo InfoSource
 *
 * Uses time() and localtime() to construct a local date and time
 * string.
 *
 */

class BasicTimeInfo : public InfoSource {
  protected:
    struct tm *now;
    ostringstream res;

  public:
    BasicTimeInfo() {
      time_t t = time(0);
      now = localtime(&t);
      res << setfill('0');
    }
  string get() const {
    return res.str();
  }
};

template< class TI, const char * delim = DEFAULT_DELIMITER>
class TimeStr: public TI {
  public:
    TimeStr() {
    this->res
      << setw(2) << this->now->tm_hour  << ":"
      << setw(2) << this->now->tm_min   << ":"
      << setw(2) << this->now->tm_sec
      << delim;
    }
};

template< class TI, const char * delim = DEFAULT_DELIMITER>
struct DateStr: public TI {
  DateStr() {
    this->res
      << setw(2) << this->now->tm_mday  << "."
      << setw(2) << this->now->tm_mon   << "."
      << setw(4) << this->now->tm_year + 1900
      << delim;
  }
};

template< class TI, const char * delim = DEFAULT_DELIMITER>
struct WeekStr: public TI {
  WeekStr(){
      this->res << "KW "   << ( this->now->tm_yday / 7 ) + 1
      << delim;
  }
};
