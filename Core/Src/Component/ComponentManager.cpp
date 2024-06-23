#include "ComponentManager.hpp"


void ComponentManager::addPositionComponent(Entity entity, const Position& component)
{
  m_position_array.addComponent(entity, component);
}

void ComponentManager::removePositionComponent(Entity entity)
{
  m_position_array.removeComponent(entity);
}

void ComponentManager::getPositionComponent(Entity entity, Position* component)
{
  m_position_array.getComponent(entity, component);
}

void ComponentManager::addVelocityComponent(Entity entity, const Velocity& component)
{
  m_velocity_array.addComponent(entity, component);
}

void ComponentManager::removeVelocityComponent(Entity entity)
{
  m_velocity_array.removeComponent(entity);
}

void ComponentManager::getVelocityComponent(Entity entity, Velocity* component)
{
  m_velocity_array.getComponent(entity, component);
}

void ComponentManager::addAccelerationComponent(Entity entity, const Acceleration& component)
{
  m_acceleration_array.addComponent(entity, component);
}

void ComponentManager::removeAccelerationComponent(Entity entity)
{
  m_acceleration_array.removeComponent(entity);
}

void ComponentManager::getAccelerationComponent(Entity entity, Acceleration* component)
{
  m_acceleration_array.getComponent(entity, component);
}

void ComponentManager::addScaleComponent(Entity entity, const Scale& component)
{
  m_scale_array.addComponent(entity, component);
}

void ComponentManager::removeScaleComponent(Entity entity)
{
  m_scale_array.removeComponent(entity);
}

void ComponentManager::getScaleComponent(Entity entity, Scale* component)
{
  m_scale_array.getComponent(entity, component);
}

void ComponentManager::addRotationComponent(Entity entity, const Rotation& component)
{
  m_rotation_array.addComponent(entity, component);
}

void ComponentManager::removeRotationComponent(Entity entity)
{
  m_rotation_array.removeComponent(entity);
}

void ComponentManager::getRotationComponent(Entity entity, Rotation* component)
{
  m_rotation_array.getComponent(entity, component);
}

void ComponentManager::addBoundingBoxComponent(Entity entity, const BoundingBox& component)
{
  m_boundingbox_array.addComponent(entity, component);
}

void ComponentManager::removeBoundingBoxComponent(Entity entity)
{
  m_boundingbox_array.removeComponent(entity);
}

void ComponentManager::getBoundingBoxComponent(Entity entity, BoundingBox* component)
{
  m_boundingbox_array.getComponent(entity, component);
}

void ComponentManager::addBoundingSphereComponent(Entity entity, const BoundingSphere& component)
{
  m_boundingsphere_array.addComponent(entity, component);
}

void ComponentManager::removeBoundingSphereComponent(Entity entity)
{
  m_boundingsphere_array.removeComponent(entity);
}

void ComponentManager::getBoundingSphereComponent(Entity entity, BoundingSphere* component)
{
  m_boundingsphere_array.getComponent(entity, component);
}
