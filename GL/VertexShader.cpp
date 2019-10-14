#include <glad/glad.h>

#include "VertexShader.h"

GL::VertexShader::VertexShader()
{
    _id = glCreateShader(GL_VERTEX_SHADER);
}
