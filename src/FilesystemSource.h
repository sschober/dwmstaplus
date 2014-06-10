#pragma once
#include <fstream>
#include <ostream>

#include "InfoSource.h"

using std::string;
using std::ifstream;
using std::ostream;

class FilesystemSource : public InfoSource {
  string path;
  public:
    FilesystemSource(std::string p) : path(p) {}
    string get(){
      ifstream file(path.c_str());
      if(file.good()){
        string ln;
        if(getline(file,ln)){
          return ln;
        }
      }
      return "";
    }
    virtual ostream& operator<<( ostream &os ){
      return os << get();
    }
};

