#pragma once

#include "type_common.h"

#include <cmath>
#include <numbers>

NP_BEGIN

class an_math
{
private:
  an_math() { };

public:
  /**
   * @brief the value of pi, defined in the standard library since C++20, but we define it here for convenience
   */
#if __cplusplus >= 202002L
  static inline constexpr double PI = std::numbers::pi;
#else
  static inline constexpr double PI = 3.14159265358979323846;
#endif
  /**
   * @brief a small value used for floating point comparison, defined as 1e-6, which is a common choice in graphics programming
   */
  static inline constexpr double EPSILON = 1e-6;

public:
  /**
   * @brief calculate the sine of an angle in radians
   * @param angle the angle in radians
   * @return the sine of the angle
   */
  inline static double sin(double angle) { return std::sin(angle); }
  /**
   * @brief calculate the cosine of an angle in radians
   * @param angle the angle in radians
   * @return the cosine of the angle
   */
  inline static double cos(double angle) { return std::cos(angle); }
  /**
   * @brief calculate the tangent of an angle in radians
   * @param angle the angle in radians
   * @return the tangent of the angle
   */
  inline static double tan(double angle) { return std::tan(angle); }
  /**
   * @brief calculate the arcsine of a value, which is the inverse of sine, and the result is in radians
   * @param value the value to calculate the arcsine of, which should be in the range [-1, 1]
   * @return the arcsine of the value, which is in radians
   */
  inline static double asin(double value) { return std::asin(value); }
  /**
   * @brief calculate the arccosine of a value, which is the inverse of cosine, and the result is in radians
   * @param value the value to calculate the arccosine of, which should be in the range [-1, 1]
   * @return the arccosine of the value, which is in radians
   */
  inline static double acos(double value) { return std::acos(value); }
  /**
   * @brief calculate the arctangent of a point (y, x), which is the inverse of tangent, and the result is in radians
   * @param y the y-coordinate of the point
   * @param x the x-coordinate of the point
   * @return the arctangent of the point, which is in radians
   */
  inline static double atan(double y, double x) { return std::atan2(y, x); }
  /**
   * @brief calculate the arctangent of a value, which is the inverse of tangent, and the result is in radians
   * @param value the value to calculate the arctangent of
   * @return the arctangent of the value, which is in radians
   */
  inline static double atan(double value) { return std::atan(value); }

public:
  /**
   * @brief convert degrees to radians
   * @tparam T the type of the input and output, usually float or double
   * @param degrees the angle in degrees
   * @return the angle in radians
   */
  template<typename T>
  static T radians(T degrees)
  {
    return degrees * static_cast<T>(PI) / static_cast<T>(180.0);
  }
  /**
   * @brief convert radians to degrees
   * @tparam T the type of the input and output, usually float or double
   * @param radians the angle in radians
   * @return the angle in degrees
   */
  template<typename T>
  static T degrees(T radians)
  {
    return radians * static_cast<T>(180.0) / static_cast<T>(PI);
  }
};

NP_END