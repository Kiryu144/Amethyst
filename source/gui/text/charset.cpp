/* Created by David Klostermann on 16.08.2017. */
#include "charset.h"

FT_Library AM::Charset::ftLibrary;
bool AM::Charset::freeTypeInitialized = false;

AM::Charset::Charset(std::string fontPath, std::string chars, unsigned int pixelHeight) {
    if(!freeTypeInitialized){
        FT_Init_FreeType(&ftLibrary);
    }
    FT_New_Face(ftLibrary, fontPath.c_str(), 0, &m_face);
    FT_Set_Pixel_Sizes(m_face, 0, pixelHeight);
    m_chars = chars;

    this->regenerate(pixelHeight);
}

void AM::Charset::regenerate(unsigned int pixelHeight) {
    m_pixelHeight = pixelHeight;
    FT_Set_Pixel_Sizes(m_face, 0, pixelHeight);
    for(char c : m_chars){
        if(FT_Load_Char(m_face, c, FT_LOAD_RENDER)){
            AM::Logger::error("Could not get char '" + std::to_string(c) + "'. It does not exist in the font-file! Skipping ..");
            continue;
        }
        FT_Bitmap bitmap = m_face->glyph->bitmap;
        glm::vec2 bitmapSize(bitmap.width, bitmap.rows);

        AM::Pixelfield pixelfield(bitmapSize);
        for(int x = 0; x < bitmapSize.x; x++){
            for(int y = 0; y < bitmapSize.y; y++){
                unsigned int brightness = bitmap.buffer[y * bitmap.width + x];
                if(brightness){
                    pixelfield.drawPixel(glm::vec2(x, y), glm::tvec4<unsigned char>(brightness, brightness, brightness, 255));
                }
            }
        }

        CharData data;
        try{
            data.texture = new AM::Texture(pixelfield);
        }catch(__AmethystException exception){
            data.texture = nullptr;
        }
        data.advanceX = m_face->glyph->advance.x / 64;
        data.heightCorrection = bitmapSize.y - m_face->glyph->bitmap_top;
        m_charData[c] = data;
    }
}

const AM::CharData AM::Charset::getChar(char c) {
    return m_charData[c];
}

unsigned int AM::Charset::getPixelHeight() {
    return m_pixelHeight;
}
