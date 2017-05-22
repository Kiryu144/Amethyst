/* Created by David Klostermann on 22.05.2017. */
#ifndef AMETHYST_KEYBOARD_H
#define AMETHYST_KEYBOARD_H

#include "view/window.h"

#include <map>
#include <stack>

namespace AM {

class InputController {
private:
    static std::map<int, bool> m_lastFramePressedKeys;
    static std::map<int, bool> m_pressedKeys;
    static std::map<int, bool> m_alreadyClickedKeys; //Stores if key was pressed but not released any time
    static std::map<int, bool> m_alreadyClickedKeysThisFrame; // -||- .. this frame
public:
    static void __keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void init();
    static void process();

    static bool isPressed(int key); //Returns true while key is pressed
    static bool isClicked(int key); //Returns true when key is pressed once, ignored all after
    static bool isReleased(int key); //Returns true when key is released, after being pressed
};

}


#endif
