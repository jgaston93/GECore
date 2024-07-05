#include "ScriptSystem.hpp"
#include "Scene/SceneManager.hpp"
#include "Component/Script.hpp"

void ScriptSystem::init()
{
  const Entity *entities = getEntities();
  for (unsigned long i = 0; i < getEntityCount(); i++)
  {
    Script *script = nullptr;
    SceneManager::getComponentManager()->getComponent<Script>(i, script);
    if (script != nullptr)
    {
      script->script->init();
    }
  }
}

void ScriptSystem::update(const Time dt_ms)
{
  const Entity *entities = getEntities();
  for (unsigned long i = 0; i < getEntityCount(); i++)
  {
    Script *script = nullptr;
    SceneManager::getComponentManager()->getComponent<Script>(i, script);
    if (script != nullptr)
    {
      script->script->update(dt_ms);
    }
  }
}