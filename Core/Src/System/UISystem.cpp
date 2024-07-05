#include "UISystem.hpp"
#include "Scene/SceneManager.hpp"
#include "Component/Position.hpp"
#include "Component/Rotation.hpp"
#include "Component/Scale.hpp"
#include "Component/BoundingBox.hpp"
#include "Component/CoordinateReference.hpp"
#include "Texture/TextureManager.hpp"
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <cstdio>

const unsigned long NUM_VERTICES_PER_QUAD = 4;
const unsigned long NUM_INDICES_PER_ENTITY = 6;
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
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void UISystem::update(const Time dt_ms)
{
  const Entity *entities = getEntities();
  unsigned long entity_count = 0;
  Vertex vertices[MAX_ENTITY_COUNT * NUM_VERTICES_PER_QUAD];
  unsigned long indices[MAX_ENTITY_COUNT * NUM_INDICES_PER_ENTITY];
  for (unsigned long i = 0; i < getEntityCount(); i++)
  {
    Position *position = nullptr;
    Rotation *rotation = nullptr;
    Scale *scale = nullptr;
    BoundingBox *bounding_box = nullptr;
    CoordinateReference *coordinate_reference = nullptr;
    Texture *texture = nullptr;

    SceneManager::getComponentManager()->getComponent<Position>(entities[i], position);
    SceneManager::getComponentManager()->getComponent<Rotation>(entities[i], rotation);
    SceneManager::getComponentManager()->getComponent<Scale>(entities[i], scale);
    SceneManager::getComponentManager()->getComponent<BoundingBox>(entities[i], bounding_box);
    SceneManager::getComponentManager()->getComponent<CoordinateReference>(entities[i], coordinate_reference);
    SceneManager::getComponentManager()->getComponent<Texture>(entities[i], texture);

    if (coordinate_reference != nullptr && coordinate_reference->coordinate_space == CoordinateSpace::Screen)
    {
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 0].position[0] = position->x + (bounding_box->x / 2);
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 0].position[1] = position->y + (bounding_box->y / 2);
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 0].position[2] = position->z + 0;
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 0].tex_coord[0] = texture->x + texture->u;
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 0].tex_coord[1] = texture->y + texture->v;

      vertices[NUM_VERTICES_PER_QUAD * entity_count + 1].position[0] = position->x + (bounding_box->x / 2);
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 1].position[1] = position->y + -(bounding_box->y / 2);
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 1].position[2] = position->z + 0;
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 1].tex_coord[0] = texture->x + texture->u;
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 1].tex_coord[1] = texture->y;

      vertices[NUM_VERTICES_PER_QUAD * entity_count + 2].position[0] = position->x + -(bounding_box->x / 2);
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 2].position[1] = position->y + -(bounding_box->y / 2);
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 2].position[2] = position->z + 0;
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 2].tex_coord[0] = texture->x;
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 2].tex_coord[1] = texture->y;

      vertices[NUM_VERTICES_PER_QUAD * entity_count + 3].position[0] = position->x + -(bounding_box->x / 2);
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 3].position[1] = position->y + (bounding_box->y / 2);
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 3].position[2] = position->z + 0;
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 3].tex_coord[0] = texture->x;
      vertices[NUM_VERTICES_PER_QUAD * entity_count + 3].tex_coord[1] = texture->y + texture->v;

      indices[NUM_INDICES_PER_ENTITY * entity_count + 0] = NUM_VERTICES_PER_QUAD * entity_count + 0;
      indices[NUM_INDICES_PER_ENTITY * entity_count + 1] = NUM_VERTICES_PER_QUAD * entity_count + 1;
      indices[NUM_INDICES_PER_ENTITY * entity_count + 2] = NUM_VERTICES_PER_QUAD * entity_count + 2;
      indices[NUM_INDICES_PER_ENTITY * entity_count + 3] = NUM_VERTICES_PER_QUAD * entity_count + 2;
      indices[NUM_INDICES_PER_ENTITY * entity_count + 4] = NUM_VERTICES_PER_QUAD * entity_count + 3;
      indices[NUM_INDICES_PER_ENTITY * entity_count + 5] = NUM_VERTICES_PER_QUAD * entity_count + 0;

      entity_count++;
    }
  }
  glBufferData(GL_ARRAY_BUFFER, entity_count * NUM_VERTICES_PER_QUAD * sizeof(Vertex), vertices, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, entity_count * NUM_INDICES_PER_ENTITY * sizeof(unsigned long), indices, GL_STATIC_DRAW);
  glDrawElements(GL_TRIANGLES, entity_count * NUM_INDICES_PER_ENTITY, GL_UNSIGNED_INT, nullptr);
}