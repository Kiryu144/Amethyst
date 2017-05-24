/* Created by David Klostermann on 22.05.2017. */
#include "keyboard.h"

std::map<int, bool> AM::InputController::m_lastFramePressedKeys;
std::map<int, bool> AM::InputController::m_pressedKeys;
std::map<int, bool> AM::InputController::m_alreadyClickedKeys;
std::map<int, bool> AM::InputController::m_alreadyClickedKeysThisFrame;

void AM::InputController::process() {
    m_lastFramePressedKeys = m_pressedKeys;
    m_pressedKeys = std::map<int, bool>();


    for(int i = -3; i < __glfwKeyCodeAmount; i++){ //Check for every key if its pressed
        if(i >= 0) { //Keyboard
            m_pressedKeys[__glfwKeyCodes[i]] = (glfwGetKey(WindowHandler::getGlfwWindow(), __glfwKeyCodes[i]) == GLFW_PRESS);
        }else{ //Mouse
            switch(i){
                case -3: m_pressedKeys[GLFW_KEY_RMB] = glfwGetMouseButton(WindowHandler::getGlfwWindow(), GLFW_MOUSE_BUTTON_RIGHT); break;
                case -2: m_pressedKeys[GLFW_KEY_LMB] = glfwGetMouseButton(WindowHandler::getGlfwWindow(), GLFW_MOUSE_BUTTON_LEFT); break;
                case -1: m_pressedKeys[GLFW_KEY_MMB] = glfwGetMouseButton(WindowHandler::getGlfwWindow(), GLFW_MOUSE_BUTTON_MIDDLE); break;
            } //TODO: Fix ClickedKey support for mouse
        }
        if(m_alreadyClickedKeys[__glfwKeyCodes[i]] && !m_pressedKeys[__glfwKeyCodes[i]]){
            m_alreadyClickedKeys[__glfwKeyCodes[i]] = false;
        }
    }
}

bool AM::InputController::isPressed(int key) {
    return m_pressedKeys[key];
}

bool AM::InputController::isClicked(int key) {
    if(m_pressedKeys[key] && !m_alreadyClickedKeys[key]){
        m_alreadyClickedKeys[key] = true;
    }
}

bool AM::InputController::isReleased(int key) {
    return m_lastFramePressedKeys[key] && !m_pressedKeys[key];
}
