#include <glad/glad.h>
#include <iostream>

#include "GL.h"
#include "Attribute.h"

namespace GL {

GL::GL() :
    _window(nullptr),
    _vaos()
{

}

GL &GL::attachWindow(Window &window)
{
    _window = &window;

    return *this;
}

GL &GL::addVAO(const VAO &vao)
{
    _vaos.emplace_back(vao);

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

    if(!hasVAO())
    {
        std::cerr << "thers is no VAO attached" << std::endl;
    }

    while(_window->isRunning())
    {
        Color color = _window->getBackgroundColor();
        glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        glClear(GL_COLOR_BUFFER_BIT);

        program.use();

        for(auto &vao : _vaos)
        {
            draw(vao);
        }

        _window->swapBuffers();
        _window->pollEvents();
    }
}

GL::~GL()
{
    for(auto &vao : _vaos)
    {
        vao.remove();
    }
}

GL &GL::draw(const VAO &vao)
{
    glBindVertexArray(vao.getID());

    if(!vao.hasVertices())
    {
        std::cerr << "VAO with id: " << vao.getID() << " has no vertices" << std::endl;
        return *this;
    }

    if(!vao.hasAttributes())
    {
        std::cerr << "VAO with id: " << vao.getID() << " has no attributes" << std::endl;
        return *this;
    }

    if(vao.getPremitive() == Premitive::POINTS)
    {
        drawPoints(vao.getNumOfVertices());
    }
    else if(vao.getPremitive() == Premitive::LINES)
    {
        drawLines(vao.getNumOfVertices());
    }
    else if(vao.getPremitive() == Premitive::TRIANGLES)
    {
        drawTriangles(vao.getNumOfVertices());
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


