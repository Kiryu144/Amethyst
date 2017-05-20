/* Created by David Klostermann on 26.03.2017. */
#ifndef AMETHYST3D_ROTATION_H
#define AMETHYST3D_ROTATION_H

#include <GLM/common.hpp>
#include <GLM/mat4x4.hpp>
#include <GLM/gtx/euler_angles.hpp>

namespace AM {

class Quaternion {
private:
    glm::vec3 m_rotation;
public:
    template<typename T>
    Quaternion(T x, T y, T z) {
        m_rotation = glm::vec3(x, y, z);
    }

    Quaternion(glm::vec3 rot);

    Quaternion() {};

    const glm::vec3 &getRotation() const;

    void setRotation(glm::vec3 rot);

    glm::mat4 getMatrix() const;
};

}

#endif
