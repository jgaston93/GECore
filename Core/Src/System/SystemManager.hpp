#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "PhysicsSystem.hpp"
#include "RenderSystem.hpp"

#include "Scene/Scene.hpp"

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
  
  void init()
  {
    m_physics_system.init();
    m_render_system.init();
  }

  void update(const Time dt_ms)
  {
    m_physics_system.update(dt_ms);
    m_render_system.update(dt_ms);
  }

  void loadScene(Scene *scene)
  {
    m_physics_system.loadScene(scene);
    m_render_system.loadScene(scene);
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