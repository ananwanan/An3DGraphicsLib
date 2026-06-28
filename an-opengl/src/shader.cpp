//
// Created by coder on 2026/6/12.
//

#include "shader.h"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

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

  int  success;
  char infoLog[1024];

  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vSrc, nullptr);
  glCompileShader(vertex);
  glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertex, 1024, nullptr, infoLog);
    std::cout << "VERTEX SHADER ERROR:\n" << infoLog << std::endl;
  }

  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fSrc, nullptr);
  glCompileShader(fragment);
  glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragment, 1024, nullptr, infoLog);
    std::cout << "FRAGMENT SHADER ERROR:\n" << infoLog << std::endl;
  }

  ID = glCreateProgram();
  glAttachShader(ID, vertex);
  glAttachShader(ID, fragment);
  glLinkProgram(ID);

  printOpenGLVersion();

  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void Shader::use() const { glUseProgram(ID); }

void Shader::printOpenGLVersion()
{
  const GLubyte* version = glGetString(GL_VERSION);

  if (!version)
  {
    std::cerr << "Failed to get OpenGL version (no context?)" << std::endl;
  }

  std::cout << "OpenGL Version: " << version << std::endl;
}
