#include "EntityManager.hpp"

Entity EntityManager::createEntity()
{
  Entity e = MAX_ENTITY_COUNT;

  // Ensure an entity ID is available
  if (m_entity_count < MAX_ENTITY_COUNT)
  {
    // Search for next inactive entity ID
    while (m_entity_active[m_entity_pointer] == true)
    {
      // Increment pointer and wrap-around when reached end of ID list
      m_entity_pointer++;
      if (m_entity_pointer >= MAX_ENTITY_COUNT)
      {
        m_entity_pointer = 0;
      }
    }

    // Set entity ID to active and reduce available entity count
    m_entity_active[m_entity_pointer] = true;

    // Add entity to active entity list
    m_active_entities[m_entity_count++] = m_entity_pointer;

    // Save entity ID to return
    e = m_entity_pointer;
  }
  return e;
}

void EntityManager::destroyEntity(Entity e)
{
  // Ensure entity ID is in range and active
  if (e < MAX_ENTITY_COUNT && m_entity_active[e] == true)
  {
    // Set entity ID to inactive and increase available ID count
    m_entity_active[e] = false;

    // Consolidate active enity id list
    for (unsigned long i = e; i < MAX_ENTITY_COUNT - 1; i++)
    {
      m_active_entities[i] = m_active_entities[i + 1];
    }

    m_entity_count--;
  }
}

void EntityManager::setSignature(Entity e, Signature s)
{
  // Ensure entity ID is in range and active
  if (e < MAX_ENTITY_COUNT && m_entity_active[e] == true)
  {
    m_signatures[e] = s;
  }
}

Signature EntityManager::getSignature(Entity e) const
{
  Signature s = 0;

  // Ensure entity ID is in range and active
  if (e < MAX_ENTITY_COUNT && m_entity_active[e] == true)
  {
    s = m_signatures[e];
  }
  return s;
}

unsigned long EntityManager::getNumEntities() const
{
  return m_entity_count;
}

Entity *EntityManager::getEntities()
{
  return &(m_active_entities[0]);
}
