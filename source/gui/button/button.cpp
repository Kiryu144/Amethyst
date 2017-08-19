/* Created by David Klostermann on 16.08.2017. */
#include "button.h"

AM::Button::Button(AM::AABB2D area) {
    m_area = area;
}

void AM::Button::update() {
    if(m_area.isInside(AM::InputController::getMousePosition())){ //Button is hovered
        if(AM::InputController::isPressed(GLFW_KEY_LMB)){ //Is pressed down

        }
        if(AM::InputController::isReleased(GLFW_KEY_LMB)){ //Is released
            AM::Logger::info("Button has been pressed!");
        }
    }else{ //Nothing happens with the button

    }
}
