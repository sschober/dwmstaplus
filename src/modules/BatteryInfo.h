#pragma once
#include <ostream>

#include "FilesystemSource.h"

using std::ostream;

#ifndef BATTERY_INFO_PATH
#define BATTERY_INFO_PATH "/sys/class/power_supply/BAT0/capacity"
#endif

/**
 * BatteryInfo InfoSource
 *
 * Reads the ACPI battery info from the proc file system
 *
 */

struct BatteryInfo : public FilesystemSource {
  BatteryInfo() :
    FilesystemSource(BATTERY_INFO_PATH) {}
};

