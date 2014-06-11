#pragma once

#include "Chain.h"

#include "BatteryInfo.h"
#include "LoadInfo.h"
#include "TimeInfo.h"
#include "MemFreeInfo.h"
#include "KBToMBDecorator.h"

// Defines the presence and order of information sources to be
// displayed in the statusbar
typedef Chain< KBToMBDecorator<MemFreeInfo> ,
        Chain< BatteryInfo<>,
        Chain< LoadInfo,
               TimeInfo<true> > > > InfoModules;
