#ifndef VELOCITY_HPP
#define VELOCITY_HPP

#include "DataTypes/VelocityX.hpp"
#include "DataTypes/VelocityY.hpp"
#include "DataTypes/VelocityZ.hpp"

struct Velocity
{
  VelocityX* x;
  VelocityY* y;
  VelocityZ* z;
};

#endif