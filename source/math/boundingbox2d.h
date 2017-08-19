/* Created by David Klostermann on 16.08.2017. */
#ifndef AMETHYST_BOUNDINGBOX2D_H
#define AMETHYST_BOUNDINGBOX2D_H

#include <GLM/common.hpp>

namespace AM{

class AABB2D {
private:
    glm::vec2 m_first;
    glm::vec2 m_second;
public:
    AABB2D() {};
    AABB2D(glm::vec2 first, glm::vec2 second);

    glm::vec2 getFirst();
    glm::vec2 getSecond();
    glm::vec2 getCenter();
    glm::vec2 getSize();

    void translate(glm::vec2 translate);

    void setFirst(glm::vec2 first);
    void setSecond(glm::vec2 second);
    void set(glm::vec2 first, glm::vec2 second);

    bool isInside(glm::vec2 pos);
};

}


#endif
