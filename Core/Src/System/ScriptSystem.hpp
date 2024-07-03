#ifndef SCRIPT_SYSTEM_HPP
#define SCRIPT_SYSTEM_HPP

#include "ISystem.hpp"

class ScriptSystem : public ISystem
{
public:
  ScriptSystem() : ISystem(SCRIPT_SIGNATURE_MASK
                                 )
  {
  }
  void init() final;
  void update(const Time dt_ms) final;
};

#endif // SCRIPT_SYSTEM_HPP