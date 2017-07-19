/* Created by David Klostermann on 22.05.2017. */
#include "keyboard.h"

std::map<int, bool> AM::InputController::m_lastFramePressedKeys;
std::map<int, bool> AM::InputController::m_pressedKeys;
std::map<int, bool> AM::InputController::m_alreadyClickedKeys;
std::map<int, bool> AM::InputController::m_alreadyClickedKeysThisFrame;
glm::vec2 AM::InputController::m_mousePosition;
glm::vec2 AM::InputController::m_mouseOffsetPerFrame;
glm::vec2 AM::InputController::m_mouseLockPosition = glm::vec2(-1, -1);

void AM::InputController::process() {
    m_lastFramePressedKeys = m_pressedKeys;
    m_pressedKeys = std::map<int, bool>();

    for(int i = 0; i < __glfwKeyCodeAmount + 3; i++){ //Check for every key if its pressed
        if(i < __glfwKeyCodeAmount) { //Keyboard
            m_pressedKeys[__glfwKeyCodes[i]] = (glfwGetKey(WindowHandler::getGlfwWindow(), __glfwKeyCodes[i]) == GLFW_PRESS);
        }else{ //Mouse
            switch(__glfwKeyCodes[i]){
                case GLFW_KEY_RMB: m_pressedKeys[GLFW_KEY_RMB] = (glfwGetMouseButton(WindowHandler::getGlfwWindow(), GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS ); break;
                case GLFW_KEY_LMB: m_pressedKeys[GLFW_KEY_LMB] = (glfwGetMouseButton(WindowHandler::getGlfwWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS ); break;
                case GLFW_KEY_MMB: m_pressedKeys[GLFW_KEY_MMB] = (glfwGetMouseButton(WindowHandler::getGlfwWindow(), GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS ); break;
            }
        }
        if(m_alreadyClickedKeys[__glfwKeyCodes[i]] && !m_pressedKeys[__glfwKeyCodes[i]]){
            m_alreadyClickedKeys[__glfwKeyCodes[i]] = false;
        }
    }

    double mousePosX;
    double mousePosY;
    glfwGetCursorPos(WindowHandler::getGlfwWindow(), &mousePosX, &mousePosY);
    m_mousePosition = glm::vec2(mousePosX, mousePosY);

    if(mouseIsLocked()){
        m_mouseOffsetPerFrame = m_mouseLockPosition - m_mousePosition;
        setMousePosition(m_mouseLockPosition);
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

glm::vec2 AM::InputController::getMousePosition() {
    return m_mousePosition;
}

void AM::InputController::setMousePosition(glm::vec2 pos) {
    glfwSetCursorPos(WindowHandler::getGlfwWindow(), pos.x, pos.y);
}

void AM::InputController::lockMousePosition(glm::vec2 pos) {
    m_mouseLockPosition = pos;
}

void AM::InputController::releaseMouse() {
    m_mouseLockPosition = glm::vec2(-1, -1);
}

bool AM::InputController::mouseIsLocked() {
    return m_mouseLockPosition != glm::vec2(-1, -1);
}

glm::vec2 AM::InputController::getMouseFrameOffset() {
    return m_mouseOffsetPerFrame;
}

