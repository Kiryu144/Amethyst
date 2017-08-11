/* Created by David Klostermann on 11.08.2017. */
#ifndef AMETHYST_PIXELFIELD_H
#define AMETHYST_PIXELFIELD_H

#include <GLM/common.hpp>
#include <vector>

namespace AM{

class Pixelfield {
private:
    std::vector<glm::tvec4<unsigned char>> m_fieldData;
    glm::vec2 m_fieldSize;
public:
    Pixelfield(glm::vec2 size);

    std::vector<glm::tvec4<unsigned char>>& get();
    glm::vec2 getSize();

    void drawPixel(glm::vec2 pos, glm::vec4 color);

   // void drawCircle(glm::vec2 pos, float radius, glm::vec4 color);
};

}

#endif
