/* Created by David Klostermann on 30.05.2017. */
#include "transformationcomponent.h"

AM::TransformationComponent::TransformationComponent(glm::vec3 data) {
    m_data = data;
}

void AM::TransformationComponent::translate(glm::vec3 vec) {
    m_data += vec;
}

void AM::TransformationComponent::set(glm::vec3 vec) {
    m_data = vec;
}

glm::vec3 AM::TransformationComponent::get() const {
    return m_data;
}
