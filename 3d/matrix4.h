//
// Created by coder on 2026/6/8.
//

#pragma once

#include <array>
#include <type_common.h>

namespace anan3d
{
    /**
     * @brief the matrix4 class, 4x4 matrix, used for transformation in 3D space
     */
    ANAN3D_MY_DLL_H class matrix4
    {
    public:
        matrix4();
        virtual ~matrix4();
        //copy constructor
        matrix4(const matrix4& matrix) noexcept;
        //move constructor
        matrix4(const matrix4&& matrix) noexcept;
    public:
        /**
         * @brief the matrix4 data, 4x4 matrix
         */
        std::array<std::array<double, 4>, 4> m{};

    public:
        matrix4 operator =(const matrix4& matrix);
        matrix4 operator =(const matrix4&& matrix) noexcept;

    public:
        /**
         * @brief get the identity matrix
         * @return the identity matrix
         */
        static matrix4 identity();

    public:
        /**
         * @brief set the translation component of the matrix
         */
        void setTranslation(double x, double y, double z);
        void setRotation(double angle);
        void setScale(double x, double y, double z);
    public:
        /**
         * @brief debug the matrix4, only in debug mode
         */
        void debug();

    };
}
