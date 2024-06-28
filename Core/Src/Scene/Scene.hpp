#ifndef SCENE_HPP
#define SCENE_HPP

#include "Entity/EntityManager.hpp"
#include "Component/ComponentManager.hpp"
#include "System/SystemManager.hpp"

class Scene
{
public:
  explicit Scene(unsigned long scene_id);

  void update(const Time dt_ms);

  EntityManager *getEntityManager();
  ComponentManager *getComponentManager();
  SystemManager *getSystemManager();

private:
  const unsigned long m_scene_id;
  EntityManager m_entity_manager;
  ComponentManager m_component_manager;
  SystemManager m_system_manager;
};

#endif // SCENE_HPP
