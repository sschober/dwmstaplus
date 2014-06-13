#pragma once
#include <fstream>
#include <ostream>
#include <regex>

#include "InfoSource.h"

using std::string;
using std::ifstream;
using std::ostream;
using std::regex;
using std::regex_match;
using std::smatch;

/**
 * Reads first line of file
 *
 * The file to be read has to be configured by a concrete sub-class
 *
 */

struct FirstLineMatcher {
  string match( const string ln ) const {
    return ln;
  }
};

template<const char *re_str>
class RegexMatcher {
    regex re;
  public:
    RegexMatcher() : re(re_str) {}
    string match(string ln) const {
      smatch sm;
      if(regex_match( ln, sm, re )){
        if( 1 < sm.size() ){
          return string(sm[1]);
        }
      }
      return string();
    }
};

template <const char *PATH, class MATCHINGSTRATEGY = FirstLineMatcher>
class FilesystemSource : public InfoSource {
  MATCHINGSTRATEGY ms;
  public:
    string get() const {
      ifstream file(PATH);
      if(file.good()){
        string ln;
        while(getline(file,ln)){
          string m( ms.match(ln) );
          if(!m.empty()){
            return m;
          }
        }
      }
      return "";
    }

};

