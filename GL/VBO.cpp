#include <glad/glad.h>
#include <algorithm>
#include <iostream>

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
    auto it = std::find_if(_attributes.begin(), _attributes.end(), [&atr](Attribute &a)
    {
        return a.getID() == atr.getID();
    });

    if(it != _attributes.end())
    {
        std::cerr << "attribute with id: " << atr.getID() << " is already exists" << std::endl;
    }

    _attributes.push_back(atr);

    return *this;

}

} //namespace GL


