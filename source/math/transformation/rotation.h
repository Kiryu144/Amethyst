/* Created by David Klostermann on 26.03.2017. */
#ifndef AMETHYST3D_ROTATION_H
#define AMETHYST3D_ROTATION_H

#include "math/transformation/transformationcomponent.h"

#include <GLM/common.hpp>
#include <GLM/mat4x4.hpp>
#include <GLM/gtx/euler_angles.hpp>

namespace AM {

class Quaternion : public TransformationComponent {
public:
    using TransformationComponent::TransformationComponent;

    glm::mat4 getMatrix() const;
};

}

#endif
