//
// Created by anan on 2026/6/9.
//

#include <cmath>
#include <format>
#include <limits>
#include <iostream>
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

double vector3::dotProduct(const vector3& other) const { return this->x * other.x + this->y * other.y + this->z * other.z; }

vector3 vector3::crossProduct(const vector3& other) const
{
  vector3 result;
  result.x = this->y * other.z - this->z * other.y;
  result.y = this->z * other.x - this->x * other.z;
  result.z = this->x * other.y - this->y * other.x;
  return result;
}

radians vector3::getAngle(const vector3& other) const
{
  double dotResult    = this->dotProduct(other);
  double lengthResult = this->length() * other.length();
  double arcCos       = 0.0;
  if (lengthResult > std::numeric_limits<double>::epsilon())
  {
    arcCos = dotResult / lengthResult;
  }
  return std::acos(arcCos);
}

void vector3::debug() const { std::cout << std::format("{:.3f} {:.3f} {:.3f}", this->x, this->y, this->z) << std::endl; }

NP_END