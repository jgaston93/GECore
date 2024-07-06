#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include "InputMapping.hpp"

class InputManager
{
public:
  static void setKey(InputKey key, bool value);
  static bool getKey(InputKey key);

private:
  static bool m_key_info[INPUT_KEY_COUNT];
};

#endif // INPUT_MANAGER_HPP