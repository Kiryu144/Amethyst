/* Created by David Klostermann on 16.08.2017. */
#include "profiler.h"

AM::Profiler::Profiler(float min, float initMax, bool adjustMax) {
    m_min = min;
    m_max = initMax;
    m_adjustMax = adjustMax;

    m_values = std::vector<float>();
    for(int i = 0; i < SIZE; i++){
        m_values.push_back(0);
    }
}

void AM::Profiler::addValue(float value) {
    //m_values.insert(m_values.begin()+1, m_values.end(), m_values.begin());
    for(int i = 1; i < SIZE; i++){
        m_values[i-1] = m_values[i];
    }

    m_values[SIZE-1] = value;
}

void AM::Profiler::regenerate() {
    AM::Pixelfield field = AM::Pixelfield(glm::vec2(SIZE));

    if(m_adjustMax){
        m_max = 1;
        for(int i = 0; i < SIZE; i++){
            if(m_values.at(i) > m_max){
                m_max = m_values.at(i);
            }
        }
    }

    float pixelHeight = SIZE/(m_max - m_min);
    for(int x = 0; x < SIZE; x++){
        field.drawPixel(glm::vec2(x, m_values.at(x) * pixelHeight), glm::tvec4<unsigned char>(255, 0, 0, 255));
    }
    field.drawHollowRectangle(glm::vec2(0), glm::vec2(SIZE), glm::tvec4<unsigned char>(255, 0, 255, 255));

    if(m_texture != nullptr){
        delete(m_texture);
    }
    m_texture = new AM::Texture(field);
}

AM::Texture *AM::Profiler::getTexture() {
    return m_texture;
}
