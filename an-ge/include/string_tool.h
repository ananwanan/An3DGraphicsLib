//
// Created by coder on 2026/6/23.
//
#pragma once

#include <type_common.h>
#include <iomanip>
#include <sstream>

NP_BEGIN

class AN3D_API string_tool
{
public:
  template<typename T>
  static String toString(T data, const std::streamsize precision = 0)
  {
    std::stringstream ss;
    if (precision > 0)
    {
      ss << std::fixed << std::setprecision(precision);
    }
    ss << data;
    return ss.str();
  };
};

NP_END