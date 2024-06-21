#ifndef I_COMPONENT_ARRAY_HPP
#define I_COMPONENT_ARRAY_HPP

#include "Entity/Entity.hpp"

class IComponentArray
{
public:
  virtual ~IComponentArray() = default;
  virtual void entityDestroyed(Entity entity) = 0;
};

#endif // I_COMPONENT_ARRAY_HPP