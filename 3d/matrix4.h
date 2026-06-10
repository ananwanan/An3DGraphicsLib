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
    class AN3D_API matrix4
    {
    public:
        matrix4();
        virtual ~matrix4();
        // copy constructor
        matrix4(const matrix4& matrix) noexcept;
        // move constructor
        matrix4(const matrix4&& matrix) noexcept;

    public:
        /**
         * @brief the matrix4 data, 4x4 matrix
         */
        std::array<std::array<double, 4>, 4> m{};

    public:
        matrix4& operator=(const matrix4& matrix);
        matrix4& operator=(matrix4&& matrix) noexcept;

    public:
        /**
         * @brief get the identity matrix
         * @return the identity matrix
         */
        static matrix4 identity();

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
         * @brief Set the Rotation object
         * 
         * @param angle the rotation angle in degrees, only rotate around z axis
         */
        void setRotation(double angle);
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
    };
}  // namespace anan3d
