#ifndef POSITION_HPP
#define POSITION_HPP

#include "DataType/PositionX.hpp"
#include "DataType/PositionY.hpp"
#include "DataType/PositionZ.hpp"

struct Position
{
  PositionX x;
  PositionY y;
  PositionZ z;
};

#endif