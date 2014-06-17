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
    virtual void _fill() {
      time_t t = time(0);
      now = localtime(&t);
      res.str("");
      res.clear();
      res << setfill('0');
    }
  public:
    string get() {
      _fill();
      return res.str();
    }
};

template< class TI, const char * delim = DEFAULT_DELIMITER>
class TimeStr: public TI {
  protected:
  virtual void _fill() {
    TI::_fill();
    this->res
      << setw(2) << this->now->tm_hour  << ":"
      << setw(2) << this->now->tm_min   << ":"
      << setw(2) << this->now->tm_sec
      << delim;
  }
};

template< class TI, const char * delim = DEFAULT_DELIMITER>
class DateStr: public TI {
  protected:
  virtual void _fill() {
    TI::_fill();
    this->res
      << setw(2) << this->now->tm_mday  << "."
      << setw(2) << this->now->tm_mon + 1  << "."
      << setw(4) << this->now->tm_year + 1900
      << delim;
  }
};

template< class TI, const char * delim = DEFAULT_DELIMITER>
class WeekStr: public TI {
  protected:
    virtual void _fill(){
      TI::_fill();
      this->res << "KW "   << ( this->now->tm_yday / 7 ) + 1
        << delim;
    }
};
