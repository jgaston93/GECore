#ifndef POSITION_HPP
#define POSITION_HPP

#include "DataTypes/PositionX.hpp"
#include "DataTypes/PositionY.hpp"
#include "DataTypes/PositionZ.hpp"

#include "Entity.hpp"

struct Position
{
  PositionX x[MAX_ENTITY_COUNT];
  PositionY y[MAX_ENTITY_COUNT];
  PositionZ z[MAX_ENTITY_COUNT];

  unsigned long m_entity_to_index_map[MAX_ENTITY_COUNT];
  Entity m_index_to_entity_map[MAX_ENTITY_COUNT];
  unsigned long m_size = 0;
};

#endif