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
void SystemManager::addEntity<UISystem>(Entity entity)
{
  m_ui_system.addEntity(entity);
}

template<>
void SystemManager::removeEntity<UISystem>(Entity entity)
{
  m_ui_system.removeEntity(entity);
}

template<>
void SystemManager::addEntity<ScriptSystem>(Entity entity)
{
  m_script_system.addEntity(entity);
}

template<>
void SystemManager::removeEntity<ScriptSystem>(Entity entity)
{
  m_script_system.removeEntity(entity);
}
