#include "Scene.hpp"

Scene::Scene(unsigned long scene_id) : m_scene_id(scene_id)
{
}

EntityManager *Scene::getEntityManager()
{
  return &m_entity_manager;
}
ComponentManager *Scene::getComponentManager()
{
  return &m_component_manager;
}