#ifndef PHYSICS_SYSTEM_HPP
#define PHYSICS_SYSTEM_HPP

#include "ISystem.hpp"

class PhysicsSystem : public ISystem
{
public:
  PhysicsSystem() : ISystem(POSITION_SIGNATURE_MASK | 
                                 VELOCITY_SIGNATURE_MASK | 
                                 ACCELERATION_SIGNATURE_MASK | 
                                 ROTATION_SIGNATURE_MASK
                                 )
  {
  }
  void init() final;
  void update(const Time dt_ms) final;
};

#endif // PHYSICS_SYSTEM_HPP