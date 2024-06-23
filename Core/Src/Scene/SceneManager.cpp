#include "SceneManager.hpp"

SceneManager *SceneManager::m_scene_manager = nullptr;

void SceneManager::addScene(Scene *scene)
{
  if (m_scene_count < MAX_SCENE_COUNT)
  {
    m_scenes[m_scene_count++] = scene;
  }
}
void SceneManager::loadScene(unsigned long scene_id)
{
  if (scene_id < MAX_SCENE_COUNT)
  {
    m_current_scene = m_scenes[scene_id];
  }
}
void SceneManager::update(const Time dt_ms)
{
  m_current_scene->update(dt_ms);
}

SceneManager *SceneManager::getSceneManager()
{
  if (m_scene_manager == nullptr)
  {
    m_scene_manager = new SceneManager();
  }
  return m_scene_manager;
}
