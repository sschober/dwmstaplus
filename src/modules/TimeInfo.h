#pragma onve
#include <sstream>
#include <iomanip>
#include <ctime>

#include "InfoSource.h"

using std::string;
using std::ostringstream;
using std::setfill;
using std::setw;
using std::ostream;

/**
 * TimeInfo InfoSource
 *
 * Uses time() and localtime() to construct a local date and time
 * string.
 *
 */

struct TimeInfo : public InfoSource {
  string get() const {
    time_t t = time(0);
    struct tm * now = localtime(&t);
    ostringstream res;
    res << setfill('0')
#ifdef TIME_INFO_SHOW_CALENDAR_WEEK
      << "KW "   << ( now->tm_yday / 7 ) + 1 << " | "
#endif
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

