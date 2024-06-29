#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "Entity.hpp"
#include "Signature.hpp"

class EntityManager
{
public:
  Entity createEntity();
  void destroyEntity(Entity e);
  void setSignature(Entity e, Signature s);
  Signature getSignature(Entity e) const;
  unsigned long getNumEntities() const;
  Entity *getEntities();

private:
  Entity m_entity_count = 0;
  Entity m_active_entities[MAX_ENTITY_COUNT] = {0};
  bool m_entity_active[MAX_ENTITY_COUNT] = {false};
  Entity m_entity_pointer = 0;
  Signature m_signatures[MAX_ENTITY_COUNT] = {0};
};

#endif // ENTITY_MANAGER_HPP