/* Created by David Klostermann on 14.06.2017. */
#ifndef AMETHYST_BOUNDINGBOX_H
#define AMETHYST_BOUNDINGBOX_H

#include <GLM/common.hpp>

class AABB {
private:
    glm::vec3 m_first;
    glm::vec3 m_second;
public:
    AABB() {};
    AABB(glm::vec3 first, glm::vec3 second);

    glm::vec3 getFirst();
    glm::vec3 getSecond();
    glm::vec3 getCenter();
    glm::vec3 getSize();

    void translate(glm::vec3 translate);

    void setFirst(glm::vec3 first);
    void setSecond(glm::vec3 second);
    void set(glm::vec3 first, glm::vec3 second);
};


#endif
