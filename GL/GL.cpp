#include <glad/glad.h>
#include <iostream>

#include "GL.h"
#include "Attribute.h"

namespace GL {

GL::GL() :
    _window(nullptr),
    _vaos(),
    _program(nullptr)
{

}

GL &GL::attachWindow(Window &window)
{
    _window = &window;

    return *this;
}

GL &GL::compileShader(const Shader &shader)
{
    if(!shader.isSourceSet())
    {
        std::cerr << "shader with id: " << shader.getID() << " has no source" << std::endl;
        return *this;
    }

    uint32 shader_id = shader.getID();

    glCompileShader(shader_id);

    int success = -1;
    char log[512];

    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader_id, 512, nullptr, log);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << log << std::endl;
    }

    return *this;
}

GL &GL::linkProgram(const Program &program)
{

    if(!program.hasShadersAttached())
    {
        std::cerr << "program with id: " << program.getID() << " has no shaders attached" << std::endl;
        return *this;
    }

    uint32 program_id = program.getID();

    glLinkProgram(program_id);

    int success = -1;
    char log[512];

    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program_id, 512, nullptr, log);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << log << std::endl;
    }
    else
    {
        _program = std::make_shared<Program>(program);
    }

    return *this;
}

GL &GL::addVAO(const VAO &vao)
{
    _vaos.emplace_back(vao);

    bindVAO(vao);

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

GL &GL::bindVAO(const VAO &vao)
{
    if(!vao.hasVBO())
    {
        std::cerr << "VAO with id: " << vao.getID() << " has no VBO attached" << std::endl;
        return *this;
    }

    glBindVertexArray(vao.getID());

    VBO vbo = vao.getVBO();

    if(!vbo.hasVertices())
    {
        std::cerr << "VBO with id: " << vbo.getID() << " has not vertices" << std::endl;
        return *this;
    }

    if(!vbo.hasAttributes())
    {
        std::cerr << "VBO with id: " << vbo.getID() << " has not attributes" << std::endl;
        return *this;
    }

    glBindBuffer(GL_ARRAY_BUFFER, vbo.getID());

    glBufferData(GL_ARRAY_BUFFER, INT64(sizeof(Vertex) * vbo.getVertices().size()), vbo.getVertices().data(), GL_STATIC_DRAW);

    for(auto &atr : vbo.getAttributes())
    {
        glVertexAttribPointer(atr.getID(), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(atr.offset()));
        glEnableVertexAttribArray(atr.getID());
    }

    return *this;
}

void GL::run()
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

    if(!_program)
    {
        std::cerr << "program was not linked" << std::endl;
    }

    while(_window->isRunning())
    {
        Color color = _window->getBackgroundColor();
        glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        glClear(GL_COLOR_BUFFER_BIT);

        if(_program)
        {
            glUseProgram(_program->getID());
        }

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
        auto vao_id_to_destroy = vao.getID();
        auto vbo_id_to_destroy = vao.getVBO().getID();

        glDeleteVertexArrays(1, &vao_id_to_destroy);
        glDeleteBuffers(1, &vbo_id_to_destroy);
    }
}

GL &GL::draw(const VAO &vao)
{
    glBindVertexArray(vao.getID());

    auto num_of_vbo_vertices = INT32(vao.getVBO().getVertices().size());

    if(vao.getPremitive() == Premitive::POINTS)
    {
        glDrawArrays(GL_POINTS, 0, num_of_vbo_vertices);
    }
    else if(vao.getPremitive() == Premitive::LINES)
    {
        if(num_of_vbo_vertices > 0 && num_of_vbo_vertices % 2 != 0)
        {
            std::cerr << "premitive set to 'lines' but num of vertices: " << num_of_vbo_vertices <<
                         " does not divide with 2" << std::endl;
        }

        glDrawArrays(GL_LINES, 0, num_of_vbo_vertices);
    }
    else if(vao.getPremitive() == Premitive::TRIANGLES)
    {
        if(num_of_vbo_vertices % 3 != 0)
        {
            std::cerr << "premitive set to 'triangles' but num of vertices: " << num_of_vbo_vertices <<
                         " does not divede with 3" << std::endl;
        }

        glDrawArrays(GL_TRIANGLES, 0, num_of_vbo_vertices);
    }

    return *this;
}

} //namespace GL


