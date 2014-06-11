#pragma once
#include <ostream>

#include "FilesystemSource.h"

using std::ostream;
using std::string;

struct PathSupplier {
  virtual string get() const = 0;
};

struct Bat0Supplier : public PathSupplier {
  string get() const { return "/sys/class/power_supply/BAT0/capacity"; }
};

/**
 * BatteryInfo InfoSource
 *
 * Reads the ACPI battery info from the proc file system
 *
 */

template <class PS = Bat0Supplier>
struct BatteryInfo : public FilesystemSource {
  BatteryInfo() :
    FilesystemSource(PS().get()) {}
};

