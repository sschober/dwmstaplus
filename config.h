#pragma once

#include "Chain.h"

#include "BatteryInfo.h"
#include "LoadInfo.h"

// show calendar weeks
#define TIME_INFO_SHOW_CALENDAR_WEEK 1
#include "TimeInfo.h"

// display free mem in MBs
#define MEM_FREE_INFO_HUMAN_READABLE 1
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
