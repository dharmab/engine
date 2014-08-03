#ifndef Core_KeyCode_h
#define Core_KeyCode_h

enum KeyCode {
    KEYBOARD_UNKNOWN = -1,
    // USB HID 1.12 key codes for US keyboard
    KEYBOARD_A = 4,
    KEYBOARD_B = 5,
    KEYBOARD_C = 6,
    KEYBOARD_D = 7,
    KEYBOARD_E = 8,
    KEYBOARD_F = 9,
    KEYBOARD_G = 10,
    KEYBOARD_H = 11,
    KEYBOARD_I = 12,
    KEYBOARD_J = 13,
    KEYBOARD_K = 14,
    KEYBOARD_L = 15,
    KEYBOARD_M = 16,
    KEYBOARD_N = 17,
    KEYBOARD_O = 18,
    KEYBOARD_P = 19,
    KEYBOARD_Q = 20,
    KEYBOARD_R = 21,
    KEYBOARD_S = 22,
    KEYBOARD_T = 23,
    KEYBOARD_U = 24,
    KEYBOARD_V = 25,
    KEYBOARD_W = 26,
    KEYBOARD_X = 27,
    KEYBOARD_Y = 28,
    KEYBOARD_Z = 29,
    KEYBOARD_1 = 30,
    KEYBOARD_2 = 31,
    KEYBOARD_3 = 32,
    KEYBOARD_4 = 33,
    KEYBOARD_5 = 34,
    KEYBOARD_6 = 35,
    KEYBOARD_7 = 36,
    KEYBOARD_8 = 37,
    KEYBOARD_9 = 38,
    KEYBOARD_0 = 39,
    KEYBOARD_ENTER = 40,
    KEYBOARD_ESCAPE = 41,
    KEYBOARD_BACKSPACE = 42,
    KEYBOARD_TAB = 43,
    KEYBOARD_SPACEBAR = 44,
    KEYBOARD_MINUS = 45,
    KEYBOARD_EQUALS = 46,
    KEYBOARD_LEFT_BRACKET = 47,
    KEYBOARD_RIGHT_BRACKET = 48,
    KEYBOARD_BACKSLASH = 49,
    KEYBOARD_SEMICOLON = 51,
    KEYBOARD_QUOTE = 52,
    KEYBOARD_GRAVE_ACCENT = 53,
    KEYBOARD_COMMA = 54,
    KEYBOARD_PERIOD = 55,
    KEYBOARD_FORWARD_SLASH = 56,
    // Deprecated
    // KEYBOARD_CAPS_LOCK = 57,
    KEYBOARD_F1 = 58,
    KEYBOARD_F2 = 59,
    KEYBOARD_F3 = 60,
    KEYBOARD_F4 = 61,
    KEYBOARD_F5 = 62,
    KEYBOARD_F6 = 63,
    KEYBOARD_F7 = 64,
    KEYBOARD_F8 = 65,
    KEYBOARD_F9 = 66,
    KEYBOARD_F10 = 67,
    KEYBOARD_F11 = 68,
    KEYBOARD_F12 = 69,
    // Deprecated
    // KEYBOARD_PRINT_SCREEN = 70,
    // KEYBOARD_SCROLL_LOCK = 71,
    // KEYBOARD_PAUSE = 72,
    KEYBOARD_INSERT = 73,
    KEYBOARD_HOME = 74,
    KEYBOARD_PAGE_UP = 75,
    KEYBOARD_DELETE = 76,
    KEYBOARD_END = 77,
    KEYBOARD_PAGE_DOWN = 78,
    KEYBOARD_RIGHT_ARROW = 79,
    KEYBOARD_LEFT_ARROW = 80,
    KEYBOARD_DOWN_ARROW = 81,
    KEYBOARD_UP_ARROW = 82,
    // Deprecated
    // KEYBOARD_NUM_LOCK = 83,
    KEYBOARD_NUM_FORWARD_SLASH = 84,
    KEYBOARD_NUM_ASTERISK = 85,
    KEYBOARD_NUM_MINUS = 86,
    KEYBOARD_NUM_PLUS = 87,
    // Deprecated
    // KEYBOARD_NUM_ENTER = 88,
    KEYBOARD_NUM_1 = 89,
    KEYBOARD_NUM_2 = 90,
    KEYBOARD_NUM_3 = 91,
    KEYBOARD_NUM_4 = 92,
    KEYBOARD_NUM_5 = 93,
    KEYBOARD_NUM_6 = 94,
    KEYBOARD_NUM_7 = 95,
    KEYBOARD_NUM_8 = 96,
    KEYBOARD_NUM_9 = 97,
    KEYBOARD_NUM_0 = 98,
    // Deprecated
    // KEYBOARD_NUM_PERIOD = 99,
    // KEYBOARD_NUM_EQUALS = 103,
    KEYBOARD_LEFT_CONTROL = 224,
    KEYBOARD_LEFT_SHIFT = 225,
    KEYBOARD_LEFT_ALT = 226,
    KEYBOARD_LEFT_SUPER = 227,
    KEYBOARD_RIGHT_CONTROL = 228,
    KEYBOARD_RIGHT_SHIFT = 229,
    KEYBOARD_RIGHT_ALT = 230,
    KEYBOARD_RIGHT_SUPER = 231
};

enum MouseCode {
    // Deprecated
    // MOUSE_UNKNOWN = -1,
    MOUSE_1 = 1,
    MOUSE_2 = 2,
    MOUSE_3 = 3,
    MOUSE_4 = 4,
    MOUSE_5 = 5,
    // Deprecated
    // MOUSE_6 = 6,
    // MOUSE_7 = 7,
    // MOUSE_8 = 8
};

#endif
