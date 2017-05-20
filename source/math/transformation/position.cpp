/* Created by David Klostermann on 26.03.2017. */
#include "position.h"

AM::Position::Position(glm::vec3 pos) {
    m_position = pos;
}

const glm::vec3 &AM::Position::getPosition() const {
    return m_position;
}

void AM::Position::setPosition(glm::vec3 pos) {
    this->m_position = pos;
}

void AM::Position::translate(glm::vec3 other) {
    this->m_position += other;
}

glm::mat4 AM::Position::getMatrix() const {
    return glm::translate(m_position);
}


