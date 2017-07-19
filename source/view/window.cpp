/* Created by David Klostermann on 18.05.2017. */
#include "window.h"


AM::Window::Window(std::string title, glm::vec2 size, GLFWwindow *master, bool visible) {
    glfwInit();

    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 2);
    glfwWindowHint(GLFW_VISIBLE, visible);

    m_glfwWindow = glfwCreateWindow(size.x, size.y, "", NULL, master);

    this->setSize(size);
    this->setTitle(title);

    glfwSwapInterval(0);

    if(master == nullptr){
        this->makeContextCurrent();
    }
}

AM::Window::~Window() {
    glfwDestroyWindow(m_glfwWindow);
}

void AM::Window::swap() {
    glfwSwapBuffers(m_glfwWindow);
}

void AM::Window::clear(int buffers) {
    if(buffers != 0){
        glClear(buffers);
    }
}

GLFWwindow *AM::Window::getGLFWwindow() {
    return m_glfwWindow;
}

void AM::Window::makeContextCurrent() {
    glfwMakeContextCurrent(m_glfwWindow);
}

void AM::Window::makeContextNull() {
    glfwMakeContextCurrent(nullptr);
}

void AM::Window::setTitle(std::string title) {
    glfwSetWindowTitle(m_glfwWindow, title.c_str());
    m_lastTitle = title;
}

std::string AM::Window::getTitle() {
    return m_lastTitle;
}

void AM::Window::setSize(glm::vec2 size) {
    glfwSetWindowSize(m_glfwWindow, size.x, size.y);
}

glm::vec2 AM::Window::getSize() {
    glm::tvec2<int> size;
    glfwGetWindowSize(m_glfwWindow, &size.x, &size.y);
    return size;
}

void AM::Window::setClearColor(glm::vec4 clearColor) {
    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    m_lastClearColor = clearColor;
}

glm::vec4 AM::Window::getClearColor() {
    return m_lastClearColor;
}

void AM::Window::setFocus() {
    glfwFocusWindow(m_glfwWindow);
}

bool AM::Window::isFocused() {
    glfwGetWindowAttrib(m_glfwWindow, GLFW_FOCUSED);
}

bool AM::Window::isVisible() {
    return glfwGetWindowAttrib(m_glfwWindow, GLFW_VISIBLE);
}



//======================================
//          WINDOW HANDLER
//======================================

void AM::WindowHandler::init(std::string title, glm::vec2 size, glm::vec4 clearColor, int sharedWindows){
    if(AM::WindowHandler::detail::masterWindow != nullptr){
        throwAmethystException(AM_WINDOW_ALREADY_INITIALIZED, "Windowhandler already initialized.");
    }

    AM::WindowHandler::detail::masterWindow = new AM::Window(title, size, nullptr, true);
    setupOpenGLSettings();
    glewInit();
    AM::WindowHandler::detail::masterWindow->setClearColor(clearColor);

    for(int i = 0; i < sharedWindows; i++){
        std::string title = "SharedWin " + std::to_string(i);
        AM::WindowHandler::detail::sharedWindows.push_back(new AM::Window(title, glm::vec2(1, 1), AM::WindowHandler::detail::masterWindow->getGLFWwindow(), false));
    }
}

void AM::WindowHandler::init(){
    AM::WindowHandler::init("Amethyst", glm::vec2(1280, 720), glm::vec4(0, 0, 0, 1), 0);
}

void AM::WindowHandler::destroy(){
    delete(AM::WindowHandler::detail::masterWindow);
    for(Window* window : AM::WindowHandler::detail::sharedWindows){
        delete(window);
    }
}

bool AM::WindowHandler::update(bool swap){
    glfwPollEvents();

    if(swap){
        AM::WindowHandler::detail::masterWindow->swap();
        AM::WindowHandler::detail::masterWindow->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    return !glfwWindowShouldClose(AM::WindowHandler::detail::masterWindow->getGLFWwindow());
}

AM::Window* AM::WindowHandler::getWindow(){
    return AM::WindowHandler::detail::masterWindow;
}

GLFWwindow* AM::WindowHandler::getGlfwWindow(){
    return AM::WindowHandler::detail::masterWindow->getGLFWwindow();
}

AM::Window* AM::WindowHandler::getSharedWindow(int index){
    return AM::WindowHandler::detail::sharedWindows.at(index);
}
