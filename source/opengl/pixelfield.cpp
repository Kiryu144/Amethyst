/* Created by David Klostermann on 11.08.2017. */
#include "pixelfield.h"

AM::Pixelfield::Pixelfield(glm::vec2 size) {
    m_fieldSize = glm::vec2(std::round(size.x), std::round(size.y));
    m_fieldData = std::vector<glm::tvec4<unsigned char>>(m_fieldSize.x * m_fieldSize.y);
}

std::vector<glm::tvec4<unsigned char>> &AM::Pixelfield::get() {
    return m_fieldData;
}

glm::vec2 AM::Pixelfield::getSize() {
    return m_fieldSize;
}

void AM::Pixelfield::drawPixel(glm::vec2 pos, glm::vec4 color) {
    m_fieldData.at(m_fieldSize.x * pos.x + pos.y) = color;
}



