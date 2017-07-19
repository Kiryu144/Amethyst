/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_FRAMEBUFFER_H
#define AMETHYST_FRAMEBUFFER_H

#include "view/window.h"
#include "opengl/texture.h"

#define AM_FRAMEBUFFER_GPU_ERROR 1

namespace AM {

class Framebuffer {
private:
    unsigned int m_framebVBO;
    unsigned int m_depthVBO;

    Texture m_texture;
    glm::vec2 m_size;

    unsigned int generateDepthBuffer(glm::vec2 size);
public:
    Framebuffer(glm::vec2 size);
    ~Framebuffer();

    void bind();
    void unbind();

    Texture* getTexture();
};

}

#endif
