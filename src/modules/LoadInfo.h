#pragma onve

#include "FilesystemSource.h"

/**
 * LoadInfo InfoSource
 *
 * Reads the proc filesystem to extract load information.
 *
 */

struct LoadInfo : public FilesystemSource {
    LoadInfo() : FilesystemSource("/proc/loadavg") {}
};

