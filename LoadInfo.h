#pragma onve
#include "FilesystemSource.h"
class LoadInfo : public FilesystemSource {
  public:
    string get(){
      return get_proc_file_line("/proc/loadavg");
    }
};

