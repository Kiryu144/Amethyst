/* Created by David Klostermann on 16.08.2017. */
#ifndef AMETHYST_PROFILER_H
#define AMETHYST_PROFILER_H

#include "opengl/texture.h"

namespace AM{

class Profiler {
private:
    bool m_adjustMax;
    float m_min;
    float m_max;

    std::vector<float> m_values;

    AM::Texture* m_texture = nullptr;
public:
    Profiler(float min, float initMax, bool adjustMax = true);
    const int SIZE = 128;

    void addValue(float value);
    void regenerate();
    AM::Texture* getTexture();
};

}


#endif
