#pragma once
#include <fstream>
#include "InfoSource.h"

class FilesystemSource : public InfoSource {
  std::string path;
  public:
    FilesystemSource(std::string p) : path(p) {}
    std::string get(){
      std::ifstream file(path.c_str());
      if(file.good()){
        std::string ln;
        if(getline(file,ln)){
          return ln;
        }
      }
      return "";
    }
};

