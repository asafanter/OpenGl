#include <glad/glad.h>
#include <iostream>

#include "GL.h"

GL::GL::GL() :
    _window(nullptr)
{

}

GL::GL &GL::GL::attachWindow(Window &window)
{
    _window = &window;

    return *this;
}

GL::GL &GL::GL::copyDataToGPU(const std::vector<Vertex> &vertices)
{
    glBufferData(GL_ARRAY_BUFFER, static_cast<long long>(sizeof(Vertex) * vertices.size()),
                 vertices.data(), GL_STATIC_DRAW);

    return *this;
}

void GL::GL::run()
{
    if(_window == nullptr)
    {
        std::cout << "window was not set" << std::endl;
        return;
    }

    while(_window->isRunning())
    {
        Window::Color color = _window->getBackgroundColor();
        glPointSize(3);
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(_window->getWindow());
        glfwPollEvents();
    }
}
