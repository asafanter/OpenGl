#include <glad/glad.h>

#include "VAO.h"

namespace GL {

VAO::VAO() :
    _id(UINT32(-1)),
    _premitive(Premitive::POINTS)
{
    glGenVertexArrays(1, &_id);
}

VAO &VAO::setPremitive(const VAO::Premitive &new_premitive)
{
    _premitive = new_premitive;

    return *this;
}

} //namespace GL


