/* Created by David Klostermann on 20.05.2017. */
#ifndef AMETHYST_CAMERA_H
#define AMETHYST_CAMERA_H

#include <limits>

#include "math/transformation/transformation.h"

namespace AM {

class Camera {
private:
    //Note: The scale component equals to the screen dimensions
    AM::Transformation m_transformation;

    glm::mat4 m_projection;
    glm::vec4 m_front;
    glm::mat4 m_view;

    float m_fov = 80;
    float m_clippingPlaneNear = 0.01f;
    float m_clippingPlaneFar = 1000000000;
public:
    Camera() {};
    Camera(AM::Transformation transformation);

    void update();

    Transformation& getTransformation();

     glm::mat4 getProjection();
     glm::mat4 getView();
     glm::vec3 getFront();

     void setFOV(float fov);
     float getFOV();

     void setClippingPlaneNear(float clippingPlaneNear);
     float getClippingPlaneNear();

     void setClippingPlaneFar(float clippingPlaneFar);
     float getClippingPlaneFar();
};

}

#endif
