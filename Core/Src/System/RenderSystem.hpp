#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "ISystem.hpp"

class RenderSystem : public ISystem
{
public:
  RenderSystem() : ISystem(POSITION_SIGNATURE_MASK | 
                                 ROTATION_SIGNATURE_MASK | 
                                 SCALE_SIGNATURE_MASK | 
                                 BOUNDINGBOX_SIGNATURE_MASK
                                 )
  {
  }
  void init() final;
  void update(const Time dt_ms) final;
};

#endif // RENDER_SYSTEM_HPP