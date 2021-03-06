#include <glad/glad.h>
#include <iostream>

#include "Program.h"

namespace GL {

Program::Program() :
    _id(UINT32(-1)),
    _shaders_attached(),
    _is_linked(false)
{
    _id = glCreateProgram();
}

Program &Program::attachShader(const Shader &shader)
{
    glAttachShader(_id, shader.getID());

    _shaders_attached.emplace_back(shader.getID());

    return *this;
}

Program &Program::link()
{
    if(!hasShadersAttached())
    {
        std::cerr << "program with id: " << _id << " has no shaders attached" << std::endl;
        return *this;
    }

    glLinkProgram(_id);

    int success = -1;
    char log[512];

    glGetProgramiv(_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(_id, 512, nullptr, log);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << log << std::endl;
    }
    else
    {
        _is_linked = true;
    }

    return *this;
}

const Program &Program::setMatrix4(const string &name, const glm::core::type::mat4 &new_matrix) const
{
    int32 location  = glGetUniformLocation(_id, name.c_str());

    if(location == -1)
    {
        std::cerr <<"failed to find location of matrix named: " << name << std::endl;
        return *this;
    }

    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(new_matrix));

    return *this;
}

const Program &Program::use() const
{
    if(!_is_linked)
    {
        std::cerr << "program was not linked" << std::endl;
        return *this;
    }

    glUseProgram(_id);

    return *this;
}


} //namespace GL

