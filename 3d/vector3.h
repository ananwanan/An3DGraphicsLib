//
// Created by anan on 2026/6/9.
//

#pragma once

#include <array>

namespace anan3d
{
    class vector3
    {
    public:
        vector3()          = default;
        virtual ~vector3() = default;

    public:
        std::array<double, 3> vec{};
    };
}  // namespace anan3d