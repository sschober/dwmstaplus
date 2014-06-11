#pragma onve

#include <regex>
#include "FilesystemSource.h"

using std::string;
using std::regex;
using std::regex_match;
using std::smatch;

/**
 * LoadInfo InfoSource
 *
 * Reads the proc filesystem to extract load information.
 *
 */

class LoadInfo : public FilesystemSource {
  public:
  regex re_loadavgs_only;
    LoadInfo() : FilesystemSource("/proc/loadavg"),
                 re_loadavgs_only(regex("([0-9]*\\.[0-9]* [0-9]*\\.[0-9]* [0-9]*\\.[0-9]*).*"))
  {}
    /**
     * We override match as we want to extract a line from the file
     * which is not the first one.
     */
    string match(string ln) const {
      smatch sm;
      if(regex_match( ln, sm, re_loadavgs_only )){
        if( 1 < sm.size() ){
          return sm[1];
        }
      }
      return string();
    }
};

