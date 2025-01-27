#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "Entity/EntityManager.hpp"
#include "DataType/Time.hpp"
#include "Scene/Scene.hpp"

class ISystem
{
public:
  explicit ISystem(Signature signature) : m_signature(signature){};
  virtual ~ISystem() = default;

  virtual void init() = 0;
  virtual void update(const Time dt_ms) = 0;

  void addEntity(Entity entity)
  {
    if (m_entity_count < MAX_ENTITY_COUNT)
    {
      m_entities[m_entity_count++] = entity;
    }
  }

  void removeEntity(Entity entity)
  {
    bool entity_found = false;
    unsigned long entity_index = 0;
    for (unsigned long i = 0; i < m_entity_count && !entity_found; i++)
    {
      if (m_entities[i] == entity)
      {
        entity_index = i;
        entity_found = true;
      }
    }

    if (entity_found)
    {
      for (unsigned long i = entity_index; i < MAX_ENTITY_COUNT - 1; i++)
      {
        m_entities[i] = m_entities[i + 1];
      }
      m_entity_count--;
    }
  }

  void loadScene(Scene *scene)
  {
    EntityManager *entity_manager = scene->getEntityManager();
    const Entity *entity_list = entity_manager->getEntities();
    m_entity_count = 0;
    for (unsigned long i = 0; i < entity_manager->getNumEntities(); i++)
    {
      if ((entity_manager->getSignature(entity_list[i]) & m_signature) == m_signature)
      {
        m_entities[i] = entity_list[i];
        m_entity_count++;
      }
    }
  }

  unsigned long getEntityCount() const
  {
    return m_entity_count;
  }

  Entity *getEntities()
  {
    return &(m_entities[0]);
  }

private:
  Entity m_entities[MAX_ENTITY_COUNT];
  Entity m_entity_count = 0;
  Signature m_signature = 0;
};

#endif // SYSTEM_HPP