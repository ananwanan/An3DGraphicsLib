//
// Created by coder on 2026/6/8.
//

#pragma once

#include <array>
#include <type_common.h>
#include <vector3.h>
#include <an_math.h>

USE_NP

NP_BEGIN

/**
 * @brief the matrix4 class, 4x4 matrix, used for transformation in 3D space
 */
class AN3D_API matrix4
{
public:
  matrix4();
  virtual ~matrix4();
  // copy constructor
  matrix4(const matrix4& matrix) noexcept;
  // move constructor
  matrix4(const matrix4&& matrix) noexcept;
  // constructor with data, the data should be in row-major order, which is the default in C++, and is also the default in OpenGL
  explicit matrix4(std::array<double, 16> data) : m_data(std::move(data)) { };

public:
  matrix4& operator=(const matrix4& matrix);
  matrix4& operator=(matrix4&& matrix) noexcept;

public:
  // the operator[] is used to access the first element of each row, which is convenient for some operations, such as translation, rotation and scale
  double       operator[](std::size_t row);
  const double operator[](std::size_t row) const;

  // the operator() is used to access the element of the matrix, which is convenient for some operations, such as matrix multiplication
  double&      operator()(size_t row, size_t col);
  const double operator()(size_t row, size_t col) const;

  // the data() function is used to get the pointer of the matrix data, which is convenient for some operations, such as passing the matrix to OpenGL
  const double* data() const;

public:
  matrix4& operator+=(const matrix4& other);
  matrix4& operator-=(const matrix4& other);
  matrix4& operator*=(const matrix4& other);
  matrix4& operator/=(const matrix4& other);

  friend matrix4 operator+(matrix4 lhs, const matrix4& rhs) { return lhs += rhs; }
  friend matrix4 operator-(matrix4 lhs, const matrix4& rhs) { return lhs -= rhs; }
  friend matrix4 operator*(matrix4 lhs, const matrix4& rhs) { return lhs *= rhs; }
  friend matrix4 operator/(matrix4 lhs, const matrix4& rhs) { return lhs /= rhs; }

  friend bool operator==(const matrix4& lhs, const matrix4& rhs);
  friend bool operator!=(const matrix4& lhs, const matrix4& rhs);

  // dot product
  friend matrix4 dotProduct(const matrix4& other);
  // cross product
  friend matrix4 crossProduct(const matrix4& other);

public:
  /**
   * @brief get the identity matrix
   * @return the identity matrix
   */
  static matrix4 identity();
  /**
   * @brief get the rotation matrix, which is used to rotate a vector around an axis by a certain angle, and the angle is in radians, and the axis is a unit
   * vector, and the default axis is the Z axis, which is the most common case in 2D rotation
   * @param radians the angle in radians, which is the amount of rotation, and is a positive value for counter-clockwise rotation, and a negative value for
   * clockwise rotation
   * @param axis the axis of rotation, which is a unit vector, and the default axis is the Z axis, which is the most common case in 2D rotation, and the
   * rotation is performed
   * @return the rotation matrix, which is a 4x4 matrix, and the rotation is performed around the origin, which is the point (0, 0, 0), and the rotation is
   * performed in the right-hand rule, which means that if the axis is pointing towards you, the rotation is counter-clockwise, and if the axis is pointing
   * away from you, the rotation is clockwise
   */
  static matrix4 rotate(double radians, const vector3& axis = vector3::AXIS_Z);
  /**
   * @brief get the translation matrix, which is used to translate a vector by a certain amount in x, y and z directions, and the translation is performed in
   * the right-hand rule
   * @param x the translation in x direction
   * @param y the translation in y direction
   * @param z the translation in z direction
   * @return the translation matrix, which is a 4x4 matrix, and the translation is performed around the origin, which is the point (0, 0, 0), and the
   * translation is performed in the right-hand rule, which means that if the axis is pointing towards you, the translation is counter-clockwise, and if the
   * axis is pointing away from you, the translation is clockwise
   */
  static matrix4 translate(double x, double y, double z);

public:
  /**
   * @brief set the translation component of the matrix
   *
   * @param x the translation in x direction
   * @param y the translation in y direction
   * @param z the translation in z direction
   */
  void setTranslation(double x, double y, double z);
  /**
   * @brief set the scale component of the matrix
   *
   * @param x the scale in x direction
   * @param y the scale in y direction
   * @param z the scale in z direction
   */
  void setScale(double x, double y, double z);

public:
  /**
   * @brief debug the matrix4, only in debug mode
   */
  void debug() const;

public:
  /**
   * @brief the matrix4 data, 4x4 matrix
   * force 32-byte alignment, if it is double[16], it is exactly 128 bytes,
   * which is beneficial for cache line alignment
   */
  alignas(32) std::array<double, 16> m_data{};
};

NP_END
