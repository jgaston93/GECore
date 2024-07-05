#include "TextureManager.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <stdio.h>
#include <string.h>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

unsigned long TextureManager::m_texture_count = 0;
char TextureManager::m_texture_names[MAX_NUM_TEXTURES][MAX_TEXTURE_NAME_SIZE] = {0};
TextureInfo TextureManager::m_textures[MAX_NUM_TEXTURES] = {0};

void TextureManager::loadTexture(const char *texture_name, const char *image_name)
{
  strcpy(m_texture_names[m_texture_count], texture_name);

  unsigned int texture = 0;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  m_textures[m_texture_count].texture_id = texture;

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  int width = 0;
  int height = 0;
  int nrChannels = 0;
  stbi_set_flip_vertically_on_load(1);
  unsigned char *data = stbi_load(image_name, &width, &height, &nrChannels, 0);
  if (data)
  {
    m_textures[m_texture_count].width = width;
    m_textures[m_texture_count].height = height;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    m_texture_count++;
  }
  else
  {
    printf("Failed to load texture\n");
  }
  stbi_image_free(data);
}

TextureInfo *TextureManager::getTextureInfo(const char *texture_name)
{
  TextureInfo *texture_info = nullptr;
  for (unsigned long i = 0; i < m_texture_count && texture_info == nullptr; i++)
  {
    if (strcmp(texture_name, m_texture_names[i]) == 0)
    {
      texture_info = &m_textures[i];
    }
  }
  return texture_info;
}