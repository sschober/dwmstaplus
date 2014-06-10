#pragma onve

#include <string>
#include <regex>

#include "FilesystemSource.h"

using std::string;
using std::regex;
using std::regex_match;
using std::smatch;

/**
 * MemFreeInfo InfoSource
 *
 * Reads the proc filesystem to extract load information.
 *
 */

class MemFreeInfo : public FilesystemSource {
  regex re_memfree;

  public:
    MemFreeInfo() : FilesystemSource("/proc/meminfo"),
                    re_memfree(regex("MemFree:[ ]*(.*)")) {}

    /**
     * We override match as we want to extract a line from the file
     * which is not the first one.
     */
    string match(string ln) const {
      smatch sm;
      if(regex_match( ln, sm, re_memfree )){
        if( 1 < sm.size() ){
          return sm[1];
        }
      }
      return string();
    }
};

