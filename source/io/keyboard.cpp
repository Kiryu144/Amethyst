/* Created by David Klostermann on 22.05.2017. */
#include "keyboard.h"

std::map<int, bool> AM::InputController::m_lastFramePressedKeys;
std::map<int, bool> AM::InputController::m_pressedKeys;
std::map<int, bool> AM::InputController::m_alreadyClickedKeys;
std::map<int, bool> AM::InputController::m_alreadyClickedKeysThisFrame;

void __keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

void AM::InputController::__keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    m_pressedKeys[key] = (action == GLFW_PRESS);
}

void AM::InputController::init() {
    glfwSetKeyCallback(WindowHandler::getGlfwWindow(), AM::InputController::__keyCallback);
    AM::Logger::info("InputController initialized!", 2);
}

void AM::InputController::process() {
    m_lastFramePressedKeys = m_pressedKeys;
    m_pressedKeys.clear();
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
