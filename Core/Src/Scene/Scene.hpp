#ifndef SCENE_HPP
#define SCENE_HPP

#include "Entity/EntityManager.hpp"
#include "Component/ComponentManager.hpp"

class Scene
{
public:
  explicit Scene(unsigned long scene_id);
  EntityManager *getEntityManager();
  ComponentManager *getComponentManager();

private:
  const unsigned long m_scene_id;
  EntityManager m_entity_manager;
  ComponentManager m_component_manager;
};

#endif // SCENE_HPP
