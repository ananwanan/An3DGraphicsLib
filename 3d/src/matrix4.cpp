//
// Created by coder on 2026/6/8.
//

#include <iostream>
#include "../matrix4.h"

namespace anan3d
{
    matrix4::matrix4()
    {}

    matrix4::~matrix4()
    {}

    matrix4::matrix4(const matrix4& matrix) noexcept
    {
        m = matrix.m;
    }

    matrix4::matrix4(const matrix4&& matrix) noexcept :m(std::move(matrix.m))
    {}

    matrix4 matrix4::operator=(const matrix4& matrix)
    {
        if (this == &matrix)
        {
            return *this;
        }
        m = matrix.m;
        return *this;
    }


    matrix4 matrix4::operator=(const matrix4&& matrix) noexcept
    {
        if (this == &matrix)
        {
            return *this;
        }
        m = matrix.m;
        return *this;
    }

    void matrix4::debug()
    {
#ifdef _DEBUG
        for (auto& row : m)
        {
            for (auto& col : row)
            {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }
#endif // _DEBUG

    }

}
