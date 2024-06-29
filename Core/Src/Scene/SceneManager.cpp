#include "SceneManager.hpp"

SceneManager *SceneManager::m_scene_manager = nullptr;

SceneManager::~SceneManager()
{
  delete m_scene_manager;
}

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
    m_system_manager->loadScene(m_current_scene);
  }
}

void SceneManager::setSystemManager(SystemManager *system_manager)
{
  m_system_manager = system_manager;
}

SceneManager *SceneManager::getSceneManager()
{
  if (m_scene_manager == nullptr)
  {
    m_scene_manager = new SceneManager();
  }
  return m_scene_manager;
}
