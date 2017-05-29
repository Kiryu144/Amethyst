/* Created by David Klostermann on 26.03.2017. */
#ifndef AMETHYST3D_POSITION_H
#define AMETHYST3D_POSITION_H

#include "math/transformation/transformationcomponent.h"

#include <GLM/common.hpp>
#include <GLM/gtx/transform.hpp>

namespace AM {

class Position : public TransformationComponent {
public:
    using TransformationComponent::TransformationComponent;

    glm::mat4 getMatrix() const;
};

}

#endif
