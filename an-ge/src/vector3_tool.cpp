//
// Created by anan on 2026/6/9.
//

#include <limits>
#include <cmath>
#include <string_tool.h>
#include <vector3.h>

USE_NP

NP_BEGIN

double vector3::length() const { return std::sqrt(x * x + y * y + z * z); }

vector3 vector3::normalized() const
{
  vector3      result = identity();
  const double length = this->length();
  if (length > std::numeric_limits<double>::epsilon())
  {
    result.x = this->x / length;
    result.y = this->y / length;
    result.z = this->z / length;
  }
  return result;
}

void vector3::debug() const
{
  String str_x = string_tool::toString(this->x);
  String str_y = string_tool::toString(this->y);
  String str_z = string_tool::toString(this->z);
}

NP_END