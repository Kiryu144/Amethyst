/* Created by David Klostermann on 26.03.2017. */
#include "scale.h"

glm::mat4 AM::Scale::getMatrix() const {
    return glm::scale(m_data);
}


