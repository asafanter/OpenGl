#include <glad/glad.h>

#include "ColoredBuffer.h"

namespace GL {

ColoredBuffer::ColoredBuffer() :
    _vertices()
{

}

void GL::ColoredBuffer::setupVertices() const
{
    glBufferData(GL_ARRAY_BUFFER, INT64(_vertices.size() * sizeof(ColoredVertex)), _vertices.data(), GL_STATIC_DRAW);
}

void ColoredBuffer::setupAttributes() const
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(ColoredVertex), nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(ColoredVertex), reinterpret_cast<void*>(sizeof(Vertex)));
    glEnableVertexAttribArray(1);
}

} //namespace GL


