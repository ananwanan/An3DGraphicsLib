//
// Created by anan on 2026/6/9.
//

#include <stdexcept>
#include <vector3.h>

namespace anan3d
{
  const auto AXIS_X = vector3{ 1, 0, 0 };
  const auto AXIS_Y = vector3{ 0, 1, 0 };
  const auto AXIS_Z = vector3{ 0, 0, 1 };

  vector3::vector3(const double x, const double y, const double z) : x(x), y(y), z(z) { }

}  // namespace anan3d
