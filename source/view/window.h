/* Created by David Klostermann on 18.05.2017. */
#ifndef AMETHYST_WINDOW_H
#define AMETHYST_WINDOW_H

#include <string>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
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


class Window {
private:
    GLFWwindow* m_glfwWindow;

    std::string m_lastTitle;
    glm::vec4 m_lastClearColor;
public:
    Window(std::string title, glm::vec2 size, GLFWwindow* master, bool visible = true);
    ~Window();

    void swap();
    void clear(int buffers = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLFWwindow* getGLFWwindow();
    void makeContextCurrent();
    void makeContextNull();

    /* Settings */
    void setTitle(std::string title);
    std::string getTitle();

    void setSize(glm::vec2 size);
    glm::vec2 getSize();

    void setClearColor(glm::vec4 clearColor);
    glm::vec4 getClearColor();

    void setFocus();
    bool isFocused();

    bool isVisible();
};

namespace WindowHandler {
namespace detail {
    static Window* masterWindow;
    static std::vector<Window*> sharedWindows;
}

void init(std::string title, glm::vec2 size, glm::vec4 clearColor, int sharedWindows);
void destroy();

bool update(bool swap = true);
Window* getWindow();
GLFWwindow* getGlfwWindow();
Window* getSharedWindow(int index);

}

}

#endif
