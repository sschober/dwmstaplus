#pragma once
#include <ostream>

#include "FilesystemSource.h"

using std::ostream;

/**
 * BatteryInfo InfoSource
 *
 * Reads the ACPI battery info from the proc file system
 *
 */

struct BatteryInfo : public FilesystemSource {
  BatteryInfo() :
    FilesystemSource("/sys/class/power_supply/BAT0/capacity") {}
};

