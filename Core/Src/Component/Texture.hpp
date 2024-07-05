#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "DataType/TextureName.hpp"
#include "DataType/PositionX.hpp"
#include "DataType/PositionY.hpp"
#include "DataType/ExtentX.hpp"
#include "DataType/ExtentY.hpp"

struct Texture
{
  TextureName texture_name;
  PositionX x;
  PositionY y;
  ExtentX u;
  ExtentY v;
};

#endif