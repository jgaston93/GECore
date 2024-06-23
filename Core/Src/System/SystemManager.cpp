#include "SystemManager.hpp"


void SystemManager::addPhysicsSystemEntity(Entity entity)
{
  m_physics_system.addEntity(entity);
}

void SystemManager::removePhysicsSystemEntity(Entity entity)
{
  m_physics_system.removeEntity(entity);
}

void SystemManager::addUISystemEntity(Entity entity)
{
  m_ui_system.addEntity(entity);
}

void SystemManager::removeUISystemEntity(Entity entity)
{
  m_ui_system.removeEntity(entity);
}
