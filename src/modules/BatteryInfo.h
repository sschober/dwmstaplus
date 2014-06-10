#pragma once
#include <ostream>

#include "FilesystemSource.h"

using std::ostream;

class BatteryInfo : public FilesystemSource {
  public:
  BatteryInfo() :
    FilesystemSource("/sys/class/power_supply/BAT0/capacity") {}

};

