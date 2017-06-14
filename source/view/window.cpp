/* Created by David Klostermann on 18.05.2017. */
#include "window.h"

GLFWwindow *AM::WindowHandler::m_glfwWindow = nullptr;
glm::vec2 AM::WindowHandler::m_windowSize;
glm::vec4 AM::WindowHandler::m_clearColor;
glm::vec4 AM::WindowHandler::m_clearColorNormalized;

static void init();
static bool poll();
static void swapBuffers(bool clear = true);
static void createWindow(std::string title, glm::vec2 size, glm::vec4 color);
static GLFWwindow *getGlfwWindow();
static void setClearColor(glm::vec4 color);
static glm::vec4 getClearColor();
static glm::vec2 getSize();
static glm::vec2 getSize();
static void setFocus();
static bool isFocused();

void AM::WindowHandler::init() {
    float start = glfwGetTime();
    if(!glfwInit()){
        throwAmethystException("Could not initialize GLFW!");
    }
    AM::Logger::info("WindowHandler initialized in " + std::to_string(glfwGetTime() - start) + " ms!", 2);
}

bool AM::WindowHandler::poll() {
    /* Look out for OS events */
    glfwPollEvents();

    if(glfwWindowShouldClose(m_glfwWindow)){
        Logger::info("Received close request", 3);
        return false;
    }else{
        swapBuffers(true);
        return true;
    }
}

void AM::WindowHandler::swapBuffers(bool clear) {
    glfwSwapBuffers(m_glfwWindow);
    if(clear){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}


void AM::WindowHandler::createWindow(std::string title, glm::vec2 size, glm::vec4 color) {
    float start = glfwGetTime();
    if(m_glfwWindow != nullptr){
        throwAmethystException(("AM::WindowHandler::createWindow() failed. Window already created"));
    }

    AM::WindowHandler::m_windowSize = size;

    /* Set window properties */
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 2);

    /* Create window and bind with openGL */
    m_glfwWindow = glfwCreateWindow(int(size.x), int(size.y), title.c_str(), NULL, NULL); /* Creates window (GLFW)*/
    glfwMakeContextCurrent(m_glfwWindow);
    glfwSwapInterval(0);

    /* Init glew and set clear color */
    setupOpenGLSettings();
    glewInit();
    setClearColor(color);

    Logger::info("WindowHandler created window in " + std::to_string(glfwGetTime() - start) + " ms!", 3);
}

GLFWwindow *AM::WindowHandler::getGlfwWindow() {
    return m_glfwWindow;
}

void AM::WindowHandler::setClearColor(glm::vec4 color) {
    AM::WindowHandler::m_clearColor = color;
    m_clearColorNormalized = color / glm::vec4(256.0f);
    glClearColor(m_clearColorNormalized.r, m_clearColorNormalized.g, m_clearColorNormalized.b, m_clearColorNormalized.a);
}

glm::vec4 AM::WindowHandler::getClearColor() {
    return m_clearColor;
}


void AM::WindowHandler::setSize(glm::vec2 size) {
    if(size.x <= 0 || size.y <= 0){
        throwAmethystException(("AM::WindowHandler::setSize() failed. Size argument is < 1"));
    }
    glfwSetWindowSize(m_glfwWindow, size.x, size.y);
}

glm::vec2 AM::WindowHandler::getSize(){
    return m_windowSize;
}

void AM::WindowHandler::setFocus() {
    glfwFocusWindow(m_glfwWindow);
}

bool AM::WindowHandler::isFocused() {
    return glfwGetWindowAttrib(AM::WindowHandler::getGlfwWindow(), GLFW_FOCUSED);
}

void AM::WindowHandler::destroy() {
    glfwDestroyWindow(m_glfwWindow);
}