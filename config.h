#pragma once

#include "Chain.h"

#include "BatteryInfo.h"
#include "LoadInfo.h"
#include "TimeInfo.h"

#define SLEEP_TIME 2

typedef Chain<BatteryInfo, Chain<LoadInfo, TimeInfo> > InfoModules;
