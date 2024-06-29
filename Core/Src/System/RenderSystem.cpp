#include "RenderSystem.hpp"
#include "Scene/SceneManager.hpp"
#include "Component/Position.hpp"
#include "Component/Rotation.hpp"
#include "Component/Scale.hpp"
#include "Component/BoundingBox.hpp"
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cstdio>

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "} \n\0";

void RenderSystem::init()
{
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);

  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
    printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED: %s\n", infoLog);
  }

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
    printf("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED: %s\n", infoLog);
  }

  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();

  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);

  glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(shaderProgram, 512, nullptr, infoLog);
    printf("ERROR::SHADER::PROGRAM::COMPILATION_FAILED: %s\n", infoLog);
  }

  glUseProgram(shaderProgram);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)nullptr);
  glEnableVertexAttribArray(0);
}

void RenderSystem::update(const Time dt_ms)
{
  const Entity *entities = getEntities();
  float vertices[12];
  for (unsigned long i = 0; i < getEntityCount(); i++)
  {
    BoundingBox *bounding_box = nullptr;
    SceneManager::getComponentManager()->getComponent<BoundingBox>(entities[i], bounding_box);
    vertices[0] = -(bounding_box->x / 2);
    vertices[1] = -(bounding_box->y / 2);
    vertices[2] = -(bounding_box->z / 2);

    vertices[3] = -(bounding_box->x / 2);
    vertices[4] = -(bounding_box->y / 2);
    vertices[5] = -(bounding_box->z / 2);

    vertices[6] = -(bounding_box->x / 2);
    vertices[7] = -(bounding_box->y / 2);
    vertices[8] = -(bounding_box->z / 2);

    vertices[9] = -(bounding_box->x / 2);
    vertices[10] = -(bounding_box->y / 2);
    vertices[11] = -(bounding_box->z / 2);
  }
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}