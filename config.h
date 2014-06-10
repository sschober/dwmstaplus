#pragma once

#include "Chain.h"

#include "BatteryInfo.h"
#include "LoadInfo.h"
#include "TimeInfo.h"
#include "MemFreeInfo.h"

#ifndef SLEEP_TIME
#define SLEEP_TIME 2
#endif

// Defines the presence and order of information sources to be
// displayed in the statusbar
typedef Chain< MemFreeInfo,
        Chain< BatteryInfo,
        Chain< LoadInfo,
               TimeInfo > > > InfoModules;
