#pragma once

#include "Chain.h"

#include "FilesystemSource.h"
#include "HumanReadableBytes.h"
#include "TimeInfo.h"


// Construct a module on-the-fly
//
// Here, we use a FilesystemSource, which reads a file provided by a
// template parameter. It matches each line of the file against
// using a matching strategy, which can be provided using the second
// template parameter. The default matching strategy just returns
// the string, which results in selecting the first line of the
// file. Here, we use a RegexMatcher, which uses the provided
// regular expression.
//
// We typedef the resulting configuration, which enables a more
// convenient construction of our module list below.
char LOAD_AVGS_PATH[]     = "/proc/loadavg";
char LOAD_AVGS_REGEX[]    = "([0-9]*\\.[0-9]* [0-9]*\\.[0-9]* [0-9]*\\.[0-9]*).*";
typedef FilesystemSource<LOAD_AVGS_PATH, RegexMatcher<LOAD_AVGS_REGEX> > LoadInfo;

// Another on-the-fly module definition
//
// We configure a FilesystemSource to read the first line of the
// provided file
char BATTERY_INFO_PATH[]  = "/sys/class/power_supply/BAT0/capacity";
typedef FilesystemSource<BATTERY_INFO_PATH> BatteryInfo;

// The last on-the-fly module definition reads the free memory byts
char MEM_FREE_PATH[]      = "/proc/meminfo";
char MEM_FREE_REGEX[]     = "MemFree:[ ]*([0-9]*).*";
typedef FilesystemSource<MEM_FREE_PATH, RegexMatcher<MEM_FREE_REGEX> > MemFreeInfoInKB;

// We would like to see KB converted to MBs, when exceeding a given
// size (4 digits here)
typedef HumanReadableBytes<MemFreeInfoInKB, 4> MemFreeInfo;

// We construct a time module on-the-fly.
//
// The innermost module BasicTimeInfo fetches the struct tm and
// stores it in a variable. It further defines an ostringstream
// `res` in a local variable, plus a methode `get()` to fetch a
// string from it.
//
// The outer modules inherit from the inner one and can thus access
// the variables provided by the BasicTimeInfo module. This is an
// application of the decorator pattern.
//
char TIME_DELIMITER[]          = " ";
char NULL_DELIMITER[]          = "";
typedef TimeStr < DateStr < WeekStr < BasicTimeInfo >, TIME_DELIMITER >, NULL_DELIMITER > TimeInfo;

// Defines the presence and order of information sources to be
// displayed in the statusbar
//
// Each Chain-element glues two InfoSources together using a
// standard delimiter of '|', which can also be customized using an
// optional, third template paramter.

//char DELIMITER[]          = " * ";
typedef Chain<        MemFreeInfo,
          Chain<      LoadInfo,
            Chain<  BatteryInfo,
                      TimeInfo
            >
          >
//        ,DELIMITER
        >
        InfoModules;
