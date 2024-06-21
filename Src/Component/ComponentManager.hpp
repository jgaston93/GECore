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
private:
  ComponentArray<Position> m_position_array;
  ComponentArray<Velocity> m_velocity_array;
  ComponentArray<Acceleration> m_acceleration_array;
  ComponentArray<Scale> m_scale_array;
  ComponentArray<Rotation> m_rotation_array;
  ComponentArray<BoundingBox> m_boundingbox_array;
  ComponentArray<BoundingSphere> m_boundingsphere_array;
};

template<>
void ComponentManager::addComponent<Position>(Entity e, const Position& component)
{
  m_position_array.addComponent(e, component);
}

template<>
void ComponentManager::removeComponent<Position>(Entity e)
{
  m_position_array.removeComponent(e);
}

template<>
void ComponentManager::getComponent<Position>(Entity e, Position* component)
{
  m_position_array.getComponent(e, component);
}

template<>
void ComponentManager::addComponent<Velocity>(Entity e, const Velocity& component)
{
  m_velocity_array.addComponent(e, component);
}

template<>
void ComponentManager::removeComponent<Velocity>(Entity e)
{
  m_velocity_array.removeComponent(e);
}

template<>
void ComponentManager::getComponent<Velocity>(Entity e, Velocity* component)
{
  m_velocity_array.getComponent(e, component);
}

template<>
void ComponentManager::addComponent<Acceleration>(Entity e, const Acceleration& component)
{
  m_acceleration_array.addComponent(e, component);
}

template<>
void ComponentManager::removeComponent<Acceleration>(Entity e)
{
  m_acceleration_array.removeComponent(e);
}

template<>
void ComponentManager::getComponent<Acceleration>(Entity e, Acceleration* component)
{
  m_acceleration_array.getComponent(e, component);
}

template<>
void ComponentManager::addComponent<Scale>(Entity e, const Scale& component)
{
  m_scale_array.addComponent(e, component);
}

template<>
void ComponentManager::removeComponent<Scale>(Entity e)
{
  m_scale_array.removeComponent(e);
}

template<>
void ComponentManager::getComponent<Scale>(Entity e, Scale* component)
{
  m_scale_array.getComponent(e, component);
}

template<>
void ComponentManager::addComponent<Rotation>(Entity e, const Rotation& component)
{
  m_rotation_array.addComponent(e, component);
}

template<>
void ComponentManager::removeComponent<Rotation>(Entity e)
{
  m_rotation_array.removeComponent(e);
}

template<>
void ComponentManager::getComponent<Rotation>(Entity e, Rotation* component)
{
  m_rotation_array.getComponent(e, component);
}

template<>
void ComponentManager::addComponent<BoundingBox>(Entity e, const BoundingBox& component)
{
  m_boundingbox_array.addComponent(e, component);
}

template<>
void ComponentManager::removeComponent<BoundingBox>(Entity e)
{
  m_boundingbox_array.removeComponent(e);
}

template<>
void ComponentManager::getComponent<BoundingBox>(Entity e, BoundingBox* component)
{
  m_boundingbox_array.getComponent(e, component);
}

template<>
void ComponentManager::addComponent<BoundingSphere>(Entity e, const BoundingSphere& component)
{
  m_boundingsphere_array.addComponent(e, component);
}

template<>
void ComponentManager::removeComponent<BoundingSphere>(Entity e)
{
  m_boundingsphere_array.removeComponent(e);
}

template<>
void ComponentManager::getComponent<BoundingSphere>(Entity e, BoundingSphere* component)
{
  m_boundingsphere_array.getComponent(e, component);
}


#endif // COMPONENT_MANAGER_HPP