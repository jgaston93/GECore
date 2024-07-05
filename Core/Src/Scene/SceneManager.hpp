#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include "Scene.hpp"
#include "System/SystemManager.hpp"
#include "DataType/Time.hpp"

const unsigned long MAX_SCENE_COUNT = 100;

class SceneManager
{
public:
  ~SceneManager();

  void addScene(Scene *scene);
  void loadScene(unsigned long scene_id);
  void setSystemManager(SystemManager *system_manager);

  static SceneManager *getSceneManager();
  static ComponentManager *getComponentManager();

private:
  Scene *m_scenes[MAX_SCENE_COUNT];
  unsigned long m_scene_count = 0;
  Scene *m_current_scene = nullptr;
  SystemManager *m_system_manager = nullptr;

  static SceneManager *m_scene_manager;
  static ComponentManager *m_current_component_manager;
};

#endif // SCENE_MANAGER_HPP