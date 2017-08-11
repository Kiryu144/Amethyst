/* Created by David Klostermann on 03.07.2017. */
#ifndef AMETHYST_UTIL_H
#define AMETHYST_UTIL_H

#include <vector>
#include <GLM/common.hpp>

namespace AM{

    static const glm::vec3 __plane[] = {
            //FRONT, left bottom
            glm::vec3(0, 0, 0),
            glm::vec3(1, 0, 0),
            glm::vec3(0, 1, 0),
            //FRONT, right top
            glm::vec3(0, 1, 0),
            glm::vec3(1, 1, 0),
            glm::vec3(1, 0, 0)
    };

    static const glm::vec2 ___model_plane_uv[] = {
            glm::vec2(0, 0),
            glm::vec2(1, 0),
            glm::vec2(0, 1),

            glm::vec2(0, 1),
            glm::vec2(1, 1),
            glm::vec2(1, 0)
    };

    static std::vector<glm::vec3> plane(__plane, __plane + sizeof(__plane) / sizeof(glm::vec3));
    static std::vector<glm::vec2> plane_uv(___model_plane_uv, ___model_plane_uv + sizeof(___model_plane_uv) / sizeof(glm::vec2));


    template <typename T, typename N>
    static float map(T val, N min, N max){
        if(val > max) return max;
        else if(val < min) return min;
        else return val;
    }

    template <typename T>
    static int pythonModulus(T val1, T val2){
        return (val2 + (val1 % val2)) % val2;
    }

    static glm::vec4 rgba(int R, int G, int B, int A){
        return glm::vec4(R, G, B, A) / glm::vec4(256.0f);
    }

    static glm::vec4 rgb(int R, int G, int B){
        return glm::vec4(R, G, B, 256) / glm::vec4(256.0f);
    }

}

#endif
