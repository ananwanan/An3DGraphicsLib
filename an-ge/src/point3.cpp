//
// Created by coder on 2026/6/10.
//

#include <point3.h>
#include <matrix4.h>

NP_BEGIN

point3 point3::translation(double tx, double ty, double tz)
{
  x += tx;
  y += ty;
  z += tz;
  return *this;
}

point3 point3::rotate(double radians, const vector3& axis)
{
  matrix4 R = matrix4::build_rotate(radians, axis);

  double nx = R(0, 0) * x + R(0, 1) * y + R(0, 2) * z + R(0, 3);
  double ny = R(1, 0) * x + R(1, 1) * y + R(1, 2) * z + R(1, 3);
  double nz = R(2, 0) * x + R(2, 1) * y + R(2, 2) * z + R(2, 3);

  x = nx;
  y = ny;
  z = nz;

  return *this;
}

point3 point3::scale(double sx, double sy, double sz)
{
  x *= sx;
  y *= sy;
  z *= sz;
  return *this;
}

NP_END