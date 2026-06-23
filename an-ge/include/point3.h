#pragma once

#include <type_common.h>

NP_BEGIN

/**
 * @brief  the point3 class, used for representing a 3D point
 */
class AN3D_API point3
{
public:
  point3()                         = default;
  virtual ~point3()                = default;
  point3(const point3&)            = default;
  point3& operator=(const point3&) = default;

public:
  // the x coordinates of the point
  double x;
  // the y coordinates of the point
  double y;
  // the z coordinates of the point
  double z;
};

NP_END