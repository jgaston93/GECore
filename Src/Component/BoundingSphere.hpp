#ifndef BOUNDINGSPHERE_HPP
#define BOUNDINGSPHERE_HPP

#include "DataTypes/Radius.hpp"

#include "Entity.hpp"

struct BoundingSphere
{
  Radius r[MAX_ENTITY_COUNT];

  unsigned long m_entity_to_index_map[MAX_ENTITY_COUNT];
  Entity m_index_to_entity_map[MAX_ENTITY_COUNT];
  unsigned long m_size = 0;
};

#endif