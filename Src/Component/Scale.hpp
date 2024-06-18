#ifndef SCALE_HPP
#define SCALE_HPP

#include "DataTypes/ScaleX.hpp"
#include "DataTypes/ScaleY.hpp"
#include "DataTypes/ScaleZ.hpp"

#include "Entity.hpp"

struct Scale
{
  ScaleX x[MAX_ENTITY_COUNT];
  ScaleY y[MAX_ENTITY_COUNT];
  ScaleZ z[MAX_ENTITY_COUNT];

  unsigned long m_entity_to_index_map[MAX_ENTITY_COUNT];
  Entity m_index_to_entity_map[MAX_ENTITY_COUNT];
  unsigned long m_size = 0;
};

#endif