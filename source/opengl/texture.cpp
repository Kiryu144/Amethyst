/* Created by David Klostermann on 18.05.2017. */
#include "texture.h"

Texture::Texture(glm::vec2 size) {
    glGenTextures(1, &m_textureVBO);
    this->bind();

    //Generate empty image
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, int(size.x), int(size.y), 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

Texture::~Texture() {
    glDeleteTextures(1, &m_textureVBO);
}

void Texture::bind() const {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_textureVBO);
}

unsigned int Texture::getVBO() const {
    return m_textureVBO;
}
