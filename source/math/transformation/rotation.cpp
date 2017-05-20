/* Created by David Klostermann on 26.03.2017. */
#include "rotation.h"

AM::Quaternion::Quaternion(glm::vec3 rot) {
    m_rotation = rot;
}

const glm::vec3& AM::Quaternion::getRotation() const {
    return m_rotation;
}

void AM::Quaternion::setRotation(glm::vec3 rot) {
    this->m_rotation = rot;
}

glm::mat4 AM::Quaternion::getMatrix() const {
    return glm::orientate4(m_rotation / glm::vec3(57.2958)); //Convert degrees to radiants
}

