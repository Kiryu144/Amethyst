/* Created by David Klostermann on 16.08.2017. */
#include "boundingbox2d.h"

AM::AABB2D::AABB2D(glm::vec2 first, glm::vec2 second) {
    this->set(first, second);
}

glm::vec2 AM::AABB2D::getFirst() {
    return m_first;
}

glm::vec2 AM::AABB2D::getSecond() {
    return m_second;
}

glm::vec2 AM::AABB2D::getCenter() {
    return m_first + (this->getSize() / glm::vec2(2.0));
}

glm::vec2 AM::AABB2D::getSize() {
    return  glm::abs(m_second - m_first);
}

void AM::AABB2D::setFirst(glm::vec2 first) {
    this->set(first, m_second);
}

void AM::AABB2D::setSecond(glm::vec2 second) {
    this->set(m_first, second);
}

void AM::AABB2D::set(glm::vec2 first, glm::vec2 second) {
    m_first = glm::min(first, second);
    m_second = glm::max(first, second);
}

void AM::AABB2D::translate(glm::vec2 translate) {
    this->set(m_first + translate, m_second + translate);
}

bool AM::AABB2D::isInside(glm::vec2 pos) {
    if(pos.x >= m_first.x && pos.x < m_second.x){
        if(pos.y >= m_first.y && pos.y < m_second.y){
            return true;
        }
    }
    return false;
}
