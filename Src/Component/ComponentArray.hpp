#ifndef COMPONENT_ARRAY_HPP
#define COMPONENT_ARRAY_HPP

template <typename T>
class ComponentArray
{
public:
  bool isEntityAvailable(Entity entity) const
  {
    bool entity_found = false;
    for (unsigned long i = 0; i < m_size && !entity_found; i++)
    {
      if (m_entity_to_index_map[i] == entity)
      {
        entity_found = true;
      }
    }
    return entity_found;
  }

  void addComponent(Entity entity, const T &component)
  {
    if (m_size < MAX_ENTITY_COUNT)
    {
      bool entity_found = isEntityAvailable(entity);

      if (!entity_found)
      {
        unsigned long new_index = m_size;
        m_entity_to_index_map[entity] = new_index;
        m_index_to_entity_map[new_index] = entity;
        m_array[new_index] = component;
        m_size++;
      }
    }
  }

  void removeComponent(Entity entity)
  {
    bool entity_found = isEntityAvailable(entity);

    if (entity_found)
    {
      unsigned long removed_index = m_entity_to_index_map[entity];
      unsigned long last_index = m_size - 1;
      m_array[removed_index] = m_array[last_index];

      Entity last_entity = m_index_to_entity_map[last_index];
      m_entity_to_index_map[last_entity] = removed_index;
      m_index_to_entity_map[removed_index] = last_entity;

      m_size--;
    }
  }

  void getComponent(Entity entity, T *component)
  {
    component = nullptr;

    bool entity_found = false;
    for (unsigned long i = 0; i < m_size && !entity_found; i++)
    {
      if (m_entity_to_index_map[i] == entity)
      {
        entity_found = true;
        component = &m_array[m_entity_to_index_map[i]];
      }
    }
  }

private:
  T m_array[MAX_ENTITY_COUNT];
  unsigned long m_entity_to_index_map[MAX_ENTITY_COUNT];
  Entity m_index_to_entity_map[MAX_ENTITY_COUNT];
  unsigned long m_size = 0;
};

#endif // COMPONENT_ARRAY_HPP