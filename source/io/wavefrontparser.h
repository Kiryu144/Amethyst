/* Created by David Klostermann on 21.05.2017. */
#ifndef AMETHYST_WAVEFRONTPARSER_H
#define AMETHYST_WAVEFRONTPARSER_H

#include <GLM/common.hpp>

#include "util/stringedit.h"
#include "mesh/mesh.h"
#include "util/fastfileio.h"

namespace AM {

struct WavefrontData {
    Mesh<glm::vec3> vertexData;
    Mesh<glm::vec2> uvData;
    Mesh<glm::vec3> normalData;
};

class WavefrontParser {
private:
    WavefrontParser() {};
public:
    static void readObj(std::string filePath, WavefrontData& data);
};

}

#endif
