#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "PhysicsSystem.hpp"
#include "UISystem.hpp"

class SystemManager
{
public:
  template<typename T>
  void addEntity(Entity)
  {
    /* NO ACTION */
  }
  template<typename T>
  void removeEntity(Entity)
  {
    /* NO ACTION */
  }
private:
  PhysicsSystem m_physics_system;
  UISystem m_ui_system;
};

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


#endif // SYSTEM_MANAGER_HPP