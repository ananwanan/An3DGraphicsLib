//
// Created by anan on 2026/6/9.
//

#include <vector3.h>

namespace anan3d
{
  const vector3 AXIS_X = vector3(1, 0, 0);
  const vector3 AXIS_Y = vector3(0, 1, 0);
  const vector3 AXIS_Z = vector3(0, 0, 1);

  vector3::vector3(double x, double y, double z) : vec{ x, y, z } { }

}  // namespace anan3d
