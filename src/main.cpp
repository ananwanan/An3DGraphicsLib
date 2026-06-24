//
// Created by coder on 2026/6/12.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>

#include <iostream>

#include <shader.h>

#include <matrix4.h>

USE_NP

void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }

int _main()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr);
  glfwMakeContextCurrent(window);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to init GLAD\n";
    return -1;
  }

  Shader shader("shaders/basic.vert", "shaders/basic.frag");

  float vertices[] = { 0.0f, 0.5f, 0.0f, -0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f };

  unsigned int VAO, VBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);

    shader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}

void test_with_gl()
{
  glm::vec3 pos1(12.12f, 26.0f, 3.34f);
  glm::vec3 pos2(11.34f, 12.0f, 3.34f);

  glm::vec3 result = glm::cross(pos1, pos2);
  std::cout << result.x << " " << result.y << " " << result.z << std::endl;

  double dot = glm::dot(pos1, pos2);
  std::cout << dot << " " << dot << " " << dot << std::endl;

  pos1           = glm::normalize(pos1);
  pos2           = glm::normalize(pos2);
  double radians = glm::angle(pos1, pos2);
  std::cout << "radians:" << radians << std::endl;
}

void test_with_ge()
{
  vector3 pos1(12.12f, 26.0f, 3.34f);
  vector3 pos2(11.34f, 12.0f, 3.34f);

  vector3 result = pos1.crossProduct(pos2);
  result.debug();

  double dot = pos1.dotProduct(pos2);
  std::cout << dot << " " << dot << " " << dot << std::endl;

  double radians = pos1.getAngle(pos2);
  std::cout << "radians:" << radians << std::endl;
}

int main()
{
  // 旋转 90 度 (PI / 2)
  const double radians = 3.14159265358979323846 / 2.0;
  test_with_gl();
  std::cout << "--------- test_with_gl end ---------" << std::endl;
  test_with_ge();

  return 0;
}