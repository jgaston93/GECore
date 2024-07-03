#include "UISystem.hpp"
#include "Scene/SceneManager.hpp"
#include "Component/Position.hpp"
#include "Component/Rotation.hpp"
#include "Component/Scale.hpp"
#include "Component/BoundingBox.hpp"
#include "Texture/TextureManager.hpp"
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cstdio>

struct Vertex
{
  float position[3];
  float color[3];
  float tex_coord[2];
};

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "layout (location = 1) in vec3 aColor;\n"
                                 "layout (location = 2) in vec2 aTexCoord;\n"
                                 "out vec3 ourColor;\n"
                                 "out vec2 TexCoord;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos, 1.0);\n"
                                 "   ourColor = aColor;\n"
                                 "   TexCoord = aTexCoord;\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "in vec3 ourColor;\n"
                                   "in vec2 TexCoord;\n"
                                   "uniform sampler2D ourTexture;\n"
                                   "void main()\n"
                                   "{\n"
                                   "    FragColor = texture(ourTexture, TexCoord);\n"
                                   "} \n\0";

void UISystem::init()
{
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  unsigned int EBO;
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

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

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)nullptr);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
  glEnableVertexAttribArray(2);

  TextureManager::loadTexture("test_texture", "TestProject/Textures/TestPng.jpg");
}

void UISystem::update(const Time dt_ms)
{
  const Entity *entities = getEntities();
  Vertex vertices[4];
  unsigned long indices[6];
  for (unsigned long i = 0; i < getEntityCount(); i++)
  {
    BoundingBox *bounding_box = nullptr;
    SceneManager::getComponentManager()->getComponent<BoundingBox>(entities[i], bounding_box);
    vertices[0].position[0] = (bounding_box->x / 2);
    vertices[0].position[1] = (bounding_box->y / 2);
    vertices[0].position[2] = 0;
    vertices[0].tex_coord[0] = 0.5;
    vertices[0].tex_coord[1] = 0.5;

    vertices[1].position[0] = (bounding_box->x / 2);
    vertices[1].position[1] = -(bounding_box->y / 2);
    vertices[1].position[2] = 0;
    vertices[1].tex_coord[0] = 0.5;
    vertices[1].tex_coord[1] = 0;

    vertices[2].position[0] = -(bounding_box->x / 2);
    vertices[2].position[1] = -(bounding_box->y / 2);
    vertices[2].position[2] = 0;
    vertices[2].tex_coord[0] = 0;
    vertices[2].tex_coord[1] = 0;

    vertices[3].position[0] = -(bounding_box->x / 2);
    vertices[3].position[1] = (bounding_box->y / 2);
    vertices[3].position[2] = 0;
    vertices[3].tex_coord[0] = 0;
    vertices[3].tex_coord[1] = 0.5;

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    indices[3] = 2;
    indices[4] = 3;
    indices[5] = 0;
  }
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}