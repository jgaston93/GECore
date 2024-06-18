#include "EntityManager.hpp"

EntityManager::EntityManager()
{
  for (unsigned long i = 0; i < MAX_ENTITY_COUNT; i++)
  {
    m_entity_active[i] = false;
    m_signatures[i] = 0;
  }
}

Entity EntityManager::CreateEntity()
{
  Entity e = MAX_ENTITY_COUNT;

  // Ensure an entity ID is available
  if (m_available_entity_count > 0)
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
    m_available_entity_count--;

    // Save entity ID to return
    e = m_entity_pointer;
  }
  return e;
}

void EntityManager::DestroyEntity(Entity e)
{
  // Ensure entity ID is in range and active
  if (e < MAX_ENTITY_COUNT && m_entity_active[e] == true)
  {
    // Set entity ID to inactive and increase available ID count
    m_entity_active[e] = false;
    m_available_entity_count++;
  }
}

void EntityManager::SetSignature(Entity e, Signature s)
{
  // Ensure entity ID is in range and active
  if (e < MAX_ENTITY_COUNT && m_entity_active[e] == true)
  {
    m_signatures[e] = s;
  }
}

Signature EntityManager::GetSignature(Entity e)
{
  Signature s = 0;

  // Ensure entity ID is in range and active
  if (e < MAX_ENTITY_COUNT && m_entity_active[e] == true)
  {
    s = m_signatures[e];
  }
  return s;
}
