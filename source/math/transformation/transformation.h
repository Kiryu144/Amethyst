/* Created by David Klostermann on 26.03.2017. */
#ifndef AMETHYST3D_TRANSFORMATION_H
#define AMETHYST3D_TRANSFORMATION_H

//TODO: Very stupid way. Make a parent class to avoid code duplicates
#include "position.h"
#include "rotation.h"
#include "scale.h"

#include <GLM/mat4x4.hpp>
#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <GLM/gtx/euler_angles.hpp>
#include <GLM/gtx/quaternion.hpp>

namespace AM {

class Transformation {
private:
    Position m_position;
    Quaternion m_quaternion;
    Scale m_scale;
public:
    Transformation(){};
    Transformation(Position position, Quaternion quaternion = Quaternion(), Scale scale = Scale());

    glm::mat4 getMatrix() const;
    Position& getPosition();
    Quaternion& getRotation();
    Scale& getScale();
};

}

#endif
