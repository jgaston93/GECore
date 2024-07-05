#ifndef VELOCITY_HPP
#define VELOCITY_HPP

#include "DataType/VelocityX.hpp"
#include "DataType/VelocityY.hpp"
#include "DataType/VelocityZ.hpp"

struct Velocity
{
  VelocityX x;
  VelocityY y;
  VelocityZ z;
};

#endif