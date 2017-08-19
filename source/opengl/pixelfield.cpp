/* Created by David Klostermann on 11.08.2017. */
#include "pixelfield.h"

AM::Pixelfield::Pixelfield(glm::vec2 size) {
    m_fieldSize = glm::vec2(std::round(size.x), std::round(size.y));
    m_fieldData = std::vector<glm::tvec4<unsigned char>>(m_fieldSize.x * m_fieldSize.y);
}

AM::Pixelfield::Pixelfield(std::string filePath) {
    std::vector<unsigned char> encodedImage;
    AM::readFile(filePath, encodedImage);
    std::vector<unsigned char> decodedImage;
    glm::tvec2<unsigned long> size;
    decodePNG(decodedImage, size.x, size.y, &encodedImage.at(0), encodedImage.size());
    m_fieldSize = size;
    m_fieldData.reserve(size.x * size.y);
    for(int i = 0; i < decodedImage.size(); i+=4){
        m_fieldData.push_back(glm::tvec4<unsigned char>(decodedImage.at(i+0), decodedImage.at(i+1), decodedImage.at(i+2), decodedImage.at(i+3)));
    }
}

std::vector<glm::tvec4<unsigned char>> &AM::Pixelfield::get() {
    return m_fieldData;
}

glm::vec2 AM::Pixelfield::getSize() {
    return m_fieldSize;
}

void AM::Pixelfield::drawPixel(glm::vec2 pos, glm::vec4 color) {
    try{
        m_fieldData.at(std::round(m_fieldSize.x) * std::round(pos.y) + std::round(pos.x)) = color;
    }catch(std::out_of_range out_of_range){
        throwAmethystException("Pixel position " + glm::to_string(pos) + " is not inside field with size " + glm::to_string(m_fieldSize));
    }
}

glm::vec4 AM::Pixelfield::getPixel(glm::vec2 pos) {
    return m_fieldData.at(std::round(m_fieldSize.x) * std::round(pos.y) + std::round(pos.x));
}

void AM::Pixelfield::drawLine(glm::vec2 pos1, glm::vec2 pos2, glm::vec4 color) {
    int dx, dy, p, x, y;

    dx = pos2.x - pos1.x;
    dy = pos2.y - pos1.y;

    x = pos1.x;
    y = pos1.y;

    p = 2 * dy - dx;

    while (x < pos2.x) {
        if (p >= 0) {
            this->drawPixel(glm::vec2(x, y), color);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        } else {
            this->drawPixel(glm::vec2(x, y), color);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}

void AM::Pixelfield::drawHollowRectangle(glm::vec2 pos, glm::vec2 size, glm::vec4 color) {
    for(int x = 0; x < size.x; x++){
        drawPixel(glm::vec2(pos.x + x, pos.y), color);
        drawPixel(glm::vec2(pos.x + x, pos.y + size.y), color);
    }

    for(int y = 0; y < size.y; y++){
        drawPixel(glm::vec2(pos.x, pos.y + y), color);
        drawPixel(glm::vec2(pos.x + size.x, pos.y + y), color);
    }
}

AM::Pixelfield AM::Pixelfield::cut(glm::vec2 first, glm::vec2 size) {
    Pixelfield field(size);

    for(int x = 0; x < size.x; x++){
        for(int y = 0; y < size.y; y++){
            glm::vec4 pixel = this->getPixel(glm::vec2(first.x + x, first.y + y));
            field.drawPixel(glm::vec2(x, y), pixel);
        }
    }

    return field;
}


