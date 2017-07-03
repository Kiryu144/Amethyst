/* Created by David Klostermann on 03.07.2017. */
#ifndef AMETHYST_UTIL_H
#define AMETHYST_UTIL_H

namespace AM{

    template <typename T, typename N>
    float map(T val, N min, N max){
        if(val > max) return max;
        else if(val < min) return min;
        else return val;
    };

}

#endif
