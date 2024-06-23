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
  
  void addPositionComponent(Entity entity, const Position& component);
  void removePositionComponent(Entity entity);
  void getPositionComponent(Entity entity, Position* component);
  
  void addVelocityComponent(Entity entity, const Velocity& component);
  void removeVelocityComponent(Entity entity);
  void getVelocityComponent(Entity entity, Velocity* component);
  
  void addAccelerationComponent(Entity entity, const Acceleration& component);
  void removeAccelerationComponent(Entity entity);
  void getAccelerationComponent(Entity entity, Acceleration* component);
  
  void addScaleComponent(Entity entity, const Scale& component);
  void removeScaleComponent(Entity entity);
  void getScaleComponent(Entity entity, Scale* component);
  
  void addRotationComponent(Entity entity, const Rotation& component);
  void removeRotationComponent(Entity entity);
  void getRotationComponent(Entity entity, Rotation* component);
  
  void addBoundingBoxComponent(Entity entity, const BoundingBox& component);
  void removeBoundingBoxComponent(Entity entity);
  void getBoundingBoxComponent(Entity entity, BoundingBox* component);
  
  void addBoundingSphereComponent(Entity entity, const BoundingSphere& component);
  void removeBoundingSphereComponent(Entity entity);
  void getBoundingSphereComponent(Entity entity, BoundingSphere* component);
  

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