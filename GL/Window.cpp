#include <iostream>

#include <glad/glad.h>

#include "glfw3.h"
#include "Window.h"

namespace GL {

std::function<void(uint32, uint32)> Window::_handler_size_changed = std::function<void(uint32, uint32)>();
std::function<void(int32, int32)> Window::_handler_key_pressed = std::function<void(int32, int32)>();

Window::Window(const uint16 &width, const uint16 &height, const string &title) :
    _window(nullptr),
    _background_color(),
    _width(width),
    _height(height),
    _title(title),
    _is_open(false)
{
    init().createWindow(width, height, title).initGlad();
}

Window::Window(const uint16 &width, const uint16 &height, const string &title, const Color &background_color) :
    _window(nullptr),
    _background_color(background_color),
    _width(width),
    _height(height),
    _title(title)
{
    init().createWindow(width, height, title).initGlad();
}

Window::~Window()
{
    glfwTerminate();
}

Window &Window::setBackgroundColor(const real32 &r, const real32 &g, const real32 &b, const real32 &a)
{
    _background_color.setRed(r);
    _background_color.setGreen(g);
    _background_color.setBlue(b);
    _background_color.setAlpha(a);

    return *this;
}

Window &Window::setOnSizeChangedHandler(std::function<void(uint32, uint32)> handler)
{
    _handler_size_changed = handler;

    return *this;
}

Window &Window::setOnKeyPressedHandler(std::function<void(int32, int32)> handler)
{
    _handler_key_pressed = handler;

    return *this;
}

Window Window::close()
{
    glfwSetWindowShouldClose(_window, true);
    _is_open = false;

    return *this;
}

Window &Window::swapBuffers()
{
    glfwSwapBuffers(_window);

    return *this;
}

Window &Window::pollEvents()
{
    glfwPollEvents();

    return *this;
}

Window &Window::createWindow(const uint16 &width, const uint16 &height, const string &title)
{
    _window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height),
                               title.c_str(), nullptr, nullptr);

    if (!_window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return *this;
    }

    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, &onSizeChanged);
    glfwSetKeyCallback(_window, &onKeyPressed);

    _is_open = true;

    return *this;
}

void Window::onSizeChanged(GLFWwindow* window, int32 width, int32 height)
{
    (void)window;

    _handler_size_changed(UINT32(width), UINT32(height));
}

void Window::onKeyPressed(GLFWwindow *window, int key, int scan_code, int action, int mods)
{
    (void)window;
    (void)scan_code;
    (void)mods;

    _handler_key_pressed(key, action);
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
        std::cerr << "Failed to initialize GLAD" << std::endl;
    }

    return *this;
}
}
