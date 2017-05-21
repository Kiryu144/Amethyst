/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_TEXTURE_H
#define AMETHYST_TEXTURE_H

#include "view/window.h"

namespace AM {

class Texture {
private:
    unsigned int m_textureVBO;

    void generateDepthBuffer(glm::vec2 size);
public:
    Texture(glm::vec2 size);
    ~Texture();

    void bind() const;
    unsigned int getVBO() const;
};

}

#endif
