/* Created by David Klostermann on 14.06.2017. */
#include "boundingbox.h"

AABB::AABB(glm::vec3 first, glm::vec3 second) {
    this->set(first, second);
}

glm::vec3 AABB::getFirst() {
    return m_first;
}

glm::vec3 AABB::getSecond() {
    return m_second;
}

glm::vec3 AABB::getCenter() {
    return m_first + (this->getSize() / glm::vec3(2.0));
}

glm::vec3 AABB::getSize() {
    return  glm::abs(m_second - m_first);
}

void AABB::setFirst(glm::vec3 first) {
    this->set(first, m_second);
}

void AABB::setSecond(glm::vec3 second) {
    this->set(m_first, second);
}

void AABB::set(glm::vec3 first, glm::vec3 second) {
    m_first = glm::min(first, second);
    m_second = glm::max(first, second);
}

void AABB::translate(glm::vec3 translate) {
    set(m_first + translate, m_second + translate);
}

