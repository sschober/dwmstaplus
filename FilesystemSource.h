#pragma once
#include "InfoSource.h"

class FilesystemSource : public InfoSource {
  protected:
    string get_proc_file_line(string path){
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

