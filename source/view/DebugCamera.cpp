/* Created by David Klostermann on 25.05.2017. */
#include "debugcamera.h"

AM::Debugcamera::Debugcamera(AM::Camera *camera) {
    m_camera = camera;
}

void AM::Debugcamera::updateMovement() {
    if (WindowHandler::getWindow()->isFocused()) {
        if (InputController::isPressed(GLFW_KEY_W)) {
            m_camera->getTransformation().getPosition().translate(glm::normalize(m_camera->getFront() * glm::vec3(1.0f, 0.0f, 1.0f)) * m_speed * DeltaTime::getBigDeltaTime());
        }
        if (InputController::isPressed(GLFW_KEY_S)) {
            m_camera->getTransformation().getPosition().translate(-glm::normalize(m_camera->getFront() * glm::vec3(1.0f, 0.0f, 1.0f)) * m_speed * DeltaTime::getBigDeltaTime());
        }
        if (InputController::isPressed(GLFW_KEY_A)) {
            m_camera->getTransformation().getPosition().translate(glm::rotateY(glm::normalize(m_camera->getFront() * glm::vec3(1.0f, 0.0f, 1.0f)), glm::radians(90.0f)) * m_speed * DeltaTime::getBigDeltaTime());
        }
        if (InputController::isPressed(GLFW_KEY_D)) {
            m_camera->getTransformation().getPosition().translate(glm::rotateY(glm::normalize(m_camera->getFront() * glm::vec3(1.0f, 0.0f, 1.0f)), glm::radians(-90.0f)) * m_speed * DeltaTime::getBigDeltaTime());
        }
        if (InputController::isPressed(GLFW_KEY_SPACE)) {
            m_camera->getTransformation().getPosition().translate(glm::vec3(0.0f, 1.0f, 0.0f) * m_speed * DeltaTime::getBigDeltaTime());
        }
        if (InputController::isPressed(GLFW_KEY_LEFT_SHIFT)) {
            m_camera->getTransformation().getPosition().translate(-glm::vec3(0.0f, 1.0f, 0.0f) * m_speed * DeltaTime::getBigDeltaTime());
        }

        float newRotX = m_camera->getTransformation().getRotation().get().x + InputController::getMouseFrameOffset().y/4;
        float newRotY = m_camera->getTransformation().getRotation().get().y - InputController::getMouseFrameOffset().x/4;

        if(newRotX <= -89){
            newRotX = -88.9999;
        }else if(newRotX >= 89){
            newRotX = 88.9999;
        }

        m_camera->getTransformation().getRotation().set(glm::vec3(newRotX, newRotY, 0));
    }
}

void AM::Debugcamera::setSpeed(float speed) {
    m_speed = speed;
}

float AM::Debugcamera::getSpeed() {
    return m_speed;
}

/*
void AM::Debugcamera::updateMovement() {
    glm::vec3 movingDirection;
    if(WindowHandler::isFocused()){
        if(InputController::isPressed(GLFW_KEY_W)) {
            m_relativeMovement.x += (m_speed/m_smoothing) * DeltaTime::getBigDeltaTime();
            movingDirection.x = 1;
        }
        if(InputController::isPressed(GLFW_KEY_S)) {
            m_relativeMovement.x -= (m_speed/m_smoothing) * DeltaTime::getBigDeltaTime();
            movingDirection.x = -1;
        }
        if(InputController::isPressed(GLFW_KEY_D)) {
            m_relativeMovement.z += (m_speed/m_smoothing) * DeltaTime::getBigDeltaTime();
            movingDirection.z = 1;
        }
        if(InputController::isPressed(GLFW_KEY_A)) {
            m_relativeMovement.z -= (m_speed/m_smoothing) * DeltaTime::getBigDeltaTime();
            movingDirection.z = -1;
        }
        if(InputController::isPressed(GLFW_KEY_SPACE)) {
            m_relativeMovement.y += (m_speed/m_smoothing) * DeltaTime::getBigDeltaTime();
            movingDirection.y = 1;
        }
        if(InputController::isPressed(GLFW_KEY_LEFT_SHIFT)) {
            m_relativeMovement.y -= (m_speed/m_smoothing) * DeltaTime::getBigDeltaTime();
            movingDirection.y = -1;
        }
    }

    for(int i = 0; i < 3; i++){
        if(movingDirection[i] == 0){
            float delta = (m_speed/m_smoothing)* 2 * DeltaTime::getBigDeltaTime();
            if(std::abs(m_relativeMovement[i]) < delta ){
                m_relativeMovement[i] = 0;
            }else if(m_relativeMovement[i] > 0){
                m_relativeMovement[i] -= delta;
            }else if(m_relativeMovement[i] < 0){
                m_relativeMovement[i] += (m_speed/m_smoothing)* 2 * DeltaTime::getBigDeltaTime();
            }
        }
    }

    m_velocity = m_camera->getFront() * m_relativeMovement.x;
    m_velocity += glm::rotateY(m_camera->getFront(), glm::radians(-90.0f)) * m_relativeMovement.z;
    m_velocity.y += m_relativeMovement.y;

    //Limiting velocity to max velocity
    for(int i = 0; i < 3; i++){
        if(m_velocity[i] > m_maxVelocity[i]){
            m_velocity[i] = m_maxVelocity[i];
        }else if(m_velocity[i] < -m_maxVelocity[i]){
            m_velocity[i] = -m_maxVelocity[i];
        }
    }

    m_camera->getTransformation().getPosition().translate(m_velocity * glm::vec3(DeltaTime::getBigDeltaTime()));
}


 */