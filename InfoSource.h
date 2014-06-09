#pragma once
#include <string>
struct InfoSource {
  virtual std::string get() = 0;
};

