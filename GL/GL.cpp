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

GL &GL::compileShader(const Shader &shader)
{
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
    uint32 program_id = program.getID();

    glLinkProgram(program_id);

    int success = -1;
    char log[512];

    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program_id, 512, nullptr, log);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << log << std::endl;
    }

    return *this;
}

GL &GL::addVAO(const VAO &vao)
{
    _vaos.push_back(vao);

    return *this;
}

GL &GL::bindVAO(const VAO &vao)
{
    glBindVertexArray(vao.getID());

    return *this;
}

GL &GL::bindVBO(const VBO &vbo)
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo.getID());

    glBufferData(GL_ARRAY_BUFFER, INT64(sizeof(Vertex) * vbo.getVertices().size()), vbo.getVertices().data(), GL_STATIC_DRAW);

    for(auto &atr : vbo.getAttributes())
    {
        glVertexAttribPointer(atr.getID(), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(atr.offset()));
        glEnableVertexAttribArray(atr.getID());
    }

    return *this;
}

void GL::run(const Program &program)
{
    if(_window == nullptr)
    {
        std::cout << "window was not set" << std::endl;
        return;
    }

    while(_window->isRunning())
    {
        Color color = _window->getBackgroundColor();
        glPointSize(2);
        glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program.getID());

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
        glDeleteVertexArrays(1, &vao_id_to_destroy);
    }
}

GL &GL::draw(const VAO &vao)
{
    glBindVertexArray(vao.getID());

    if(vao.getPremitive() == VAO::Premitive::POINTS)
    {
        glDrawArrays(GL_POINTS, 0, 3);
    }
    else if(vao.getPremitive() == VAO::Premitive::LINES)
    {
        glDrawArrays(GL_LINES, 0, 4);
    }
    else if(vao.getPremitive() == VAO::Premitive::TRIANGLES)
    {
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    return *this;
}

} //namespace GL


