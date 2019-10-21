#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

#include "GL.h"

namespace GL {

GL::GL() :
    _window(nullptr),
    _meshes(),
    _view(glm::mat4(1.0)),
    _projection(glm::mat4(1.0f)),
    _camera({})
{
    _camera.pos = glm::vec3(1.0, 0.0, 3.0);
    _camera.front = glm::vec3(0.0, 0.0, -1.0);
    _camera.up = glm::vec3(0.0, 1.0, 0.0);
}

GL &GL::attachWindow(Window &window)
{
    _window = &window;

    _projection = glm::perspective(45.0f, REAL32(_window->getWidth()) / REAL32(_window->getHeight()), 0.1f, 100.0f);

    _window->setOnSizeChangedHandler([this](uint32 width, uint32 height)
    {
        _projection = glm::perspective(45.0f, REAL32(width) / REAL32(height), 0.1f, 100.0f);
        glViewport(0, 0, INT32(width), INT32(height));
    });

    return *this;
}

GL &GL::addMesh(const Mesh &mesh)
{
    _meshes.emplace_back(mesh);

    return *this;
}

GL &GL::setPointSize(const uint32 &size)
{
    glPointSize(size);

    return *this;
}

GL &GL::setLineWidth(const uint32 &width)
{
    glLineWidth(width);

    return *this;
}

void GL::run(const Program &program)
{
    if(_window == nullptr)
    {
        std::cerr << "there is no window attached" << std::endl;
        return;
    }
    if(_meshes.empty())
    {
        std::cerr << "there is no meshes to draw" << std::endl;
        return;
    }

    glEnable(GL_DEPTH_TEST);

    while(_window->isRunning())
    {
        _window->ProcessInput();
        clearBackgroundColor();
        program.use();

        updateMatrices(program);

        for(auto &mesh : _meshes)
        {
            mesh.draw(program);
        }

        _window->swapBuffers();
        _window->pollEvents();
    }
}

GL::~GL()
{
    for(auto &mesh : _meshes)
    {
        mesh.remove();
    }
}

GL &GL::drawPoints(const uint64 &num_of_vertices)
{
    glDrawArrays(GL_POINTS, 0, INT32(num_of_vertices));

    return *this;
}

GL &GL::drawLines(const uint64 &num_of_vertices)
{
    if(num_of_vertices > 0 && num_of_vertices % 2 != 0)
    {
        std::cerr << "premitive set to 'lines' but num of vertices: " << num_of_vertices <<
                     " does not divide with 2" << std::endl;
    }

    glDrawArrays(GL_LINES, 0, INT32(num_of_vertices));

    return *this;
}

GL &GL::drawTriangles(const uint64 &num_of_vertices)
{
    if(num_of_vertices % 3 != 0)
    {
        std::cerr << "premitive set to 'triangles' but num of vertices: " << num_of_vertices <<
                     " does not divede with 3" << std::endl;
    }

    glDrawArrays(GL_TRIANGLES, 0, INT32(num_of_vertices));

    return *this;
}

GL &GL::clearBackgroundColor()
{
    Color color = _window->getBackgroundColor();
    glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    return *this;
}

GL &GL::updateMatrices(const Program &program)
{
    _view = glm::lookAt(_camera.pos, _camera.pos + _camera.front, _camera.up);
    program.setMatrix4("view", _view);
    program.setMatrix4("projection", _projection);

    return *this;
}

} //namespace GL


