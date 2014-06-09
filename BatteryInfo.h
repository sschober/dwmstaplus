#pragma once
#include "FilesystemSource.h"
struct BatteryInfo : public FilesystemSource {
  BatteryInfo() :
    FilesystemSource("/sys/class/power_supply/BAT0/capacity") {}
};

