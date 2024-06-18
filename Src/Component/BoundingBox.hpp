#ifndef BOUNDINGBOX_HPP
#define BOUNDINGBOX_HPP

#include "DataTypes/ExtentX.hpp"
#include "DataTypes/ExtentY.hpp"
#include "DataTypes/ExtentZ.hpp"

#include "Entity.hpp"

struct BoundingBox
{
  ExtentX x[MAX_ENTITY_COUNT];
  ExtentY y[MAX_ENTITY_COUNT];
  ExtentZ z[MAX_ENTITY_COUNT];

  unsigned long m_entity_to_index_map[MAX_ENTITY_COUNT];
  Entity m_index_to_entity_map[MAX_ENTITY_COUNT];
  unsigned long m_size = 0;
};

#endif