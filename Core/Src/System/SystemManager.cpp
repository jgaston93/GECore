#include "SystemManager.hpp"


template<>
void SystemManager::addEntity<PhysicsSystem>(Entity entity)
{
  m_physics_system.addEntity(entity);
}

template<>
void SystemManager::removeEntity<PhysicsSystem>(Entity entity)
{
  m_physics_system.removeEntity(entity);
}

template<>
void SystemManager::addEntity<RenderSystem>(Entity entity)
{
  m_render_system.addEntity(entity);
}

template<>
void SystemManager::removeEntity<RenderSystem>(Entity entity)
{
  m_render_system.removeEntity(entity);
}
