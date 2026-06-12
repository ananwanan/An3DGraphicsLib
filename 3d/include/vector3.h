//
// Created by anan on 2026/6/9.
//

#pragma once

#include <an_common.h>

namespace anan3d
{
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
    double x{};
    double y{};
    double z{};
  };
}  // namespace anan3d