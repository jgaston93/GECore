#ifndef UI_SYSTEM_HPP
#define UI_SYSTEM_HPP

#include "ISystem.hpp"

class UISystem : public ISystem
{
public:
  UISystem() : ISystem(POSITION_SIGNATURE_MASK | 
                                 ROTATION_SIGNATURE_MASK | 
                                 SCALE_SIGNATURE_MASK | 
                                 BOUNDINGBOX_SIGNATURE_MASK
                                 )
  {
  }
  void init() final;
  void update(const Time dt_ms) final;
};

#endif // UI_SYSTEM_HPP