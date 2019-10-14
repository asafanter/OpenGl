#include <glad/glad.h>

#include "Program.h"

namespace GL {

Program::Program() :
    _id(UINT32(-1))
{
    _id = glCreateProgram();
}

Program &Program::attachShader(const Shader &shader)
{
    glAttachShader(_id, shader.getID());

    return *this;
}


} //namespace GL

