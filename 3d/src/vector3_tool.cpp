//
// Created by anan on 2026/6/9.
//

#include <limits>
#include <cmath>

#include <vector3.h>

using namespace anan3d;

namespace anan3d
{
  double vector3::length() const { return std::sqrt(x * x + y * y + z * z); }

  vector3 vector3::normalized() const
  {
    vector3 result = vector3::identity();
    double  length = result.length();
    if (length > std::numeric_limits<double>::epsilon())
    {
      result.x = this->x / length;
      result.y = this->y / length;
      result.z = this->z / length;
    }
    return result;
  }
}  // namespace anan3d