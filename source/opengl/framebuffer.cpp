/* Created by David Klostermann on 18.05.2017. */
#include "framebuffer.h"

AM::Framebuffer::Framebuffer(glm::vec2 size) : m_texture(size) {
    glGenFramebuffers(1, &m_framebVBO);
    this->bind(size);
    m_texture.bind();
    m_depthVBO = this->generateDepthBuffer(size);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, m_texture.getVBO(), 0);
    GLenum drawBuffers[1] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, drawBuffers);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        throwAmethystException("Error while creating Framebuffer");
    }

    this->unbind();
}

AM::Framebuffer::~Framebuffer() {
    glDeleteFramebuffers(1, &m_framebVBO);
    glDeleteRenderbuffers(1, &m_depthVBO);
}

unsigned int AM::Framebuffer::generateDepthBuffer(glm::vec2 size) {
    unsigned int vbo;
    glGenRenderbuffers(1, &vbo);
    glBindRenderbuffer(GL_RENDERBUFFER, vbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, int(size.x), int(size.y));
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, vbo);
    return vbo;
}

void AM::Framebuffer::bind(glm::vec2 size) {
    glBindFramebuffer(GL_FRAMEBUFFER, m_framebVBO);
    glViewport(0, 0, size.x, size.y);
}

void AM::Framebuffer::unbind() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Texture *AM::Framebuffer::getTexture() {
    return &m_texture;
}


