#include <glad/glad.h>

#include "VertexShader.h"

namespace GL {

VertexShader::VertexShader()
{
    _id = glCreateShader(GL_VERTEX_SHADER);
}


} //namespace GL



