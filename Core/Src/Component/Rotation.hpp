#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "DataType/RotationX.hpp"
#include "DataType/RotationY.hpp"
#include "DataType/RotationZ.hpp"

struct Rotation
{
  RotationX x;
  RotationY y;
  RotationZ z;
};

#endif