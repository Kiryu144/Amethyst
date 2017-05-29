/* Created by David Klostermann on 22.05.2017. */
#ifndef AMETHYST_KEYBOARD_H
#define AMETHYST_KEYBOARD_H

#include "view/window.h"

#include <map>
#include <stack>

#define GLFW_KEY_LMB 1000
#define GLFW_KEY_RMB 1001
#define GLFW_KEY_MMB 1002

namespace AM {

static const int __glfwKeyCodes[] = {32, 39, 44, 45, 46, 47, 0, 48, 1, 49, 2, 50, 3, 51, 4, 52, 5, 53, 6, 54, 7, 55, 8, 56, 9, 57, 59, 61, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 96, 1, 161, 1, 2, 162, 2, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 280, 281, 282, 283, 284, 1, 290, 2, 291, 3, 292, 4, 293, 5, 294, 6, 295, 7, 296, 8, 297, 9, 298, 10, 299, 11, 300, 12, 301, 13, 302, 14, 303, 15, 304, 16, 305, 17, 306, 18, 307, 19, 308, 20, 309, 21, 310, 22, 311, 23, 312, 24, 313, 25, 314, 0, 320, 1, 321, 2, 322, 3, 323, 4, 324, 5, 325, 6, 326, 7, 327, 8, 328, 9, 329, 330, 331, 332, 333, 334, 335, 336, 340, 341, 342, 343, 344, 345, 346, 347, 348, 1000, 1001, 1002};
static const int __glfwKeyCodeAmount = 169; //Ignore the last 3 (mouse buttons)

class InputController {
private:
    static std::map<int, bool> m_lastFramePressedKeys;
    static std::map<int, bool> m_pressedKeys;
    static std::map<int, bool> m_alreadyClickedKeys; //Stores if key was pressed but not released any time
    static std::map<int, bool> m_alreadyClickedKeysThisFrame; // -||- .. this frame
    static glm::vec2 m_mousePosition;

    static glm::vec2 m_mouseOffsetPerFrame;
    static glm::vec2 m_mouseLockPosition;
public:
    static void process();

    static bool isPressed(int key); //Returns true while key is pressed
    static bool isClicked(int key); //Returns true when key is pressed once, ignored all after
    static bool isReleased(int key); //Returns true when key is released, after being pressed
    static glm::vec2 getMousePosition();
    static void setMousePosition(glm::vec2 pos);

    static void lockMousePosition(glm::vec2 pos);
    static void releaseMouse();
    static bool mouseIsLocked();
    static glm::vec2 getMouseFrameOffset();
};

}


#endif
