#ifndef ROTATION_HPP
#define ROTATION_HPP

#include "DataTypes/RotationX.hpp"
#include "DataTypes/RotationY.hpp"
#include "DataTypes/RotationZ.hpp"

#include "Entity.hpp"

struct Rotation
{
  RotationX x[MAX_ENTITY_COUNT];
  RotationY y[MAX_ENTITY_COUNT];
  RotationZ z[MAX_ENTITY_COUNT];

  unsigned long m_entity_to_index_map[MAX_ENTITY_COUNT];
  Entity m_index_to_entity_map[MAX_ENTITY_COUNT];
  unsigned long m_size = 0;
};

#endif