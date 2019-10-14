#include <glad/glad.h>

#include "FragmentShader.h"

namespace GL {

FragmentShader::FragmentShader()
{
    _id = glCreateShader(GL_FRAGMENT_SHADER);
}

} //namespace GL


