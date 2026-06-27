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

  vector3& operator+=(const vector3& other);
  vector3& operator-=(const vector3& other);

  /**
   * @brief return the dot product of this vector and another vector, which is a scalar value that represents the cosine of the angle between the two vectors,
   * and is calculated by the formula: dotProduct = x1 * x2 + y1 * y2 + z1 * z2
   * @param other another vector to calculate the dot product with
   * @return the dot product of this vector and another vector, which is a scalar value
   */
  [[nodiscard]]
  double dotProduct(const vector3& other) const;

  /**
   * @brief return the cross product of this vector and another vector, which is a vector that is perpendicular to both vectors, and is calculated by the
   * formula: crossProduct = (y1 * z2 - z1 * y2, z1 * x2 - x1 * z2, x1 * y2 - y1 * x2)
   * @param other another vector to calculate the cross product with
   * @return the cross product of this vector and another vector, which is a vector that is perpendicular to both vectors
   */
  [[nodiscard]]
  vector3 crossProduct(const vector3& other) const;

  /**
   * @brief return the angle between this vector and another vector, which is the angle formed by the two vectors when they are placed tail to tail, and is
   * calculated by the formula: angle = acos(dotProduct / (length1 * length2))
   * @param other another vector to calculate the angle with
   * @return the angle between this vector and another vector, which is a scalar value in radians
   */
  [[nodiscard]]
  radians getAngle(const vector3& other) const;

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
  [[nodiscard]] inline double length() const;

  /**
   * @brief normalize the vector, which is the process of converting a vector to a unit vector, which has a length of 1, and is calculated by dividing each
   * component of the vector by its length
   * @return the normalized vector
   */
  vector3 normalized() const;

public:
  /**
   * @brief translate the vector by a certain amount in x, y and z directions, and the translation is performed in the right-hand rule
   * @param x the translation in x direction
   * @param y the translation in y direction
   * @param z the translation in z direction
   * @return the translated vector
   */
  vector3 translation(double x, double y, double z) const;
  
  /**
   * @brief rotate the vector around an axis by a certain angle, and the angle is in radians, and the axis is a unit vector, and the default axis is the Z
   * axis, which is the most common case in 2D rotation
   * @param radians the angle in radians, which is the amount of rotation, and is a positive value for counter-clockwise rotation, and a negative value for
   * clockwise rotation
   * @param axis the axis of rotation, which is a unit vector, and the default axis is the Z axis, which is the most common case in 2D rotation, and the
   * rotation is performed
   * @return the rotated vector
   */
  vector3 rotate(double radians, const vector3& axis = AXIS_Z) const;

  /**
   * @brief scale the vector by a certain amount in x, y and z directions, and the scale is performed in the right-hand rule
   *
   * @param x scale in x direction
   * @param y scale in y direction
   * @param z scale in z direction
   * @return vector3 the scaled vector
   */
  vector3 scale(double x, double y, double z) const;

public:  // tools only for debug
  /**
   * @brief debug the matrix4, only in debug mode
   */
  void debug() const;

public:
  double x;
  double y;
  double z;
};

NP_END