#include <glad/glad.h>
#include <fstream>
#include <iostream>

#include "Shader.h"

namespace GL {

Shader::Shader() :
    _id(UINT32(-1))
{

}

Shader &Shader::setSource(const string &file_name)
{
    std::fstream in(file_name, std::ios::in);
    if(!in.is_open())
    {
        std::cerr << "cannot open shader file: " << file_name << std::endl;

        return *this;
    }

    _src = std::string((std::istreambuf_iterator<char>(in)),
                     std::istreambuf_iterator<char>());

    const int8* source = _src.data();

    glShaderSource(_id, 1, &source, nullptr);

    return *this;
}

Shader::~Shader()
{
    glDeleteShader(_id);
}

} //namespace GL


