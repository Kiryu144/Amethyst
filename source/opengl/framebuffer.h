/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_FRAMEBUFFER_H
#define AMETHYST_FRAMEBUFFER_H

#include "view/window.h"
#include "opengl/texture.h"

namespace AM {

class Framebuffer {
private:
    unsigned int m_framebVBO;
    unsigned int m_depthVBO;

    Texture m_texture;

    unsigned int generateDepthBuffer(glm::vec2 size);
public:
    Framebuffer(glm::vec2 size);
    ~Framebuffer();

    void bind(glm::vec2 size);
    void unbind();
    Texture* getTexture();
};

}

#endif
