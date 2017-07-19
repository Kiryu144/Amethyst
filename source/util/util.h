/* Created by David Klostermann on 03.07.2017. */
#ifndef AMETHYST_UTIL_H
#define AMETHYST_UTIL_H

#include <GLM/common.hpp>

namespace AM{

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
