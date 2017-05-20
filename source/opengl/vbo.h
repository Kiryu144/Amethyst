/* Created by David Klostermann on 08.05.2017. */
#ifndef AMETHYST_VBO_H
#define AMETHYST_VBO_H

#include <vector>
#include "view/window.h"

namespace AM {

template<typename T, unsigned int elementAmount, int dataType = GL_FLOAT>
class VBO {
private:
    unsigned int m_vbo = -1; //Setting to max int
public:
    VBO() {}

    ~VBO() {
        deleteVBO();
    }

    void upload(std::vector<T> &data, GLenum storagePattern = GL_STATIC_DRAW) {
        if (this->vboExists()) {
            this->deleteVBO();
        }
        glGenBuffers(1, &m_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(T), &data.at(0), GL_STATIC_DRAW);
    }

    bool vboExists() const{
        return m_vbo != (unsigned int)-1;
    }

    void deleteVBO() {
        glDeleteBuffers(1, &m_vbo);
        m_vbo = -1;
    }

    unsigned int getVBO() const {
        return m_vbo;
    }

    void bind(unsigned int index) {
        glEnableVertexAttribArray(index);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        glVertexAttribPointer(index, elementAmount, dataType, GL_FALSE, 0, (void *) 0);
    }
};

}

#endif
