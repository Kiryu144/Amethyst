/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_WINDOW_H
#define AMETHYST_WINDOW_H

#include <string>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <GLM/common.hpp>

#include "util/amethystexception.h"
#include "util/logger.h"

namespace AM {

static void setupOpenGLSettings() {
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
};

static void glewInit() {
    float start = glfwGetTime();
    glewExperimental = GL_TRUE;
    int glewState = ::glewInit();
    if(glewState){ /* If glewInit() fails */
        throwAmethystException(("Could not glewInit(). GLEW Error: " + std::string((const char*)glewGetErrorString(glewState))));
    }

    Logger::info("OpenGL version " + std::string((const char*)glGetString(GL_VERSION)), 2);
    Logger::info("Created GLEW interface in " + std::to_string(glfwGetTime() - start) + " ms!", 3);
}

class WindowHandler {
private:
    static GLFWwindow *m_glfwWindow;
    static GLFWwindow *m_sharedGlfwWindow;

    static glm::vec2 m_windowSize;
    static glm::vec4 m_clearColor;
    static glm::vec4 m_clearColorNormalized;
public:
    static void init();
    static void destroy();
    static bool poll(bool swap = true);

    static void swapBuffers(bool clear = true);
    static void createWindow(std::string title, glm::vec2 size, glm::vec4 color);
    static GLFWwindow *getGlfwWindow();
    static GLFWwindow *getSharedGlfwWindow();
    static void setClearColor(glm::vec4 color);
    static glm::vec4 getClearColor();
    static void setSize(glm::vec2 size);
    static glm::vec2 getSize();
    static void setFocus();
    static bool isFocused();
};

}

#endif
