#include <glad/glad.h>

#include "Program.h"

namespace GL {

Program::Program() :
    _id(UINT32(-1)),
    _shaders_attached()
{
    _id = glCreateProgram();
}

Program &Program::attachShader(const Shader &shader)
{
    glAttachShader(_id, shader.getID());

    _shaders_attached.emplace_back(shader.getID());

    return *this;
}


} //namespace GL

