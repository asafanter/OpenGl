#include <glad/glad.h>

#include "VAO.h"

namespace GL {

VAO::VAO() :
    _id(UINT32(-1)),
    _premitive(Premitive::POINTS)
{
    glGenVertexArrays(1, &_id);
}

VAO &VAO::setVBO(const VBO &vbo)
{
    _vbo = std::make_shared<VBO>(vbo);

    return *this;
}

VAO &VAO::setPremitive(const GL::Premitive &new_premitive)
{
    _premitive = new_premitive;

    return *this;
}

} //namespace GL


