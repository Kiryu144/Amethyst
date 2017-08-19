/* Created by David Klostermann on 16.08.2017. */
#ifndef AMETHYST_BUTTON_H
#define AMETHYST_BUTTON_H

#include "math/boundingbox2d.h"
#include "io/keyboard.h"


namespace AM{

class Button {
private:
    AABB2D m_area;
public:
    Button(AABB2D area);

    void update();
};

}


#endif
