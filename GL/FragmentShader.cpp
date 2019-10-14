#include <glad/glad.h>

#include "FragmentShader.h"

GL::FragmentShader::FragmentShader()
{
    _id = glCreateShader(GL_FRAGMENT_SHADER);
}
