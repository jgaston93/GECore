#ifndef SCENE_MANAGER_HPP
#define SCENE_MANAGER_HPP

#include "Scene.hpp"

#include "DataTypes/Time.hpp"

const unsigned long MAX_SCENE_COUNT = 100;

class SceneManager
{
public:
  void addScene(Scene *scene);
  void loadScene(unsigned long scene_id);
  void update(const Time dt_ms);

  static SceneManager *getSceneManager();

private:
  Scene *m_scenes[MAX_SCENE_COUNT];
  unsigned long m_scene_count = 0;
  Scene *m_current_scene = nullptr;

  static SceneManager *m_scene_manager;
};

#endif // SCENE_MANAGER_HPP