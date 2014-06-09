#pragma once
#include "FilesystemSource.h"
class BatteryInfo : public FilesystemSource {
  public:
    string get(){
      return get_proc_file_line("/sys/class/power_supply/BAT0/capacity");
    }
};

