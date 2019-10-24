#include <iostream>

#include <glad/glad.h>

#include "glfw3.h"
#include "Window.h"

namespace GL {

std::function<void(real64, real64)> Window::_on_mouse_moved = nullptr;
std::function<void(uint32, uint32)> Window::_handler_size_changed = nullptr;
std::function<void(int32, int32)> Window::_handler_key_pressed = nullptr;

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

Window &Window::setOnMouseMovedHandler(std::function<void (real64, real64)> handler)
{
    _on_mouse_moved = handler;

    return *this;
}

Window Window::close()
{
    glfwSetWindowShouldClose(_window, true);
    _is_open = false;

    return *this;
}

const Window &Window::maximize() const
{
    glfwMaximizeWindow(_window);

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
    glfwSetCursorPosCallback(_window, &onMouseMoved);
//    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    _is_open = true;

    return *this;
}

void Window::onSizeChanged(GLFWwindow* window, int32 width, int32 height)
{
    (void)window;

    glViewport(0, 0, INT32(width), INT32(height));

    if(_handler_size_changed)
    {
        _handler_size_changed(UINT32(width), UINT32(height));
    }
}

void Window::onKeyPressed(GLFWwindow *window, int32 key, int32 scan_code, int32 action, int32 mods)
{
    (void)window;
    (void)scan_code;
    (void)mods;

    if(_handler_key_pressed)
    {
        _handler_key_pressed(key, action);
    }
}

void Window::onMouseMoved(GLFWwindow *window, real64 x, real64 y)
{
    (void)window;

    if(_on_mouse_moved)
    {
        _on_mouse_moved(x, y);
    }
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
