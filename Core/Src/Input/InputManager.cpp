#include "InputManager.hpp"

bool InputManager::m_key_info[INPUT_KEY_COUNT] = {0};

void InputManager::setKey(InputKey key, bool value)
{
  m_key_info[getInputIndex(key)] = value;
}

bool InputManager::getKey(InputKey key)
{
  return m_key_info[getInputIndex(key)];
}
