/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_MESH_H
#define AMETHYST_MESH_H

#include <vector>

namespace AM {

template<typename T>
class Mesh {
private:
    std::vector<T> m_vertices;

public:
    Mesh() {
    }

    Mesh(std::vector<T> &vertices) {
        m_vertices.assign(vertices.begin(), vertices.end());
    }

    void add(T vertice){
        m_vertices.push_back(vertice);
    }

    void add(std::vector<T>& vertices){
        m_vertices.insert(m_vertices.end(), vertices.begin(), vertices.end());
    }

    std::vector<T>& get(){
        return m_vertices;
    }

    void clear(){
        m_vertices.clear();
    }

    void set(std::vector<T>& vertices){
        this->clear();
        this->add(vertices);
    }

    unsigned long long int size(){
        return m_vertices.size();
    }
};

}

#endif
