/* Created by David Klostermann on 17.05.2017. */
#ifndef AMETHYST_SHADER_H
#define AMETHYST_SHADER_H

#include <string>
#include <map>
#include <GLM/common.hpp>
#include <GLM/mat4x4.hpp>

#include "view/window.h"
#include "util/fastfileio.h"
#include "util/amethystexception.h"

#define SHADER_CODE 1
#define SHADER_PATH 2

namespace AM {

class Shader {
private:
    unsigned int m_programID = -1;
    std::map<std::string, int> m_uniformLocations;

    bool m_isCompiled() const;
public:
    Shader(std::string vertex, std::string fragment, int type = SHADER_PATH);
    ~Shader();

    unsigned int compileShader(std::string& shader, int shaderType);
    unsigned int linkShaders(unsigned int vertID, unsigned int fragID);

    void bind() const;

    int getUniformLocation(std::string uniformName);
    void setUniform(std::string uniform, float value);
    void setUniform(std::string uniform, glm::vec2 vec);
    void setUniform(std::string uniform, glm::vec3 vec);
    void setUniform(std::string uniform, glm::vec4 vec);
    void setUniform(std::string uniform, glm::mat4 mat);
    void setUniform(std::string uniform, int value);
};

}


#endif
