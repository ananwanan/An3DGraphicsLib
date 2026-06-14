//
// Created by coder on 2026/6/12.
//

#include "shader.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

namespace anan3d
{
    Shader::Shader(const char* vertexPath, const char* fragmentPath)
    {
        std::ifstream vFile(vertexPath);
        std::ifstream fFile(fragmentPath);

        std::stringstream vStream, fStream;

        vStream << vFile.rdbuf();
        fStream << fFile.rdbuf();

        std::string vCode = vStream.str();
        std::string fCode = fStream.str();

        const char* vSrc = vCode.c_str();
        const char* fSrc = fCode.c_str();

        unsigned int vertex, fragment;

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vSrc, nullptr);
        glCompileShader(vertex);

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fSrc, nullptr);
        glCompileShader(fragment);

        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    void Shader::use() const
    {
        glUseProgram(ID);
    }
}
