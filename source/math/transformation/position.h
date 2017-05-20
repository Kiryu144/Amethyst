/* Created by David Klostermann on 26.03.2017. */
#ifndef AMETHYST3D_POSITION_H
#define AMETHYST3D_POSITION_H

#include <GLM/common.hpp>
#include <GLM/gtx/transform.hpp>

namespace AM {

class Position {
private:
    glm::vec3 m_position;
public:
    template<typename T>
    Position(T x, T y, T z){
        m_position = glm::vec3(x, y, z);
    }
    Position(glm::vec3 pos);
    Position() {};

    const glm::vec3 &getPosition() const;
    void setPosition(glm::vec3 pos);
    void translate(glm::vec3 other);

    glm::mat4 getMatrix() const;
};

}

#endif
