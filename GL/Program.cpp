#include <glad/glad.h>
#include <iostream>

#include "Program.h"

GL::Program::Program()
{
    _id = glCreateProgram();
}

GL::Program &GL::Program::addShader(const GL::Shader &shader)
{
    glAttachShader(_id, shader.getId());

    return *this;
}

GL::Program &GL::Program::link()
{
    glLinkProgram(_id);

    int success = 0;
    char result[512];

    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(_id, 512, nullptr, result);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << result << std::endl;
    }

    //delete shaders

    return *this;
}
