#ifndef VELOCITY_HPP
#define VELOCITY_HPP

#include "DataTypes/VelocityX.hpp"
#include "DataTypes/VelocityY.hpp"
#include "DataTypes/VelocityZ.hpp"

#include "Entity.hpp"

struct Velocity
{
  VelocityX x[MAX_ENTITY_COUNT];
  VelocityY y[MAX_ENTITY_COUNT];
  VelocityZ z[MAX_ENTITY_COUNT];

  unsigned long m_entity_to_index_map[MAX_ENTITY_COUNT];
  Entity m_index_to_entity_map[MAX_ENTITY_COUNT];
  unsigned long m_size = 0;
};

#endif