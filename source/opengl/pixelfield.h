/* Created by David Klostermann on 11.08.2017. */
#ifndef AMETHYST_PIXELFIELD_H
#define AMETHYST_PIXELFIELD_H

#include <GLM/common.hpp>
#include <GLM/gtx/string_cast.hpp>
#include <vector>
#include <algorithm>
#include <string>
#include <PICOPNG/Picopng.h>

#include "util/logger.h"
#include "util/fastfileio.h"

namespace AM{

class Pixelfield {
private:
    std::vector<glm::tvec4<unsigned char>> m_fieldData;
    glm::vec2 m_fieldSize;

public:
    Pixelfield(glm::vec2 size);
    Pixelfield(std::string filePath);

    std::vector<glm::tvec4<unsigned char>>& get();
    glm::vec2 getSize();

    Pixelfield cut(glm::vec2 first, glm::vec2 size);

    glm::vec4 getPixel(glm::vec2 pos);
    void drawPixel(glm::vec2 pos, glm::vec4 color);
    void drawLine(glm::vec2 pos1, glm::vec2 pos2, glm::vec4 color);

    void drawHollowRectangle(glm::vec2 pos, glm::vec2 size, glm::vec4 color);

};

}

#endif
