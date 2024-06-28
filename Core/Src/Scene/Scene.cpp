#include "Scene.hpp"

Scene::Scene(unsigned long scene_id) : m_scene_id(scene_id)
{
}
void Scene::update(const Time dt_ms)
{
  m_system_manager.update(dt_ms);
}

EntityManager *Scene::getEntityManager()
{
  return &m_entity_manager;
}
ComponentManager *Scene::getComponentManager()
{
  return &m_component_manager;
}
SystemManager *Scene::getSystemManager()
{
  return &m_system_manager;
}