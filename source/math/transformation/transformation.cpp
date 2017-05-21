/* Created by David Klostermann on 26.03.2017. */
#include "transformation.h"

AM::Transformation::Transformation(AM::Position position, AM::Quaternion quaternion, AM::Scale scale) {
    m_position = position;
    m_quaternion = quaternion;
    m_scale = scale;
}

glm::mat4 AM::Transformation::getMatrix() const {
    return m_position.getMatrix() * m_quaternion.getMatrix() * m_scale.getMatrix();
}

AM::Position& AM::Transformation::getPosition() {
    return m_position;
}

AM::Quaternion& AM::Transformation::getRotation() {
    return m_quaternion;
}

AM::Scale& AM::Transformation::getScale() {
    return m_scale;
}

AM::Position &AM::Transformation::pos() {
    return this->getPosition();
}

AM::Quaternion &AM::Transformation::rot() {
    return this->getRotation();
}

AM::Scale &AM::Transformation::scl() {
    return this->getScale();
}

void AM::Transformation::lookAt(glm::vec3 dest) {
    //TODO: Implement
}
