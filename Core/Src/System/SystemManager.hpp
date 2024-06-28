#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "PhysicsSystem.hpp"
#include "RenderSystem.hpp"

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

  void update(const Time dt_ms)
  {
    m_physics_system.update(dt_ms);
    m_render_system.update(dt_ms);
  }

  void entityDestroyed(Entity entity)
  {
    m_physics_system.removeEntity(entity);
    m_render_system.removeEntity(entity);
  }
private:
  PhysicsSystem m_physics_system;
  RenderSystem m_render_system;
};

#endif // SYSTEM_MANAGER_HPP