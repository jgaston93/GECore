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

template<>
void ComponentManager::addComponent<Position>(Entity entity, const Position& component)
{
  m_position_array.addComponent(entity, component);
}

template<>
void ComponentManager::removeComponent<Position>(Entity entity)
{
  m_position_array.removeComponent(entity);
}

template<>
void ComponentManager::getComponent<Position>(Entity entity, Position* component)
{
  m_position_array.getComponent(entity, component);
}

template<>
void ComponentManager::addComponent<Velocity>(Entity entity, const Velocity& component)
{
  m_velocity_array.addComponent(entity, component);
}

template<>
void ComponentManager::removeComponent<Velocity>(Entity entity)
{
  m_velocity_array.removeComponent(entity);
}

template<>
void ComponentManager::getComponent<Velocity>(Entity entity, Velocity* component)
{
  m_velocity_array.getComponent(entity, component);
}

template<>
void ComponentManager::addComponent<Acceleration>(Entity entity, const Acceleration& component)
{
  m_acceleration_array.addComponent(entity, component);
}

template<>
void ComponentManager::removeComponent<Acceleration>(Entity entity)
{
  m_acceleration_array.removeComponent(entity);
}

template<>
void ComponentManager::getComponent<Acceleration>(Entity entity, Acceleration* component)
{
  m_acceleration_array.getComponent(entity, component);
}

template<>
void ComponentManager::addComponent<Scale>(Entity entity, const Scale& component)
{
  m_scale_array.addComponent(entity, component);
}

template<>
void ComponentManager::removeComponent<Scale>(Entity entity)
{
  m_scale_array.removeComponent(entity);
}

template<>
void ComponentManager::getComponent<Scale>(Entity entity, Scale* component)
{
  m_scale_array.getComponent(entity, component);
}

template<>
void ComponentManager::addComponent<Rotation>(Entity entity, const Rotation& component)
{
  m_rotation_array.addComponent(entity, component);
}

template<>
void ComponentManager::removeComponent<Rotation>(Entity entity)
{
  m_rotation_array.removeComponent(entity);
}

template<>
void ComponentManager::getComponent<Rotation>(Entity entity, Rotation* component)
{
  m_rotation_array.getComponent(entity, component);
}

template<>
void ComponentManager::addComponent<BoundingBox>(Entity entity, const BoundingBox& component)
{
  m_boundingbox_array.addComponent(entity, component);
}

template<>
void ComponentManager::removeComponent<BoundingBox>(Entity entity)
{
  m_boundingbox_array.removeComponent(entity);
}

template<>
void ComponentManager::getComponent<BoundingBox>(Entity entity, BoundingBox* component)
{
  m_boundingbox_array.getComponent(entity, component);
}

template<>
void ComponentManager::addComponent<BoundingSphere>(Entity entity, const BoundingSphere& component)
{
  m_boundingsphere_array.addComponent(entity, component);
}

template<>
void ComponentManager::removeComponent<BoundingSphere>(Entity entity)
{
  m_boundingsphere_array.removeComponent(entity);
}

template<>
void ComponentManager::getComponent<BoundingSphere>(Entity entity, BoundingSphere* component)
{
  m_boundingsphere_array.getComponent(entity, component);
}


#endif // COMPONENT_MANAGER_HPP