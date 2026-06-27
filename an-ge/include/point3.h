#pragma once

#include <type_common.h>
#include <vector3.h>

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
  /**
   * @brief set the translation component of the matrix, which is used to translate a point by a certain amount in x, y and z directions, and the translation is
   * performed in the right-hand rule
   *
   * @param tx the translation in x direction
   * @param ty the translation in y direction
   * @param tz the translation in z direction
   * @return point3 the translated point
   */
  point3 translation(double tx, double ty, double tz);

  /**
   * @brief set the rotation component of the matrix, which is used to rotate a point around an axis by a certain angle, and the angle is in radians, and the
   * axis is a unit vector, and the default axis is the Z axis, which is the most common case in 2D rotation
   *
   * @param radians the angle in radians, which is the amount of rotation, and is a positive value for counter-clockwise rotation, and a negative value for
   * clockwise rotation
   * @param axis the axis of rotation, which is a unit vector, and the default axis is the Z axis, which is the most common case in 2D rotation, and the
   * rotation is performed
   * @return point3 the rotated point
   */
  point3 rotate(double radians, const vector3& axis = vector3::AXIS_Z);

  /**
   * @brief set the scale component of the matrix
   *
   * @param sx the scale in x direction
   * @param sy the scale in y direction
   * @param sz the scale in z direction
   */
  point3 scale(double sx, double sy, double sz);

public:
  // the x coordinates of the point
  double x;
  // the y coordinates of the point
  double y;
  // the z coordinates of the point
  double z;
};

NP_END