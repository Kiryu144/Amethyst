/* Created by David Klostermann on 26.03.2017. */
#ifndef AMETHYST3D_SCALE_H
#define AMETHYST3D_SCALE_H

#include <GLM/common.hpp>
#include <GLM/gtx/transform.hpp>

namespace AM {

class Scale {
private:
    glm::vec3 m_scale = glm::vec3(1, 1, 1);
public:
    template<typename T>
    Scale(T x, T y, T z) {
        m_scale = glm::vec3(x, y, z);
    }
    Scale(glm::vec3 scl);
    Scale(float scl);
    Scale() {};

    const glm::vec3 &getScale() const;
    void setScale(glm::vec3 scl);
    void setScale(double scl);
    glm::mat4 getMatrix() const;
};

}

#endif
