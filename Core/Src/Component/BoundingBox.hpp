#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

#include "DataType/ExtentX.hpp"
#include "DataType/ExtentY.hpp"
#include "DataType/ExtentZ.hpp"

struct BoundingBox
{
  ExtentX x;
  ExtentY y;
  ExtentZ z;
};

#endif