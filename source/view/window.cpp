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

    AM::Logger::info("Created window " + title, 2);
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
    AM::WindowHandler::detail::masterWindow = new AM::Window(title, size, nullptr, true);
    setupOpenGLSettings();
    glewInit();
    AM::WindowHandler::detail::masterWindow->setClearColor(clearColor);

    for(int i = 0; i < sharedWindows; i++){
        std::string title = "SharedWin " + std::to_string(i);
        AM::WindowHandler::detail::sharedWindows.push_back(new AM::Window(title, glm::vec2(1, 1), AM::WindowHandler::detail::masterWindow->getGLFWwindow(), false));
    }
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


#ifdef fgwegwe
GLFWwindow *AM::WindowHandler::m_glfwWindow = nullptr;
GLFWwindow *AM::WindowHandler::m_sharedGlfwWindow = nullptr;
glm::vec2 AM::WindowHandler::m_windowSize;
glm::vec4 AM::WindowHandler::m_clearColor;
glm::vec4 AM::WindowHandler::m_clearColorNormalized;

static void init();
static bool poll(bool swap = true);
static void swapBuffers(bool clear = true);
static void createWindow(std::string title, glm::vec2 size, glm::vec4 color);
static GLFWwindow *getGlfwWindow();
static GLFWwindow *getSharedGlfwWindow();
static void setClearColor(glm::vec4 color);
static glm::vec4 getClearColor();
static glm::vec2 getSize();
static glm::vec2 getSize();
static void setFocus();
static bool isFocused();
static void setTitle(std::string title);


void AM::WindowHandler::init() {
    float start = glfwGetTime();
    if(!glfwInit()){
        throwAmethystException("Could not initialize GLFW!");
    }
    AM::Logger::info("WindowHandler initialized in " + std::to_string(glfwGetTime() - start) + " ms!", 2);
}

bool AM::WindowHandler::poll(bool swap) {
    /* Look out for OS events */
    glfwPollEvents();

    if(glfwWindowShouldClose(m_glfwWindow)){
        Logger::info("Received close request", 3);
        return false;
    }else if(swap){
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

    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
    m_sharedGlfwWindow = glfwCreateWindow( 1, 1, "Thread Window", NULL, NULL);

    /* Set window properties */
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_SAMPLES, 2);

    glfwWindowHint( GLFW_VISIBLE, GL_TRUE);
    /* Create window and bind with openGL */
    m_glfwWindow = glfwCreateWindow(int(size.x), int(size.y), title.c_str(), NULL, m_sharedGlfwWindow); /* Creates window (GLFW)*/
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

GLFWwindow *AM::WindowHandler::getSharedGlfwWindow() {
    return m_sharedGlfwWindow;
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

void AM::WindowHandler::setTitle(std::string title) {
    glfwSetWindowTitle(m_glfwWindow, title.c_str());
}
#endif
