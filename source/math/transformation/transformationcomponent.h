/* Created by David Klostermann on 30.05.2017. */
#ifndef AMETHYST_TRANSFORMATIONCOMPONENT_H
#define AMETHYST_TRANSFORMATIONCOMPONENT_H

#include <GLM/common.hpp>

namespace AM {

class TransformationComponent {
protected:
    glm::vec3 m_data;
public:
    explicit TransformationComponent() {};
    template<typename T>
    explicit TransformationComponent(T x, T y, T z) { m_data = glm::vec3(x, y, z); }
    explicit TransformationComponent(glm::vec3 data);

    void translate(glm::vec3 vec);
    void set(glm::vec3 vec);
    glm::vec3 get() const;

    virtual glm::mat4 getMatrix() const = 0;
};

}


#endif
