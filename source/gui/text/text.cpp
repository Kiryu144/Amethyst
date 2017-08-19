/* Created by David Klostermann on 16.08.2017. */
#include "text.h"

AM::GUI::Text::Text(AM::Charset* charset, std::string text, unsigned int pixelHeight) {
    if(charset == nullptr){
        throwAmethystException("Invalid charset. (nullptr)")
    }

    m_text = text;
    m_pixelHeight = pixelHeight;
    m_charset = charset;
}

void AM::GUI::Text::set(std::string newText) {
    m_text = newText;
}

void AM::GUI::Text::draw(glm::vec2 position) {
    AM::Transformation transformation(AM::Position(glm::vec3(position.x, position.y, 0)), AM::Quaternion(), AM::Scale(glm::vec3(0, m_pixelHeight, 0)));

    float scale = float(m_pixelHeight) / float(m_charset->getPixelHeight());

    for(char c : m_text){
        CharData charData = m_charset->getChar(c);
        AM::Texture* texture = charData.texture;

        if(texture != nullptr){
            transformation.getScale().set(glm::vec3(texture->getSize().x * scale, texture->getSize().y * scale, 0));
            //transformation.getPosition().set(glm::vec3(transformation.pos().get().x, position.y + (((m_pixelHeight - texture->getSize().y) + charData.heightCorrection) * scale), 0));
            transformation.getPosition().set(glm::vec3(transformation.pos().get().x, position.y + (m_pixelHeight - (texture->getSize().y * scale)) + charData.heightCorrection * scale, 0));
            //m_text[51513] = 'c'; //Crash on purpose
            m_renderer.addToBatch(texture, transformation);
        }

        transformation.getPosition().translate(glm::vec3(charData.advanceX * scale, 0, 0));
    }
    m_renderer.render();
}

void AM::GUI::Text::setPixelHeight(unsigned int height) {
    m_pixelHeight = height;
}


