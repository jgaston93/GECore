#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "Entity.hpp"
#include "Signature.hpp"

class EntityManager
{
public:
  EntityManager();
  Entity createEntity();
  void destroyEntity(Entity e);
  void setSignature(Entity e, Signature s);
  Signature getSignature(Entity e) const;

private:
  Entity m_available_entity_count = MAX_ENTITY_COUNT;
  bool m_entity_active[MAX_ENTITY_COUNT];
  Entity m_entity_pointer = 0;
  Signature m_signatures[MAX_ENTITY_COUNT];
};

#endif // ENTITY_MANAGER_HPP