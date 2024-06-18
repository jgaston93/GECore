#ifndef ACCELERATION_HPP
#define ACCELERATION_HPP

#include "DataTypes/AccelerationX.hpp"
#include "DataTypes/AccelerationY.hpp"
#include "DataTypes/AccelerationZ.hpp"

struct Acceleration
{
  AccelerationX* x;
  AccelerationY* y;
  AccelerationZ* z;
};

#endif