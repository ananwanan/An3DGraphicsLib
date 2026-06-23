//
// Created by coder on 2026/6/8.
//

#include <matrix4.h>

#include <iostream>
#include <format>

namespace anan3d
{
  matrix4::matrix4() { m_data.fill(0); };

  matrix4::~matrix4() = default;

  matrix4::matrix4(const matrix4& matrix) noexcept { m_data = matrix.m_data; }

  matrix4::matrix4(const matrix4&& matrix) noexcept : m_data(matrix.m_data) { }

  matrix4& matrix4::operator=(const matrix4& matrix)
  {
    if (this == &matrix)
    {
      return *this;
    }
    m_data = matrix.m_data;
    return *this;
  }

  matrix4& matrix4::operator=(matrix4&& matrix) noexcept
  {
    if (this == &matrix)
    {
      return *this;
    }
    m_data = matrix.m_data;
    return *this;
  }

  double matrix4::operator[](std::size_t row) { return *(m_data.data() + row * 4); }

  double& matrix4::operator()(size_t row, size_t col) { return m_data[row * 4 + col]; }

  const double matrix4::operator()(size_t row, size_t col) const { return m_data[row * 4 + col]; }

  const double matrix4::operator[](std::size_t row) const { return *(m_data.data() + row * 4); }

  const double* matrix4::data() const { return m_data.data(); }

  matrix4& matrix4::operator+=(const matrix4& other)
  {
    for (std::size_t i = 0; i < this->m_data.size(); ++i)
    {
      m_data[i] = m_data[i] + other.m_data[i];
    }
    return *this;
  }

  matrix4& matrix4::operator-=(const matrix4& other)
  {
    for (std::size_t i = 0; i < this->m_data.size(); ++i)
    {
      m_data[i] = m_data[i] - other.m_data[i];
    }
    return *this;
  }

  matrix4& matrix4::operator*=(const matrix4& other)
  {
    for (std::size_t row = 0; row < 4; ++row)
    {
      for (std::size_t col = 0; col < 4; ++col)
      {
        m_data[row * 4 + col] = 0;
        for (std::size_t k = 0; k < 4; ++k)
        {
          m_data[row * 4 + col] += m_data[row * 4 + k] * other.m_data[k * 4 + col];
        }
      }
    }
    return *this;
  }

  matrix4& matrix4::operator/=(const matrix4& other)
  {
    for (std::size_t i = 0; i < this->m_data.size(); ++i)
    {
      m_data[i] = m_data[i] / other.m_data[i];
    }
    return *this;
  }

  bool operator==(const matrix4& lhs, const matrix4& rhs) { return lhs.m_data == rhs.m_data; }

  bool operator!=(const matrix4& lhs, const matrix4& rhs) { return !(lhs == rhs); }

  matrix4 matrix4::rotate(double radians, const vector3& axis /*= vector3::AXIS_Z*/)
  {
    const auto c = an_math::cos(radians);
    const auto s = an_math::sin(radians);
    const auto t = 1.0 - c;

    const auto n = axis.normalized();

    const auto x = n.x;
    const auto y = n.y;
    const auto z = n.z;
    
    // clang-format off
    return matrix4(std::array{
          t * x * x + c,     t * x * y - s * z, t * x * z + s * y, 0.0,
          t * y * x + s * z, t * y * y + c,     t * y * z - s * x, 0.0,
          t * z * x - s * y, t * z * y + s * x, t * z * z + c,     0.0,
          0.0,               0.0,               0.0,               1.0
      });
    // clang-format on
  }

  matrix4 matrix4::translate(double x, double y, double z)
  {
    matrix4 result = matrix4::identity();
    result(0, 3)   = x;
    result(1, 3)   = y;
    result(2, 3)   = z;
    return result;
  }

  void matrix4::debug() const
  {
    for (std::size_t row = 0; row < 4; ++row)
    {
      for (std::size_t col = 0; col < 4; ++col)
      {
        std::cout << std::format("{:.2f} ", m_data[row * 4 + col]);
      }
      std::cout << '\n';
    }
  }

}  // namespace anan3d
