/* Created by David Klostermann on 16.08.2017. */
#ifndef AMETHYST_TEXT_H
#define AMETHYST_TEXT_H

#include "gui/text/charset.h"
#include "render/renderer/renderer2d.h"

namespace AM{
namespace GUI{

class Text {
private:
    AM::Renderer2D m_renderer;
    AM::Charset* m_charset;

    std::string m_text;
    unsigned int m_pixelHeight;
public:
    Text(AM::Charset* charset, std::string text, unsigned int pixelHeight);
    void set(std::string newText);
    void draw(glm::vec2 position);

    void setPixelHeight(unsigned int height);
};

}
}


#endif
