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
    _view(glm::mat4(1.0f)),
    _projection(glm::mat4(1.0f))
{
    _view = glm::translate(_view, glm::vec3(0.0f, 0.0f, -3.0f));
}

GL &GL::attachWindow(Window &window)
{
    _window = &window;

    _projection = glm::perspective(45.0f, REAL32(_window->getWidth()) / REAL32(_window->getHeight()), 0.1f, 100.0f);

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
        std::cout << "there is no window attached" << std::endl;
        return;
    }

        glEnable(GL_DEPTH_TEST);

    while(_window->isRunning())
    {
        Color color = _window->getBackgroundColor();
        glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        program.use();

        program.setMatrix4("view", _view);
        program.setMatrix4("projection", _projection);

        for(auto &mesh : _meshes)
        {
            mesh.rotate(0.005, 0.005, 0.0);
            mesh.draw();
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

GL &GL::draw()
{

    for(auto &mesh : _meshes)
    {
        mesh.draw();
    }

    return *this;
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

} //namespace GL


