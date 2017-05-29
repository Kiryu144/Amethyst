/* Created by David Klostermann on 26.03.2017. */
#include "rotation.h"

glm::mat4 AM::Quaternion::getMatrix() const {
    return glm::orientate4(m_data / glm::vec3(57.2958)); //Convert degrees to radiants
}
