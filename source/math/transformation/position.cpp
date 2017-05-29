/* Created by David Klostermann on 26.03.2017. */
#include "position.h"

glm::mat4 AM::Position::getMatrix() const {
    return glm::translate(m_data);
}
