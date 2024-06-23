#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "PhysicsSystem.hpp"
#include "UISystem.hpp"

class SystemManager
{
public:
  
  void addPhysicsSystemEntity(Entity entity);
  void removePhysicsSystemEntity(Entity entity);
  
  void addUISystemEntity(Entity entity);
  void removeUISystemEntity(Entity entity);
  

  void update(const Time dt_ms)
  {
    m_physics_system.update(dt_ms);
    m_ui_system.update(dt_ms);
  }

  void entityDestroyed(Entity entity)
  {
    m_physics_system.removeEntity(entity);
    m_ui_system.removeEntity(entity);
  }
private:
  PhysicsSystem m_physics_system;
  UISystem m_ui_system;
};

#endif // SYSTEM_MANAGER_HPP