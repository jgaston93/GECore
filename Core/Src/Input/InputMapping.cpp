#include "InputMapping.hpp"

unsigned long getInputIndex(InputKey key)
{
  unsigned long index = 0;
  switch (key)
  {
  case InputKey::KEY_SPACE:
    index = 0;
    break;
  case InputKey::KEY_APOSTROPHE:
    index = 1;
    break;
  case InputKey::KEY_COMMA:
    index = 2;
    break;
  case InputKey::KEY_MINUS:
    index = 3;
    break;
  case InputKey::KEY_PERIOD:
    index = 4;
    break;
  case InputKey::KEY_SLASH:
    index = 5;
    break;
  case InputKey::KEY_0:
    index = 6;
    break;
  case InputKey::KEY_1:
    index = 7;
    break;
  case InputKey::KEY_2:
    index = 8;
    break;
  case InputKey::KEY_3:
    index = 9;
    break;
  case InputKey::KEY_4:
    index = 10;
    break;
  case InputKey::KEY_5:
    index = 11;
    break;
  case InputKey::KEY_6:
    index = 12;
    break;
  case InputKey::KEY_7:
    index = 13;
    break;
  case InputKey::KEY_8:
    index = 14;
    break;
  case InputKey::KEY_9:
    index = 15;
    break;
  case InputKey::KEY_SEMICOLON:
    index = 16;
    break;
  case InputKey::KEY_EQUAL:
    index = 17;
    break;
  case InputKey::KEY_A:
    index = 18;
    break;
  case InputKey::KEY_B:
    index = 19;
    break;
  case InputKey::KEY_C:
    index = 20;
    break;
  case InputKey::KEY_D:
    index = 21;
    break;
  case InputKey::KEY_E:
    index = 22;
    break;
  case InputKey::KEY_F:
    index = 23;
    break;
  case InputKey::KEY_G:
    index = 24;
    break;
  case InputKey::KEY_H:
    index = 25;
    break;
  case InputKey::KEY_I:
    index = 26;
    break;
  case InputKey::KEY_J:
    index = 27;
    break;
  case InputKey::KEY_K:
    index = 28;
    break;
  case InputKey::KEY_L:
    index = 29;
    break;
  case InputKey::KEY_M:
    index = 30;
    break;
  case InputKey::KEY_N:
    index = 31;
    break;
  case InputKey::KEY_O:
    index = 32;
    break;
  case InputKey::KEY_P:
    index = 33;
    break;
  case InputKey::KEY_Q:
    index = 34;
    break;
  case InputKey::KEY_R:
    index = 35;
    break;
  case InputKey::KEY_S:
    index = 36;
    break;
  case InputKey::KEY_T:
    index = 37;
    break;
  case InputKey::KEY_U:
    index = 38;
    break;
  case InputKey::KEY_V:
    index = 39;
    break;
  case InputKey::KEY_W:
    index = 40;
    break;
  case InputKey::KEY_X:
    index = 41;
    break;
  case InputKey::KEY_Y:
    index = 42;
    break;
  case InputKey::KEY_Z:
    index = 43;
    break;
  case InputKey::KEY_LEFT_BRACKET:
    index = 44;
    break;
  case InputKey::KEY_BACKSLASH:
    index = 45;
    break;
  case InputKey::KEY_RIGHT_BRACKET:
    index = 46;
    break;
  case InputKey::KEY_GRAVE_ACCENT:
    index = 47;
    break;
  case InputKey::KEY_WORLD_1:
    index = 48;
    break;
  case InputKey::KEY_WORLD_2:
    index = 49;
    break;
  case InputKey::KEY_ESCAPE:
    index = 50;
    break;
  case InputKey::KEY_ENTER:
    index = 51;
    break;
  case InputKey::KEY_TAB:
    index = 52;
    break;
  case InputKey::KEY_BACKSPACE:
    index = 53;
    break;
  case InputKey::KEY_INSERT:
    index = 54;
    break;
  case InputKey::KEY_DELETE:
    index = 55;
    break;
  case InputKey::KEY_RIGHT:
    index = 56;
    break;
  case InputKey::KEY_LEFT:
    index = 57;
    break;
  case InputKey::KEY_DOWN:
    index = 58;
    break;
  case InputKey::KEY_UP:
    index = 59;
    break;
  case InputKey::KEY_PAGE_UP:
    index = 60;
    break;
  case InputKey::KEY_PAGE_DOWN:
    index = 61;
    break;
  case InputKey::KEY_HOME:
    index = 62;
    break;
  case InputKey::KEY_END:
    index = 63;
    break;
  case InputKey::KEY_CAPS_LOCK:
    index = 64;
    break;
  case InputKey::KEY_SCROLL_LOCK:
    index = 65;
    break;
  case InputKey::KEY_NUM_LOCK:
    index = 66;
    break;
  case InputKey::KEY_PRINT_SCREEN:
    index = 67;
    break;
  case InputKey::KEY_PAUSE:
    index = 68;
    break;
  case InputKey::KEY_F1:
    index = 69;
    break;
  case InputKey::KEY_F2:
    index = 70;
    break;
  case InputKey::KEY_F3:
    index = 71;
    break;
  case InputKey::KEY_F4:
    index = 72;
    break;
  case InputKey::KEY_F5:
    index = 73;
    break;
  case InputKey::KEY_F6:
    index = 74;
    break;
  case InputKey::KEY_F7:
    index = 75;
    break;
  case InputKey::KEY_F8:
    index = 76;
    break;
  case InputKey::KEY_F9:
    index = 77;
    break;
  case InputKey::KEY_F10:
    index = 78;
    break;
  case InputKey::KEY_F11:
    index = 79;
    break;
  case InputKey::KEY_F12:
    index = 80;
    break;
  case InputKey::KEY_F13:
    index = 81;
    break;
  case InputKey::KEY_F14:
    index = 82;
    break;
  case InputKey::KEY_F15:
    index = 83;
    break;
  case InputKey::KEY_F16:
    index = 84;
    break;
  case InputKey::KEY_F17:
    index = 85;
    break;
  case InputKey::KEY_F18:
    index = 86;
    break;
  case InputKey::KEY_F19:
    index = 87;
    break;
  case InputKey::KEY_F20:
    index = 88;
    break;
  case InputKey::KEY_F21:
    index = 89;
    break;
  case InputKey::KEY_F22:
    index = 90;
    break;
  case InputKey::KEY_F23:
    index = 91;
    break;
  case InputKey::KEY_F24:
    index = 92;
    break;
  case InputKey::KEY_F25:
    index = 93;
    break;
  case InputKey::KEY_KP_0:
    index = 94;
    break;
  case InputKey::KEY_KP_1:
    index = 95;
    break;
  case InputKey::KEY_KP_2:
    index = 96;
    break;
  case InputKey::KEY_KP_3:
    index = 97;
    break;
  case InputKey::KEY_KP_4:
    index = 98;
    break;
  case InputKey::KEY_KP_5:
    index = 99;
    break;
  case InputKey::KEY_KP_6:
    index = 100;
    break;
  case InputKey::KEY_KP_7:
    index = 101;
    break;
  case InputKey::KEY_KP_8:
    index = 102;
    break;
  case InputKey::KEY_KP_9:
    index = 103;
    break;
  case InputKey::KEY_KP_DECIMAL:
    index = 104;
    break;
  case InputKey::KEY_KP_DIVIDE:
    index = 105;
    break;
  case InputKey::KEY_KP_MULTIPLY:
    index = 106;
    break;
  case InputKey::KEY_KP_SUBTRACT:
    index = 107;
    break;
  case InputKey::KEY_KP_ADD:
    index = 108;
    break;
  case InputKey::KEY_KP_ENTER:
    index = 109;
    break;
  case InputKey::KEY_KP_EQUAL:
    index = 110;
    break;
  case InputKey::KEY_LEFT_SHIFT:
    index = 111;
    break;
  case InputKey::KEY_LEFT_CONTROL:
    index = 112;
    break;
  case InputKey::KEY_LEFT_ALT:
    index = 113;
    break;
  case InputKey::KEY_LEFT_SUPER:
    index = 114;
    break;
  case InputKey::KEY_RIGHT_SHIFT:
    index = 115;
    break;
  case InputKey::KEY_RIGHT_CONTROL:
    index = 116;
    break;
  case InputKey::KEY_RIGHT_ALT:
    index = 117;
    break;
  case InputKey::KEY_RIGHT_SUPER:
    index = 118;
    break;
  case InputKey::KEY_MENU:
    index = 119;
    break;
  }
  return index;
}

InputKey getInputKey(long glfw_key)
{
  InputKey key = InputKey::Max;
  switch (glfw_key)
  {
  case GLFW_KEY_SPACE:
    key = InputKey::KEY_SPACE;
    break;
  case GLFW_KEY_APOSTROPHE:
    key = InputKey::KEY_APOSTROPHE;
    break;
  case GLFW_KEY_COMMA:
    key = InputKey::KEY_COMMA;
    break;
  case GLFW_KEY_MINUS:
    key = InputKey::KEY_MINUS;
    break;
  case GLFW_KEY_PERIOD:
    key = InputKey::KEY_PERIOD;
    break;
  case GLFW_KEY_SLASH:
    key = InputKey::KEY_SLASH;
    break;
  case GLFW_KEY_0:
    key = InputKey::KEY_0;
    break;
  case GLFW_KEY_1:
    key = InputKey::KEY_1;
    break;
  case GLFW_KEY_2:
    key = InputKey::KEY_2;
    break;
  case GLFW_KEY_3:
    key = InputKey::KEY_3;
    break;
  case GLFW_KEY_4:
    key = InputKey::KEY_4;
    break;
  case GLFW_KEY_5:
    key = InputKey::KEY_5;
    break;
  case GLFW_KEY_6:
    key = InputKey::KEY_6;
    break;
  case GLFW_KEY_7:
    key = InputKey::KEY_7;
    break;
  case GLFW_KEY_8:
    key = InputKey::KEY_8;
    break;
  case GLFW_KEY_9:
    key = InputKey::KEY_9;
    break;
  case GLFW_KEY_SEMICOLON:
    key = InputKey::KEY_SEMICOLON;
    break;
  case GLFW_KEY_EQUAL:
    key = InputKey::KEY_EQUAL;
    break;
  case GLFW_KEY_A:
    key = InputKey::KEY_A;
    break;
  case GLFW_KEY_B:
    key = InputKey::KEY_B;
    break;
  case GLFW_KEY_C:
    key = InputKey::KEY_C;
    break;
  case GLFW_KEY_D:
    key = InputKey::KEY_D;
    break;
  case GLFW_KEY_E:
    key = InputKey::KEY_E;
    break;
  case GLFW_KEY_F:
    key = InputKey::KEY_F;
    break;
  case GLFW_KEY_G:
    key = InputKey::KEY_G;
    break;
  case GLFW_KEY_H:
    key = InputKey::KEY_H;
    break;
  case GLFW_KEY_I:
    key = InputKey::KEY_I;
    break;
  case GLFW_KEY_J:
    key = InputKey::KEY_J;
    break;
  case GLFW_KEY_K:
    key = InputKey::KEY_K;
    break;
  case GLFW_KEY_L:
    key = InputKey::KEY_L;
    break;
  case GLFW_KEY_M:
    key = InputKey::KEY_M;
    break;
  case GLFW_KEY_N:
    key = InputKey::KEY_N;
    break;
  case GLFW_KEY_O:
    key = InputKey::KEY_O;
    break;
  case GLFW_KEY_P:
    key = InputKey::KEY_P;
    break;
  case GLFW_KEY_Q:
    key = InputKey::KEY_Q;
    break;
  case GLFW_KEY_R:
    key = InputKey::KEY_R;
    break;
  case GLFW_KEY_S:
    key = InputKey::KEY_S;
    break;
  case GLFW_KEY_T:
    key = InputKey::KEY_T;
    break;
  case GLFW_KEY_U:
    key = InputKey::KEY_U;
    break;
  case GLFW_KEY_V:
    key = InputKey::KEY_V;
    break;
  case GLFW_KEY_W:
    key = InputKey::KEY_W;
    break;
  case GLFW_KEY_X:
    key = InputKey::KEY_X;
    break;
  case GLFW_KEY_Y:
    key = InputKey::KEY_Y;
    break;
  case GLFW_KEY_Z:
    key = InputKey::KEY_Z;
    break;
  case GLFW_KEY_LEFT_BRACKET:
    key = InputKey::KEY_LEFT_BRACKET;
    break;
  case GLFW_KEY_BACKSLASH:
    key = InputKey::KEY_BACKSLASH;
    break;
  case GLFW_KEY_RIGHT_BRACKET:
    key = InputKey::KEY_RIGHT_BRACKET;
    break;
  case GLFW_KEY_GRAVE_ACCENT:
    key = InputKey::KEY_GRAVE_ACCENT;
    break;
  case GLFW_KEY_WORLD_1:
    key = InputKey::KEY_WORLD_1;
    break;
  case GLFW_KEY_WORLD_2:
    key = InputKey::KEY_WORLD_2;
    break;
  case GLFW_KEY_ESCAPE:
    key = InputKey::KEY_ESCAPE;
    break;
  case GLFW_KEY_ENTER:
    key = InputKey::KEY_ENTER;
    break;
  case GLFW_KEY_TAB:
    key = InputKey::KEY_TAB;
    break;
  case GLFW_KEY_BACKSPACE:
    key = InputKey::KEY_BACKSPACE;
    break;
  case GLFW_KEY_INSERT:
    key = InputKey::KEY_INSERT;
    break;
  case GLFW_KEY_DELETE:
    key = InputKey::KEY_DELETE;
    break;
  case GLFW_KEY_RIGHT:
    key = InputKey::KEY_RIGHT;
    break;
  case GLFW_KEY_LEFT:
    key = InputKey::KEY_LEFT;
    break;
  case GLFW_KEY_DOWN:
    key = InputKey::KEY_DOWN;
    break;
  case GLFW_KEY_UP:
    key = InputKey::KEY_UP;
    break;
  case GLFW_KEY_PAGE_UP:
    key = InputKey::KEY_PAGE_UP;
    break;
  case GLFW_KEY_PAGE_DOWN:
    key = InputKey::KEY_PAGE_DOWN;
    break;
  case GLFW_KEY_HOME:
    key = InputKey::KEY_HOME;
    break;
  case GLFW_KEY_END:
    key = InputKey::KEY_END;
    break;
  case GLFW_KEY_CAPS_LOCK:
    key = InputKey::KEY_CAPS_LOCK;
    break;
  case GLFW_KEY_SCROLL_LOCK:
    key = InputKey::KEY_SCROLL_LOCK;
    break;
  case GLFW_KEY_NUM_LOCK:
    key = InputKey::KEY_NUM_LOCK;
    break;
  case GLFW_KEY_PRINT_SCREEN:
    key = InputKey::KEY_PRINT_SCREEN;
    break;
  case GLFW_KEY_PAUSE:
    key = InputKey::KEY_PAUSE;
    break;
  case GLFW_KEY_F1:
    key = InputKey::KEY_F1;
    break;
  case GLFW_KEY_F2:
    key = InputKey::KEY_F2;
    break;
  case GLFW_KEY_F3:
    key = InputKey::KEY_F3;
    break;
  case GLFW_KEY_F4:
    key = InputKey::KEY_F4;
    break;
  case GLFW_KEY_F5:
    key = InputKey::KEY_F5;
    break;
  case GLFW_KEY_F6:
    key = InputKey::KEY_F6;
    break;
  case GLFW_KEY_F7:
    key = InputKey::KEY_F7;
    break;
  case GLFW_KEY_F8:
    key = InputKey::KEY_F8;
    break;
  case GLFW_KEY_F9:
    key = InputKey::KEY_F9;
    break;
  case GLFW_KEY_F10:
    key = InputKey::KEY_F10;
    break;
  case GLFW_KEY_F11:
    key = InputKey::KEY_F11;
    break;
  case GLFW_KEY_F12:
    key = InputKey::KEY_F12;
    break;
  case GLFW_KEY_F13:
    key = InputKey::KEY_F13;
    break;
  case GLFW_KEY_F14:
    key = InputKey::KEY_F14;
    break;
  case GLFW_KEY_F15:
    key = InputKey::KEY_F15;
    break;
  case GLFW_KEY_F16:
    key = InputKey::KEY_F16;
    break;
  case GLFW_KEY_F17:
    key = InputKey::KEY_F17;
    break;
  case GLFW_KEY_F18:
    key = InputKey::KEY_F18;
    break;
  case GLFW_KEY_F19:
    key = InputKey::KEY_F19;
    break;
  case GLFW_KEY_F20:
    key = InputKey::KEY_F20;
    break;
  case GLFW_KEY_F21:
    key = InputKey::KEY_F21;
    break;
  case GLFW_KEY_F22:
    key = InputKey::KEY_F22;
    break;
  case GLFW_KEY_F23:
    key = InputKey::KEY_F23;
    break;
  case GLFW_KEY_F24:
    key = InputKey::KEY_F24;
    break;
  case GLFW_KEY_F25:
    key = InputKey::KEY_F25;
    break;
  case GLFW_KEY_KP_0:
    key = InputKey::KEY_KP_0;
    break;
  case GLFW_KEY_KP_1:
    key = InputKey::KEY_KP_1;
    break;
  case GLFW_KEY_KP_2:
    key = InputKey::KEY_KP_2;
    break;
  case GLFW_KEY_KP_3:
    key = InputKey::KEY_KP_3;
    break;
  case GLFW_KEY_KP_4:
    key = InputKey::KEY_KP_4;
    break;
  case GLFW_KEY_KP_5:
    key = InputKey::KEY_KP_5;
    break;
  case GLFW_KEY_KP_6:
    key = InputKey::KEY_KP_6;
    break;
  case GLFW_KEY_KP_7:
    key = InputKey::KEY_KP_7;
    break;
  case GLFW_KEY_KP_8:
    key = InputKey::KEY_KP_8;
    break;
  case GLFW_KEY_KP_9:
    key = InputKey::KEY_KP_9;
    break;
  case GLFW_KEY_KP_DECIMAL:
    key = InputKey::KEY_KP_DECIMAL;
    break;
  case GLFW_KEY_KP_DIVIDE:
    key = InputKey::KEY_KP_DIVIDE;
    break;
  case GLFW_KEY_KP_MULTIPLY:
    key = InputKey::KEY_KP_MULTIPLY;
    break;
  case GLFW_KEY_KP_SUBTRACT:
    key = InputKey::KEY_KP_SUBTRACT;
    break;
  case GLFW_KEY_KP_ADD:
    key = InputKey::KEY_KP_ADD;
    break;
  case GLFW_KEY_KP_ENTER:
    key = InputKey::KEY_KP_ENTER;
    break;
  case GLFW_KEY_KP_EQUAL:
    key = InputKey::KEY_KP_EQUAL;
    break;
  case GLFW_KEY_LEFT_SHIFT:
    key = InputKey::KEY_LEFT_SHIFT;
    break;
  case GLFW_KEY_LEFT_CONTROL:
    key = InputKey::KEY_LEFT_CONTROL;
    break;
  case GLFW_KEY_LEFT_ALT:
    key = InputKey::KEY_LEFT_ALT;
    break;
  case GLFW_KEY_LEFT_SUPER:
    key = InputKey::KEY_LEFT_SUPER;
    break;
  case GLFW_KEY_RIGHT_SHIFT:
    key = InputKey::KEY_RIGHT_SHIFT;
    break;
  case GLFW_KEY_RIGHT_CONTROL:
    key = InputKey::KEY_RIGHT_CONTROL;
    break;
  case GLFW_KEY_RIGHT_ALT:
    key = InputKey::KEY_RIGHT_ALT;
    break;
  case GLFW_KEY_RIGHT_SUPER:
    key = InputKey::KEY_RIGHT_SUPER;
    break;
  case GLFW_KEY_MENU:
    key = InputKey::KEY_MENU;
    break;
  }
  return key;
}