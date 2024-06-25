#include "ComponentManager.hpp"


template<>
void ComponentManager::addComponent<Position>(Entity entity, const Position& component)
{
  m_position_array.addComponent(entity, component);
};

template<>
void ComponentManager::removeComponent<Position>(Entity entity)
{
  m_position_array.removeComponent(entity);
};

template<>
void ComponentManager::getComponent<Position>(Entity entity, Position* component)
{
  m_position_array.getComponent(entity, component);
};

template<>
void ComponentManager::addComponent<Velocity>(Entity entity, const Velocity& component)
{
  m_velocity_array.addComponent(entity, component);
};

template<>
void ComponentManager::removeComponent<Velocity>(Entity entity)
{
  m_velocity_array.removeComponent(entity);
};

template<>
void ComponentManager::getComponent<Velocity>(Entity entity, Velocity* component)
{
  m_velocity_array.getComponent(entity, component);
};

template<>
void ComponentManager::addComponent<Acceleration>(Entity entity, const Acceleration& component)
{
  m_acceleration_array.addComponent(entity, component);
};

template<>
void ComponentManager::removeComponent<Acceleration>(Entity entity)
{
  m_acceleration_array.removeComponent(entity);
};

template<>
void ComponentManager::getComponent<Acceleration>(Entity entity, Acceleration* component)
{
  m_acceleration_array.getComponent(entity, component);
};

template<>
void ComponentManager::addComponent<Scale>(Entity entity, const Scale& component)
{
  m_scale_array.addComponent(entity, component);
};

template<>
void ComponentManager::removeComponent<Scale>(Entity entity)
{
  m_scale_array.removeComponent(entity);
};

template<>
void ComponentManager::getComponent<Scale>(Entity entity, Scale* component)
{
  m_scale_array.getComponent(entity, component);
};

template<>
void ComponentManager::addComponent<Rotation>(Entity entity, const Rotation& component)
{
  m_rotation_array.addComponent(entity, component);
};

template<>
void ComponentManager::removeComponent<Rotation>(Entity entity)
{
  m_rotation_array.removeComponent(entity);
};

template<>
void ComponentManager::getComponent<Rotation>(Entity entity, Rotation* component)
{
  m_rotation_array.getComponent(entity, component);
};

template<>
void ComponentManager::addComponent<BoundingBox>(Entity entity, const BoundingBox& component)
{
  m_boundingbox_array.addComponent(entity, component);
};

template<>
void ComponentManager::removeComponent<BoundingBox>(Entity entity)
{
  m_boundingbox_array.removeComponent(entity);
};

template<>
void ComponentManager::getComponent<BoundingBox>(Entity entity, BoundingBox* component)
{
  m_boundingbox_array.getComponent(entity, component);
};

template<>
void ComponentManager::addComponent<BoundingSphere>(Entity entity, const BoundingSphere& component)
{
  m_boundingsphere_array.addComponent(entity, component);
};

template<>
void ComponentManager::removeComponent<BoundingSphere>(Entity entity)
{
  m_boundingsphere_array.removeComponent(entity);
};

template<>
void ComponentManager::getComponent<BoundingSphere>(Entity entity, BoundingSphere* component)
{
  m_boundingsphere_array.getComponent(entity, component);
};
