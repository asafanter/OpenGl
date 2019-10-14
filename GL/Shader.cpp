#include <glad/glad.h>
#include <iostream>

#include "Shader.h"

GL::Shader &GL::Shader::setSource(const GL::string &src)
{
    const char* src_ptr = src.data();

    glShaderSource(_id, 1, &src_ptr, nullptr);

    return *this;
}

GL::Shader &GL::Shader::compile()
{
    glCompileShader(_id);

    int success = 0;
    char result[512];
    glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(_id, 512, nullptr, result);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << result << std::endl;
    }

    return *this;
}
