/* Created by David Klostermann on 17.05.2017. */
#include "shader.h"

AM::Shader::Shader(std::string vertex, std::string fragment, int type) {
    if(type == SHADER_CODE){
        m_programID = this->linkShaders(this->compileShader(vertex, GL_VERTEX_SHADER), this->compileShader(fragment, GL_FRAGMENT_SHADER));
    }else{
        std::string vertexShader;
        std::string fragShader;
        readFile(vertex, vertexShader);
        readFile(fragment, fragShader);

        m_programID = this->linkShaders(this->compileShader(vertexShader, GL_VERTEX_SHADER), this->compileShader(fragShader, GL_FRAGMENT_SHADER));
    }
}

AM::Shader::~Shader() {
    glDeleteProgram(m_programID);
}

bool AM::Shader::m_isCompiled() const {
    return m_programID != (unsigned int)-1;
}

unsigned int AM::Shader::compileShader(std::string& shader, int shaderType) {
    unsigned int shaderID = glCreateShader(shaderType);

    const char* cShader = &shader.at(0);
    glShaderSource(shaderID, 1, &cShader, NULL); //Upload
    glCompileShader(shaderID); //Compile

    int success = GL_FALSE;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE){ //Compiling failed
        int logLenght;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLenght); //Get log size

        std::vector<GLchar> log(logLenght);
        glGetShaderInfoLog(shaderID, logLenght, &logLenght, &log[0]);
        std::printf("%s\n", &log[0]);
        throwAmethystException(AM_SHADER_COMPILE_FAIL, "Could not compile shader!");
    }

    return shaderID;
}

unsigned int AM::Shader::linkShaders(unsigned int vertID, unsigned int fragID) {
    unsigned int programID = glCreateProgram();

    glAttachShader(programID, vertID);
    glAttachShader(programID, fragID);
    glLinkProgram(programID);

    int success = GL_FALSE;
    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (success == GL_FALSE) {
        int logLenght;
        glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLenght); //Get log size

        std::string log = ">";
        glGetProgramInfoLog(programID, logLenght, &logLenght, &log.at(0));

        glDeleteShader(vertID);
        glDeleteShader(fragID);

        throwAmethystException(AM_SHADER_LINK_FAIL, "Could not link shaders!" + log);
    }

    glDetachShader(programID, vertID);
    glDetachShader(programID, fragID);

    return programID;
}

void AM::Shader::bind() const {
    glUseProgram(m_programID);
}

int AM::Shader::getUniformLocation(std::string uniformName) {
    if(m_uniformLocations.find(uniformName) == m_uniformLocations.end()){
        this->bind();
        int uniformLocation = glGetUniformLocation(m_programID, uniformName.c_str());
        if(uniformLocation == GL_INVALID_INDEX){
            throwAmethystException(AM_SHADER_COULD_NOT_RETREIVE_UNIFORM, "Could not get uniform location!");
        }
        m_uniformLocations[uniformName] = uniformLocation;
        return uniformLocation;
    }else{
        return m_uniformLocations.at(uniformName);
    }
}

void AM::Shader::setUniform(std::string uniform, float value) {
    glUniform1f(getUniformLocation(uniform), value);
}

void AM::Shader::setUniform(std::string uniform, glm::vec2 vec) {
    glUniform2f(getUniformLocation(uniform), vec.x, vec.y);
}

void AM::Shader::setUniform(std::string uniform, glm::vec3 vec) {
    glUniform3f(getUniformLocation(uniform), vec.x, vec.y, vec.z);
}

void AM::Shader::setUniform(std::string uniform, glm::vec4 vec) {
    glUniform4f(getUniformLocation(uniform), vec.r, vec.g, vec.b, vec.a);
}

void AM::Shader::setUniform(std::string uniform, glm::mat4 mat) {
    glUniformMatrix4fv(getUniformLocation(uniform), 1, GL_FALSE, &mat[0][0]);
}

void AM::Shader::setUniform(std::string uniform, int value) {
    glUniform1i(getUniformLocation(uniform), 0);
}
