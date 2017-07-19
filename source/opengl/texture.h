/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_TEXTURE_H
#define AMETHYST_TEXTURE_H

#include <PICOPNG/Picopng.h>
#include <GLM/GTX/string_cast.hpp>

#include "util/fastfileio.h"
#include "view/window.h"

#define AM_TEXTURE_PICOPNG_ERROR 1
#define AM_SHADER_BIND_FAIL    2

namespace AM {

class Texture {
private:
    unsigned int m_textureVBO = -1;
    glm::tvec2<unsigned long> m_size;

public:
    Texture() {};
    Texture(glm::vec2 size);
    Texture(std::string filePath);
    ~Texture();

    void bind() const;
    unsigned int getVBO() const;
};

}

#endif
