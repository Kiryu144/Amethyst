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

AM::Texture::Texture(AM::Pixelfield &pixelfield) {
    glGenTextures(1, &m_textureVBO);
    this->bind();

    m_size = pixelfield.getSize();
    if(!m_size.x || !m_size.y){
        throwAmethystException("Cannot generate texture with 0 size pixelfield!");
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_size.x, m_size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, &pixelfield.get().at(0));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}


AM::Texture::~Texture() {
    glDeleteTextures(1, &m_textureVBO);
}

void AM::Texture::bind() const {
    if(m_textureVBO == unsigned (-1)){
        throwAmethystException("Cannot bind texture with no VBO data uploaded!");
    }
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_textureVBO);
}

unsigned int AM::Texture::getVBO() const {
    return m_textureVBO;
}

glm::vec2 AM::Texture::getSize() {
    return m_size;
}



