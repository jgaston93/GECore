#ifndef PHYSICS_SYSTEM_HPP
#define PHYSICS_SYSTEM_HPP

#include "ISystem.hpp"

class PhysicsSystem : public ISystem
{
public:
  void Update(Time dt_ms) final;
};

#endif // PHYSICS_SYSTEM_HPP