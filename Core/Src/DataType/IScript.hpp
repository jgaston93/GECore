#ifndef ISCRIPT_HPP
#define ISCRIPT_HPP

#include "Entity.hpp"
#include "Time.hpp"

class IScript
{
public:
  explicit IScript(Entity entity) : m_entity(entity) {};
  virtual ~IScript() = default;
  virtual void init() = 0;
  virtual void update(const Time dt_ms) = 0;
  Entity getEntity() { return m_entity; }
private:
  const Entity m_entity;
};

#endif