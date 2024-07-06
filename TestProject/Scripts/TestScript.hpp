#ifndef TEST_SCRIPT_HPP
#define TEST_SCRIPT_HPP

#include "DataType/IScript.hpp"

#include "Scene/SceneManager.hpp"

class TestScript : public IScript
{
public:
  explicit TestScript(Entity entity) : IScript(entity){};
  void init() final;
  void update(const Time dt_ms) final;
};

void TestScript::init()
{
}

void TestScript::update(const Time dt_ms)
{
  Position *position = nullptr;
  SceneManager::getComponentManager()->getComponent<Position>(0, position);

  position->x += 1.0 * static_cast<float>(dt_ms) * 1e-3;
}

#endif // TEST_SCRIPT_HPP