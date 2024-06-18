#ifndef ACCELERATION_HPP
#define ACCELERATION_HPP

#include "DataTypes/AccelerationX.hpp"
#include "DataTypes/AccelerationY.hpp"
#include "DataTypes/AccelerationZ.hpp"

#include "Entity.hpp"

struct Acceleration
{
  AccelerationX x[MAX_ENTITY_COUNT];
  AccelerationY y[MAX_ENTITY_COUNT];
  AccelerationZ z[MAX_ENTITY_COUNT];

  unsigned long m_entity_to_index_map[MAX_ENTITY_COUNT];
  Entity m_index_to_entity_map[MAX_ENTITY_COUNT];
  unsigned long m_size = 0;
};

#endif