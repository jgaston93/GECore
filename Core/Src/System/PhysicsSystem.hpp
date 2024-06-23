#ifndef PHYSICS_SYSTEM_HPP
#define PHYSICS_SYSTEM_HPP

#include "Entity/Entity.hpp"
#include "Entity/Signature.hpp"
#include "DataTypes/Time.hpp"

class PhysicsSystem
{
public:
  void update(const Time dt_ms);

  void addEntity(Entity entity)
  {
    if(m_entity_count < MAX_ENTITY_COUNT)
    {
      m_entities[m_entity_count++] = entity;
    }
  }

  void removeEntity(Entity entity)
  {
    bool entity_found = false;
    unsigned long entity_index = 0;
    for(unsigned long i = 0; i < m_entity_count && !entity_found; i++)
    {
      if(m_entities[i] == entity)
      {
        entity_index = i;
        entity_found = true;
      }
    }

    if(entity_found)
    {
      for(unsigned long i = entity_index; i < MAX_ENTITY_COUNT - 1; i++)
      {
        m_entities[i] = m_entities[i + 1];
      }
      m_entity_count--;
    }
  }
private:
  Entity m_entities[MAX_ENTITY_COUNT];
  Entity m_entity_count = 0;
  Signature m_signature = POSITION_SIGNATURE_MASK | VELOCITY_SIGNATURE_MASK | ACCELERATION_SIGNATURE_MASK | ROTATION_SIGNATURE_MASK;
};

#endif // PHYSICS_SYSTEM_HPP