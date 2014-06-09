#pragma onve
#include "FilesystemSource.h"
struct LoadInfo : public FilesystemSource {
    LoadInfo() : FilesystemSource("/proc/loadavg") {}
};

