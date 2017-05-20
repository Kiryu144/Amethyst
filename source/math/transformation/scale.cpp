/* Created by David Klostermann on 26.03.2017. */
#include "scale.h"


AM::Scale::Scale(glm::vec3 scl) {
    m_scale = scl;
}

AM::Scale::Scale(float scl) {
    m_scale = glm::vec3(scl);
}

const glm::vec3& AM::Scale::getScale() const {
    return m_scale;
}

void AM::Scale::setScale(glm::vec3 scl) {
    this->m_scale = scl;
}

void AM::Scale::setScale(double scl) {
    setScale(glm::vec3(scl, scl, scl));
}

glm::mat4 AM::Scale::getMatrix() const {
    return glm::scale(m_scale);
}


