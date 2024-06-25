#ifndef COMPONENT_MANAGER_HPP
#define COMPONENT_MANAGER_HPP

#include "Position.hpp"
#include "Velocity.hpp"
#include "Acceleration.hpp"
#include "Scale.hpp"
#include "Rotation.hpp"
#include "BoundingBox.hpp"
#include "BoundingSphere.hpp"

#include "ComponentArray.hpp"
#include "Entity.hpp"

class ComponentManager
{
public:
  template<typename T>
  void addComponent(Entity, const T&)
  {
    /* NO ACTION */
  }

  template<typename T>
  void removeComponent(Entity)
  {
    /* NO ACTION */
  }

  template<typename T>
  void getComponent(Entity, T* component)
  {
    component = nullptr;
  }

  void entityDestroyed(Entity entity)
  {
    m_position_array.removeComponent(entity);
    m_velocity_array.removeComponent(entity);
    m_acceleration_array.removeComponent(entity);
    m_scale_array.removeComponent(entity);
    m_rotation_array.removeComponent(entity);
    m_boundingbox_array.removeComponent(entity);
    m_boundingsphere_array.removeComponent(entity);
  }
private:
  ComponentArray<Position> m_position_array;
  ComponentArray<Velocity> m_velocity_array;
  ComponentArray<Acceleration> m_acceleration_array;
  ComponentArray<Scale> m_scale_array;
  ComponentArray<Rotation> m_rotation_array;
  ComponentArray<BoundingBox> m_boundingbox_array;
  ComponentArray<BoundingSphere> m_boundingsphere_array;
};

#endif // COMPONENT_MANAGER_HPP