#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "DataTypes/TextureName.hpp"
#include "DataTypes/PositionX.hpp"
#include "DataTypes/PositionY.hpp"
#include "DataTypes/ExtentX.hpp"
#include "DataTypes/ExtentY.hpp"

struct Texture
{
  TextureName texture_name;
  PositionX x;
  PositionY y;
  ExtentX u;
  ExtentY v;
};

#endif