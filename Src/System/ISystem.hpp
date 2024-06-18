#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "DataTypes/Time.hpp"

class ISystem
{
public:
  virtual ~ISystem() = default;
  virtual void Update(Time dt_ms) = 0;
};

#endif // SYSTEM_HPP