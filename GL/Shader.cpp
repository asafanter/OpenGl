#include <glad/glad.h>
#include <fstream>
#include <iostream>

#include "Shader.h"

namespace GL {

Shader::Shader() :
    _id(UINT32(-1)),
    _src()
{

}

void Shader::remove()
{
    if(_id == UINT32(-1))
    {
        return;
    }

    glDeleteShader(_id);
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

const Shader &Shader::compile() const
{
    if(!isSourceSet())
    {
        std::cerr << "shader with id: " << _id << " has no source" << std::endl;
        return *this;
    }

    glCompileShader(_id);

    int success = -1;
    char log[512];

    glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(_id, 512, nullptr, log);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << log << std::endl;
    }

    return *this;
}

Shader::~Shader()
{
    glDeleteShader(_id);
}

} //namespace GL


