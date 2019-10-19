#include <glad/glad.h>
#include <algorithm>
#include <iostream>

#include "VAO.h"

namespace GL {

VAO::VAO() :
    _id(UINT32(-1)),
    _premitive(Premitive::POINTS),
    _vbo({}),
    _vertices()
{
    glGenVertexArrays(1, &_id);
    glGenBuffers(1, &_vbo.id);
}

const VAO &VAO::bind() const
{
    glBindVertexArray(_id);

    return *this;
}

const VAO &VAO::unbind() const
{
    glBindVertexArray(0);

    return *this;

}

VAO &VAO::setVertices(const std::vector<Vertex> &new_vertices)
{
    bind();

    glBindBuffer(GL_ARRAY_BUFFER, _vbo.id);
    glBufferData(GL_ARRAY_BUFFER, INT64(sizeof(Vertex) * new_vertices.size()), new_vertices.data(), GL_STATIC_DRAW);

    _vertices = new_vertices;

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    unbind();

    return *this;
}

VAO &VAO::addAttribute(const Attribute &atr)
{
    auto it = std::find_if(_attributes.begin(), _attributes.end(), [&atr](Attribute &a)
    {
        return a.getID() == atr.getID();
    });

    if(it != _attributes.end())
    {
        std::cerr << "attribute with id: " << atr.getID() << " is already exists" << std::endl;
        return *this;
    }

    bind();
    glBindBuffer(GL_ARRAY_BUFFER, _vbo.id);

    glVertexAttribPointer(atr.getID(), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(atr.offset()));
    glEnableVertexAttribArray(atr.getID());

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    unbind();

    _attributes.push_back(atr);

    return *this;
}

void VAO::remove()
{
    glDeleteVertexArrays(1, &_id);
    glDeleteBuffers(1, &_vbo.id);
}

} //namespace GL


