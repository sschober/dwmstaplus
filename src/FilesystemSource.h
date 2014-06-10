#pragma once
#include <fstream>
#include <ostream>

#include "InfoSource.h"

using std::string;
using std::ifstream;
using std::ostream;

/**
 * Reads first line of file
 *
 * The file to be read has to be configured by a concrete sub-class
 *
 */

class FilesystemSource : public InfoSource {
  string path;
  public:
    FilesystemSource(std::string p) : path(p) {}
    string get() const {
      ifstream file(path.c_str());
      if(file.good()){
        string ln;
        if(getline(file,ln)){
          return ln;
        }
      }
      return "";
    }
};

