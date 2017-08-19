/* Created by David Klostermann on 16.08.2017. */
#ifndef AMETHYST_CHARSET_H
#define AMETHYST_CHARSET_H

#include <string>
#include <FREETYPE/ft2build.h>
#include <opengl/texture.h>
#include FT_FREETYPE_H

#include "view/window.h"
#include "util/amethystexception.h"

namespace AM{

class CharData{
public:
    AM::Texture* texture = nullptr;
    int advanceX;
    int heightCorrection;
};

class Charset {
private:
    FT_Face m_face;
    std::string m_chars;
    unsigned int m_pixelHeight;

    CharData m_charData[256];
public:
    Charset(std::string fontPath, std::string chars, unsigned int pixelHeight);

    void regenerate(unsigned int pixelHeight);

    const CharData getChar(char c);

    unsigned int getPixelHeight();

    static FT_Library ftLibrary;
    static bool freeTypeInitialized;
};

}


#endif
