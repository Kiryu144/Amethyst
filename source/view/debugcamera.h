/* Created by David Klostermann on 25.05.2017. */
#ifndef AMETHYST_DEBUGCAMERA_H
#define AMETHYST_DEBUGCAMERA_H

#include <GLM/GTX/rotate_vector.hpp>
#include <GLM/GTX/vector_angle.hpp>

#include "view/camera.h"
#include "view/window.h"
#include "math/time.h"
#include "io/keyboard.h"

namespace AM {

class Debugcamera {
private:
    Camera* m_camera;

    /*
    glm::vec3 m_relativeMovement;
    glm::vec3 m_velocity;
    glm::vec3 m_maxVelocity = glm::vec3(1.0f, 1.0f, 1.0f);
    float m_speed = 1.0f;
    float m_smoothing = 3.5f;
     */

    float m_speed = 1.0f;
public:
    Debugcamera(Camera* camera);
    void updateMovement();

    void setSpeed(float speed);
    float getSpeed();
};

}


#endif
