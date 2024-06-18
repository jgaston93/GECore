#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "Entity.hpp"
#include "Signature.hpp"

class EntityManager
{
public:
  EntityManager();
  Entity CreateEntity();
  void DestroyEntity(Entity e);
  void SetSignature(Entity e, Signature s);
  Signature GetSignature(Entity e);

private:
  Entity m_available_entity_count = MAX_ENTITY_COUNT;
  bool m_entity_active[MAX_ENTITY_COUNT];
  Entity m_entity_pointer = 1;
  Signature m_signatures[MAX_ENTITY_COUNT];
};

#endif // ENTITY_MANAGER_HPP