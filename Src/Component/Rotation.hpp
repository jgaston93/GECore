#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "DataTypes/RotationX.hpp"
#include "DataTypes/RotationY.hpp"
#include "DataTypes/RotationZ.hpp"

struct Rotation
{
  RotationX* x;
  RotationY* y;
  RotationZ* z;
};

#endif