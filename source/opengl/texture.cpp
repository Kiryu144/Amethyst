/* Created by David Klostermann on 18.05.2017. */
#include "texture.h"

AM::Texture::Texture(glm::vec2 size) {
    m_size = size;
    glGenTextures(1, &m_textureVBO);
    this->bind();

    //Generate empty image
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, int(size.x), int(size.y), 0, GL_RGB, GL_UNSIGNED_BYTE, 0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

AM::Texture::Texture(std::string filePath) {
    std::vector<unsigned char> encodedImage;
    AM::readFile(filePath, encodedImage);
    std::vector<unsigned char> decodedImage;
    int error = decodePNG(decodedImage, m_size.x, m_size.y, &encodedImage.at(0), encodedImage.size());
    if(error != 0){
        throwAmethystException("PicoPNG returned error code " + std::to_string(error));
    }

    glGenTextures(1, &m_textureVBO);
    this->bind();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x, m_size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, &decodedImage.at(0));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

AM::Texture::~Texture() {
    glDeleteTextures(1, &m_textureVBO);
}

void AM::Texture::bind() const {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_textureVBO);
}

unsigned int AM::Texture::getVBO() const {
    return m_textureVBO;
}


