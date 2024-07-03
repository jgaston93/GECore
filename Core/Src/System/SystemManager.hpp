#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "PhysicsSystem.hpp"
#include "UISystem.hpp"
#include "ScriptSystem.hpp"

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
    m_ui_system.init();
    m_script_system.init();
  }

  void update(const Time dt_ms)
  {
    m_physics_system.update(dt_ms);
    m_ui_system.update(dt_ms);
    m_script_system.update(dt_ms);
  }

  void loadScene(Scene *scene)
  {
    m_physics_system.loadScene(scene);
    m_ui_system.loadScene(scene);
    m_script_system.loadScene(scene);
  }

  void entityDestroyed(Entity entity)
  {
    m_physics_system.removeEntity(entity);
    m_ui_system.removeEntity(entity);
    m_script_system.removeEntity(entity);
  }
private:
  PhysicsSystem m_physics_system;
  UISystem m_ui_system;
  ScriptSystem m_script_system;
};

#endif // SYSTEM_MANAGER_HPP