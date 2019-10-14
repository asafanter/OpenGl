#include <glad/glad.h>

#include "VBO.h"

namespace GL {

VBO::VBO() :
    _id(UINT32(-1)),
    _vertices(),
    _attributes()
{
    glGenBuffers(1, &_id);
}

VBO &VBO::setVertices(const std::vector<Vertex> &new_vertices)
{
    _vertices = new_vertices;

    return *this;
}

VBO &VBO::addAttribute(const Attribute &atr)
{
    _attributes.push_back(atr);

    return *this;

}

VBO::~VBO()
{
    glDeleteBuffers(1, &_id);
}

} //namespace GL


