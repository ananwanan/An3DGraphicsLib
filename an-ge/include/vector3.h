//
// Created by anan on 2026/6/9.
//

#pragma once

#include <type_common.h>

NP_BEGIN
/**
 * @brief the vector3 class, used for representing a 3D vector
 *
 */
class AN3D_API vector3
{
public:
  explicit vector3(double x = 0.0, double y = 0.0, double z = 0.0);
  virtual ~vector3()                 = default;
  vector3(const vector3&)            = default;
  vector3& operator=(const vector3&) = default;

public:
  /**
   * the unit vectors of the X axes
   */
  static const vector3 AXIS_X;

  /**
   * the unit vectors of the Y axes
   */
  static const vector3 AXIS_Y;

  /**
   * the unit vectors of the Z axes
   */
  static const vector3 AXIS_Z;

public:
  friend bool operator==(const vector3& lhs, const vector3& rhs);
  friend bool operator!=(const vector3& lhs, const vector3& rhs);

public:
  /**
   * @brief get the zero vector, which is a vector with all components equal to zero, and is used as the additive identity in vector operations
   * @return the zero vector, which is (0, 0, 0)
   */
  static vector3 identity();

public:
  /**
   * @brief calculate the length of the vector, which is the distance from the origin to the point represented by the vector, and is calculated by the
   * formula: length = sqrt(x^2 + y^2 + z^2)
   * @return the length of the vector, which is a non-negative value
   */
  inline double length() const;
  /**
   * @brief normalize the vector, which is the process of converting a vector to a unit vector, which has a length of 1, and is calculated by dividing each
   * component of the vector by its length
   * @return the normalized vector
   */
  vector3 normalized() const;

public:
  /**
   * @brief debug the matrix4, only in debug mode
   */
  void debug() const;

public:
  double x{};
  double y{};
  double z{};
};

NP_END