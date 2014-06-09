#pragma once

#include "Chain.h"

#include "BatteryInfo.h"
#include "LoadInfo.h"
#include "TimeInfo.h"

#ifndef SLEEP_TIME
#define SLEEP_TIME 2
#endif

typedef Chain<BatteryInfo, Chain<LoadInfo, TimeInfo> > InfoModules;
