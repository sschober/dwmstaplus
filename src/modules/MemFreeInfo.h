#pragma onve

#include <string>
#include <regex>

#include "FilesystemSource.h"

using std::string;
using std::regex;
using std::regex_match;
using std::smatch;
using std::stoi;
using std::to_string;

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
                    re_memfree(regex("MemFree:[ ]*([0-9]*).*")) {}

    /**
     * We override match as we want to extract a line from the file
     * which is not the first one.
     */
    string match(string ln) const {
      smatch sm;
      if(regex_match( ln, sm, re_memfree )){
        if( 1 < sm.size() ){
#ifdef MEM_FREE_INFO_HUMAN_READABLE
          if( string(sm[1]).size() > 5 ){
            int kbytes = stoi( sm[1] );
            return to_string( kbytes / 1024 ) + " MB";
          }
#endif
          return string(sm[1]) + " KB";
        }
      }
      return string();
    }
};

