#include <iostream>

#include <glad/glad.h>

#include "glfw3.h"
#include "Window.h"

namespace GL {

Window::Window(const uint &width, const uint &height, const string &title) :
    _window(nullptr),
    _background_color({})
{
    init().createWindow(width, height, title).initGlad();
}

Window::~Window()
{
    glfwTerminate();
}

Window &Window::setBackgroundColor(const float &r, const float &g, const float &b, const float &a)
{
    _background_color.r = r;
    _background_color.g = g;
    _background_color.b = b;
    _background_color.a = a;

    return *this;
}

bool Window::isRunning() const
{
    return !glfwWindowShouldClose(_window);
}

Window &Window::createWindow(const uint &width, const uint &height, const string &title)
{
    _window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height),
                               title.c_str(), nullptr, nullptr);

    if (_window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(_window);
//    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

    return *this;
}

Window& Window::init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return *this;
}

Window &Window::initGlad()
{
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }

    return *this;
}
}
