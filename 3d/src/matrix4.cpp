//
// Created by coder on 2026/6/8.
//

#include <matrix4.h>

#include <iostream>

namespace anan3d
{
  matrix4::matrix4() = default;

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

  void matrix4::debug() const
  {
    for (std::size_t row = 0; row < 4; ++row)
    {
      for (std::size_t col = 0; col < 4; ++col)
      {
        std::cout << m_data[row * 4 + col] << ' ';
      }
      std::cout << '\n';
    }
  }

}  // namespace anan3d
