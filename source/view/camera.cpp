/* Created by David Klostermann on 20.05.2017. */
#include "camera.h"

AM::Camera::Camera(AM::Transformation transformation) {
    m_transformation = transformation;
}

void AM::Camera::update() {
    m_lastProjection = glm::perspective(glm::radians(m_fov), m_transformation.getScale().getScale().x / m_transformation.getScale().getScale().y, m_clippingPlaneNear, m_clippingPlaneFar);
    m_lastView = glm::lookAt(m_transformation.getPosition().getPosition(), m_transformation.getPosition().getPosition() + getFront(), glm::vec3(0.0f, 1.0f, 0.0f));
    m_lastProjectionViewMatrix = this->getProjection() * this->getView();

    if (m_transformation.getRotation().getRotation() - m_lastRotation != glm::vec3(0, 0, 0)) {
        m_front.x = cos(glm::radians(m_transformation.getRotation().getRotation().x)) * cos(glm::radians(m_transformation.getRotation().getRotation().y));
        m_front.y = sin(glm::radians(m_transformation.getRotation().getRotation().x));
        m_front.z = cos(glm::radians(m_transformation.getRotation().getRotation().x)) * sin(glm::radians(m_transformation.getRotation().getRotation().y));
        m_lastRotation = m_transformation.getRotation().getRotation();
    }
}

AM::Transformation& AM::Camera::getTransformation() {
    return m_transformation;
}

glm::mat4 AM::Camera::getProjection() {
    return m_lastProjection;
}

glm::mat4 AM::Camera::getView() {
    return m_lastView;
}

glm::mat4 AM::Camera::getProjectionViewMatrix() {
    return m_lastProjectionViewMatrix;
}

glm::vec3& AM::Camera::getFront() {
    return m_lastFront;
}

void AM::Camera::setFOV(float fov) {
    m_fov = fov;
}

float AM::Camera::getFOV() {
    return m_fov;
}

void AM::Camera::setClippingPlaneNear(float clippingPlaneNear) {
    m_clippingPlaneNear = clippingPlaneNear;
}

float AM::Camera::getClippingPlaneNear() {
    return m_clippingPlaneNear;
}

void AM::Camera::setClippingPlaneFar(float clippingPlaneFar) {
    m_clippingPlaneFar = clippingPlaneFar;
}

float AM::Camera::getClippingPlaneFar() {
    return m_clippingPlaneFar;
}

/*

void AM::Camera::updateDebugCameraMovement() {
    if(m_debugCameraMovementEnabled) {
        if (AM::WindowHandler::isFocused()) {
            if (keyboard.keyPressed(GLFW_KEY_W)) {
                m_transformation.getPosition().setPosition((*m_transformation.getPosition().getPosition()) + AM::Camera::getFront() * m_debugCameraMovementSpeed * DeltaTime::getBigDeltaTime());
            }
            if (keyboard.keyPressed(GLFW_KEY_S)) {
                m_transformation.getPosition().setPosition((*m_transformation.getPosition().getPosition()) - AM::Camera::getFront() * m_debugCameraMovementSpeed * DeltaTime::getBigDeltaTime());
            }
            if (keyboard.keyPressed(GLFW_KEY_A)) {
                m_transformation.getPosition().setPosition((*m_transformation.getPosition().getPosition()) - glm::normalize(glm::cross(AM::Camera::getFront(), AM::Camera::getUp())) * m_debugCameraMovementSpeed * DeltaTime::getBigDeltaTime());
            }
            if (keyboard.keyPressed(GLFW_KEY_D)) {
                m_transformation.getPosition().setPosition((*m_transformation.getPosition().getPosition()) + glm::normalize(glm::cross(AM::Camera::getFront(), AM::Camera::getUp())) * m_debugCameraMovementSpeed * DeltaTime::getBigDeltaTime());
            }

            if (keyboard.keyPressed(GLFW_KEY_LEFT_CONTROL)) {
                if (keyboard.keyClicked(GLFW_KEY_PAGE_UP)) {
                    m_debugCameraMovementSpeed += 0.25;
                } else if (keyboard.keyClicked(GLFW_KEY_PAGE_DOWN)) {
                    m_debugCameraMovementSpeed -= 0.25;
                }
            }

            float newRotX = m_transformation.getRotation().getRotation()->x + keyboard.getFrameMousePos().y/4;
            float newRotY = m_transformation.getRotation().getRotation()->y - keyboard.getFrameMousePos().x/4;
            if(newRotX <= -89){
                newRotX = -88.9999;
            }else if(newRotX >= 89){
                newRotX = 88.9999;
            }
            m_transformation.getRotation().setRotation(glm::vec3(newRotX, newRotY, 0));

        }
    }
}

void AM::Camera::setDebugCameraMovementSpeed(float debugCameraMovementSpeed) {
    AM::Camera::m_debugCameraMovementSpeed = debugCameraMovementSpeed;
}

float AM::Camera::getDebugCameraMovementSpeed() {
    return m_debugCameraMovementSpeed;
}

 */