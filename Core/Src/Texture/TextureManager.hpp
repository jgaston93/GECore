#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "TextureInfo.hpp"

const unsigned long MAX_TEXTURE_NAME_SIZE = 256;
const unsigned long MAX_NUM_TEXTURES = 256;

class TextureManager
{
public:
  static void loadTexture(const char *texture_name, const char *image_name);
  static TextureInfo *getTextureInfo(const char *texture_name);

private:
  static unsigned long m_texture_count;
  static char m_texture_names[MAX_NUM_TEXTURES][MAX_TEXTURE_NAME_SIZE];
  static TextureInfo m_textures[MAX_NUM_TEXTURES];
};

#endif // TEXTURE_MANAGER_HPP