#ifndef POSITION_HPP
#define POSITION_HPP

#include "DataTypes/PositionX.hpp"
#include "DataTypes/PositionY.hpp"
#include "DataTypes/PositionZ.hpp"

struct Position
{
  PositionX* x;
  PositionY* y;
  PositionZ* z;
};

#endif