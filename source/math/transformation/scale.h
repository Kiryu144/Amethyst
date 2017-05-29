/* Created by David Klostermann on 26.03.2017. */
#ifndef AMETHYST3D_SCALE_H
#define AMETHYST3D_SCALE_H

#include "math/transformation/transformationcomponent.h"

#include <GLM/common.hpp>
#include <GLM/gtx/transform.hpp>

namespace AM {

class Scale : public TransformationComponent {
public:
    using TransformationComponent::TransformationComponent;
    Scale() { m_data = glm::vec3(1, 1, 1); };

    glm::mat4 getMatrix() const;
};

}

#endif
