#pragma once
#include "InfoSource.h"

class FilesystemSource : public InfoSource {
  string path;
  public:
    FilesystemSource(string p) : path(p) {}
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
};

