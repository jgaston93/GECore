#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

#include "DataTypes/ExtentX.hpp"
#include "DataTypes/ExtentY.hpp"
#include "DataTypes/ExtentZ.hpp"

struct BoundingBox
{
  ExtentX* x;
  ExtentY* y;
  ExtentZ* z;
};

#endif