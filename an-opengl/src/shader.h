//
// Created by coder on 2026/6/12.
//

#pragma once

#include <string>
#include <glm/glm.hpp>

namespace anan3d
{
    class Shader
    {
    public:
        unsigned int ID;

        Shader(const char* vertexPath, const char* fragmentPath);

        void use() const;

        void setBool(const std::string& name, bool value);
        void setInt(const std::string& name, int value);
        void setFloat(const std::string& name, float value);
        void setVec3(const std::string& name, const glm::vec3& value);
    };
}
